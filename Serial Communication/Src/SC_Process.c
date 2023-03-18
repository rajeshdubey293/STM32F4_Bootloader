/*
 * SC_Process.c
 *
 *  Created on: 16-Dec-2022
 *      Author: vicky
 */
#include "SC_Process.h"

char sc_Rx_Buffer;

char LED1_ON_FLAG = 0;
char LED2_ON_FLAG = 0;

uint8_t i = 0;

SC_Decode_Bootaloder_Menu sc_Option = BOOTLOADER_MENU_UNKNOWN;
SC_User_Decode sc_User_State = USER_UNKNOWN;

char user_Name_Array[10] = {0};
char user_Pass_Array[10] = {0};

char *user_Name = "admin";
char *user_Pass = "password";

char *sw_Version = "V1.0 Beta\r\n";

void SC_Process(void)
{
	if(Authenticated_User() != USER_AUTHENICATED)
	{
		return;
	}
	if(UART_Rx_Byte_Available())
	{
		UART_Get_Rx_Byte(&sc_Rx_Buffer, 1);
		if(sc_Option == BOOTLOADER_MENU)
		{
			sc_Option = sc_Rx_Buffer;
		}
		switch(sc_Option)
		{
		case UPGRADE_APP:
			Execute_Flash_Erase(5, 1);
			Boot_User_Application();
			break;
		case BOOT_APP:
			Print_Msg("Booting into User Application \r\n");
			Execute_Flash_Erase(5, 1);
			Boot_User_Application();
			break;
		case EXIT:
			sc_Option = BOOTLOADER_MENU_UNKNOWN;
			sc_User_State = USER_UNKNOWN;
			Print_Msg("Exited \r\n");
			break;
		case BOOTLOADER_MENU_UNKNOWN:
			Show_Bootloader_Menu();
			sc_Option = BOOTLOADER_MENU;
			break;
		default:
			Print_Msg("Invalid Options\r\n");
			Show_Bootloader_Menu();
			sc_Option = BOOTLOADER_MENU;
		}
	}
}
void Show_Bootloader_Menu(void)
{
	Print_Msg("******* STM32F4 Boot-loader Menu *******\r\n\n");
	Print_Msg("\t1. Upgrade Application \r\n");
	Print_Msg("\t2. Boot Application \r\n");
	Print_Msg("\tx. Exit \r\n\n");
	Print_Msg("*********************************\r\n\n");

}
SC_User_Decode Authenticated_User(void)
{
	if(UART_Rx_Byte_Available())
	{

		switch(sc_User_State)
		{
		case USER_NAME:
			UART_Get_Rx_Byte(&sc_Rx_Buffer, 1);
			if( (sc_Rx_Buffer != '\r') && (sc_Rx_Buffer != '\n'))
			{
				Print_Msg("%c", sc_Rx_Buffer);
				user_Name_Array[i++] = sc_Rx_Buffer;
			}
			else
			{
				user_Name_Array[i] = '\0';
				sc_User_State = USER_PASS;
				i = 0;
				Print_Msg("\r\nUser Password: ");
			}
			break;
		case USER_PASS:
			UART_Get_Rx_Byte(&sc_Rx_Buffer, 1);
			if( (sc_Rx_Buffer != '\r') && (sc_Rx_Buffer != '\n'))
			{
				user_Pass_Array[i++] = sc_Rx_Buffer;
				sc_Rx_Buffer = '*';
				Print_Msg("%c", sc_Rx_Buffer);
			}
			else
			{
				user_Pass_Array[i] = '\0';
				if ( (strcmp(user_Name, user_Name_Array) == 0)
						&& (strcmp(user_Pass, user_Pass_Array) == 0) )
				{
					sc_User_State = USER_AUTHENICATED;
					Print_Msg("\r\nUser Authenticated\r\n");
				}
				else
				{
					Print_Msg("\r\nWrong User Name and Password\r\n");
					sc_User_State = USER_UNKNOWN;
				}
			}
			break;
		case USER_AUTHENICATED:
			sc_User_State = USER_AUTHENICATED;
			break;
		case USER_UNKNOWN:
			UART_Get_Rx_Byte(&sc_Rx_Buffer, 1);
			Print_Msg("User Name: ");
			sc_User_State = USER_NAME;
			i = 0;
			break;
		default:
			sc_User_State = USER_UNKNOWN;
			break;
		}
	}

	return sc_User_State;
}

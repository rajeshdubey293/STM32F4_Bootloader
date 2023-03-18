/*
 * SC_Process.h
 *
 *  Created on: 16-Dec-2022
 *      Author: vicky
 */

#ifndef INC_SC_PROCESS_H_
#define INC_SC_PROCESS_H_

#include "main.h"



typedef enum {
	UPGRADE_APP = '1',
	BOOT_APP,
	EXIT = 'x',
	BOOTLOADER_MENU_UNKNOWN,
	BOOTLOADER_MENU = '\r',

}SC_Decode_Bootaloder_Menu;


typedef enum
{
	USER_NAME = '1',
	USER_PASS,
	USER_AUTHENICATE,
	USER_AUTHENICATED,
	USER_UNKNOWN
}SC_User_Decode;

void SC_Process(void);
void Show_Bootloader_Menu(void);
SC_User_Decode Authenticated_User(void);



#endif /* INC_SC_PROCESS_H_ */

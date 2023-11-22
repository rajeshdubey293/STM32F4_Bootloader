/*
 * User_Application.c
 *
 *  Created on: 16-Dec-2022
 *      Author: vicky
 */


#include "Upgrade_Application.h"

CRC_HandleTypeDef hcrc;
extern uint32_t *reset_handler_addr;

static uint32_t GetSector(uint32_t Address);

uint8_t Execute_Mem_Write(uint8_t *pBuffer, uint32_t mem_address, uint32_t len) {
	uint8_t status_flash = HAL_OK;

	//We have to unlock flash module to get control of registers
	HAL_FLASH_Unlock();
	for(uint32_t i = 0 ; i < len ; i += 1) {
		//Here we program the flash byte by byte
		status_flash = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,mem_address+i,pBuffer[i] );
	}
	HAL_FLASH_Lock();

	return status_flash;
}
uint8_t Execute_Flash_Erase(uint32_t address , uint8_t number_Of_Sector) {
	uint32_t FirstSector = 0, sector_Error = 0;

	FLASH_EraseInitTypeDef flash_Erase_Handle = {0};
	HAL_StatusTypeDef status_Flash;

	/* Get the 1st sector to erase */
	FirstSector = GetSector(address);

	flash_Erase_Handle.TypeErase = FLASH_TYPEERASE_SECTORS;
	flash_Erase_Handle.Sector = FirstSector; // this is the initial sector
	flash_Erase_Handle.NbSectors = number_Of_Sector;
	flash_Erase_Handle.Banks = Get_Bank(address);
	flash_Erase_Handle.VoltageRange = FLASH_VOLTAGE_RANGE_3;  // our mcu will work on this voltage range

	/*Get access to touch the flash registers */
	HAL_FLASH_Unlock();
	status_Flash = HAL_FLASHEx_Erase(&flash_Erase_Handle, &sector_Error);
	HAL_FLASH_Lock();

	return status_Flash;
}
uint32_t Calculate_Authentication_Key(uint32_t key) {
	uint32_t return_Value = key ^ 0xAABBCCDD;
	return return_Value;

}
uint8_t Bootloader_Verify_CRC(uint8_t *pData, uint32_t len) {
	uint32_t uwCRCValue = 0xFF;
	uint32_t *host_crc = (uint32_t*)(APP_TOTAL_LENGTH_ADDR + 4);

	for (uint32_t i = 0 ; i < len ; i++) {
		uint32_t i_Data = pData[i];
		uwCRCValue = HAL_CRC_Accumulate(&hcrc, &i_Data, 1);
	}
	/* Reset CRC Calculation Unit */
	__HAL_CRC_DR_RESET(&hcrc);
	if( uwCRCValue == *host_crc) {
		return VERIFY_CRC_SUCCESS;
	}

	return VERIFY_CRC_FAIL;
}
inline void Boot_User_Application(void) {
	void (*app_Reset_Handler)(void);

	// 1. Configure the MSP by reading the value from the base address of the sector 6
	uint32_t msp_Value = *(volatile uint32_t *)APP_FLASH_ADDR;
	//Print_Msg("MSP Value : %#x\r\n", msp_Value);
	//This function comes from CMSIS.
	__set_MSP(msp_Value);

	SCB->VTOR = APP_FLASH_ADDR;

	/* 2. Now fetch the reset handler address of the user application
	 * from the location APP_FLASH_ADDR + 4
	 */
	uint32_t reset_Handler_Address = *(volatile uint32_t *) (APP_FLASH_ADDR + 4);

	app_Reset_Handler = (void*) reset_Handler_Address;
	//Print_Msg("App Reset Handler Addr : %#x\r\n", app_Reset_Handler);
	//3. jump to reset handler of the user application
	app_Reset_Handler();
}
uint8_t Calculate_Num_Of_Sector(uint32_t len) {
	uint8_t num_Of_Sector = 0;
	uint32_t total_Size = 786432;
	uint8_t total_Sector = 6;
	if(len < FLASH_SECTOR_SIZE) {
		num_Of_Sector = 1;
	}
	else {
		num_Of_Sector = total_Sector - (total_Size / len);
	}
	return num_Of_Sector;
}
void CRC_Init(void) {
	hcrc.Instance = CRC;
	if (HAL_CRC_Init(&hcrc) != HAL_OK) {
		Error_Handler();
	}

}
void Upgrade_Application(void) {
	uint8_t input_Buffer[64] = {0};
	uint8_t data_buffer[50] = {0};
	uint32_t *reset_handler = (uint32_t*)APP_FLASH_ADDR;
	//uint8_t *data_Buffer = malloc(46000);
	//memset(data_Buffer, 0, 46000);
	uint32_t dest_Address = 0, i = 0;
	uint8_t data_Len= 0;
	uint32_t total_Packet_Len = 0;
	char rx_Byte;
	int status = 1;
	Print_Msg("Bootloader:Send S Record File\r\n");
	while(status != 0) {
		//if(UART_Rx_Byte_Available())
		if(IsDataAvailable()) {
			//UART_Get_Rx_Byte(&rx_Byte, 1);
			rx_Byte = Uart_read();
			input_Buffer[i] = rx_Byte;
			if(rx_Byte == '\r') {
				status = Extract_Srecord_file((char*)&input_Buffer, (uint8_t*)data_buffer, &dest_Address, &data_Len);
				if(status != -1) {
					Execute_Mem_Write(data_buffer, dest_Address, data_Len);
				}
				memset(data_buffer, 0, sizeof(data_buffer));
				total_Packet_Len += data_Len;
				i = 0;
				continue;
			}
			i++;
		}
	}
	//Print_Msg("Binary File is Received, total Count = %d bytes\r\n", total_Packet_Len);
	Print_Msg("Bootloader:Upgrade Successfull\r\n");
	Execute_Flash_Erase(APP_TOTAL_LENGTH_ADDR, 1);
	Execute_Mem_Write((uint8_t*)&total_Packet_Len, APP_TOTAL_LENGTH_ADDR, 4);
	Calculate_App_CRC((uint8_t*)reset_handler, total_Packet_Len);
}
int Extract_Srecord_file(char *input_Bufer, uint8_t *data_Buffer, uint32_t *dest_Address, uint8_t *data_len) {
	int type, count, i;
	unsigned int addr;
	/* Check for start code */
	if (input_Bufer[0] != 'S') {
		//Print_Msg("Error: invalid format\r\n");
		return -1;
	}

	/* Read record type */
	sscanf((char*)&input_Bufer[1], "%1x", &type);
	//Print_Msg("type = %d\r\n", type);

	/* Read record count */
	sscanf((char*)&input_Bufer[2], "%2x", &count);

	/* Read record address */
	switch (type) {
	case 0:
		return -1;
	case 3:
		sscanf((char*)&input_Bufer[4], "%8x", &addr);
		*dest_Address = addr;
		break;
	case 7:
		return 0;
	}

	/* Read data */
	for (i = 0; i < count - 5; i++) {
		sscanf((char*)&input_Bufer[8 + 2 * (i + (type - 1))], "%2x", (unsigned int*)&data_Buffer[i]);
	}
	*data_len = i;
	return 1;
}
/**
 * @brief  Gets the sector of a given address
 * @param  None
 * @retval The sector of a given address
 */
static uint32_t GetSector(uint32_t Address) {
	uint32_t sector = 0;

	if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0)) {
		sector = FLASH_SECTOR_0;
	}
	else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1)) {
		sector = FLASH_SECTOR_1;
	}
	else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2)) {
		sector = FLASH_SECTOR_2;
	}
	else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3)) {
		sector = FLASH_SECTOR_3;
	}
	else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4)) {
		sector = FLASH_SECTOR_4;
	}
	else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5)) {
		sector = FLASH_SECTOR_5;
	}
	else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6)) {
		sector = FLASH_SECTOR_6;
	}
	else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7)) {
		sector = FLASH_SECTOR_7;
	}
	else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8)) {
		sector = FLASH_SECTOR_8;
	}
	else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9)) {
		sector = FLASH_SECTOR_9;
	}
	else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10)) {
		sector = FLASH_SECTOR_10;
	}
	else if((Address < ADDR_FLASH_SECTOR_12) && (Address >= ADDR_FLASH_SECTOR_11)) {
		sector = FLASH_SECTOR_11;
	}
	else if((Address < ADDR_FLASH_SECTOR_13) && (Address >= ADDR_FLASH_SECTOR_12)) {
		sector = FLASH_SECTOR_12;
	}
	else if((Address < ADDR_FLASH_SECTOR_14) && (Address >= ADDR_FLASH_SECTOR_13)) {
		sector = FLASH_SECTOR_13;
	}
	else if((Address < ADDR_FLASH_SECTOR_15) && (Address >= ADDR_FLASH_SECTOR_14)) {
		sector = FLASH_SECTOR_14;
	}
	else if((Address < ADDR_FLASH_SECTOR_16) && (Address >= ADDR_FLASH_SECTOR_15)) {
		sector = FLASH_SECTOR_15;
	}
	else if((Address < ADDR_FLASH_SECTOR_17) && (Address >= ADDR_FLASH_SECTOR_16)) {
		sector = FLASH_SECTOR_16;
	}
	else if((Address < ADDR_FLASH_SECTOR_18) && (Address >= ADDR_FLASH_SECTOR_17)) {
		sector = FLASH_SECTOR_17;
	}
	else if((Address < ADDR_FLASH_SECTOR_19) && (Address >= ADDR_FLASH_SECTOR_18)) {
		sector = FLASH_SECTOR_18;
	}
	else if((Address < ADDR_FLASH_SECTOR_20) && (Address >= ADDR_FLASH_SECTOR_19)) {
		sector = FLASH_SECTOR_19;
	}
	else if((Address < ADDR_FLASH_SECTOR_21) && (Address >= ADDR_FLASH_SECTOR_20)) {
		sector = FLASH_SECTOR_20;
	}
	else if((Address < ADDR_FLASH_SECTOR_22) && (Address >= ADDR_FLASH_SECTOR_21)) {
		sector = FLASH_SECTOR_21;
	}
	else if((Address < ADDR_FLASH_SECTOR_23) && (Address >= ADDR_FLASH_SECTOR_22)) {
		sector = FLASH_SECTOR_22;
	}
	else/*(Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_23))*/ {
		sector = FLASH_SECTOR_23;
	}

	return sector;
}
void Calculate_App_CRC(uint8_t *addr, uint32_t len) {
	uint32_t uwCRCValue = 0xFF;
	for (uint32_t i = 0 ; i < len ; i++) {
		uint32_t i_Data = addr[i];
		uwCRCValue = HAL_CRC_Accumulate(&hcrc, &i_Data, 1);
	}
	/* Reset CRC Calculation Unit */
	__HAL_CRC_DR_RESET(&hcrc);
	Execute_Mem_Write((uint8_t*)&uwCRCValue, (APP_TOTAL_LENGTH_ADDR + 4), 4);
}
uint32_t Get_Bank(uint32_t addr) {
	if(addr < (FLASH_BASE + FLASH_BANK_SIZE)) {
		/*	Bank 1	*/
		return FLASH_BANK_1;
	}
	else {
		/*	Bank 2	*/
		return FLASH_BANK_2;
	}
}

/*
 * User_Application.h
 *
 *  Created on: 16-Dec-2022
 *      Author: vicky
 */

#ifndef INC_UPGRADE_APPLICATION_H_
#define INC_UPGRADE_APPLICATION_H_

#include "main.h"

#define FLASH_SECTOR6_BASE_ADDRESS 		0x08040000U
#define INVALID_SECTOR 					0x04
#define VERIFY_CRC_FAIL    				1
#define VERIFY_CRC_SUCCESS 				0
#define FLASH_SECTOR_SIZE 				131072

#define UPGRADE_APPLICATION_CHECK_ADDR 0x0803FFFC

void CRC_Init(void);
void Boot_User_Application(void);

uint8_t Calculate_Num_Of_Sector(uint32_t len);
uint8_t Bootloader_Verify_CRC (uint8_t *pData, uint32_t len, uint32_t crc_Host);
uint8_t Execute_Flash_Erase(uint8_t sector_Number , uint8_t number_Of_Sector);
uint8_t Execute_Mem_Write(uint8_t *pBuffer, uint32_t mem_Address, uint32_t len);
uint32_t Calculate_Authentication_Key(uint32_t key);

#endif /* INC_UPGRADE_APPLICATION_H_ */

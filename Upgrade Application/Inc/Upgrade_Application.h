/*
 * User_Application.h
 *
 *  Created on: 16-Dec-2022
 *      Author: vicky
 */

#ifndef INC_UPGRADE_APPLICATION_H_
#define INC_UPGRADE_APPLICATION_H_

#include "main.h"


#define APP_UPGRADE_CHECK_ADDR			0x08080000U
#define APP_TOTAL_LENGTH_ADDR			0x080A0000U

#define APP_FLASH_ADDR					0x08100000U

#define INVALID_SECTOR 					0x04
#define VERIFY_CRC_FAIL    				1
#define VERIFY_CRC_SUCCESS 				0
#define FLASH_SECTOR_SIZE 				131072
#define FLASH_BANK_SIZE					0x100000U

/* Base address of the Flash sectors Bank 1 */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbytes */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbytes */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbytes */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbytes */

/* Base address of the Flash sectors Bank 2 */
#define ADDR_FLASH_SECTOR_12     ((uint32_t)0x08100000) /* Base @ of Sector 0, 16 Kbytes */
#define ADDR_FLASH_SECTOR_13     ((uint32_t)0x08104000) /* Base @ of Sector 1, 16 Kbytes */
#define ADDR_FLASH_SECTOR_14     ((uint32_t)0x08108000) /* Base @ of Sector 2, 16 Kbytes */
#define ADDR_FLASH_SECTOR_15     ((uint32_t)0x0810C000) /* Base @ of Sector 3, 16 Kbytes */
#define ADDR_FLASH_SECTOR_16     ((uint32_t)0x08110000) /* Base @ of Sector 4, 64 Kbytes */
#define ADDR_FLASH_SECTOR_17     ((uint32_t)0x08120000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_18     ((uint32_t)0x08140000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_19     ((uint32_t)0x08160000) /* Base @ of Sector 7, 128 Kbytes */
#define ADDR_FLASH_SECTOR_20     ((uint32_t)0x08180000) /* Base @ of Sector 8, 128 Kbytes  */
#define ADDR_FLASH_SECTOR_21     ((uint32_t)0x081A0000) /* Base @ of Sector 9, 128 Kbytes  */
#define ADDR_FLASH_SECTOR_22     ((uint32_t)0x081C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_23     ((uint32_t)0x081E0000) /* Base @ of Sector 11, 128 Kbytes */


typedef enum Device_Boot {
	APP_EMPTY = 0xFFFFFFFFU,
	APP_UPGRADE_PENDING = 0xAABBCCDD,
}Device_Boot_E;

void CRC_Init(void);
void Boot_User_Application(void);

uint8_t Calculate_Num_Of_Sector(uint32_t len);
uint8_t Bootloader_Verify_CRC (uint8_t *pData, uint32_t len);
uint8_t Execute_Flash_Erase(uint32_t address , uint8_t number_Of_Sector);
uint8_t Execute_Mem_Write(uint8_t *pBuffer, uint32_t mem_Address, uint32_t len);
uint32_t Calculate_Authentication_Key(uint32_t key);
void Upgrade_Application(void);
int Extract_Srecord_file(char *input_Bufer, uint8_t *data_Buffer, uint32_t *dest_Address, uint8_t *data_len);
void Calculate_App_CRC(uint8_t *addr, uint32_t len);
uint32_t Get_Bank(uint32_t addr);

#endif /* INC_UPGRADE_APPLICATION_H_ */

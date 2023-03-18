/*
 * User_Application.c
 *
 *  Created on: 16-Dec-2022
 *      Author: vicky
 */


#include "Upgrade_Application.h"

CRC_HandleTypeDef hcrc;

uint8_t Execute_Mem_Write(uint8_t *pBuffer, uint32_t mem_Address, uint32_t len)
{
	uint8_t status_Flash = HAL_OK;

	//We have to unlock flash module to get control of registers
	HAL_FLASH_Unlock();

	for(uint32_t i = 0 ; i < len ; i++)
	{
		//Here we program the flash byte by byte
		status_Flash = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,mem_Address+i,pBuffer[i] );
	}
	HAL_FLASH_Lock();

	return status_Flash;
}

uint8_t Execute_Flash_Erase(uint8_t sector_Number , uint8_t number_Of_Sector)
{
	//we have totally 12 sectors in STM32F407VG mcu .. sector[0 to 11]
	//number_of_sector has to be in the range of 0 to 11
	// if sector_number = 0xff , that means mass erase !
	//Code needs to modified if your MCU supports more flash sectors
	FLASH_EraseInitTypeDef flash_Erase_Handle;
	uint32_t sector_Error;
	HAL_StatusTypeDef status_Flash;


	if( number_Of_Sector > 12 )
		return INVALID_SECTOR;

	if( (sector_Number == 0xff ) || (sector_Number <= 11) )
	{
		if(sector_Number == (uint8_t) 0xff)
		{
			flash_Erase_Handle.TypeErase = FLASH_TYPEERASE_MASSERASE;
		}else
		{
			/*Here we are just calculating how many sectors needs to erased */
			uint8_t remanining_Sector = 12 - sector_Number;
			if( number_Of_Sector > remanining_Sector)
			{
				number_Of_Sector = remanining_Sector;
			}
			flash_Erase_Handle.TypeErase = FLASH_TYPEERASE_SECTORS;
			flash_Erase_Handle.Sector = sector_Number; // this is the initial sector
			flash_Erase_Handle.NbSectors = number_Of_Sector;
		}
		flash_Erase_Handle.Banks = FLASH_BANK_1;

		/*Get access to touch the flash registers */
		HAL_FLASH_Unlock();
		flash_Erase_Handle.VoltageRange = FLASH_VOLTAGE_RANGE_3;  // our mcu will work on this voltage range
		status_Flash = (uint8_t) HAL_FLASHEx_Erase(&flash_Erase_Handle, &sector_Error);
		HAL_FLASH_Lock();

		return status_Flash;
	}


	return INVALID_SECTOR;
}
uint32_t Calculate_Authentication_Key(uint32_t key)
{
	uint32_t return_Value = key ^ 0xAABBCCDD;
	return return_Value;

}
uint8_t Bootloader_Verify_CRC (uint8_t *pData, uint32_t len, uint32_t crc_Host)
{
	uint32_t uwCRCValue = 0xFF;

	for (uint32_t i = 0 ; i < len ; i++)
	{
		uint32_t i_Data = pData[i];
		uwCRCValue = HAL_CRC_Accumulate(&hcrc, &i_Data, 1);
	}

	/* Reset CRC Calculation Unit */
	__HAL_CRC_DR_RESET(&hcrc);

	if( uwCRCValue == crc_Host)
	{
		return VERIFY_CRC_SUCCESS;
	}

	return VERIFY_CRC_FAIL;
}
void Boot_User_Application(void)
{
	void (*app_Reset_Handler)(void);

	// 1. Configure the MSP by reading the value from the base address of the sector 6
	uint32_t msp_Value = *(volatile uint32_t *)FLASH_SECTOR6_BASE_ADDRESS;
	//Print_Msg("MSP Value : %#x\r\n", msp_Value);
	//This function comes from CMSIS.
	__set_MSP(msp_Value);

	//SCB->VTOR = FLASH_SECTOR1_BASE_ADDRESS;

	/* 2. Now fetch the reset handler address of the user application
	 * from the location FLASH_SECTOR6_BASE_ADDRESS + 4
	 */
	uint32_t reset_Handler_Address = *(volatile uint32_t *) (FLASH_SECTOR6_BASE_ADDRESS + 4);

	app_Reset_Handler = (void*) reset_Handler_Address;
	//Print_Msg("App Reset Handler Addr : %#x\r\n", app_Reset_Handler);
	//3. jump to reset handler of the user application
	app_Reset_Handler();

}
uint8_t Calculate_Num_Of_Sector(uint32_t len)
{
	/*
	 * Memory Arrangement of STM32F407
	 * Sector 6 = 128Kbytes
	 * Sector 7 = 128Kbytes
	 * Sector 8 = 128Kbytes
	 * Sector 9 = 128Kbytes
	 * Sector 10 = 128Kbytes
	 * Sector 11 = 128Kbytes
	 * Total Available Size = 131072 * 6 = 786432 bytes
	 * Total Sector = 6
	 */
	uint8_t num_Of_Sector = 0;
	uint32_t total_Size = 786432;
	uint8_t total_Sector = 6;
	if(len < FLASH_SECTOR_SIZE)
	{
		num_Of_Sector = 1;
	}
	else
	{
		num_Of_Sector = total_Sector - (total_Size / len);
	}
	return num_Of_Sector;
}
void CRC_Init(void)
{
	hcrc.Instance = CRC;
	if (HAL_CRC_Init(&hcrc) != HAL_OK)
	{
		Error_Handler();
	}

}


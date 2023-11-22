/*
 * UART.c
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */
#include "UART.h"

UART_HandleTypeDef huart1;

extern uint8_t rx_Buffer;
char byte_Available = 0;

void UART_Init(void)
{
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		Error_Handler();
	}

}

void Print_Msg(char *format,...)
{
	char tx_Buffer[80];
	/*Extract the the argument list using VA APIS */
	va_list args;
	va_start(args, format);
	vsprintf(tx_Buffer, format,args);
	HAL_UART_Transmit(&huart1,(uint8_t *)tx_Buffer, strlen(tx_Buffer), 10);
	va_end(args);
}
#if 1
inline void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	byte_Available = 1;
	HAL_UART_Receive_IT(&huart1, (uint8_t*)&rx_Buffer, 1);
}
#endif
inline void UART_Receive(char *tmp_Rx_Buffer)
{
	HAL_UART_Receive(&huart1, (uint8_t*)tmp_Rx_Buffer, 1, 100);
}
#if 0
inline void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	HAL_UARTEx_ReceiveToIdle_IT(huart, (uint8_t*)&rx_Buffer, Size);
}
#endif
inline void UART_Interrupt_Start(char *tmp_Rx_Buffer)
{
	HAL_UART_Receive_IT(&huart1, (uint8_t*)tmp_Rx_Buffer, 1);
}
inline void UART_Get_Rx_Byte(char *tmp_Rx_Buffer, uint8_t size)
{

	*tmp_Rx_Buffer = rx_Buffer;
	byte_Available = 0;
}
inline int8_t UART_Rx_Byte_Available(void)
{
	return byte_Available;
}

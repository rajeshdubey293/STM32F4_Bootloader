/*
 * UART.h
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"

void UART_Init(void);
void Print_Msg(char *format,...);
void UART_Interrupt_Start(char *tmp_Rx_Buffer);
void UART_Receive(char *tmp_Rx_Buffer);
void UART_Get_Rx_Byte(char *tmp_Rx_Buffer, uint8_t size);
int8_t UART_Rx_Byte_Available(void);

#endif /* INC_UART_H_ */

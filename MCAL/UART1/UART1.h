/*
 * UART.h
 *
 * Created: 09-Sep-19 2:29:07 PM
 *  Author: al ghazaly
 */ 




#ifndef UART1_H_
#define UART1_H_

#include "IncludeAll.h"


void UART1_init(void);
void UART1_sendByte(const UINT8 data);
UINT8 UART1_recieveByte(void);
void UART1_sendString(const UINT8 *Str);
void UART1_receiveString(UINT8 *Str);




#endif /* UART_H_ */
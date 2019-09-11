/*
 * UART.c
 *
 * Created: 09-Sep-19 2:28:51 PM
 *  Author: al ghazaly
 */ 


#include "IncludeAll.h"
#define BAUD 9600                         //default baud
#define UBRR ((F_CPU/BAUD/16)-1)

void UART1_init(void)
{
	 /* Disable interrupts */
	 cli();
	 
	/* Used for enabling interrupts etc. */
	 UCSR1A = 0;
	 
	UCSR1B |= (1<<RXCIE1) | (1 << RXEN1) | (1 << TXEN1);    // Turn on the transmission reception ..
	// circuitry and receiver interrupt
	UCSR1C |= (1 << UCSZ10) | (1 << UCSZ11); // Use 8-bit character sizes
	
	
	
	/// baud rate=9600 & Fosc=8MHz -->  UBBR=( Fosc / (16 * baud rate) ) - 1 = 103 
	
	UBRR1H=(unsigned char)(UBRR>>8);    // shift the register right by 8 bits
	UBRR1L=(unsigned char)(UBRR);      // set baud rate
	
	  /* Enable interrupts */
	  sei();

}
void UART1_sendByte(const UINT8 data)
{
	while(readBit(UCSR1A,UDRE1) ==0 ){}

	UDR1 = data;

}
UINT8 UART1_recieveByte(void)
{

	while(readBit(UCSR1A,RXC1) ==0 ){}
	
	return UDR1;
}
void UART1_sendString(const UINT8 *Str)
{
	UINT8 i = 0;
	while(Str[i] != '\0')
	{
		UART1_sendByte(Str[i]);
		i++;
	}
}
void UART1_receiveString(UINT8 *Str)
{
	UINT8 i = 0;
	Str[i] = UART1_recieveByte();
	while(Str[i] != '\0')           //// note we send '#' as end of command 
	{
		i++;
		Str[i] = UART1_recieveByte();
	}
	Str[i] = '\0';
}



/*
 * BlueTooth.c
 *
 * Created: 10-Sep-19 10:19:39 AM
 *  Author: al ghazaly
 */ 
#include "IncludeAll.h"




UINT8 buffer1[25], buffer2[50];
UINT8 temp;

void Bluetooth_Init(void)
{
	UART1_init();
	
	setBit(DDRD,DDRD3);			/// set the TX pin PD3 as output
	clearBit(DDRD,DDRD2);		/// set the RX pin PD2 as input
	
}

void Bluetooth_transmit_byte(UINT8 data_byte)
{
	UART1_sendByte(data_byte);
}

UINT8 Bluetooth_receive_byte(void)
{
	return UART1_recieveByte();
}

void Bluetooth_transmit_string(UINT8 *transmit_string)
{
	UART1_sendString(transmit_string);
}

void Bluetooth_receive_string(UINT8 *receive_string )
{
	UART1_receiveString(receive_string);
}

UINT8 Bluetooth_at_command_mode_test(void)
{
	_delay_ms(500);
	UART1_sendString("AT");
	UART1_sendByte(13);	//Enter terminator must addeed after command ( \r)
	UART1_sendByte(10); //Enter terminator must addeed after command (\n)
	UART1_receiveString(buffer1);
	temp=UART1_recieveByte();
	if(!(strcmp(buffer1,"OK")))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

UINT8 Bluetooth_device_name_change(UINT8 *device_name)
{
	_delay_ms(500);
	UART1_sendString("AT+NAME=");
	UART1_sendString(device_name);
	UART1_sendByte(13);
	UART1_sendByte(10);
	UART1_receiveString(buffer1);
	temp=UART_recieveByte();
	if(!(strcmp(buffer1,"OK")))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
UINT8 Bluetooth_get_version(void)
{
	UINT8 i=9,j=0;
	_delay_ms(500);
	UART1_sendString("AT+VERSION?");
	UART1_sendByte(13);
	UART1_sendByte(10);
	UART1_receiveString(buffer2);
	for(i=9;buffer2[i]!=0;i++)             //i=9 b/c there is 9 words reserved for "+VERSION:"
	{
		buffer2[j]=buffer2[i];
		j++;
	}
	buffer2[j]=0;
	if(!(strcmp(buffer1,"OK")))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
UINT8 Bluetooth_pin_change(UINT8 *new_pin)
{
	_delay_ms(500);
	UART1_sendString("AT+PSWD=");
	UART1_sendString(new_pin);
	UART1_sendByte(13);
	UART1_sendByte(10);

	UART1_receiveString(buffer1);
	temp=UART1_recieveByte();

	if(!(strcmp(buffer1,"OK")))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

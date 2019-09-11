/*
 * Smart_Car.c
 *
 * Created: 09-Sep-19 1:43:23 PM
 *  Author: al ghazaly
 */ 


#include "IncludeAll.h"

volatile UINT8 startAutoParking;

int main(void)
{
	LCD_Init();
	Bluetooth_Init();
	

    while(1)
    {
				
    }
}

ISR(USART1_RX_vect)
{
	startAutoParking = Bluetooth_receive_byte();
	LCD_SendCharRC(1,8,startAutoParking);
}
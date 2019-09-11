
#include "IncludeAll.h"

void LCD_Init(void){
	/* Control Pins as Output */
	setBits(LCD_CONTROL_DDR,LCD_CONTROL_MASK);
	clearBits(LCD_CONTROL_PORT,LCD_CONTROL_MASK);
	/* Data Pins as Output */
	setBits(LCD_DATA_DDR,LCD_DATA_MASK);
	clearBits(LCD_DATA_PORT,LCD_DATA_MASK);
	_delay_ms(20);			/* LCD Power on delay */
	LCD_SendCMD(0x28);		/* 4-bit, 5*8 font, 2 lines */
	LCD_SendCMD(0x0C);		/* Display on, cursor off, blink off */
	LCD_SendCMD(0x06);		/* Automatic Increment */
	LCD_SendCMD(0x01);		/* Clear Display */
	_delay_ms(5);			/* Clear Display Time */
}
void LCD_GotoRC(UINT8 row, UINT8 col){
	if (row == 1)
	{
		LCD_SendCMD(0x80 + col -1);
	}
	else
	{
		LCD_SendCMD(0xC0 + col -1);
	}
}
void LCD_SendCMD(UINT8 cmd){
	/* RS, RW */
	clearBit(LCD_CONTROL_PORT,LCD_RS);	/* Command */
	clearBit(LCD_CONTROL_PORT,LCD_RW);	/* Write */
	
	/* Write cmd high nipple */
	//LCD_DATA_PORT = ((LCD_DATA_PORT&0x0F)|(cmd&0xF0));
	LCD_PORT.HN = (cmd>>4);
	/* Start Write Operation */
	setBit(LCD_CONTROL_PORT,LCD_EN);
	clearBit(LCD_CONTROL_PORT,LCD_EN);
	
	/* Write cmd low nipple */
	//LCD_DATA_PORT = ((LCD_DATA_PORT&0x0F)|(cmd<<4));
	LCD_PORT.HN = cmd;
	/* Start Write Operation */
	setBit(LCD_CONTROL_PORT,LCD_EN);
	clearBit(LCD_CONTROL_PORT,LCD_EN);
	
	/* cmd time delay */
	_delay_us(40);
}

void LCD_SendChar(UINT8 data){
	/* RS, RW */
	setBit(LCD_CONTROL_PORT,LCD_RS);	/* Data */
	clearBit(LCD_CONTROL_PORT,LCD_RW);	/* Write */
	
	/* Write cmd high nibble */
	//LCD_DATA_PORT = ((LCD_DATA_PORT&0x0F)|(data&0xF0));
	LCD_PORT.HN = (data>>4);
	/* Start Write Operation */
	setBit(LCD_CONTROL_PORT,LCD_EN);
	clearBit(LCD_CONTROL_PORT,LCD_EN);
	
	/* Write cmd low nibble */
	//LCD_DATA_PORT = ((LCD_DATA_PORT&0x0F)|(data<<4));
	LCD_PORT.HN = data;
	/* Start Write Operation */
	setBit(LCD_CONTROL_PORT,LCD_EN);
	clearBit(LCD_CONTROL_PORT,LCD_EN);
	
	/* cmd time delay */
	_delay_us(40);
}
void LCD_SendCharRC(UINT8 row, UINT8 col,UINT8 ch){
	LCD_GotoRC(row,col);
	LCD_SendChar(ch);
}
void LCD_SendInt(UINT32 valueInt){
	UINT8 str[17] = {0};
	itoa(valueInt,str,10);
	LCD_SendString(str);
}
void LCD_SendString(UINT8* str){
	UINT8 ind = 0;
	while(str[ind]){
		LCD_SendChar(str[ind]);
		ind++;
	}
}
void LCD_SendIntRC(UINT8 row, UINT8 col,UINT32 valueInt){
	LCD_GotoRC(row,col);
	LCD_SendInt(valueInt);
}

void LCD_SendStringRC(UINT8 row, UINT8 col,UINT8* str){
	LCD_GotoRC(row,col);
	LCD_SendString(str);
}
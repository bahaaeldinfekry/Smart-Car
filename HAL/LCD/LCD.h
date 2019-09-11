/*
 * LCD.h
 *
 * Created: 10-Sep-19 3:49:19 PM
 *  Author: al ghazaly
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "IncludeAll.h"



//functions prototype


#define LCD_CONTROL_PORT	PORTB
#define LCD_CONTROL_DDR		DDRB

#define LCD_DATA_PORT		PORTC
#define LCD_DATA_DDR		DDRC
#define LCD_DATA_MASK		0xF0

#define LCD_RS				PB5
#define LCD_RW				PB6
#define LCD_EN				PB7
#define LCD_CONTROL_MASK	((1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN))

struct reg{
	UINT8	LN:4;														////* low nipple  */
	UINT8	HN:4;														////* high nipple  */
};

#define LCD_PORT (*((volatile struct reg*)(&LCD_DATA_PORT)))

void LCD_Init(void);
void LCD_GotoRC(UINT8 row, UINT8 col);
void LCD_SendCMD(UINT8 cmd);

void LCD_SendChar(UINT8 data);
void LCD_SendCharRC(UINT8 row, UINT8 col,UINT8 ch);
void LCD_SendInt(UINT32 valueInt);
void LCD_SendIntRC(UINT8 row, UINT8 col,UINT32 valueInt);
void LCD_SendString(UINT8* str);
void LCD_SendStringRC(UINT8 row, UINT8 col,UINT8* str);




#endif /* LCD_H_ */
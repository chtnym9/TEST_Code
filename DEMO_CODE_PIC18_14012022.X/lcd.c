#include<stdio.h>
#include"lcd.h"   
#define _XTAL_FREQ 10000000
char *str;

void ToggleEpinOfLCD(void)
{
	LCD_E = 1;                // Give a pulse on E pin
  __delay_ms(1);    // so that LCD can latch the

	LCD_E = 0;                // data from data bus
//	 delay(E_Delay);
 __delay_ms(1);
}

void WriteCommandToLCD(unsigned char Command)
{
	LCD_RS = 0;				  // It is a command
		LCD_RW = 0;
	PORTE &= 0x0F;			  // Make Data pins zero
	LATE |= (Command&0xF0);  // Write Upper nibble of data
	ToggleEpinOfLCD();		  // Give pulse on E pin

	PORTE &= 0x0F;			  // Make Data pins zero
	LATE |= ((Command<<4)&0xF0); // Write Lower nibble of data
	ToggleEpinOfLCD();		  // Give pulse on E pin
}

void WriteDataToLCD(char LCDChar)
{
	LCD_RS = 1;				  // It is data
	LCD_RW = 0;
	PORTE &= 0x0F;			  // Make Data pins zero
	LATE |= (LCDChar&0xF0);  // Write Upper nibble of data
	ToggleEpinOfLCD();		  // Give pulse on E pin

	PORTE &= 0x0F;			  // Make Data pins zero
	LATE |= ((LCDChar<<4)&0xF0); // Write Lower nibble of data
	ToggleEpinOfLCD();		  // Give pulse on E pin
}

void InitLCD(void)
{
	// Firstly make all pins output
	LCD_E  		 		 = 0;   // E  = 0
	LCD_RS  	 		 = 0;   // RS = 0
	LCD_RW				 = 0;
	LCD_Data_Bus_D4		 = 0;  	// Data bus = 0
	LCD_Data_Bus_D5		 = 0;  	// Data bus = 0
	LCD_Data_Bus_D6		 = 0;  	// Data bus = 0
	LCD_Data_Bus_D7		 = 0;  	// Data bus = 0
	LCD_E_Dir    		 = 0;   // Make Output
	LCD_RS_Dir    	 	 = 0;   // Make Output
	LCD_Data_Bus_Dir_D4  = 0;   // Make Output
	LCD_Data_Bus_Dir_D5  = 0;   // Make Output
	LCD_Data_Bus_Dir_D6  = 0;   // Make Output
	LCD_Data_Bus_Dir_D7  = 0;   // Make Output

  ///////////////// Reset process from datasheet //////////////
   //delay(40);

	PORTE &= 0x0F;			  // Make Data pins zero
	LATE |= 0x30;			  // Write 0x3 value on data bus
	ToggleEpinOfLCD();		  // Give pulse on E pin

   //delay(30);

	PORTE &= 0x0F;			  // Make Data pins zero
	LATE |= 0x30;			  // Write 0x3 value on data bus
	ToggleEpinOfLCD();		  // Give pulse on E pin

  // delay(30);

	PORTE &= 0x0F;			  // Make Data pins zero
	LATE |= 0x30;			  // Write 0x3 value on data bus
	ToggleEpinOfLCD();		  // Give pulse on E pin

   //delay(30);

	PORTE &= 0x0F;			  // Make Data pins zero
	LATE |= 0x20;			  // Write 0x2 value on data bus
	ToggleEpinOfLCD();		  // Give pulse on E pin

	//delay(30);
  /////////////// Reset Process End ////////////////
	WriteCommandToLCD(0x28);    //function set
	WriteCommandToLCD(0x0c);    //display on,cursor off,blink off
	WriteCommandToLCD(0x01);    //clear display
	WriteCommandToLCD(0x06);    //entry mode, set increment
}


void WriteStringToLCD(const char *s)
{
	while(*s)
		WriteDataToLCD(*s++);   // print first character on LCD
}


void ClearLCDScreen(void)       // Clear the Screen and return cursor to zero position
{
	WriteCommandToLCD(0x01);    // Clear the screen
	//delay(20);              // Delay for cursor to return at zero position
}

void delay(unsigned int h)
{
    unsigned int k=0,l=0;
    for(k=0;k<h;k++);
        for(l=0;l<h;l++);
}

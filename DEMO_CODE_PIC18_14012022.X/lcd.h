/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _LCD_H_
#define	_LCD_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdio.h>
#include <stdlib.h>
#include <pic18f67j10.h>

 /*-----------LCD PINS--------------*/
#define LCD_E    			RD0    // Enable pin for LCD
#define LCD_E_Dir     		TRISD0

#define LCD_RW    			RE3    // Enable pin for LCD
#define LCD_RW_Dir    		TRISE3    // Enable pin for LCD

#define LCD_RS	 			RE2     // RS pin for LCD
#define LCD_RS_Dir   	 	TRISE2

#define LCD_Data_Bus_D4		RE4		// Data bus bit 4
#define LCD_Data_Bus_Dir_D4 TRISE4

#define LCD_Data_Bus_D5		RE5		// Data bus bit 5
#define LCD_Data_Bus_Dir_D5 TRISE5

#define LCD_Data_Bus_D6		RE6		// Data bus bit 6
#define LCD_Data_Bus_Dir_D6 TRISE6

#define LCD_Data_Bus_D7		RE7		// Data bus bit 7
#define LCD_Data_Bus_Dir_D7 TRISE7

extern void WriteCommandToLCD(unsigned char);
extern void WriteDataToLCD(char);
extern void InitLCD(void);
extern void WriteStringToLCD(const char*);
extern void ClearLCDScreen(void);
extern void delay(unsigned int);

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


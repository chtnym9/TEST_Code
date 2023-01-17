/*
 * File:   I2C_lib.c
 * Author: chtny
 *
 * Created on 14 January, 2023, 6:21 PM
 */


#include <xc.h>
#include <pic18f67j10.h>
#include"I2C_lib.h"
/**************************** I2C - RTC  **************************************/
//Function Prototype
void i2c_init();
void i2c_start(void);
void i2c_Ack();
void i2c_Nack();
void i2c_restart(void);
void i2c_stop(void);
void i2c_wait(void);
void i2c_send(unsigned char dat);
unsigned char i2c_read(void);

//Function Definition
void i2c_init()
{
	TRISD6 = 1;
	TRISD5 = 1;
	SSP2STAT |= 0x80; //Slew Rate Disabled
	SSP2CON1 = 0x28;			//Master mode
	SSP2ADD = 0x28;
	/*SSPEN = 1
	Enables the Serial Port and configures the SDA and SCL
	Pins as the Serial Pins
	SSPM3:SSPM0 --> 1000
	I2C Master Mode
	Clock = Fosc/4*(SSPADD+1)
	*/
}

void i2c_start(void)
{
	SEN2 = 1;
	//SSPCON2 bit 0
	while (SEN2 == 1);
	//SEN =1 initiate the Start Condition on SDA and SCL Pins
	//Automatically Cleared by Hardwre
	// 0 for Idle State
}

void i2c_restart(void)
{
	RSEN2 = 1;
	//SSPCON2 bit 1
	while (RSEN2 == 1);
	//RSEN = 1 initiate the Restart Condition
	//Automatically Cleared by Hardware
}

void i2c_stop(void)
{
	PEN2=1;
	while(PEN2==1)
		continue;
}

void i2c_wait(void)
{
	while ( ( SSP2CON2 & 0x1F ) || ( SSP2STAT & 0x04 ) );
}

void i2c_send(unsigned char dat)
{
	SSP2BUF = dat;    /* Move data to SSPBUF */
    while(BF2);       /* wait till complete data is sent from buffer */
    i2c_wait();       /* wait for any pending transfer */
}

unsigned char i2c_read(void)
{
	unsigned char temp;
    RCEN2 = 1;        /* Enable data reception */
    while(!BF2);      /* wait for buffer full */
    temp = SSP2BUF;   /* Read serial buffer and store in temp register */
    i2c_wait();       /* wait to check any pending transfer */
    return temp;     /* Return the read data from bus */
}
void i2c_Ack()
{
	SSP2CON2bits.ACKDT2 = 0;	//Acknowledge Data Bit, 0 = Ack
	SSP2CON2bits.ACKEN2 = 1;	//Acknowledge Enable Bit
	while(SSP2CON2bits.ACKEN2);
	//Wait for ack bit to send on bus
}
void i2c_Nack()
{
	SSP2CON2bits.ACKDT2 = 1;
	SSP2CON2bits.ACKDT2 = 1;	//Acknowledge Enable Bit
	while(SSP2CON2bits.ACKEN2);
}

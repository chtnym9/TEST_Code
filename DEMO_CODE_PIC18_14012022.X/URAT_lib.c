/*
 * File:   URAT_lib.c
 * Author: chtny
 *
 * Created on 14 January, 2023, 6:36 PM
 */


#include <xc.h>
#include <pic18f67j10.h>
#include"UART_lib.h"
#define _XTAL_FREQ 10000000
unsigned int rx_overrun_flag =0;
char UART_Init(const long int baudrate);
void UART_Write(unsigned char UART_DATA);
char UART_Read();

char UART_Init(const long int baudrate)
{
  unsigned int x;
  x = (_XTAL_FREQ - baudrate*16)/(baudrate*16); //SPBRG for High Baud Rate
  SPBRG1 = x;                                 //Writing SPBRG Register
  TXSTA1bits.BRGH = 1;                                     //Setting High Baud Rate
  TXSTA1bits.SYNC = 0;                                     //Setting Asynchronous Mode, ie UART
  RCSTA1bits.SPEN = 1;                                     //Enables Serial Port
  TRISC7 = 1;                                   //Receive
  TRISC6 = 0;                                   //Transmit
  CREN = 1;                                     //Enables Continuous Reception
  TXSTA1bits.TXEN = 1;                                     //Enables Transmission
  CLRWDT(); 
  return 1;        
  //Returns 1 to indicate Successful Completion
}

void RS485_Init()
{
   TRISCbits.RC6=0;             //Transmit
   TRISCbits.RC7=1;             //Receive
   TRISCbits.RC2=0;             //Direction control,1:Transmit,0:Receive If required
}

void UART_Write(unsigned char UART_DATA)
{
  while(!TRMT);
  TXREG = UART_DATA;
}

char UART_Read()
{
  while(!RCIF)
  {
      rx_overrun_flag ++;
      return RCREG;
  }
  
}


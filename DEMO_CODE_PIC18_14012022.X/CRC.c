//#include <pic18f87j10.h>
#include "lcd.h"
#include"I2C_lib.h"
#include"UART_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>
#define _XTAL_FREQ 10000000
#define USE_OR_MASKS
    uint16_t firstconst   = 0xFFFF;
    uint16_t mainconst    = 0xA001;
    uint16_t temp;
    uint16_t i = 1;
    uint16_t temp3;
    uint16_t temp4;
    uint16_t RX_CRC;
    
int CRC_Check(uint16_t slave_add, uint16_t funct_code,uint16_t add_hii,uint16_t add_lo, uint16_t point_hi,uint16_t point_lo)
{   
    uint16_t temp1 =  firstconst ^ slave_add ;
    uint16_t temp2 = temp1 & 0x0001 ;

    for(i=0;i<=7;i++)
    {
    if(temp2 == 0)
    {
        temp1 = temp1 >> 1;
    }

    else if(temp2 == 1)
    {
        temp1 = temp1 >> 1;
        temp1 = mainconst ^ temp1;
    }
    temp2 = temp1 & 0x0001;
    }

    temp3 = temp1 ^ funct_code;
    temp2 = temp3 & 0x0001;

    for(i=0;i<=7;i++)
        {
        if(temp2 == 0)
        {
            temp3 = temp3 >> 1;
        }

        else if(temp2 == 1)
        {
            temp3 = temp3 >> 1;
            temp3 = mainconst ^ temp3;
        }
        temp2 = temp3 & 0x0001;
        }

    temp4 = temp3 ^ add_hii;
    temp2 = temp4 & 0x0001;

    for(i=0;i<=7;i++)
         {
         if(temp2 == 0)
         {
             temp4 = temp4 >> 1;
         }

         else if(temp2 == 1)
         {
             temp4 = temp4 >> 1;
             temp4 = mainconst ^ temp4;
         }
         temp2 = temp4 & 0x0001;
         }

    uint16_t temp5 = temp4 ^ add_lo;
             temp2 = temp5 & 0x0001;
             for(i=0;i<=7;i++)
                  {
                  if(temp2 == 0)
                  {
                      temp5 = temp5 >> 1;
                  }

                  else if(temp2 == 1)
                  {
                      temp5 = temp5 >> 1;
                      temp5 = mainconst ^ temp5;
                  }
                  temp2 = temp5 & 0x0001;
                  }


             uint16_t temp6 = temp5 ^ point_hi;
                      temp2 =  temp6 & 0x0001;
                      for(i=0;i<=7;i++)
                      {
                      if(temp2 == 0)
                      {
                          temp6 = temp6 >> 1;
                      }

                      else if(temp2 == 1)
                      {
                          temp6 = temp6 >> 1;
                          temp6 = mainconst ^ temp6;
                      }
                      temp2 = temp6 & 0x0001;
                      }

               uint16_t temp7 =  temp6 ^  point_lo;
                        temp2 =   temp7 & 0x0001;
                        for(i=0;i<=7;i++)
                        {
                        if(temp2 == 0)
                        {
                            temp7 = temp7 >> 1;
                        }


                        else if(temp2 == 1)
                        {
                            temp7 = temp7 >> 1;
                            temp7 = mainconst ^ temp7;
                        }
                        temp2 = temp7 & 0x0001;
                        }
                        
                      uint16_t RX_CRC= ((temp7<<8)&0xff00)|((temp7>>8)&0x00ff);
                      return RX_CRC;                              

}

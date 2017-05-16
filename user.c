/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"





/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{

}

void wait(uint16_t *pt){

     uint16_t ms;
     RA3=1;
     for ( ms = *pt; ms>0; ms--)
     {
     __delay_ms(1);
     if (PORTAbits.RA2 ==1)
  
         break;

     
     }


  RA3=0;
       for ( ms = *pt; ms>0; ms--)
     {
     __delay_ms(1);
     if (PORTAbits.RA2 ==1)


         break;


     }

}
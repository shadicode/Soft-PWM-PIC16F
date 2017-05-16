/******************************************************************************/
/* Main Files to Include                                                      */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif



 #pragma config  FOSC    = HS         // HS oscillator (HS)

#pragma config WDTE      = OFF //

#pragma config PWRTE      = OFF //
#pragma config CP      = OFF //

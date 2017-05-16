//Software PWM implementation on PIC 16F84A microcontroller
//Shadi Soundation, 2016
//http://www.shadi.ch


/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#define initialDelay    500            //initial blinking Delay



#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */


/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

uint8_t db_count; //Debouncing counter
/******************************************************************************/

// set the blinking speed to the initial = once every second
uint16_t blinkDelay = initialDelay;

enum states {
    initialSt,
    blinkSt
};

enum states state = initialSt;

/* Main Program                                                               */

/******************************************************************************/
void main(void) {


    TRISA = 0b0111;
    TRISB = 0b1101;

    // Configure the oscillator for the device 
    ConfigureOscillator();

    // I/O and Peripherals 
    InitApp();
    RA3 = 0;
    RB1 = 1;
    while (1) {

        switch (state) {

            case initialSt:
                if ((PORTAbits.RA0 == 1) && (blinkDelay < 2000)) {
                    blinkDelay += 100;
                    state = blinkSt;
                    break;
                }
                else if ((PORTAbits.RA1 == 1) && (blinkDelay > 100)) {
                    blinkDelay -= 100;
                    state = blinkSt;
                    break;
                }
                else if ((PORTAbits.RA2 == 1) && (blinkDelay != initialDelay)) {
                    blinkDelay = initialDelay;
                    state = blinkSt;
                    break;
                }

                else {
                    break;
                }


            case blinkSt:
                if ((PORTAbits.RA0 == 1) && (blinkDelay < 2000)) {
                    blinkDelay += 100;
                    state = blinkSt;
                    break;
                }
                else if ((PORTAbits.RA1 == 1) && (blinkDelay > 100)) {
                    blinkDelay -= 100;
                    state = blinkSt;
                    break;
                }
                else if (PORTAbits.RA2 == 1) {
                    blinkDelay = initialDelay;
                    state = blinkSt;
                    break;
                }

                else {
                    break;
                }

            default:
                break;
        }



        wait(&blinkDelay);





    }

}



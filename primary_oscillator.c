/*
 * File:   primary_oscillator.c
 * Author: Kevin
 *
 * Created on 28. März 2017, 12:29
 */

// Check for Project Settings
#ifndef __dsPIC33EP512MU810__
    #error "Wrong Controller"
#endif

/* ***********************
 * Includes
 * ***********************
 */


#include <xc.h>         //Include appropriate controller specific headers
#include <stdint.h>     //Standard typedefs


/* ***********************
 * Configuration Bits
 * ***********************
 */

// Select Internal FRC at POR
_FOSCSEL(FNOSC_FRC & IESO_OFF);
// Enable Clock Switching and Configure POSC in XT mode
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);

/* Hardware  */
#define _LED200 LATBbits.LATB8

int main()
{
_LED200=1;
// Configure PLL prescaler, PLL postscaler, PLL divisor
PLLFBD=46; // M=48 //455
CLKDIVbits.PLLPOST=0; // N2=2 //2
CLKDIVbits.PLLPRE=0; // N1=2 //2
// Initiate Clock Switch to Primary Oscillator with PLL (NOSC=0b011)
__builtin_write_OSCCONH(0x03);
__builtin_write_OSCCONL(OSCCON | 0x01);
// Wait for Clock switch to occur
while (OSCCONbits.COSC!= 0b011);
// Wait for PLL to lock
while (OSCCONbits.LOCK!= 1);


while(1)
{
    _LED200=!_LED200;
}

}
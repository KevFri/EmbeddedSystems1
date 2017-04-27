/* 
 * File:   edaPIC33Oscillator.h
 * Author: Kevin
 *
 * Created on 26. April 2017, 18:15
 */

#ifndef EDAPIC33OSCILLATOR_H
#define	EDAPIC33OSCILLATOR_H

#include<xc.h>
#include<stdint.h>

// Select Internal FRC at POR
_FOSCSEL(FNOSC_FRC & IESO_OFF);
// Enable Clock Switching and Configure Primary Oscillator in XT mode
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE);



void configOscillator()
{   //configuration for 120MHz:
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD=63; // M=65
    CLKDIVbits.PLLPOST=0; // N2=2
    CLKDIVbits.PLLPRE=1; // N1=3
    
    // Initiate Clock Switch to FRC oscillator with PLL (NOSC=0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(OSCCON | 0x01);
    
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC!= 0b001);
    // Wait for PLL to lock
    while (OSCCONbits.LOCK!= 1);
}

#endif
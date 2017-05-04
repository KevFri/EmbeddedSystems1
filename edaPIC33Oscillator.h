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

//select external oscillator with 8mhz
_FOSCSEL(FNOSC_PRIPLL & IESO_OFF); //Initial Oscillator: Primary Oscillator (XT, HS, EC) with PLL
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);  //HS Crystal Oscillator Mode


/** 
 * @brief config Oscillator with extern 8Mhz Crystal to Fosc=140Mhz
 * @attention Function has to be called at first in main 
 */
void configOscillator()
{
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD=68; // M=48
    CLKDIVbits.PLLPOST=0; // N2=2
    CLKDIVbits.PLLPRE=0; // N1=2
    
    // Initiate Clock Switch to Primary Oscillator with PLL (NOSC=0b011)
    __builtin_write_OSCCONH(0x03);
    __builtin_write_OSCCONL(OSCCON | 0x01);
 
    while (OSCCONbits.COSC!= 0b011);    // Wait for Clock switch to occur
    while (OSCCONbits.LOCK!= 1);        // Wait for PLL to lock
}




/* configuration for internal Oscillator
 // Select Internal FRC at POR
_FOSCSEL(FNOSC_FRC & IESO_OFF);
// Enable Clock Switching and Configure Primary Oscillator in XT mode
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE);



void configOscillator()
{   //configuration for 120MHz:
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD=74; // 120Mhz:63 / 140Mhz:74
    CLKDIVbits.PLLPOST=0; // N2=2
    CLKDIVbits.PLLPRE=0; // N1=2
    
    // Initiate Clock Switch to FRC oscillator with PLL (NOSC=0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(OSCCON | 0x01);
    
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC!= 0b001);
    // Wait for PLL to lock
    while (OSCCONbits.LOCK!= 1);
}
 */

#endif
/** 
 * @file   MainLCD.c
 * @author Kevin Fritz
 *
 * @date 26.04.2075, 18:14
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
#include <stdio.h>      //Standard IO Library
#include "edaPIC33Hardware.h"  //edaPIC33 Hardware Library
#include "edaPIC33SystemTime.h"
#include "edaPIC33Oscillator.h"
#include "edaPIC33LCD.h"        //edaPIC33 LCD Library
#include "edaPIC33OtherStuff.h" //other Functions
#include "edaPIC33Setup.h"


/* ***********************
 * Configuration Bits
 * ***********************
 */

/* ***********************
 * Defines
 * ***********************
 */

/* Substitute for stdlib.h */
#define	EXIT_SUCCESS	0
#define	EXIT_FAILURE	1


/* ***********************
 * Prototypes
 * ***********************
 */

/* ***********************
 * Definitions
 * ***********************
 */


/* ***********************
 * Main
 * ***********************
 */
//_FWDT(FWDTEN_OFF); set watchdog (enable) off

/**
 * Main Function
 */
int main() {
    
    //config oscillator PLL with external 8Mhz crystal
    configOscillator();

    //setup pinMode for switches, led, LCD, rotatory encode,...
    setupEdaPIC33Board();
    
    //config timer 1 for getSystemTimeMillis();)
    configSystemTimeMillis();
    uint32_t ui32Time= getSystemTimeMillis(); //Variable used for time calculation
  
    char str[16];
    
    /* Endless Loop */
    while(1){

        LATBbits.LATB9=1; //set LED to 1, to measure work time


        int16_t value;
        
        LATBbits.LATB8=1;
        value = analogRead(AN0);
        LATBbits.LATB8=0;
        sprintf(str,"%d",value );
        setLCDLine(str,1);
        
        LATBbits.LATB10=1;
        value = analogRead(AN1);
        LATBbits.LATB10=0;
        sprintf(str,"%d",value );
        setLCDLine(str,2);
        
        
        sendDataToLCD(); //send one character from LCD-Storage (Shadow-String) to LCD
        ui32Time++; //increase ms counter
        LATBbits.LATB9=0; //set LED to 0, to measure work time
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            ClrWdt();   //clear watchdog timer
        }          
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()
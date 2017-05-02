/** 
 * @file   MainVorlage.c
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
#include "edaPIC33Hardware.h"
#include "edaPIC33SystemTime.h"
#include "edaPIC33Oscillator.h"
#include "edaPIC33BlinkLed.h"

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


/**
 * Main Function
 */
int main() {

    configOscillator();
    
    
    pinMode(LED0,OUTPUT);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    
    pinMode(SW0, INPUT_PULLUP);
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW3, INPUT_PULLUP);
    
    configSystemTimeMillis();
    
    
    /* Endless Loop */
    while(1){
        static uint32_t ui32Time= 0;

        blinkLed0(measureToggleTimeSW0());
        blinkLed1(measureToggleTimeSW1());
        blinkLed2(measureToggleTimeSW2());
        blinkLed3(measureToggleTimeSW3());
        
        
        ui32Time++;
        while(getSystemTimeMillis() < ui32Time);
    }//while
    
    return (EXIT_SUCCESS);  //never reached
} //main()



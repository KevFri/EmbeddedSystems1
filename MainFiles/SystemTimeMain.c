/** 
 * @file   HelloWorld2.c
 * @author JS
 *
 * @date 26.08.2015, 12:43
 * 
 * @brief Getting started with a simple program (blinking LED)
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

/* ***********************
 * Configuration Bits
 * ***********************
 */

/*
 * Oscillator Configuration
 *  (XC16 Compiler User's Guide, P. 109,
 *  33EP512MU810.html, p33EP512MU810.h, )
 * Alternative: #pragma directives
 */
_FOSCSEL(FNOSC_PRIPLL); //Initial Oscillator: Primary Oscillator (XT, HS, EC) with PLL
_FOSC(POSCMD_HS);  //HS Crystal Oscillator Mode


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
 * Hello World (Blinking LED)
 * @brief Toggles LED200 with 1 Hz, 1:1 duty cycle
 */
int main() {

    /*Oscillator Configurations*/
    PLLFBD = 455;
    CLKDIVbits.PLLPOST = 2;
    CLKDIVbits.PLLPRE = 2;
    /*
    PLLFBD = 58;
    CLKDIVbits.PLLPOST = 0;
    CLKDIVbits.PLLPRE = 0;
    */
    
    /* Endless Loop */
    pinMode(LED0,OUTPUT);
    pinMode(LED1,OUTPUT);
    configSystemTimeMillis();
    configSystemTimeSeconds();

    int a=0;
    while(1){
        a++;
       
    }//while
    
    return (EXIT_SUCCESS);  //never reached
} //main()



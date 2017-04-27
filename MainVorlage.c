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
    configSystemTimeMillis();

    /* Endless Loop */
    while(1){

        
    }//while
    
    return (EXIT_SUCCESS);  //never reached
} //main()



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

void delay_ms(uint16_t u16milliseconds);

/* ***********************
 * Definitions
 * ***********************
 */

/** 
 * @brief Provides u16milliseconds delay
 * @param u16milliseconds Delay in milliseconds
 * @details u16milliseconds=0 causes 65536 ms delay
 * @pre 7.37 MHz (Internal Fast RC), e. g.: <br>
 * _FOSCSEL(FNOSC_FRC); //Initial Oscillator:  Internal Fast RC <br>
 * _FOSC(POSCMD_NONE);  //Primary Oscillator disabled (quartz not used) <br>
 * s. 7.37 MHz DS70216C-page 39-19 <br>
 * @attention Code has to be changed if a different oscillator frequency is used.
 */
void delay_ms(uint16_t u16milliseconds){
    uint16_t ui16_i=0;
    while(u16milliseconds){
        for (ui16_i=0;ui16_i<331;ui16_i++){    //1 ms delay loop
            __asm__ volatile("nop \n\t"
                             "nop \n\t"
                             "nop \n\t");
        }//for
        u16milliseconds--;
    }//while

}
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
    
    
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    pinMode(SW0, INPUT_PULLUP);
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW3, INPUT_PULLUP);

    /* Endless Loop */
    while(1){

    digitalWrite(LED0, HIGH); //546ns
    digitalWrite(LED0, LOW);  
    
    //LATBbits.LATB8 = HIGH;  //28,4ns
    //LATBbits.LATB8 = LOW;
            
        
    //digitalWrite(LED0, LOW);    //602ns
    //digitalWrite(LED0, HIGH);  
    //LATBbits.LATB8 = LOW;  //85,6ns
    //LATBbits.LATB8 = HIGH;
    
    
    }//while
    
    return (EXIT_SUCCESS);  //never reached
} //main()


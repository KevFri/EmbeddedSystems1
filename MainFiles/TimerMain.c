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
#include "edaPIC33Timer.h"

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
    T1CONbits.TON = 0; // Disable Timer
    //set the multiplexer to timer mode
    T1CONbits.TCS = 0; // Select internal instruction cycle clock
    T1CONbits.TGATE = 0; // Disable Gated Timer mode
    //set prescaler
    T1CONbits.TCKPS = 0b10; // Select 1:8 Prescaler
    
    TMR1 = 0x00; // Clear timer register
    PR1 = 0xFFFF; // Load the period value
    
    //disable interrupt
    IPC0bits.T1IP = 0x00; // Set Timer 1 Interrupt Priority Level
    IFS0bits.T1IF = 0; // Clear Timer 1 Interrupt Flag
    IEC0bits.T1IE = 0; // Enable Timer1 interrupt
    
    T1CONbits.TON = 1; // Start Timer
    
    pinMode(LED0,OUTPUT);
    
    int16_t t0 = (int16_t)TMR1;
    int16_t t1;
    int16_t dt=0;
    */
    //int16_t t1;
     

    /* Endless Loop */
    pinMode(LED0,OUTPUT);
    configTimer1PWM_1kHz(LED0, 140000000, 50);

    while(1){  
        onCycleTimer1PWM_1kHz();
    }//while
    
    return (EXIT_SUCCESS);  //never reached
} //main()


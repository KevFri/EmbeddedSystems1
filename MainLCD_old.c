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
#include "edaPIC33Hardware.h"
#include "edaPIC33SystemTime.h"
#include "edaPIC33Oscillator.h"
#include "edaPIC33LCD.h"
#include "edaPIC33OtherStuff.h"


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
    
    configOscillator();
   
    //set LED pinmodes
    pinMode(LED0,OUTPUT);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    
    //set LEDs to low (default value)
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    
    //set switch pinmodes
    pinMode(SW0, INPUT_PULLUP);
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW3, INPUT_PULLUP);
    
    //initial LCD Display, clear LCD and set cursor home
    initMyLCD();
    home_clr();
    
    //config timer 1 for getSystemTimeMillis();)
    configSystemTimeMillis();
    
   //print start text to LCD Display
   //putsLCD("Hallo");
   //line_2();
   //putsLCD("zweite Zeile");
    
    
    uint32_t ui32Time= 0; //Variable used for time calculation
    /* Endless Loop */
    while(1){
        LATBbits.LATB9=0; //set LED to 0, to measure work time
        //static uint8_t ui8StateSWO;
        
        //home_clr();
        writeDataLCD(0xF7);
        LATBbits.LATB8=1; //toggle LED0 to measure working time of loop
        while(readBusyFlagAndAddressLCD());      
        LATBbits.LATB8=0; //toggle LED0 to measure working time of loop
        ui32Time++; //increase ms counter
        LATBbits.LATB9=1; //set LED to 1, to measure work time
        
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            ClrWdt();   //clear watchdog timer
        }
            
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()

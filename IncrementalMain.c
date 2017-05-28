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
    
    //set switch pinmodes
    pinMode(SW0, INPUT_PULLUP);
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW3, INPUT_PULLUP);
    
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
    
    //set Pin Modes for Incremental
    pinMode(INCA, INPUT_PULLUP);
    pinMode(INCB, INPUT_PULLUP);
    pinMode(INCSW, INPUT_PULLUP);
    //call rotatoryEncode function two times to initalize state
    rotatoryEncode();
    rotatoryEncode();
    int8_t i16Rotate=0;
    
    //set Pin Mode for PIEZO
    pinMode(PIEZO,OUTPUT);
    digitalWrite(PIEZO, LOW);
     
    //initial LCD Display, clear LCD and set cursor home, clear Shadow String
    initMyLCD();
    home_clr();
    clearShadowString();
    //setLCDLine1("EmbeddedSystems1");
    char str[16]; //string used for sprintf functions
            
    //config timer 1 for getSystemTimeMillis();)
    configSystemTimeMillis();
    uint32_t ui32Time= getSystemTimeMillis(); //Variable used for time calculation
    
    /* Endless Loop */
    while(1){
        //LATBbits.LATB9=1; //set LED to 1, to measure work time

        //sprintf( str, "Runtime %2lu:%2lu", ui32Time/60000,(ui32Time/1000)%60 );
        //sprintf( str, "Pi %.6f", 3.141 );
        digitalWrite(LED0, digitalRead(INCSW));
        digitalWrite(LED2, digitalRead(INCB));
        digitalWrite(LED3, digitalRead(INCA));
        
        
        i16Rotate += rotatoryEncode();
        sprintf(str, "Rotations: %d", i16Rotate);
        setLCDLine2(str);
        
       //SoftwarePwm(PIEZO,25, (int8_t)(i16Rotate) );
       
        if( i16Rotate==10 )
            digitalWrite(PIEZO, ui32Time%2);
              
        writeShadowStringToLCD();
        ui32Time++; //increase ms counter
        //LATBbits.LATB9=0; //set LED to 0, to measure work time
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            ClrWdt();   //clear watchdog timer
        }          
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()

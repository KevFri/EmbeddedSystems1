/** 
 * @file   PWM_Main.c
 * @author Kevin Fritz
 *
 * @date 26.04.2017, 18:14
 */



// Check for Project Settings
#ifndef __dsPIC33EP512MU810__
    #error "Wrong Controller"
#endif

/* ***********************
 * Includes
 * ***********************
 */

#include <xc.h>                 //Include appropriate controller specific headers
#include <stdint.h>             //Standard typedefs
#include <stdio.h>              //Standard IO Library
#include "edaPIC33Hardware.h"   //edaPIC33 Hardware Library
#include "edaPIC33SystemTime.h" //edaPIC33 System Time Library, verwendet Timer1!
#include "edaPIC33Oscillator.h" //Oscillator Library, konfiguriert Oscillator
#include "edaPIC33LCD.h"        //edaPIC33 LCD Library
#include "edaPIC33OtherStuff.h" //other Functions
#include "edaPIC33Setup.h"      //setup library for EDAPIC33 Board
#include "edaPIC33OutputCompare.h"
#include "edaPIC33ADC.h"


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
/*String used in edaPIC33LCD Library*/
extern char DataString[32];
char str[16];

/* ***********************
 * Main
 * ***********************
 */
//_FWDT(FWDTEN_OFF); set watchdog (enable) off

/**
 * Main Function
 */

int main() {
    
    //config oscillator PLL with external 8Mhz crystal to F_OSC = 140MHz
    configOscillator();

    //setup pinMode for switches, led, LCD, rotatory encode,...
    setupEdaPIC33Board();
    
    //config timer 1 for getSystemTimeMillis();)
    configSystemTimeMillis();
    uint32_t ui32Time= getSystemTimeMillis(); //Variable used for time calculation
    
    uint16_t ui16Rotary = 512;
    /* Endless Loop */
    while(1){
        uint16_t ANin = (uint16_t) analogRead(AN0);
        ui16Rotary += rotaryEncode();
        
        sprintf(str,"AN0:%u INC:%u", ANin, ui16Rotary);
        setLCDLine(str,1);
        
        sawtoothGeneratorTimeBase(OC1_Pin, ANin);
        sinusGeneratorTimeBase(OC2_Pin, ANin);
        
        stopWatch(&DataString[16], !isPressed2(INCSW,0));         
        FlipFlopLED0(isPressed2(SW0,1));
        Treppenlichtautomat(isPressed2(SW1,2),LED2,2000,4000);
        digitalToggle(LED3);
        
        
        sendDataToLCD(); //send one character from LCD-Storage (Shadow-String) to LCD
        ui32Time++; //increase ms counter
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            ClrWdt();   //clear watchdog timer
        }          
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()
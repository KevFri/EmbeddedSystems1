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
#include "edaPIC33UART1.h"


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

//#define CTS _RF12
//#define RTS _RF13
#define TRTS TRISFbits.TRISF13


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
char szRX[32] = "\0";
char szTX[32] = "\0";

extern char psUart1ReadBuffer[256];

/* ***********************
 * Main
 * ***********************
 */
/**
 * Main Function
 */
int main() {
    
    //config oscillator PLL with external 8Mhz crystal to F_OSC = 140MHz
    configOscillator();

    InitUART1();
    //char c;
    
    //setup pinMode for switches, led, LCD, rotatory encode,...
    setupEdaPIC33Board();
    
    
    
    //config timer 1 for getSystemTimeMillis();)
    configSystemTimeMillis();
    uint32_t ui32Time= getSystemTimeMillis(); //Variable used for time calculation
    
    
    putsU1("DSP Reset");
    clearUart1ReadBuffer();
    //getU1();
    
    /* Endless Loop */
    while(1){
        
               
        //getsnU1( szRX, 32);
        uint8_t i;
        for(i=0; i<16;i++)
        {
            str[i] = psUart1ReadBuffer[i] != '\0' ? psUart1ReadBuffer[i] : '$' ;
        }
        
        setLCDLine(str,1);
        
        sprintf(str, "Millis: %lu",ui32Time);
        setLCDLine(str,2);
        //putsU1(szTX);
        
        if(getUart1ReadBufferCounter() >= 17)
            clearUart1ReadBuffer();
             
        sendDataToLCD(); //send one character from LCD-Storage (Shadow-String) to LCD
        ui32Time++; //increase ms counter
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            //sendDataToLCD();
            ClrWdt();   //clear watchdog timer
        }
        
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()

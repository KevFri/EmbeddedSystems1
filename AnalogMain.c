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
/*
char* createFortschrittsbalken(char *pStr, int16_t i16Value);
uint8_t createHystere(int16_t  i16InputValue);
uint8_t createComparator(int16_t  i16InputValue);
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
    extern char DataString[32];
    
    
    /* Endless Loop */
    while(1){

        int16_t i16value;
        i16value = analogRead(AN0);
        createFortschrittsbalken(&DataString[0], i16value);
       
        i16value = analogRead(AN1);
        sprintf(str, "%d",i16value);
        setLCDLine(str,1);
        createFortschrittsbalken(&DataString[16], i16value);
        digitalWrite(LED3,createHystere(i16value));
        digitalWrite(LED2,createComparator(i16value));
        
        sendDataToLCD(); //send one character from LCD-Storage (Shadow-String) to LCD
        ui32Time++; //increase ms counter
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            ClrWdt();   //clear watchdog timer
        }          
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()

/*
char* createFortschrittsbalken(char *pStr, int16_t i16Value)
{
        uint8_t i; 
        for(i=0; i<(i16Value/64);i++)
            pStr[i] = 0xFF; 
        pStr[i++] = (uint8_t)(i16Value%64)/12;
        for(; i<16;i++)
            pStr[i] = ' '; 
        return pStr;
}

#define HYSTERESE_ON 524
#define HYSTERESE_OFF 500
#define STATE_ON 1
#define STATE_OFF 0
uint8_t createHystere(int16_t  i16InputValue)
{
    static uint8_t ui8State = STATE_OFF;
    
    if(ui8State == STATE_OFF)
    {
        if(i16InputValue >= HYSTERESE_ON)
        {
            ui8State = STATE_ON;
            return STATE_ON;
        }
        else
        {
            return STATE_OFF;
        }
        
    }
   else //(ui8State == STATE_ON)
   {
        if(i16InputValue <= HYSTERESE_OFF)
        {
            ui8State = STATE_OFF;
            return STATE_OFF;
        }
        else
        {
            return STATE_ON;
        }
   }
   return STATE_OFF;
}

#define COMPARATOR_THRESHOLD 512
uint8_t createComparator(int16_t  i16InputValue)
{
    if(i16InputValue>=COMPARATOR_THRESHOLD)
        return 1;
    else
        return 0;
}
*/
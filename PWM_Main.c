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


/* ***********************
 * Definitions
 * ***********************
 */
extern char DataString[32];  

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
    uint16_t var=0;
    float curAvg=0;
    uint32_t n=1;
    /* Endless Loop */
    while(1){
        
        if(!digitalRead(INCSW) == 1)
        {
            n=1;
            curAvg=0;
        }  
        else
            var=(uint16_t)( (int32_t)var +  (64*(int32_t)rotaryEncode()));
        
        if(n<=10000)
        {
            //calculate Mean Value
            curAvg = curAvg + ((float)analogRead(AN0) - curAvg)/(float)n;
            n++;
        }

        
        sprintf(str,"Out:%4u",var);
        setLCDLine(str,1);   
               
        setPwmDutyCycle(RC3, var);

        //createFortschrittsbalken2(&DataString[16], ui32Time, 0xFFFF);
        
        setOutputCompareValues(OC1_Pin, 2048, 2*var);
        
        sprintf(str,"In:%3.4f",curAvg);
        setLCDLine(str,2);  
        //OC1RS =  var;
        //OC1R =   OC1RS/3;  
        sendDataToLCD(); //send one character from LCD-Storage (Shadow-String) to LCD
        ui32Time++; //increase ms counter
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            ClrWdt();   //clear watchdog timer
        }          
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()



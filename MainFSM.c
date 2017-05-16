/** 
 * @file   MainFSM.c
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
//#include "edaPIC33FiniteStateMachine.h"

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
void FlipFlopLED0(uint8_t ui8SwitchState);
void digitalCountLED0to3(uint8_t ui8SwitchState);
void Treppenlichtautomat(uint8_t ui8SwitchState, uint8_t ui8LedPin, const uint32_t cui32OnTime, const uint32_t cui32TurnOffTime);
void SoftwarePwm(uint8_t ui8Pin, const uint8_t cui8PeriodTime, uint8_t ui8DutyCycle);
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
    
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    
    //set switch pinmodes
    pinMode(SW0, INPUT_PULLUP);
    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW3, INPUT_PULLUP);
    
    //config timer 1 for getSystemTimeMillis();)
    configSystemTimeMillis();
    
    
    /* Endless Loop */
    while(1){
        static uint32_t ui32Time= 0;
        //static uint8_t ui8StateSWO;
        //LATBbits.LATB8=1; //toggle LED0 to measure working time of loop
        
        //ui8StateSWO=isPressedSW0();
        
        //FlipFlopLED0(isPressedSW0());
        //digitalCountLED0to3(isPressedSW0());
        
        //SoftwarePwm(LED1, 40);
        Treppenlichtautomat( isPressedSW0(), LED1, 3000, 5000);
        
        ui32Time++; //increase ms counter
        //LATBbits.LATB8=0; //toggle LED0 to measure working time of loop
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            ClrWdt();   //clear watchdog timer
        }
            
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()


void FlipFlopLED0(uint8_t ui8SwitchState)
{
    static uint8_t ui8OldSwitchState = HIGH;
    
    if(ui8OldSwitchState == HIGH && ui8SwitchState == LOW) //Flanke von HIGH auf LOW
    {
        digitalToggle(LED0);
    }
    ui8OldSwitchState=ui8SwitchState;
    
}

void digitalCountLED0to3(uint8_t ui8SwitchState)
{
    static uint8_t ui8OldSwitchState = HIGH;
    static uint8_t ui8CountValue=0;
    
    if(ui8OldSwitchState == HIGH && ui8SwitchState == LOW) //Flanke von HIGH auf LOW
    {
        ui8CountValue++;
        digitalWrite(LED0, ui8CountValue&0x01);
        digitalWrite(LED1, ui8CountValue&0x02); 
        digitalWrite(LED2, ui8CountValue&0x04);
        digitalWrite(LED3, ui8CountValue&0x08);
    }
    ui8OldSwitchState=ui8SwitchState;
}


#define STATE_LIGHT_ON 0
#define STATE_LIGHT_OFF 1
#define STATE_LIGTH_TURNOFF 2

void Treppenlichtautomat(uint8_t ui8SwitchState, uint8_t ui8LedPin, const uint32_t cui32OnTime, const uint32_t cui32TurnOffTime)
{
    static uint8_t ui8OldSwitchState = HIGH;
    static uint32_t ui32CountValue=0;
    static uint8_t ui8State = STATE_LIGHT_OFF;
    
    if(ui8OldSwitchState == HIGH && ui8SwitchState == LOW) //Flanke von HIGH auf LOW
    {
        //nachtriggern
        ui32CountValue=0;
        digitalWrite(ui8LedPin, HIGH);
        ui8State=STATE_LIGHT_ON;
    }
    else
    {
        switch(ui8State)
        {
            case STATE_LIGHT_ON:
                ui32CountValue++;
                if(ui32CountValue >= cui32OnTime)
                {
                    ui32CountValue=0;
                    ui8State=STATE_LIGTH_TURNOFF;
                }
                break;
            case STATE_LIGTH_TURNOFF:
                ui32CountValue++;
                uint8_t ui8DutyCycle = (uint8_t)((ui32CountValue*100)/(cui32TurnOffTime));
                SoftwarePwm(ui8LedPin,25, 100-ui8DutyCycle);
                
                if(ui32CountValue>=cui32TurnOffTime)
                {
                    ui32CountValue=0;
                    digitalWrite(ui8LedPin, LOW);
                    ui8State=STATE_LIGHT_OFF;
                }
                break;
            case STATE_LIGHT_OFF:
                //do nothing wait for state change with falling edge
                break;
            default:
                //do nothing
                break;                
        }
    } 
    ui8OldSwitchState=ui8SwitchState;
}

void SoftwarePwm(uint8_t ui8Pin, const uint8_t cui8PeriodTime, uint8_t ui8DutyCycle)
{
    static uint8_t ui8Count=0;
    uint8_t ui8OutputState=digitalRead(ui8Pin);
    uint8_t ui8OnTime  = (uint8_t)((((uint16_t)cui8PeriodTime)*((uint16_t) ui8DutyCycle)/100));
    uint8_t ui8OffTime = cui8PeriodTime-ui8OnTime;
    ui8Count++;
    if(ui8OutputState == HIGH)
    {  
        if(ui8Count >= ui8OnTime)
        {
            digitalWrite(ui8Pin, LOW);
            ui8Count=0;
        }
    }
    else //ui8OutputState == LOW
    {
        if(ui8Count >= ui8OffTime)
        {
            digitalWrite(ui8Pin, HIGH);
            ui8Count=0;
        }        
    }    
}
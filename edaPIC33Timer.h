
/* 
 * File: edaPIC33Timer.h  
 * Author: Kevin Fritz
 * Comments:
 * Revision history: 
 */

// Check for Project Settings
#ifndef __dsPIC33EP512MU810__
    #error "Wrong Controller"
#endif

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef edaPIC33Timer_H
#define	edaPIC33Timer_H
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>


//declarations
#define TIMER1 TIMER1
#define TIMER2 TIMER2
#define TIMER3 TIMER3
#define TIMER4 TIMER4
#define TIMER5 TIMER5
#define TIMER6 TIMER6
#define TIMER7 TIMER7
#define TIMER8 TIMER8
#define TIMER9 TIMER9


//TODO Doxygen Documentation
uint8_t configTimer1PWM(const uint8_t ui8PWMPort, uint32_t ui32FOSC, uint32_t ui32PWMFrequenzy, uint8_t ui8DutyCycle);

//TODO Doxygen Documentation
void onCycleTimer1PWM();

//TODO Doxygen Documentation
void configTimer1PWM_1kHz(const uint8_t ui8PWMPort, uint32_t ui32FOSC, uint8_t ui8DutyCycle);

//TODO Doxygen Documentation
void onCycleTimer1PWM_1kHz();
void setTimer1PWM_DutyCycleParam(uint32_t ui32FOSC, uint8_t ui8DutyCycle);





#endif	/* edaPIC33Timer_H */


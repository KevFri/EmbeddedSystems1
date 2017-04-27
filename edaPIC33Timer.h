
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


#ifndef edaPIC33Timer_H
#define	edaPIC33Timer_H
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

//* Timer declarations
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5
#define TIMER6 6
#define TIMER7 7
#define TIMER8 8
#define TIMER9 9

/** 
 * @brief Configures the 16 Bit Timer
 * @param uint8_t ui8Timer: choose Timer (TIMER1 - TIMER9)
 * @param uint8_t ui8TSIDL: Timer Stop in Idle Mode bit 0:=continue, 1:=discoutinue (stops) in idle mode
 * @param uint8_t ui8TGATE: Gated Time Accumulation Enable bit.,0:=gated time accumulation disabled, 1:=enabled, ignored when ui8TCS=1 
 * @param uint8_t ui8TCKPS: Timer input clock prescaler 00:=1, 01:=8, 10:=64, 11:=256
 * @param uint8_t ui8TSYNC: External Clock Input Synchronization Select bit,0:=do not synchronize, 1:= synchronizes external clock input, ignored for TCS=0
 * @param uint8_t ui8TCS:   Clock Source Select bit. 0:=InternalClock Fp=Fco/2, 1:=external clock from clock pin(rising edge))
 * @param uint8_t ui8IE:    Interrupt Enable, 0:=dissable interruts, 1:=enable interrupts
 * @param uint8_t ui8IP:    Interrupt Priority 0b000....0b111
 * @details after calling this function the functions setPeriodRegister16BitTimer and start16BitTimer has to be called
 * @details TMRx 16Bit Count Register is set to zero(start value)
 * @details PRx 16Bit Period Register is set to 0xFFFF (free-running timer), can be changed with function setPeriodRegister16BitTimer(
 * @attention Timer has to be started with start16BitTimer
 * @attention !!use int16_t typecasts when programming with free running timers!!
 */
void config16BitTimer(uint8_t ui8Timer, uint8_t ui8TSIDL, uint8_t ui8TGATE, uint8_t ui8TCKPS, uint8_t ui8TSYNC, uint8_t ui8TCS, uint8_t ui8IE, uint8_t ui8IP);

/** 
 * @brief set timer period value
 * @param uint8_t ui8Timer: choose preconfigured Timer (TIMER1 - TIMER9)
 * @param uint16_t ui16PeriodValue
 * @attention set timer period value (default: 0xFFFF)
 * @attention if you want to use interrupts when timer has reached the value you have to enable them and programm then
 */
void setPeriodRegister16BitTimer(uint8_t ui8Timer, uint16_t ui16PeriodValue);

/** 
 * @brief enable interrupt for 16bit timer
 * @param uint8_t ui8Timer: choose preconfigured Timer (TIMER1 - TIMER9)
 * @attention interrupt flag has to be cleared
 */
void enableInterrupt16BitTimer(uint8_t ui8Timer);

/** 
 * @brief disnable interrupt for 16bit timer
 * @param uint8_t ui8Timer: choose preconfigured Timer (TIMER1 - TIMER9)
 * @attention interrupt flag has to be cleared
 */
void disableInterrupt16BitTimer(uint8_t ui8Timer);

/** 
 * @brief clear timer interrupt flag
 * @param uint8_t ui8Timer: choose preconfigured Timer (TIMER1 - TIMER9)
 * @attention
 */
void clearInterruptFlag16BitTimer(uint8_t ui8Timer);

/** 
 * @brief starts the 16 Bit Timer
 * @param uint8_t ui8Timer: choose preconfigured Timer (TIMER1 - TIMER9)
 * @attention set timer period value first, bevor calling this function
 */
void start16BitTimer(uint8_t ui8Timer);

/** 
 * @brief stops the 16 Bit Timer
 * @param uint8_t ui8Timer: choose preconfigured Timer (TIMER1 - TIMER9)
 */
void stop16BitTimer(uint8_t ui8Timer);




//* TODO Doxygen Documentation
//* do not use this function
uint8_t configTimer1PWM(const uint8_t ui8PWMPort, uint32_t ui32FOSC, uint32_t ui32PWMFrequenzy, uint8_t ui8DutyCycle);

/** 
 * @brief onCycle Function to generate PWM Signal with DutyCycle
 * @attention before calling this function call configTimer1PWM_1kHz func.
 * @attention do not use this function
 */
void onCycleTimer1PWM();

//* TODO Doxygen Documentation
//* do not use this function
void configTimer1PWM_1kHz(const uint8_t ui8PWMPort, uint32_t ui32FOSC, uint8_t ui8DutyCycle);

//* TODO Doxygen Documentation
//* !!do not use this function!!
void onCycleTimer1PWM_1kHz();

/** 
 * @brief calculates new DutyCayle Parameter to generate PWM Signal
 * @attention before calling this function call configTimer1PWM_1kHz func.
 * @attention !!do not use this function!!
 */
void setTimer1PWM_DutyCycleParam(uint32_t ui32FOSC, uint8_t ui8DutyCycle);



#endif	/* edaPIC33Timer_H */


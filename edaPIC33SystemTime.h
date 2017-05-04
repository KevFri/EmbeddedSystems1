/* 
 * File:   edaPIC33SystemTime.h
 * Author: Kevin
 *
 * Created on 25. April 2017, 10:37
 */
#include <xc.h>         //Include appropriate controller specific headers
#include <stdint.h>

#ifndef EDAPIC33SYSTEMTIME_H
#define	EDAPIC33SYSTEMTIME_H


/**
 * @brief System Time Millis
 * @return uint32_t ui32Millis milli Seconds since last reset
 * @details Function returns ms since the last reset
 * @attention   pinMode is not implemented for all pins (right now)
 */  
uint32_t getSystemTimeMillis();

/** 
 * @brief Configures the Timer 1 to interrupts each ms
 * @details PR1 can be calculated: Fco/(2*Prescaler*1000)-1 for Interrupts each ms
 * @param uint8_t ui8Port   Number of the Port to configure.
 */
void configSystemTimeMillis();

/** 
 * @brief Timer1 ISR Interrupt Service Routine
 * @details This Interrupt is executed each ms, when timer1 is well configured
 * @attention Interrupt enable Flag IEC0bits.T1IE has set to 1 to enable Interrupts.
 */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void);

/** 
 * @brief clear System Time Millis
 * @details functions clears the system time ms counter (set to zero)
 * @attention functions can change the timing
 */   
void clearSystemTimeMillis();

/* not well developed
uint32_t getSystemTimeSeconds();

void configSystemTimeSeconds();

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void);
*/
#endif	/* EDAPIC33SYSTEMTIME_H */


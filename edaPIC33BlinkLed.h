/* 
 * File:   edaPIC33BlinkLed.h
 * Author: Kevin
 *
 * Created on 2. Mai 2017, 10:40
 */

#ifndef EDAPIC33BLINKLED_H
#define	EDAPIC33BLINKLED_H

#include "edaPIC33Hardware.h"
#include "edaPIC33SystemTime.h"


#ifdef	__cplusplus
extern "C" {
#endif

//my code goes here
    
void blinkLed0(uint16_t ui16ToggleTime);
void blinkLed1(uint16_t ui16ToggleTime);
void blinkLed2(uint16_t ui16ToggleTime);
void blinkLed3(uint16_t ui16ToggleTime);

uint16_t measureToggleTimeSW0();
uint16_t measureToggleTimeSW1();
uint16_t measureToggleTimeSW2();
uint16_t measureToggleTimeSW3();

//end of my code
#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33BLINKLED_H */


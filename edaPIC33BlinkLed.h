/* 
 * File:   edaPIC33BlinkLed.h
 * Author: Kevin Fritz
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

/** 
 * @brief Toggle LED0 (RB_8) with toggle Time
 * @param uint16_t ui16ToggleTime Toggle Time in Functions Calls
 * @details Toggles RB_8 with the number of functions calls.
 * @details Example: If Toggle Time is 20, you have to call the function 20 times to toggle RB_8
 * @attention toggle pin has to be defined as digital output first
 */
void blinkLed0(uint16_t ui16ToggleTime);

/** 
 * @brief Toggle LED1 (RB_9) with toggle Time
 * @param uint16_t ui16ToggleTime Toggle Time in Functions Calls
 * @details Toggles RB_9 with the number of functions calls.
 * @details Example: If Toggle Time is 20, you have to call the function 20 times to toggle RB_9
 * @attention toggle pin has to be defined as digital output first
 */
void blinkLed1(uint16_t ui16ToggleTime);

/** 
 * @brief Toggle LED2 (RB_10) with toggle Time
 * @param uint16_t ui16ToggleTime Toggle Time in Functions Calls
 * @details Toggles RB_10 with the number of functions calls.
 * @details Example: If Toggle Time is 20, you have to call the function 20 times to toggle RB_10
 * @attention toggle pin has to be defined as digital output first
 */
void blinkLed2(uint16_t ui16ToggleTime);

/** 
 * @brief Toggle LED3 (RB_11) with toggle Time
 * @param uint16_t ui16ToggleTime Toggle Time in Functions Calls
 * @details Toggles RB_11 with the number of functions calls.
 * @details Example: If Toggle Time is 20, you have to call the function 20 times to toggle RB_11
 * @attention toggle pin has to be defined as digital output first
 */
void blinkLed3(uint16_t ui16ToggleTime);

/** 
 * @brief Toggles Pin with toggle Time
 * @params uint8_t ui8Pin Pin to toggle with ToggleTime
 * @param uint16_t ui16ToggleTime Toggle Time in Functions Calls
 * @details Toggles the Pin with the number of functions calls.
 * @details Example: If Toggle Time is 20, you have to call the function 20 times to toggle RB_11
 * @attention toggle pin has to be defined as digital output first
 * @attention function is only implemented for pins RG_8 to RG_11
 */
void blinkLed(uint8_t ui8Pin, uint16_t uiToggleTime);

/** 
 * @brief Measure hold Time from Pin
 * @params uint8_t ui8Pin Pin to measure the hold Time
 * @returns uint16_t ui16HoldTime HoldTime is measured in function calls
 * @details Measures Hold Time in Functions calls, if the Pin is not hold (high level) the functions retuns the last measured hold time
 * @details Example: If the Pin is hold for 40ms you get the return value 40 when the function is called each ms, or the return value 20 when the function is called each 2ms
 * @attention Pin has to be configured as input first, the functions is low active
 * @attention only implemented for the pins RG_12 - RG_15
 */
uint16_t measureToggleTimeSW(uint8_t ui8Pin);

/** 
 * @brief Measure hold Time from RG_12
 * @returns uint16_t ui16HoldTime HoldTime is measured in function calls
 * @details Measures Hold Time in Functions calls, if the Pin is not hold (high level) the functions retuns the last measured hold time
 * @details Example: If the Pin is hold for 40ms you get the return value 40 when the function is called each ms, or the return value 20 when the function is called each 2ms
 * @attention Pin has to be configured as input first, the functions is low active
 */
uint16_t measureToggleTimeSW0();

/** 
 * @brief Measure hold Time from RG_13
 * @returns uint16_t ui16HoldTime HoldTime is measured in function calls
 * @details Measures Hold Time in Functions calls, if the Pin is not hold (high level) the functions retuns the last measured hold time
 * @details Example: If the Pin is hold for 40ms you get the return value 40 when the function is called each ms, or the return value 20 when the function is called each 2ms
 * @attention Pin has to be configured as input first, the functions is low active
 */
uint16_t measureToggleTimeSW1();

/** 
 * @brief Measure hold Time from RG_14
 * @returns uint16_t ui16HoldTime HoldTime is measured in function calls
 * @details Measures Hold Time in Functions calls, if the Pin is not hold (high level) the functions retuns the last measured hold time
 * @details Example: If the Pin is hold for 40ms you get the return value 40 when the function is called each ms, or the return value 20 when the function is called each 2ms
 * @attention Pin has to be configured as input first, the functions is low active
 */
uint16_t measureToggleTimeSW2();

/** 
 * @brief Measure hold Time from RG_15
 * @returns uint16_t ui16HoldTime HoldTime is measured in function calls
 * @details Measures Hold Time in Functions calls, if the Pin is not hold (high level) the functions retuns the last measured hold time
 * @details Example: If the Pin is hold for 40ms you get the return value 40 when the function is called each ms, or the return value 20 when the function is called each 2ms
 * @attention Pin has to be configured as input first, the functions is low active
 */
uint16_t measureToggleTimeSW3();

#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33BLINKLED_H */


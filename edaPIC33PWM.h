/* 
 * File:   edaPIC33PWM.h
 * Author: Kevin
 *
 * Created on 16. Juli 2017, 18:14
 */

#ifndef EDAPIC33PWM_H
#define	EDAPIC33PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include"edaPIC33Hardware.h"

 
#define PWM1L   RE0  //pin is used for LCD Communication!
#define PWM1H   RE1  //pin is used for LCD Communication!
#define PWM2L   RE2  //pin is used for LCD Communication!
#define PWM2H   RE3  //pin is used for LCD Communication!
#define PWM3L   RE4  //pin is used for LCD Communication!
#define PWM3H   RE5  //pin is used for LCD Communication!
#define PWM4L   RE6  //pin is used for LCD Communication!
#define PWM4H   RE7  //pin is used for LCD Communication!
#define PWM5L   RC1
#define PWM5H   RC2
#define PWM6L   RC3
#define PWM6H   RC4   
    
 /** 
 * @brief  initialize PWM Modul
 * @details Function initilizes Hardware PWM Module to Independent PWM Mode
 * @param void
 * @return void
 * @attention Periode Value must be set with Function setPwmPeriodValue
 * @attention provided ports: RC1, RC2, RC3, RC4, RE0, RE1, RE2, RE3, RE4, RE5, RE6, RE7
 */
void initPwmModul();

/** 
 * @brief sets Periode Value for Hardware PWM Modul
 * @details Function sets PWM Period Value
 * @param void
 * @return void
 * @attention Periode Value must be set with Function setPwmPeriodValue
 */
void setPwmPeriodValue(uint16_t ui16PeriodValue);

/** 
 * @brief sets Duty Cycle (on Time) for Hardware PWM Modul Port
 * @param   uint8_t     ui8Port         Port you want to change the DutyCycle
 *          uint16_t    ui16DutyCycle   DutyCycle (0...Period Value)
 * @return void
 * @attention Periode Value must be set with Function setPwmPeriodValue
 */
void setPwmDutyCycle(uint8_t ui8Port, uint16_t ui16DutyCycle);



#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33PWM_H */


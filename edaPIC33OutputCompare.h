/* 
 * File:   edaPIC33OutputCompare.h
 * Author: Kevin
 *
 * Created on 15. Juli 2017, 20:47
 */

#ifndef EDAPIC33OUTPUTCOMPARE_H
#define	EDAPIC33OUTPUTCOMPARE_H
#include <xc.h> //*include processor files - each processor file is guarded.  
#include <stdint.h>//* include stdint for several datatypes 
#ifdef	__cplusplus
extern "C" {
#endif

#define OC1_Pin    1
#define OC2_Pin    2
#define OC3_Pin    3
#define OC4_Pin    4
#define OC5_Pin    5
#define OC6_Pin    6
#define OC7_Pin    7
#define OC8_Pin    8
#define OC9_Pin    9
#define OC10_Pin   10
#define OC11_Pin   11
#define OC12_Pin   12
#define OC13_Pin   13
#define OC14_Pin   14
#define OC15_Pin   15
#define OC16_Pin   16

/** 
 * @brief initialize Output Compare Module
 * @details Function initializes Output Compare Module to 
 * @param   uint8_t OC_Pin  internal OCx Pin to initalize output compare module
 * @return void
 * @attention internal OCx Pins must be mapped to Output Pins!!! See Function EdaBoardOutputMapping
 */
void initOutputComparePwm(uint8_t OC_Pin);

/** 
 * @brief set Output Compare Values 
 * @details set Parameter for Output Compare PWM Pins, Value are normalited to Fp = Fosc/2 = 70Mhz
 *          Output Frequenzy: Fpwm = Fp/PeriodeTime = 70Mhz / PeriodeTime
 *          PeriodeTime = Fp / Fpwm = 70Mhz / Fpwm
 * @param uint8_t   OC_Pin Output Compare Pin
 *        uint16_t  ui16PeriodTime Period Value for OC Pins
 *        uint16_t  ui16HighTime High Time Value for OC Pins
 * @return void
 * @attention 
 */
void setOutputCompareValues(uint8_t OC_Pin, uint16_t ui16PeriodTime, uint16_t ui16HighTime);



#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33OUTPUTCOMPARE_H */


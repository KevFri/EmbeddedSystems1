/* 
 * File:   edaPIC33ADC.h
 * Author: Kevin
 *
 * Created on 15. Juli 2017, 20:25
 */

#ifndef EDAPIC33ADC_H
#define	EDAPIC33ADC_H

#include<xc.h>
#include<stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif


//*analog pin definitions
#define AN0     RB0
#define AN1     RB1
#define AN2     RB2   
#define AN3     RB3
#define AN4     RB4
#define AN5     RB5
#define AN6     RB6
#define AN7     RB7
#define AN8     RB8
#define AN9     RB9
#define AN10    RB10
#define AN11    RB11
#define AN12    RB12
#define AN13    RB13
#define AN14    RB14
#define AN15    RB15
#define AN16    RC1
#define AN17    RC2        
#define AN18    RC3
#define AN19    RC4
#define AN20    RE8
#define AN21    RE9
#define AN22    RA6  
#define AN23    RA7
#define AN24    RE0  //pin is used for LCD Communication!
#define AN25    RE1  //pin is used for LCD Communication!
#define AN26    RE2  //pin is used for LCD Communication!
#define AN27    RE3  //pin is used for LCD Communication!
#define AN28    RE4  //pin is used for LCD Communication!
#define AN29    RE5  //pin is used for LCD Communication!
#define AN30    RE6  //pin is used for LCD Communication!
#define AN31    RE7  //pin is used for LCD Communication!    
    

/** 
 * @brief Function initilizes ADC1 for single mode with 10Bit
 * @attention ...
 */
void initADC1();

/** 
 * @brief Function reads analog Value from ui8Port
 * @param uint8_t Port Port you want to read analog
 * @return int16_t analog Value
 */
int16_t analogRead(uint8_t ui8Port);

/** 
 * @brief Function returns Analog Port Bit Number which is linked with the port
 * @param uint8_t Port Port you want to know the Analog Port Bit Number
 * @return uint8_t Return Return Value: Analog Port Bit Number of Port
 */
uint8_t getAnalogPortBitNumb(uint8_t Port);


#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33ADC_H */


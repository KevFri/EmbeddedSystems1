/* 
 * File:   edaPIC33Setup.h
 * Author: Kevin
 *
 * Created on 12. Juni 2017, 10:23
 */


#ifndef EDAPIC33SETUP_H
#define	EDAPIC33SETUP_H

#ifdef	__cplusplus
extern "C" {
#endif

//*Push-Buttons
#define SW0 RG12
#define SW1 RG13
#define SW2 RG14
#define SW3 RG15

//*Incremental Encoder
#define INCA  RG0
#define INCB  RG1
#define INCSW RG9

//* DIP Switches
#define DIP0  RG6 
#define DIP1  RG7

//* PIEZO
#define PIEZO RG8
#define Piezo PIEZO

//*On Board LEDs
#define LED0 RB8
#define LED1 RB9
#define LED2 RB10
#define LED3 RB11
#define D200 LED0
#define D201 LED1
#define D202 LED2 
#define D203 LED3

//* On Board Switches
#define SW200 SW0
#define SW201 SW1
#define SW202 SW2
#define SW203 SW3

//* EDA Board Pins
#define PWM0    OC1_Pin
#define PWM1    OC2_Pin
#define Aout0   PWM0
#define Aout1   PWM1    

//*Output Mapping Pins
#define RP64    RD0
#define RP65    RD1
#define RP66    RD2
#define RP67    RD3
#define RP69    RD5
#define RP70    RD6
#define RP71    RD7
#define RP79    RD15
#define RP80    RE0
#define RP82    RE2
#define RP84    RE4
#define RP85    RE5
#define RP87    RE7
#define RP96    RF0
#define RP97    RF1
#define RP98    RF2
#define RP99    RF3
#define RP100   RF4
#define RP101   RF5
#define RP104   RF8
#define RP108   RF12
#define RP109   RF13
#define RP112   RG0
#define RP113   RG1
#define RP118   RG6
#define RP120   RG8
#define RP125   RG13
#define RP126   RG14
#define RP127   RG15

#define RPI17   RA1
#define RPI18   RA2
#define RPI19   RA3
#define RPI20   RA4
#define RPI21   RA5
#define RPI22   RA6
#define RPI23   RA7
#define RPI30   RA14
#define RPI31   RA15
#define RPI38   RB6
#define RPI39   RB7
#define RPI40   RB8
#define RPI41   RB9
#define RPI42   RB10
#define RPI43   RB11
#define RPI44   RB12
#define RPI45   RB13
#define RPI46   RB14
#define RPI47   RB15
#define RPI60   RC12
#define RPI61   RC13
#define RPI72   RD8
#define RPI73   RD9
#define RPI74   RD10
#define RPI75   RD11
#define RPI76   RD12
#define RPI77   RD13
#define RPI78   RD14
#define RPI81   RE1
#define RPI83   RE3
#define RPI124  RG12

  
/** 
 *  @brief Setup EdaPIC33Board
 *  @details I/O ports, lcd display, rotatory encoder, switches, leds,...
 */ 
void setupEdaPIC33Board();

/** 
 * @brief Output Mapping Function
 * @details Function maps internal Pins to external output Pins
 * @details  Pin 72 (RD0) <= OC1
 * @details  Pin 76 (RD1) <= OC2
 * @param  void
 * @return void
 * @attention read Datasheet to map the pins
 */
void EdaBoardOutputMapping();

#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33SETUP_H */


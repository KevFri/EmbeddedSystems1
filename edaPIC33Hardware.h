/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: Kevin Fritz
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef EDAPIC33HARDWARE_H
#define	EDAPIC33HARDWARE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> 
// TODO Insert appropriate #include <>

// TODO Insert declarations
#define INPUT            0
#define INPUT_PULLDOWN   1
#define INPUT_PULLUP     2
#define OUTPUT           3

//defined als PIN
#define LED0 32 //RB8
#define LED1 33 //RB9
#define LED2 34 //RB10
#define LED3 35 //RB11

#define D200 LED0
#define D201 LED1
#define D202 LED2 
#define D203 LED3


#define SW0 96  //RG12
#define SW1 97  //RG13
#define SW2 95  //RG14
#define SW3 1   //RG15

#define SW200 SW0
#define SW201 SW1
#define SW202 SW2
#define SW203 SW3

//TODO add Pins in Functions:
#define INCA    90 //RG0
#define INCB    89 //RG1
#define INCSW   14 //RG9

//TODO add Pins in Functions:
#define DIP0    10 //RG6 
#define DIP1    11 //RG7

#define HIGH    1 //Logical HIGH
#define LOW     0 //Logical LOW

// TODO Insert declarations or function prototypes (right here) to leverage
// TODO Insert Doxygen
void pinMode(const uint8_t ui8Port,const  uint8_t ui8Mode);

void digitalWrite(const uint8_t ui8Port,const  uint8_t ui8Value);

void digitalToggle(const uint8_t ui8Port);

uint8_t digitalRead(const uint8_t ui8Port);

// live documentation

#endif	/* EDAPIC33HARDWARE_H */


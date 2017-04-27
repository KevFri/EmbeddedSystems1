
/* 
 * File:   
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
#ifndef EDAPIC33HARDWARE_H
#define	EDAPIC33HARDWARE_H

#include <xc.h> //*include processor files - each processor file is guarded.  
#include <stdint.h>//* include stdint for several datatypes 

//* Logical level HIGH / LOW
#define HIGH    1 //Logical HIGH
#define LOW     0 //Logical LOW

//* I/O Port Modes
#define INPUT            0
#define INPUT_PULLDOWN   1
#define INPUT_PULLUP     2
#define OUTPUT           3

//*edaPIC33 definitions
#define RG_15    1
//#define VDD     2
#define RE_5     3
#define RE_6     4
#define RE_7     5
#define RC_1     6
#define RC_2     7
#define RC_3     8
#define RC_4     9
#define RG_6     10
#define RG_7     11
#define RG_8     12
//#define MCLR    13
#define RG_9     14
//#define VSS     15
//#define VDD     16
#define RA_0     17
#define RE_8     18
#define RE_9     19
#define RB_5     20
#define RB_4     21
#define RB_3     22
#define RB_2     23
#define RB_1     24
#define RB_0     25
#define RB_6     26
#define RB_7     27
#define RA_9     28
#define RA_10    29
//#define AVDD    30
//#define AVSS    31
#define RB_8     32
#define RB_9     33
#define RB_10    34
#define RB_11    35
//#define VSS     36
//#define VDD     37
#define RA_1     38
#define RF_13    39
#define RF_12    40
#define RB_12    41
#define RB_13    42
#define RB_14    43
#define RB_15    44
//#define VSS     45
//#define VDD     46  
#define RD_14    47
#define RD_15    48
#define RF_4     49
#define RF_5     50
#define RF_3     51
#define RF_2     52
#define RF_8     53
//#define VBUS    54
//#define VUSB3V3 55
#define RG_3     56
#define RG_2     57
#define RA_2     58
#define RA_3     59
#define RA_4     60
#define RA_5     61
//#define VDD     62
#define RC_12    63
#define RC_15    64
//#define VSS     65
#define RA_14    66
#define RA_15    67
#define RD_8     68
#define RD_9     69
#define RD_10    70
#define RD_11    71
#define RD_0     72
#define RC_13    73
#define RC_14    74
//#define VSS     75
#define RD_1     76
#define RD_2     77
#define RD_3     78
#define RD_12    79
#define RD_13    80
#define RD_4     81
#define RD_5     82
#define RD_6     83
#define RD_7     84
//#define VCAP    85
//#define VDD     86
#define RF_0     87
#define RF_1     88
#define RG_1     89
#define RG_0     90
#define RA_6     91
#define RA_7     92
#define RE_0     93
#define RE_1     94
#define RG_14    95
#define RG_12    96
#define RG_13    97
#define RE_2     98
#define RE_3     99
#define RE_4     100

//*Push-Buttons
#define SW0 RG_12
#define SW1 RG_13
#define SW2 RG_14
#define SW3 RG_15

//*Incremental Encoder
#define INCA  RG_0
#define INCB  RG_1
#define INCSW RG_9

//* DIP Switches
#define DIP0  RG_6 
#define DIP1  RG_7

//* PIEZO
#define PIEZO RG_8
#define Piezo PIEZO

//*On Board LEDs
#define LED0 RB_8
#define LED1 RB_9
#define LED2 RB_10
#define LED3 RB_11
#define D200 LED0
#define D201 LED1
#define D202 LED2 
#define D203 LED3

//* On Board Switches
#define SW200 SW0
#define SW201 SW1
#define SW202 SW2
#define SW203 SW3

/** 
 * @brief Configures the specified pin to behave either as an input or an output.
 * @brief it is possible to enable the internal pullup / pulldown resistors with the mode INPUT_PULLUP, INPUT_PULLDOWN
 * @param uint8_t ui8Port   Number of the Port to configure.
 * @param uint8_t ui8Mode   Mode to configure.
 * @details Provided modes: INPUT, INPUT_PULLUP, INPUT_PULLDOWN, OUTPUT
 * @attention   pinMode is not implemented for all pins (right now)
 */
void pinMode(const uint8_t ui8Port,const  uint8_t ui8Mode);

/** 
 * @brief Write a HIGH or a LOW value to a digital pin.
 * @param uint8_t ui8Port   Number of the pin.
 * @param uint8_t ui8Value  Value to write. Ether HIGH or LOL
 * @details Provided values: HIGH, LOW, 1,0
 * @attention Each Value of ui8Value unlike zero writes HIGH to the Outputport
 * @attention digitalWrite is only implemented for the pins 32-35 and 12 (LED0-3 and PIEZO)  (right now)
 */
void digitalWrite(const uint8_t ui8Port,const  uint8_t ui8Value);

/** 
 * @brief toggles the digital pin
 * @param uint8_t ui8Port   Number of the pin to toggle.
 * @attention digitalToggle is only implemented for the pins 32-35 and 12 (LED0-3 and PIEZO)  (right now)
 */
void digitalToggle(const uint8_t ui8Port);

/** 
 * @brief reads the digital pin.
 * @param uint8_t ui8Port   Number of the pin to read.
 * @attention ...
 */
uint8_t digitalRead(const uint8_t ui8Port);
#endif	/* EDAPIC33HARDWARE_H */

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
#define RG15    1
//#define VDD     2
#define RE5     3
#define RE6     4
#define RE7     5
#define RC1     6
#define RC2     7
#define RC3     8
#define RC4     9
#define RG6     10
#define RG7     11
#define RG8     12
//#define MCLR    13
#define RG9     14
//#define VSS     15
//#define VDD     16
#define RA0     17
#define RE8     18
#define RE9     19
#define RB5     20
#define RB4     21
#define RB3     22
#define RB2     23
#define RB1     24
#define RB0     25
#define RB6     26
#define RB7     27
#define RA9     28
#define RA10    29
//#define AVDD    30
//#define AVSS    31
#define RB8     32
#define RB9     33
#define RB10    34
#define RB11    35
//#define VSS     36
//#define VDD     37
#define RA1     38
#define RF13    39
#define RF12    40
#define RB12    41
#define RB13    42
#define RB14    43
#define RB15    44
//#define VSS     45
//#define VDD     46  
#define RD14    47
#define RD15    48
#define RF4     49
#define RF5     50
#define RF3     51
#define RF2     52
#define RF8     53
//#define VBUS    54
//#define VUSB3V3 55
#define RG3     56
#define RG2     57
#define RA2     58
#define RA3     59
#define RA4     60
#define RA5     61
//#define VDD     62
#define RC12    63
#define RC15    64
//#define VSS     65
#define RA14    66
#define RA15    67
#define RD8     68
#define RD9     69
#define RD10    70
#define RD11    71
#define RD0     72
#define RC13    73
#define RC14    74
//#define VSS     75
#define RD1     76
#define RD2     77
#define RD3     78
#define RD12    79
#define RD13    80
#define RD4     81
#define RD5     82
#define RD6     83
#define RD7     84
//#define VCAP    85
//#define VDD     86
#define RF0     87
#define RF1     88
#define RG1     89
#define RG0     90
#define RA6     91
#define RA7     92
#define RE0     93
#define RE1     94
#define RG14    95
#define RG12    96
#define RG13    97
#define RE2     98
#define RE3     99
#define RE4     100

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

//* LCD Ports
#define LCD_D0 RE0
#define LCD_D1 RE1
#define LCD_D2 RE2
#define LCD_D3 RE3
#define LCD_D4 RE4
#define LCD_D5 RE5
#define LCD_D6 RE6
#define LCD_D7 RE7
#define LCD_E RD4
#define LCD_RW RD5
#define LCD_RS RB15


#define STATE_STABLE_HIGH   0
#define STATE_INSTABLE_HIGH 1
#define STATE_STABLE_LOW    2
#define STATE_INSTABLE_LOW  3



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
 * @attention not implemented for each pin
 */
uint8_t digitalRead(const uint8_t ui8Port);
#endif	/* EDAPIC33HARDWARE_H */

/** 
 * @brief Funktion zum Auswerten des Tasters SW0 (Pin 96)
 * @param const uint16_t cui16DebounceTime Entprelldauer kann in edaPIC33Hardware.c festgelegt werden [Funktionsaufrufe].
 * @details Funktion Entprellt den Taster SWO (Pin 96)
 * @attention Funktion muss zyklisch in konstanten Zeitabständen aufgerufen werden!
 */
extern const uint16_t cui16DebounceTime;
uint8_t isPressedSW0();

#define STATE_A0_B0 0
#define STATE_A1_B0 1
#define STATE_A0_B1 2
#define STATE_A1_B1 3

#define LEFT -1
#define RIGTH 1
#define IDLE 0


/** 
 * @brief Incrementalencoder
 * @param void
 * @return -1: Links, 0:unverändert, 1:Rechts
 * @details Funktionen wertet den Inkrementalencoder auf dem Board auf. Funktion muss zyklisch aufgerufen werden, damit ein drehen festgestellt werden kann
 * @attention Funktion muss zur initalisierung (mindestens) zweimal aufgerufen werden um den STATE richtig zu definieren!
 * @attention Pins INCA und INCB müssen vorher als INPUT_PULLUP definiert werden 
 */
int8_t rotatoryEncode();

uint8_t getBitNumb(uint8_t Port);
uint16_t* getpTRIS(uint8_t Port);
uint16_t* getpPORT(uint8_t Port);
uint16_t* getpLAT(uint8_t Port);
uint16_t* getpODC(uint8_t Port);
uint16_t* getpCNEN(uint8_t Port);
uint16_t* getpCNPU(uint8_t Port);
uint16_t* getpCNPD(uint8_t Port);
uint16_t* getpANSEL(uint8_t Port);
void setBit(uint16_t* pui16Var, uint8_t ui8Bit, uint8_t ui8Value);
uint8_t getBit(uint16_t* pui16Var, uint8_t ui8Bit);
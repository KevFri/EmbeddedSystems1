
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

//*edaPIC33 definitions
#define RG15    1
//#define VDD     2
#define RE5     3  //pin is used for LCD Communication!
#define RE6     4  //pin is used for LCD Communication!
#define RE7     5  //pin is used for LCD Communication!
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
#define RE0     93  //pin is used for LCD Communication!
#define RE1     94  //pin is used for LCD Communication!
#define RG14    95
#define RG12    96
#define RG13    97
#define RE2     98  //pin is used for LCD Communication!
#define RE3     99  //pin is used for LCD Communication!
#define RE4     100 //pin is used for LCD Communication!

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

//* I/O Port Modes for pinMode Function
#define DIGITAL_INPUT           0    
#define DIGITAL_INPUT_PULLDOWN  1 
#define DIGITAL_INPUT_PULLUP    2 
#define DIGITAL_OUTPUT          3
#define OPEN_DRAIN_OUTPUT       4
#define ANALOG_INPUT            5
#define ANALOG_OUTPUT           6    
#define ANALOG_INPUT_PULLDOWN   7 
#define ANALOG_INPUT_PULLUP     8 
#define PWM_OUTPUT              9

/** 
 * @brief Configures the specified pin to behave either as an input or an output.
 * @brief it is possible to enable the internal pullup / pulldown resistors with the mode INPUT_PULLUP, INPUT_PULLDOWN
 * @param uint8_t ui8Port   Number of the Port to configure.
 * @param uint8_t ui8Mode   Mode to configure.
 * @details Provided modes: INPUT, INPUT_PULLUP, INPUT_PULLDOWN, OUTPUT, ANALOG_INPUT, ANALOG_OUTPUT, ANALOG_INPUT_PULLDOWN, ANALOG_INPUT_PULLUP, PWM_OUTPUT
 * @attention   pinMode is implemented for all register pins
 */
void pinMode(const uint8_t ui8Port,const  uint8_t ui8Mode);

/** 
 * @brief Write a HIGH or a LOW value to a digital pin.
 * @param uint8_t ui8Port   Number of the pin.
 * @param uint8_t ui8Value  Value to write. Ether HIGH or LOL
 * @details Provided values: HIGH, LOW, 1,0
 * @attention Each Value of ui8Value unlike zero writes HIGH to the Outputport
 * @attention digitalWrite is implemented for all register pins
 */
void digitalWrite(const uint8_t ui8Port,const  uint8_t ui8Value);

/** 
 * @brief toggles the digital pin
 * @param uint8_t ui8Port   Number of the pin to toggle.
 * @attention Port has to be defined as Output first
 * @attention digitalToggle is implemented for all register pins
 */
void digitalToggle(const uint8_t ui8Port);

/** 
 * @brief reads the digital pin.
 * @param uint8_t ui8Port   Number of the pin to read.
 * @attention digitalRead is implemented for all register pins
 */
uint8_t digitalRead(const uint8_t ui8Port);

/** 
 * @brief Functions returns Pointer to TRIS Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pTRIS Pointer to TRIS Register
 * @details returns NULL if Port has no TRIS Register
 */
uint16_t* getpTRIS(uint8_t Port);

/** 
 * @brief Functions returns Pointer to PORT Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pPORT Pointer to PORT Register
 * @details returns NULL if Port has no PORT Register
 */
uint16_t* getpPORT(uint8_t Port);

/** 
 * @brief Functions returns Pointer to LAT Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pLAT Pointer to LAT Register
 * @details returns NULL if Port has no LAT Register
 */
uint16_t* getpLAT(uint8_t Port);

/** 
 * @brief Functions returns Pointer to ODC Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pODC Pointer to ODC Register
 * @details returns NULL if Port has no ODC Register
 */
uint16_t* getpODC(uint8_t Port);

/** 
 * @brief Functions returns Pointer to CNEN Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pCNEN Pointer to CNEN Register
 * @details returns NULL if Port has no CNEN Register
 */
uint16_t* getpCNEN(uint8_t Port);

/** 
 * @brief Functions returns Pointer to CNPU Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pCNPU Pointer to CNPU Register
 * @details returns NULL if Port has no CNPU Register
 */
uint16_t* getpCNPU(uint8_t Port);

/** 
 * @brief Functions returns Pointer to CNPD Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pCNPD Pointer to CNPD Register
 * @details returns NULL if Port has no CNPD Register
 */
uint16_t* getpCNPD(uint8_t Port);

/** 
 * @brief Functions returns Pointer to ANSEL Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pANSEL Pointer to ANSEL Register
 * @details returns NULL if Port has no ANSEL Register
 */
uint16_t* getpANSEL(uint8_t Port);

/** 
 * @brief Functions returns Pointer to IOCON Register 
 * @param uint8_t Port Number of Port
 * @return uint16_t* pIOCON Pointer to IOCON Register
 * @details returns NULL if Port has no IOCON Register
 */
uint16_t* getpIOCON(uint8_t Port);

/** 
 * @brief Functions setBit of pui16Var 
 * @param uint16_t* pui16Var Variable which contains the Bit to set
 * @param uint8_t ui8Bit Bitnumber to set 0..15
 * @param uint8_t ui8Value Value to set the Bit 0 or 1
 * @attention ui8Value has to be 0 or 1 otherwise the function doesn't change pui16Var
 */
void setBit(uint16_t* pui16Var, uint8_t ui8Bit, uint8_t ui8Value);

/** 
 * @brief Functions returns the value of one Bit form ui16Var
 * @param uint16_t ui16Var Variable which contains the Bit to read
 * @param uint8_t ui8Bit Bitnumber you want to read 0..15
 * @return uint8_t ui8Value Value of the Bit 0 or 1
 */
uint8_t getBit(uint16_t ui16Var, uint8_t ui8Bit);

/** 
 * @brief Function returns Register Bit Number which is linked with the port
 * @param uint8_t Port Port you want to know the Register
 * @return uint8_t Return Return Value: Register Bit Number of Port
 */
uint8_t getPortBitNumb(uint8_t Port);


/** 
 * @brief Function returns PWM Pin Enable Register Bit Number
 * @param uint8_t Port Port you want to know the PWM Pin Enable Register Bit Number
 * @return uint8_t Return Return Value: PWM Pin Enable Register Bit Number of Port
 */
uint8_t getPwmPinEnRegisterBitNumb(uint8_t Port);

#endif	/* EDAPIC33HARDWARE_H */
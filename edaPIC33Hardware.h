
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

#define PWM0    OC1_Pin
#define PWM1    OC2_Pin
#define Aout0   PWM0
#define Aout1   PWM1
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
 * @brief Funktion zum Entprellen des Tasters SW0 (Pin 96)
 * @param const uint16_t cui16DebounceTime Entprelldauer kann in edaPIC33Hardware.c festgelegt werden [Funktionsaufrufe].
 * @details Funktion Entprellt den Taster SWO (Pin 96)
 * @attention Funktion muss zyklisch in konstanten Zeitabständen aufgerufen werden!
 * @attention SW0 muss vorher als Eingang deklariert werden
 */
uint8_t isPressedSW0();

/** 
 * @brief Funktion zum Entprellen eines beliebigen Tasters/Schalter)
 * @param const uint16_t cui16DebounceTime Entprelldauer kann in edaPIC33Hardware.c festgelegt werden [Einheit: Funktionsaufrufe].
 * @details Funktion Entprellt den Taster SWO (Pin 96)
 * @attention Funktion muss zyklisch in konstanten Zeitabständen aufgerufen werden!
 * @attention Funktion kann nur für einen Pin verwendet werden
 * @attention Pin muss vorher als Eingang deklariert werden
 */
uint8_t isPressed(uint8_t ui8Port);
extern const uint16_t cui16DebounceTime;


/** 
 * @brief Incrementalencoder
 * @param void
 * @return int8_t value: -1: Links, 0:unverändert, 1:Rechts
 * @details Funktionen wertet den Inkrementalencoder auf dem Board auf. Funktion muss zyklisch aufgerufen werden, damit ein drehen festgestellt werden kann
 * @attention Funktion muss zur initalisierung (mindestens) zweimal aufgerufen werden um den STATE richtig zu definieren!
 * @attention Pins INCA und INCB müssen vorher als INPUT_PULLUP definiert werden 
 */
int8_t rotaryEncode();
#define LEFT -1
#define RIGTH 1
#define IDLE 0

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
 * @brief Function returns PWM Pin Enable Register Bit Number
 * @param uint8_t Port Port you want to know the PWM Pin Enable Register Bit Number
 * @return uint8_t Return Return Value: PWM Pin Enable Register Bit Number of Port
 */
uint8_t getPwmPinEnRegisterBitNumb(uint8_t Port);

/** 
 * @brief sets Duty Cycle (on Time) for Hardware PWM Modul Port
 * @param   uint8_t     ui8Port         Port you want to change the DutyCycle
 *          uint16_t    ui16DutyCycle   DutyCycle (0...Period Value)
 * @return void
 * @attention Periode Value must be set with Function setPwmPeriodValue
 */
void setPwmDutyCycle(uint8_t ui8Port, uint16_t ui16DutyCycle);

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
 * @details set Parameter for Output Compare PWM Pins, Value are normalited to Fp = Fosc/2
 * @param uint8_t   OC_Pin Output Compare Pin
 *        uint16_t  ui16PeriodTime Period Value for OC Pins
 *        uint16_t  ui16HighTime High Time Value for OC Pins
 * @return void
 * @attention 
 */
void setOutputCompareValues(uint8_t OC_Pin, uint16_t ui16PeriodTime, uint16_t ui16HighTime);

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

#endif	/* EDAPIC33HARDWARE_H */
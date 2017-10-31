#include <xc.h>
#include "edaPIC33Hardware.h"  //edaPIC33 Hardware Library
#include "edaPIC33LCD.h"        //edaPIC33 LCD Library
#include "edaPIC33Setup.h"
#include "edaPIC33ADC.h"
#include "edaPIC33OutputCompare.h"
#include "edaPIC33OtherStuff.h"
#include "edaPIC33PWM.h"

void setupEdaPIC33Board()
{
    //set switch pinmodes
    pinMode(SW0, DIGITAL_INPUT_PULLUP);
    pinMode(SW1, DIGITAL_INPUT_PULLUP);
    pinMode(SW2, DIGITAL_INPUT_PULLUP);
    pinMode(SW3, DIGITAL_INPUT_PULLUP);
    
    pinMode(DIP0, DIGITAL_INPUT_PULLUP);
    pinMode(DIP1, DIGITAL_INPUT_PULLUP);
    
    //set LED pinmodes
    pinMode(LED0,DIGITAL_OUTPUT);
    pinMode(LED1,DIGITAL_OUTPUT);
    pinMode(LED2,DIGITAL_OUTPUT);
    pinMode(LED3,DIGITAL_OUTPUT);

    //set LEDs to low (default value)
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    
    //set Pin Modes for Incremental
    pinMode(INCA, DIGITAL_INPUT_PULLUP);
    pinMode(INCB, DIGITAL_INPUT_PULLUP);
    pinMode(INCSW, DIGITAL_INPUT_PULLUP);
    rotaryEncode();  //call rotatoryEncode function two times to initalize state
    rotaryEncode();
    
    //set Pin Mode for PIEZO
    pinMode(PIEZO,DIGITAL_OUTPUT);
    digitalWrite(PIEZO, LOW);
    
    //init ADC1: Automatic Sample and Manual Conversion 10Bit Mode
    initADC1();
    //set pin modes for analog pins (potentiometers)
    pinMode(AN0, ANALOG_INPUT);
    pinMode(AN1, ANALOG_INPUT);
    
    initPwmModul();
    setPwmPeriodValue(1000);
    //pinMode(RC1, PWM_OUTPUT);
    //pinMode(RC2, PWM_OUTPUT);
    pinMode(RC3, PWM_OUTPUT);
    //pinMode(RC4, PWM_OUTPUT);
    
    //initOutputCompare();
    initOutputComparePwm(OC1_Pin);
    initOutputComparePwm(OC2_Pin);
    EdaBoardOutputMapping();
        //OC1 to Pin 72 --> RD0
        //OC2 to Pin 76 --> RD1
    
    //initial LCD Display, clear LCD and set cursor home, clear Shadow String
    initMyLCD();
    createNewChar();
    clearLCDStorage();
    home_clr(); 
}


void EdaBoardOutputMapping()
{
    __builtin_write_OSCCONL(OSCCON & ~(1<<6));
    //_RP64R = 0b010000; //OC1 to Pin 72 --> RD0
    //_RP65R = 0b010001; //OC2 to Pin 76 --> RD1
    _RP64R = _RPOUT_OC1;
    _RP65R = _RPOUT_OC2;
    
    RPOR9 = 0;
    RPOR9bits.RP101R = 1;       //RF5/RP101 as U1TX
    RPINR18bits.U1RXR = 100;    //RP100/RF4 as U1RX
    
    
    
    //_RP120R =  0b010000;  //OC1 to Piezo
    __builtin_write_OSCCONL(OSCCON | (1<<6));
}

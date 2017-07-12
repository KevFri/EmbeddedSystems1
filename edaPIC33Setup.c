#include <xc.h>
#include "edaPIC33Hardware.h"  //edaPIC33 Hardware Library
#include "edaPIC33LCD.h"        //edaPIC33 LCD Library
#include "edaPIC33Setup.h"

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
    
    //initalize ADC1 to 10Bit mode and set pin modes for analog pins (potentiometers)
    initADC1();
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
    
    //initial LCD Display, clear LCD and set cursor home, clear Shadow String
    initMyLCD();
    createNewChar();
    clearLCDStorage();
    home_clr(); 
}



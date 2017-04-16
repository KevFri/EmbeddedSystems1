/*
 * File:   edaPIC33Hardware.c
 * Author: Kevin Fritz
 *
 * Created on 4. April 2017, 10:41
 */
#include "edaPIC33Timer.h"
#include "edaPIC33Hardware.h"
#include <stdint.h>
/** 
 * @attention   unimplemented function!
 */
uint8_t configTimer1PWM(const uint8_t ui8PWMPort, uint32_t ui32FOSC, uint32_t ui32PWMFrequenzy, uint8_t ui8DutyCycle)
{
    //
    return 0;
}

/** 
 * @attention   unimplemented function!
 */
void onCycleTimer1PWM()
{
    //...
}

int16_t    _i16Timer1_1kHz_dTOn=0;
int16_t    _i16Timer1_1kHz_dTOff=0;
uint8_t    _ui8Timer1_1kHz_Port=0;

/** 
 * @brief Configures Timer1 to generate PWM Signal with DutyCycle
 * @param uint8_t ui8PWMPort Port for the PWM Signal
 * @param uint32_t ui32FOSC Oscillator Frequency
 * @param uint8_t ui8DutyCycle DutyCycle [0...100]  
 * @attention ui8PWMPort has to be configured first with pinMode(ui8PWMPort, OUTPUT)
 */
void configTimer1PWM_1kHz(const uint8_t ui8PWMPort, uint32_t ui32FOSC, uint8_t ui8DutyCycle)
{
    T1CONbits.TON = 0; // Disable Timer
    //set the multiplexer to timer mode
    T1CONbits.TCS = 0;   // Select internal instruction cycle clock
    T1CONbits.TGATE = 0; // Disable Gated Timer mode
    //set prescaler
    T1CONbits.TCKPS = 0b10; // Select 1:64Prescaler
    
    TMR1 = 0x00; // Clear timer register
    PR1 = 0xFFFF; // Load the period value
  
    //disable interrupt
    IPC0bits.T1IP = 0x00; // Set Timer 1 Interrupt Priority Level
    IFS0bits.T1IF = 0; // Clear Timer 1 Interrupt Flag
    IEC0bits.T1IE = 0; // Enable Timer1 interrupt 
    
    T1CONbits.TON = 1; // Start Timer
    
    _ui8Timer1_1kHz_Port = ui8PWMPort;
    
    
    uint64_t ui64NumOfIncrements =((uint64_t)ui32FOSC / 128000); //(2*64*1000) //Number of Increments for 1kHz
    uint64_t ui64temp = ((uint64_t)ui8DutyCycle*(uint64_t)ui64NumOfIncrements)/100;
    _i16Timer1_1kHz_dTOn = (int16_t) ui64temp;
    _i16Timer1_1kHz_dTOff = (int16_t)ui64NumOfIncrements-_i16Timer1_1kHz_dTOn;
}


/** 
 * @brief onCycle Function to generate PWM Signal with DutyCycle
 * @attention before calling this function call configTimer1PWM_1kHz func.
 */
void onCycleTimer1PWM_1kHz()
{
    static uint8_t _ui8Timer1_1kHz_Mode=0;
    static int16_t _i16Timer1_1kHz_T0 = 0;
    int16_t i16_T1 = (int16_t)TMR1;
    if(_ui8Timer1_1kHz_Mode == 0)
    {
        if((i16_T1 - _i16Timer1_1kHz_T0) >= _i16Timer1_1kHz_dTOff) //_i16Timer1_1kHz_dTOff
        {
            digitalWrite(_ui8Timer1_1kHz_Port,HIGH);
            _i16Timer1_1kHz_T0 = (int16_t)TMR1;
            _ui8Timer1_1kHz_Mode=1;        
        }
    }
    else
    {
        if((i16_T1 - _i16Timer1_1kHz_T0) >= _i16Timer1_1kHz_dTOn) //_i16Timer1_1kHz_dTOn
        {
            digitalWrite(_ui8Timer1_1kHz_Port,LOW);
            _i16Timer1_1kHz_T0 = (int16_t)TMR1;
            _ui8Timer1_1kHz_Mode=0;       
        }

    }  
}

/** 
 * @brief calculates new DutyCayle Parameter to generate PWM Signal
 * @attention before calling this function call configTimer1PWM_1kHz func.
 */
void setTimer1PWM_DutyCycleParam(uint32_t ui32FOSC, uint8_t ui8DutyCycle)
{
    uint64_t ui64NumOfIncrements =((uint64_t)ui32FOSC / 128000); //(2*64*1000) //Number of Increments for 1kHz
    uint64_t ui64temp = ((uint64_t)ui8DutyCycle*(uint64_t)ui64NumOfIncrements)/100;
    _i16Timer1_1kHz_dTOn = (int16_t) ui64temp;
    _i16Timer1_1kHz_dTOff = (int16_t)ui64NumOfIncrements-_i16Timer1_1kHz_dTOn; 
}
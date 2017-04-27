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

void setTimer1PWM_DutyCycleParam(uint32_t ui32FOSC, uint8_t ui8DutyCycle)
{
    uint64_t ui64NumOfIncrements =((uint64_t)ui32FOSC / 128000); //(2*64*1000) //Number of Increments for 1kHz
    uint64_t ui64temp = ((uint64_t)ui8DutyCycle*(uint64_t)ui64NumOfIncrements)/100;
    _i16Timer1_1kHz_dTOn = (int16_t) ui64temp;
    _i16Timer1_1kHz_dTOff = (int16_t)ui64NumOfIncrements-_i16Timer1_1kHz_dTOn; 
}

void config16BitTimer(uint8_t ui8Timer, uint8_t ui8TSIDL, uint8_t ui8TGATE, uint8_t ui8TCKPS, uint8_t ui8TSYNC, uint8_t ui8TCS, uint8_t ui8IE, uint8_t ui8IP)
{
    switch(ui8Timer)
    {
        case TIMER1:
            T1CONbits.TON = 0; //turn off timer
            T1CONbits.TSIDL = ui8TSIDL;
            T1CONbits.TGATE = ui8TGATE;
            T1CONbits.TCKPS = ui8TCKPS;
            T1CONbits.TSYNC = ui8TSYNC;
            T1CONbits.TCS   = ui8TCS;
            //T1CONbits.T32   = 0;
            IPC0bits.T1IP = ui8IP; // Set Timer 1 Interrupt Priority Level
            IFS0bits.T1IF = 0; // Clear Timer 1 Interrupt Flag
            IEC0bits.T1IE = ui8IE; // Enable Timer1 interrupt
            TMR1 = 0; //set start value of timer to 0
            PR1 = 0xFFFF;
            break;

        case TIMER2:
            T2CONbits.TON = 0;
            T2CONbits.TSIDL = ui8TSIDL;
            T2CONbits.TGATE = ui8TGATE;
            T2CONbits.TCKPS = ui8TCKPS;
            //T2CONbits.TSYNC = ui8TSYNC;
            T2CONbits.TCS   = ui8TCS;
            T2CONbits.T32   = 0;
            IPC1bits.T2IP = ui8IP;
            IFS0bits.T2IF = 0;
            IEC0bits.T2IE = ui8IE;
            TMR2 = 0;
            PR2 = 0xFFFF;
            break;
        
        case TIMER3:
            T3CONbits.TON = 0;
            T3CONbits.TSIDL = ui8TSIDL;
            T3CONbits.TGATE = ui8TGATE;
            T3CONbits.TCKPS = ui8TCKPS;
            //T3CONbits.TSYNC = ui8TSYNC;
            T3CONbits.TCS   = ui8TCS;
            //T3CONbits.T32   = 0;
            IPC2bits.T3IP = ui8IP;
            IFS0bits.T3IF = 0;
            IEC0bits.T3IE = ui8IE;
            TMR3 = 0;
            PR3 = 0xFFFF;
            break;
        
        case TIMER4:
            T4CONbits.TON = 0;
            T4CONbits.TSIDL = ui8TSIDL;
            T4CONbits.TGATE = ui8TGATE;
            T4CONbits.TCKPS = ui8TCKPS;
            //T4CONbits.TSYNC = ui8TSYNC;
            T4CONbits.TCS   = ui8TCS;
            T4CONbits.T32   = 0;
            IPC6bits.T4IP = ui8IP;
            IFS1bits.T4IF = 0;
            IEC1bits.T4IE = ui8IE;
            TMR4 = 0;
            PR4 = 0xFFFF;
            break;
        
        case TIMER5:
            T5CONbits.TON = 0;
            T5CONbits.TSIDL = ui8TSIDL;
            T5CONbits.TGATE = ui8TGATE;
            T5CONbits.TCKPS = ui8TCKPS;
            //T5CONbits.TSYNC = ui8TSYNC;
            T5CONbits.TCS   = ui8TCS;            
            //T5CONbits.T32   = 0;
            IPC7bits.T5IP = ui8IP;
            IFS1bits.T5IF = 0;
            IEC1bits.T5IE = ui8IE;            
            TMR5 = 0;
            PR5 = 0xFFFF;
            break;
        
        case TIMER6:
            T6CONbits.TON = 0;
            T6CONbits.TSIDL = ui8TSIDL;
            T6CONbits.TGATE = ui8TGATE;
            T6CONbits.TCKPS = ui8TCKPS;
            //T6CONbits.TSYNC = ui8TSYNC;
            T6CONbits.TCS   = ui8TCS;            
            T6CONbits.T32   = 0;
            IPC11bits.T6IP = ui8IP;
            IFS2bits.T6IF = 0;
            IEC2bits.T6IE = ui8IE;            
            TMR6 = 0;
            PR6 = 0xFFFF;
            break;
        
        case TIMER7:
            T7CONbits.TON = 0;
            T7CONbits.TSIDL = ui8TSIDL;
            T7CONbits.TGATE = ui8TGATE;
            T7CONbits.TCKPS = ui8TCKPS;
            //T7CONbits.TSYNC = ui8TSYNC;
            T7CONbits.TCS   = ui8TCS;            
            //T7CONbits.T32   = 0;
            IPC12bits.T7IP = ui8IP;
            IFS3bits.T7IF = 0;
            IEC3bits.T7IE = ui8IE;  
            TMR7 = 0;
            PR7 = 0xFFFF;
            break;
        
        case TIMER8:
            T8CONbits.TON = 0;
            T8CONbits.TSIDL = ui8TSIDL;
            T8CONbits.TGATE = ui8TGATE;
            T8CONbits.TCKPS = ui8TCKPS;
            //T8CONbits.TSYNC = ui8TSYNC;
            T8CONbits.TCS   = ui8TCS;            
            T8CONbits.T32   = 0;
            IPC12bits.T8IP = ui8IP;
            IFS3bits.T8IF = 0;
            IEC3bits.T8IE = ui8IE;  
            TMR8 = 0;
            PR8 = 0xFFFF;
            break;
        
        case TIMER9:
            T9CONbits.TON = 0;
            T9CONbits.TSIDL = ui8TSIDL;
            T9CONbits.TGATE = ui8TGATE;
            T9CONbits.TCKPS = ui8TCKPS;
            //T9CONbits.TSYNC = ui8TSYNC;
            T9CONbits.TCS   = ui8TCS;           
            //T9CONbits.T32   = 0;
            IPC13bits.T9IP = ui8IP;
            IFS3bits.T9IF = 0;
            IEC3bits.T9IE = ui8IE;
            TMR9 = 0;
            PR9 = 0xFFFF;
            break;
        
        default:
            break;      
    };
}

void start16BitTimer(uint8_t ui8Timer)
{
    switch(ui8Timer)
    {
        case TIMER1:
            T1CONbits.TON = 1; //turn on timer
            break;

        case TIMER2:
            T2CONbits.TON = 1;
            break;
        
        case TIMER3:
            T3CONbits.TON = 1;
            break;
        
        case TIMER4:
            T4CONbits.TON = 1;
            break;
        
        case TIMER5:
            T5CONbits.TON = 1;
            break;
        
        case TIMER6:
            T6CONbits.TON = 1;
            break;
        
        case TIMER7:
            T7CONbits.TON = 1;
            break;
        
        case TIMER8:
            T8CONbits.TON = 1;
            break;
        
        case TIMER9:
            T9CONbits.TON = 1;
            break;
        
        default:
            break;      
    };
}

void stop16BitTimer(uint8_t ui8Timer)
{
    switch(ui8Timer)
    {
        case TIMER1:
            T1CONbits.TON = 0; //turn off timer
            break;

        case TIMER2:
            T2CONbits.TON = 0;
            break;
        
        case TIMER3:
            T3CONbits.TON = 0;
            break;
        
        case TIMER4:
            T4CONbits.TON = 0;
            break;
        
        case TIMER5:
            T5CONbits.TON = 0;
            break;
        
        case TIMER6:
            T6CONbits.TON = 0;
            break;
        
        case TIMER7:
            T7CONbits.TON = 0;
            break;
        
        case TIMER8:
            T8CONbits.TON = 0;
            break;
        
        case TIMER9:
            T9CONbits.TON = 0;
            break;
        
        default:
            break;      
    };
}

void setPeriodRegister16BitTimer(uint8_t ui8Timer, uint16_t ui16PeriodValue)
{
    switch(ui8Timer)
    {
        case TIMER1:
            PR1 = ui16PeriodValue;
            break;

        case TIMER2:
            PR2 = ui16PeriodValue;
            break;
        
        case TIMER3:
            PR3 = ui16PeriodValue;
            break;
        
        case TIMER4:
            PR4 = ui16PeriodValue;
            break;
        
        case TIMER5:
            PR5 = ui16PeriodValue;
            break;
        
        case TIMER6:
            PR6 = ui16PeriodValue;
            break;
        
        case TIMER7:
            PR7 = ui16PeriodValue;
            break;
        
        case TIMER8:
            PR8 = ui16PeriodValue;
            break;
        
        case TIMER9:
            PR9 = ui16PeriodValue;
            break;
        
        default:
            break;      
    };
}

void disableInterrupt16BitTimer(uint8_t ui8Timer)
{
    switch(ui8Timer)
    {
        case TIMER1:
            _T1IE = 0;
            break;

        case TIMER2:
            _T2IE = 0;
            break;
        
        case TIMER3:
            _T3IE = 0;
            break;
        
        case TIMER4:
            _T4IE = 0;
            break;
        
        case TIMER5:
            _T5IE = 0;
            break;
        
        case TIMER6:
            _T6IE = 0;
            break;
        
        case TIMER7:
            _T7IE = 0;
            break;
        
        case TIMER8:
            _T8IE = 0;
            break;
        
        case TIMER9:
            _T9IE = 0;
            break;
        
        default:
            break;      
    };
}

void enableInterrupt16BitTimer(uint8_t ui8Timer)
{
    switch(ui8Timer)
    {
        case TIMER1:
            _T1IE = 1;
            break;

        case TIMER2:
            _T2IE = 1;
            break;
        
        case TIMER3:
            _T3IE = 1;
            break;
        
        case TIMER4:
            _T4IE = 1;
            break;
        
        case TIMER5:
            _T5IE = 1;
            break;
        
        case TIMER6:
            _T6IE = 1;
            break;
        
        case TIMER7:
            _T7IE = 1;
            break;
        
        case TIMER8:
            _T8IE = 1;
            break;
        
        case TIMER9:
            _T9IE = 1;
            break;
        
        default:
            break;      
    };
}

void clearInterruptFlag16BitTimer(uint8_t ui8Timer)
{
    switch(ui8Timer)
    {
        case TIMER1:
            _T1IF = 0;
            break;

        case TIMER2:
            _T2IF = 0;
            break;
        
        case TIMER3:
            _T3IF = 0;
            break;
        
        case TIMER4:
            _T4IF = 0;
            break;
        
        case TIMER5:
            _T5IF = 0;
            break;
        
        case TIMER6:
            _T6IF = 0;
            break;
        
        case TIMER7:
            _T7IF = 0;
            break;
        
        case TIMER8:
            _T8IF = 0;
            break;
        
        case TIMER9:
            _T9IF = 0;
            break;
        
        default:
            break;      
    };
}
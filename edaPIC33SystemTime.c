
#include <stdint.h>
#include <xc.h> 
#include "edaPIC33SystemTime.h"
#include "edaPIC33Hardware.h"

volatile uint32_t ui32SystemTimeMillis = 0; //global variable for SystemTime in millis
volatile uint8_t ui8SystemTimeMillisAccesFlag = 0;
volatile uint8_t ui8SystemTimeMillisConflictFlag = 0; 

/*
volatile uint32_t ui32SystemTimeSeconds = 0; //global variable for SystemTime in millis
volatile uint8_t ui8SystemTimeSecondsAccesFlag = 0;
volatile uint8_t ui8SystemTimeSecondsConflictFlag = 0; 
*/

/** Doxygen Template 
 * @brief
 * @param
 * @return 
 * @details
 * @attention
 */

/** 
 * @brief Configures the Timer 1 to interrupts each ms
 * @details PR1 can be calculated: Fco/(2*Prescaler*1000)-1 for Interrupts each ms
 * @param uint8_t ui8Port   Number of the Port to configure.
 */
void configSystemTimeMillis()
{
    T1CONbits.TON = 0; // Disable Timer
    T1CONbits.TCS = 0; // Select internal instruction cycle clock
    T1CONbits.TGATE = 0; // Disable Gated Timer mode
    T1CONbits.TCKPS = 0b01; // Select 1:8 Prescaler
    TMR1 = 0x00; // Clear timer register
    PR1 = 8750-1; // Load the period value //TODO CALIBRATE NEW 140Mhz: 8750-1 / 120Mhz: 7500-1
    IPC0bits.T1IP = 0x01; // Set Timer 1 Interrupt Priority Level
    IFS0bits.T1IF = 0; // Clear Timer 1 Interrupt Flag
    IEC0bits.T1IE = 1; // Enable Timer1 interrupt
    T1CONbits.TON = 1; // Start Timer
}

/** 
 * @brief Timer1 ISR Interrupt Service Routine
 * @details This Interrupt is executed each ms, when timer1 is well configured
 * @attention Interrupt enable Flag IEC0bits.T1IE has set to 1 to enable Interrupts.
 */
void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    ui32SystemTimeMillis++;  //increase millis counter
    //LATBbits.LATB8=!LATBbits.LATB8; //toggle LED0
    if (ui8SystemTimeMillisAccesFlag == 1)
        ui8SystemTimeMillisConflictFlag = 1;
    else
        ui8SystemTimeMillisConflictFlag = 0;

    IFS0bits.T1IF = 0;      //Clear Timer1 interrupt flag
}


/**
 * @brief System Time Millis
 * @return uint32_t ui32Millis milli Seconds since last reset
 * @details Function returns ms since the last reset
 * @attention   pinMode is not implemented for all pins (right now)
 */   
uint32_t getSystemTimeMillis()
{
    uint32_t ui32ReturnValue=0;
    static uint32_t ui32OldValue=0; 
            
    ui8SystemTimeMillisAccesFlag = 1;
    ui32ReturnValue = ui32SystemTimeMillis;
    ui8SystemTimeMillisAccesFlag = 0;
    
    if(ui8SystemTimeMillisConflictFlag ==1)
    {
        ui8SystemTimeMillisConflictFlag=0;
        ui32ReturnValue =  ui32OldValue;
    }
    
    ui32OldValue = ui32ReturnValue;
    
    return ui32ReturnValue;
}

/** 
 * @brief clear System Time Millis
 * @details functions clears the system time ms counter (set to zero)
 * @attention functions can change the timing
 */   
void clearSystemTimeMillis()
{          
    ui8SystemTimeMillisAccesFlag = 1;
    ui32SystemTimeMillis=0;
    ui8SystemTimeMillisAccesFlag = 0;
    
    if(ui8SystemTimeMillisConflictFlag ==1)
    {
        ui8SystemTimeMillisConflictFlag=0;
        ui32SystemTimeMillis= 0;
    }
}


/*
uint32_t getSystemTimeSeconds()
{
    uint32_t ui32ReturnValue=0;
    static uint32_t ui32OldValue=0; 
            
    ui8SystemTimeSecondsAccesFlag = 1;
    ui32ReturnValue = ui32SystemTimeSeconds;
    ui8SystemTimeSecondsAccesFlag = 0;
    
    if(ui8SystemTimeSecondsConflictFlag ==1)
    {
        ui8SystemTimeSecondsConflictFlag=0;
        ui32ReturnValue =  ui32OldValue;
    }
    
    ui32OldValue = ui32ReturnValue;
    
    return ui32ReturnValue;
}

void configSystemTimeSeconds()
{
    RPINR3bits.T3CKR=0b0111110;
    T3CONbits.TON = 0; // Disable Timer
    T3CONbits.TCS = 1; // Select external oszillator
    T3CONbits.TGATE = 0; // Disable Gated Timer mode

    T3CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
    
    TMR3 = 0x00; // Clear timer register
    PR3 = 32000; // Load the period value
    IPC2bits.T3IP = 0x01; // Set Timer 1 Interrupt Priority Level
    IFS0bits.T3IF = 0; // Clear Timer 1 Interrupt Flag
    IEC0bits.T3IE = 1; // Enable Timer1 interrupt
    T3CONbits.TON = 1; // Start Timer
}

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void)
{
    ui32SystemTimeSeconds++;  //increase millis counter

    if (ui8SystemTimeSecondsAccesFlag == 1)    //if acces flag=1, set config flag
       ui8SystemTimeSecondsConflictFlag = 1;
    else
        ui8SystemTimeSecondsConflictFlag = 0;

    IFS0bits.T3IF = 0;      //Clear Timer3 interrupt flag
}
*/
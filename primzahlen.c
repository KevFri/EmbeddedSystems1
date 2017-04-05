/** 
 * @file   HelloWorld2.c
 * @author JS
 *
 * @date 26.08.2015, 12:43
 * 
 * @brief Getting started with a simple program (blinking LED)
 */



// Check for Project Settings
#ifndef __dsPIC33EP512MU810__
    #error "Wrong Controller"
#endif

/* ***********************
 * Includes
 * ***********************
 */


#include <xc.h>         //Include appropriate controller specific headers
#include <stdint.h>     //Standard typedefs
#include <stdlib.h>
#include<math.h>


/* ***********************
 * Configuration Bits
 * ***********************
 */

/*
 * Oscillator Configuration
 *  (XC16 Compiler User's Guide, P. 109,
 *  33EP512MU810.html, p33EP512MU810.h, )
 * Alternative: #pragma directives
 */

// old
//_FOSCSEL(FNOSC_FRC); //Initial Oscillator:  Internal Fast RC
//_FOSC(POSCMD_NONE);  //Primary Oscillator disabled (quartz not used)

// old
_FOSCSEL(FNOSC_PRIPLL); //Initial Oscillator: Primary Oscillator (XT, HS, EC) with PLL
_FOSC(POSCMD_HS);  //HS Crystal Oscillator Mode



/* ***********************
 * Defines
 * ***********************
 */

/* Substitute for stdlib.h */
#define	EXIT_SUCCESS	0
#define	EXIT_FAILURE	1

/* Hardware  */
#define _LED200 LATBbits.LATB8

/* ***********************
 * Prototypes
 * ***********************
 */

void delay_ms(uint16_t u16milliseconds);
uint8_t isPrim(uint32_t ui32Number);

/* ***********************
 * Definitions
 * ***********************
 */

/** 
 * @brief Provides u16milliseconds delay
 * @param u16milliseconds Delay in milliseconds
 * @details u16milliseconds=0 causes 65536 ms delay
 * @pre 7.37 MHz (Internal Fast RC), e. g.: <br>
 * _FOSCSEL(FNOSC_FRC); //Initial Oscillator:  Internal Fast RC <br>
 * _FOSC(POSCMD_NONE);  //Primary Oscillator disabled (quartz not used) <br>
 * s. 7.37 MHz DS70216C-page 39-19 <br>
 * @attention Code has to be changed if a different oscillator frequency is used.
 */
void delay_ms(uint16_t u16milliseconds){
    uint16_t ui16_i=0;
    while(u16milliseconds){
        for (ui16_i=0;ui16_i<331;ui16_i++){    //1 ms delay loop
            __asm__ volatile("nop \n\t"
                             "nop \n\t"
                             "nop \n\t");
        }//for
        u16milliseconds--;
    }//while

}
/* ***********************
 * Main
 * ***********************
 */


/**
 * Hello World (Blinking LED)
 * @brief Toggles LED200 with 1 Hz, 1:1 duty cycle
 */

int main() {    //scope_25 47,8ms

    PLLFBD = 418;
    CLKDIVbits.PLLPOST = 2;
    CLKDIVbits.PLLPRE = 2;
    
    /* Port Configurations */
    // DS70616G-page 209
    // ODCB (open drain config) unimplemented (DS70616G, Table 4-56)
    ANSELBbits.ANSB8=0;     //Digital I/O
    CNENBbits.CNIEB8=0;     //Disable change notification interrupt
    CNPUBbits.CNPUB8=0;     //Disable weak pullup
    CNPDBbits.CNPDB8=0;     //Disable weak pulldown
    TRISBbits.TRISB8=0;     //Pin B8: Digital Output
    LATBbits.LATB8=0;       //Pin B8: Low
    _LED200 = 1;
    //uint32_t    ui32Var1=2;
    //uint32_t    ui32Var2=2;
    //uint32_t    ui32Var3=2;
    while (OSCCONbits.LOCK!= 1);
    /* Endless Loop */
    
    uint32_t ui32Number= 1000000;     //start value
    uint16_t ui8PrimeCounter=0;       //counts the number of calculated prime numbers
    const uint16_t ui8PrimMax=10;
    
    while(1){

    _LED200=1;      //hard on/off 28,5ns  scope_15
        
    ui32Number= 1000000;     //start value
    ui8PrimeCounter=0;       //counts the number of calculated prime numbers
    //ui8PrimMax=10;

    for(; ui8PrimeCounter<ui8PrimMax; ui32Number++)
        if(isPrim(ui32Number)) //check if the number is prime
        {
            //printf("%d\t%d\n",ui8PrimeCounter,ui32Number);
            ui8PrimeCounter++; //increase PrimeCounter, if the number is prime
        }
        
        _LED200=0; 
        delay_ms(500);
       
    }//while
    
    return (EXIT_SUCCESS);  //never reached
} //main()

uint8_t isPrim(uint32_t ui32Number){

    if(ui32Number==0 || ui32Number==1)
        return 0;

    
    if((ui32Number%2)==0)
    {
        if(ui32Number==2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    uint32_t ui32Divider;
    uint32_t ui32SqrtNumber =((uint32_t) sqrt((long double)(ui32Number)))+1;

    for(ui32Divider=3; ui32Divider<ui32SqrtNumber; ui32Divider+=2)
    {
        if((ui32Number%ui32Divider) == 0) //check if ui32Divider is a in whole divider of ui32Number
        {
            return 0; //uiNumber32 isn't a prime number
        }
    }
    return 1; //ui32Number is a Prime Number
}
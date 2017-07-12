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

int main() {

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
    
    int32_t i32Var1;
    int32_t i32Var2;
    int32_t i32Var3;
    
    
    
    while(1){
        //_LED200=!_LED200;
        /* LATBbits.LATB8 = !(LATBbits.LATB8); //Toggle Pin B8 */
        i32Var1 = rand();
        i32Var2 = rand();
        _LED200=1;      //hard on/off 28,5ns  scope_15
        
        
        _LED200=0; 
     
        //uint8_t
        /*
         Addition 72,5ns
         Subtraktion    86,9ns
         Multiplikation 100,9ns
         Division   101,3ns
         */
        
        
        //ui16Var3 = ui16Var1 + ui16Var2; //72ns scope_23      
        //ui16Var1 += ui16Var2; // 58ns
        
        //ui16Var3 = ui16Var1 - ui16Var2; //72,5ns
        //ui16Var1 -= ui16Var2; //58ns
        
        //ui16Var3 = ui16Var1 * ui16Var2; //87ns
        //ui16Var3 *= ui16Var1; //87ns
  
        //ui16Var3 = ui16Var1 / ui16Var2; //358ns
        //ui16Var1 /= ui16Var2; //357,5ns
        
        //ui16Var3 = ui16Var1 % ui16Var2; //372ns
        //ui16Var3 %= ui16Var1; //372,5ns
        
        
        
        //ui32Var3 = ui32Var1 + ui32Var2; //144ns scope_11      
        //ui32Var1 += ui32Var2; // 88ns scope_12
        
        //ui32Var3 = ui32Var1 - ui32Var2; //144ns scope_14
        //ui32Var1 -= ui32Var2; //101ns scope_16
        
        //ui32Var3 = ui32Var1 * ui32Var2; //258,5ns scope_17
        //ui32Var3 *= ui32Var1; //258ns scope_18
  
        //ui32Var3 = ui32Var1 / ui32Var2; // 7,57us scope_19
        //ui32Var3 /= ui32Var1; //7,57us
        
        //ui32Var3 = ui32Var1 % ui32Var2; // 7,75us scope_20
        //ui32Var3 %= ui32Var1; //142,5us //7,74us
        
        //int8_t
        /*
         Addition 86,5ns
         Subtraktion 86,5ns
         Multiplikation 101ns
         Division   373ns
         */
        
        //int16_t
        /*
         Addition 72,5ns
         Subtraktion 72,5ns
         Multiplikation 116,5ns
         Division   359ns
         */
        
        /*
        _LED200=1;
        
        i32Var3 = i32Var1 + i32Var2; //172ns scope_11      
        
        i32Var3 = i32Var1 - i32Var2; //142ns scope_14

        i32Var3 = i32Var1 * i32Var2; //260ns

        i32Var3 = i32Var1 / i32Var2; // 7,98us
        
        _LED200=0;
        */
         
        //int64_t        
        /*
         Addition 282ns
         Subtraktion 256ns
         Multiplikation 1,53us
         Division   130us
         */
        
       // delay_ms(500);
       
                
                
    }//while
    
    return (EXIT_SUCCESS);  //never reached
} //main()

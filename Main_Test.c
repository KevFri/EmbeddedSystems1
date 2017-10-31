/** 
 * @file   PWM_Main.c
 * @author Kevin Fritz
 *
 * @date 26.04.2017, 18:14
 */



// Check for Project Settings
#ifndef __dsPIC33EP512MU810__
    #error "Wrong Controller"
#endif

/* ***********************
 * Includes
 * ***********************
 */

#include <xc.h>                 //Include appropriate controller specific headers
#include <stdint.h>             //Standard typedefs
#include <stdio.h>              //Standard IO Library
#include "edaPIC33Hardware.h"   //edaPIC33 Hardware Library
#include "edaPIC33SystemTime.h" //edaPIC33 System Time Library, verwendet Timer1!
#include "edaPIC33Oscillator.h" //Oscillator Library, konfiguriert Oscillator
#include "edaPIC33LCD.h"        //edaPIC33 LCD Library
#include "edaPIC33OtherStuff.h" //other Functions
#include "edaPIC33Setup.h"      //setup library for EDAPIC33 Board
#include "edaPIC33OutputCompare.h"
#include "edaPIC33ADC.h"
#include "edaPIC33UART1.h"


/* ***********************
 * Configuration Bits
 * ***********************
 */

/* ***********************
 * Defines
 * ***********************
 */

/* Substitute for stdlib.h */
#define	EXIT_SUCCESS	0
#define	EXIT_FAILURE	1

//#define CTS _RF12
//#define RTS _RF13
#define TRTS TRISFbits.TRISF13


/* ***********************
 * Prototypes
 * ***********************
 */
void initU2(void);

int putU2(int c);

char getU2(void);

int putU1(int c);
char getU1(void);

char putUart1(char c);

void putsU1(char* s);

char* getsnU1( char *s, int len);

/* ***********************
 * Definitions
 * ***********************
 */
/*String used in edaPIC33LCD Library*/
extern char DataString[32];
char str[16];
char szRX[32];
char szTX[32];

/* ***********************
 * Main
 * ***********************
 */
/**
 * Main Function
 */
int main() {
    
    //config oscillator PLL with external 8Mhz crystal to F_OSC = 140MHz
    configOscillator();

    InitU1();
    char c;
    
    //setup pinMode for switches, led, LCD, rotatory encode,...
    setupEdaPIC33Board();

    
    
    //config timer 1 for getSystemTimeMillis();)
    configSystemTimeMillis();
    uint32_t ui32Time= getSystemTimeMillis(); //Variable used for time calculation
    
    
    setLCDLine("Hallo i bims!",1);
            
    setLCDLine("Test LCD Line",2);
    
    putsU1("Hallo i bims 1 Startstring vong niceigkeit her amk");
  
    
    /* Endless Loop */
    while(1){
        
        
        /*
        c = getU1();
        if(c!=0)
        {
            putU1( c);
            sprintf(str,"last char: %c %x", c,c);
            setLCDLine(str,1);
        }
        */
        
        getsnU1( szRX, 32);
        
        sprintf(szTX, "PIC: %s",szRX);
        putsU1(szTX);
        
        
        sendDataToLCD(); //send one character from LCD-Storage (Shadow-String) to LCD
        ui32Time++; //increase ms counter
        while(getSystemTimeMillis() < ui32Time) //wait rest of 1ms
        {
            //sendDataToLCD();
            ClrWdt();   //clear watchdog timer
        }
    }//while
    return (EXIT_SUCCESS);  //never reached
} //main()



/*
void initU2(void)
{
    U2BRG = 34; //115200 Baud
    U2MODE = 0x8008; //enable the UART peripheral
    U2STA = 0x0400; //enable transmission
    //RTS = 1;
    TRTS = 0;
}

int putU2(int c)
{
    //while(CTS);             //wait for !CTS clear to send
    while(U2STAbits.UTXBF); //wait while Tx buffer full
    U2TXREG = c;
    return c;
}

char getU2(void)
{
    //RTS = 0;                    //assert Request to send
    while(!U2STAbits.URXDA);    //wait
    //RTS = 1;
    return U2RXREG;             //red from the recieve buffer
}
*/



int putU1(int c)
{
    //while(CTS);             //wait for !CTS clear to send
    while(U1STAbits.UTXBF); //wait while Tx buffer full
    U1TXREG = c;
    return c;
}

char getU1(void)
{
    //RTS = 0;                    //assert Request to send
    while(!U1STAbits.URXDA);
        //return 0;    //wait
    //RTS = 1;
    return U1RXREG;             //red from the recieve buffer
}


char putUart1(char c)
{
    //while(CTS);             //wait for !CTS clear to send
    while(U1STAbits.UTXBF); //wait while Tx buffer full
    U1TXREG = c;
    return c;
}

void putsU1( char *s)
{
    while( *s) // loop until *s == '\0' the end of the string
    putU1( *s++); // send the character and point to the next one
    putU1( '\r'); // terminate with a cr / line feed
    putU1( '\n');
} // putsU2


char *getsnU1( char *s, int len)
{
    char *p = s; // copy the buffer pointer
    do{
        *s = getU1(); // wait for a new character

        if ( *s=='\r') // end of line, end loop
            break;
        s++; // increment buffer pointer
        len--;
    } while ( len>1 ); // until buffer full
    *s = '\0'; // null terminate the string
    return p; // return buffer pointer
} // getsnU2
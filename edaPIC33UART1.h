/* 
 * File:   edaPIC33Oscillator.h
 * Author: Kevin
 *
 * Created on 26. April 2017, 18:15
 */

#ifndef EDAPIC33UART1_H
#define	EDAPIC33UART1_H

#include<xc.h>
#include<stdint.h>

//select external oscillator with 8mhz



/** 
 * @brief config Oscillator with extern 8Mhz Crystal to Fosc=140Mhz
 * @attention Function has to be called at first in main 
 */
void InitUART1( void );

int putU1(int c);

char getU1(void);

void putsU1(char* s);

char* getsnU1( char *s, int len);

/*
void __attribute__ ( (interrupt, no_auto_psv) ) _U1RXInterrupt( void )
{
    LATA = U1RXREG;
    IFS0bits.U1RXIF = 0;
}

void __attribute__ ( (interrupt, no_auto_psv) ) _U1TXInterrupt( void )
{
    IFS0bits.U1TXIF = 0;
}
*/


void InitUART1(void)
{
    U1BRG = 150;
    U1MODE = 0x8008;
    U1STA = 0x0400;
    //RTS = 1; // set RTS default status
    //TRTS = 0; // make RTS output
} // InitU2

int putU1(int c)
{
    //while(CTS);             //wait for !CTS clear to send
    while(U1STAbits.UTXBF); //wait while Tx buffer full
    U1TXREG = c;
    return c;
}

char getU1(void)
{
    //RTS = 0;                      //assert Request to send
    while(!U1STAbits.URXDA);        //wait
    //RTS = 1;
    return U1RXREG;             //red from the recieve buffer
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
#endif
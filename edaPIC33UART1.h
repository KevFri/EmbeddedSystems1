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

//char psUart1ReadBuffer[256];

//volatile uint8_t ui8Uart1ReadBufferCounter = 0; //global variable for Uart 1 Buffer

void clrUart1ReadBufferCounter( void );

uint8_t getUart1ReadBufferCounter();

void __attribute__ ( (interrupt, no_auto_psv) ) _U1RXInterrupt( void );

void clrUart1ReadBuffer(void);


void initUart1(void);

char putCharUart1(char c);

void putStrUart1(char *pStr);

uint8_t getUart1NewMessageFlag( void );

char* getNewMsgUart1(char* pMsg);

/* unused function, blocking code!
char getCharUart1(void)
{
    while(!U1STAbits.URXDA);        //wait !!
    
    return U1RXREG;             //red from the recieve buffer
}
*/

#endif
#include<xc.h>
#include<stdint.h>
#include"edaPIC33UART1.h"

char psUart1ReadBuffer[256];

volatile uint8_t ui8Uart1ReadBufferCounter = 0; //global variable for Uart 1 Buffer

volatile uint8_t ui8Uart1NewMessageFlag = 0;

void clrUart1ReadBufferCounter( void )
{
    ui8Uart1ReadBufferCounter = 0;
}

uint8_t getUart1ReadBufferCounter()
{
    return ui8Uart1ReadBufferCounter;
}

uint8_t getUart1NewMessageFlag( void )
{
    return ui8Uart1NewMessageFlag;
}

void clrUart1NewMessageFlag( void )
{
    ui8Uart1NewMessageFlag = 0;
}

void __attribute__ ( (interrupt, no_auto_psv) ) _U1RXInterrupt( void )
{
    while(U1STAbits.URXDA)
        psUart1ReadBuffer[ui8Uart1ReadBufferCounter] = U1RXREG;

    if(psUart1ReadBuffer[ui8Uart1ReadBufferCounter] == 0x0D)
        ui8Uart1NewMessageFlag = 1;
    
    ui8Uart1ReadBufferCounter++;
    
    IFS0bits.U1RXIF = 0;
}

void clrUart1ReadBuffer(void)
{
    uint16_t i;
    for(i=0; i<=256; i++)
        psUart1ReadBuffer[i]='_';
    
    ui8Uart1ReadBufferCounter=0;
    
    clrUart1NewMessageFlag();
}


void initUart1(void)
{
    U1BRG = 150;
    U1MODE = 0x8008;
    U1STA = 0x0400;
    U1STAbits.URXISEL = 0b00;
    
    IPC7 = 0x4400;        // Mid Range Interrupt Priority level, no urgent reason
    IFS0bits.U1RXIF = 0;  // Clear the Recieve Interrupt Flag
    IEC0bits.U1RXIE = 1;  // Enable Recieve Interrupts
    //U1MODEbits.UARTEN = 1;// Turn the UART1 peripheral on
    
    
}

char putCharUart1(char c)
{
    //while(CTS);             //wait for !CTS clear to send
    while(U1STAbits.UTXBF); //wait while Tx buffer full
    U1TXREG = c;
    return c;
}

/* unused function, blocking code!
char getCharUart1(void)
{
    while(!U1STAbits.URXDA);        //wait !!
    
    return U1RXREG;             //red from the recieve buffer
}
*/


void putStrUart1( char *pStr)
{
    while( *pStr) // loop until *s == '\0' the end of the string
        putCharUart1(*pStr++); // send the character and point to the next one
    
    putCharUart1(0x0D); // terminate with a cr
    //putCharUart1( '\r'); 
    //putCharUart1( '\n');
}


char* getNewMsgUart1(char* pMsg)
{
    uint8_t ui8Counter = 0;
    
    for(ui8Counter = 0; psUart1ReadBuffer[ui8Counter] != '\0'; ui8Counter++)
        pMsg[ui8Counter] = psUart1ReadBuffer[ui8Counter];
    
    return pMsg;
}
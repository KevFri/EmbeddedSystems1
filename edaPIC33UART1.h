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

void InitUART1( void )
{
    // This is an EXAMPLE, so brutal typing goes into explaining all bit sets
    // The HPC16 board has a DB9 connector wired to UART2, so we will
    // be configuring this port only
    // configure U1MODE
    U1MODEbits.UARTEN = 0;      // Bit15 TX, RX DISABLED, ENABLE at end of func

    //U1MODEbits.notimplemented;// Bit14
    U1MODEbits.USIDL = 0;       // Bit13 Continue in Idle
    U1MODEbits.IREN = 0;        // Bit12 No IR translation
    U1MODEbits.RTSMD = 0;       // Bit11 Simplex Mode

    //U1MODEbits.notimplemented;// Bit10
    U1MODEbits.UEN = 0;         // Bits8,9 TX,RX enabled, CTS,RTS not
    U1MODEbits.WAKE = 0;        // Bit7 No Wake up (since we don't sleep here)
    U1MODEbits.LPBACK = 0;      // Bit6 No Loop Back
    U1MODEbits.ABAUD = 0;       // Bit5 No Autobaud (would require sending '55')
    U1MODEbits.BRGH = 0;        // Bit3 16 clocks per bit period
    U1MODEbits.PDSEL = 0;       // Bits1,2 8bit, No Parity
    U1MODEbits.STSEL = 0;       // Bit0 One Stop Bit

    // Load a value into Baud Rate Generator.  Example is for 9600.
    // See section 19.3.1 of datasheet.
    //  U1BRG = (Fcy/(16*BaudRate))-1
    //  U1BRG = (37M/(16*9600))-1
    // U1BRG = 240;
    U1BRG = 150;                // 140Mhz osc, 115200 Baud

    // Load all values in for U1STA SFR
    U1STAbits.UTXISEL1 = 1;     //Bit15 Int when Char is transferred (1/2 config!)
    U1STAbits.UTXINV = 0;       //Bit14 N/A, IRDA config
    U1STAbits.UTXISEL0 = 1;     //Bit13 Other half of Bit15

    //U1STAbits.notimplemented = 0;//Bit12
    U1STAbits.UTXBRK = 0;       //Bit11 Disabled
    U1STAbits.UTXEN = 0;        //Bit10 TX pins controlled by periph
    U1STAbits.UTXBF = 0;        //Bit9 *Read Only Bit*
    U1STAbits.TRMT = 0;         //Bit8 *Read Only bit*
    U1STAbits.URXISEL = 0;      //Bits6,7 Int. on character recieved
    U1STAbits.ADDEN = 0;        //Bit5 Address Detect Disabled
    U1STAbits.RIDLE = 0;        //Bit4 *Read Only Bit*
    U1STAbits.PERR = 0;         //Bit3 *Read Only Bit*
    U1STAbits.FERR = 0;         //Bit2 *Read Only Bit*
    U1STAbits.OERR = 0;         //Bit1 *Read Only Bit*
    U1STAbits.URXDA = 0;        //Bit0 *Read Only Bit*
    IPC7 = 0x4400;              // Mid Range Interrupt Priority level, no urgent reason
    IFS0bits.U1TXIF = 0;        // Clear the Transmit Interrupt Flag
    IEC0bits.U1TXIE = 0;        // Disable Transmit Interrupts
    IFS0bits.U1RXIF = 0;        // Clear the Recieve Interrupt Flag
    IEC0bits.U1RXIE = 0;        // Disable Recieve Interrupts
    RPOR9 = 0;
    RPOR9bits.RP101R = 1;       //RF5/RP101 as U1TX
    RPINR18bits.U1RXR = 100;    //RP100/RF4 as U1RX
    U1MODEbits.UARTEN = 1;      // And turn the peripheral on
    U1STAbits.UTXEN = 1;
    IFS0bits.U1TXIF = 0;
}

void InitU1( void)
{
    U1BRG = 150;
    U1MODE = 0x8008;
    U1STA = 0x0400;
    //RTS = 1; // set RTS default status
    //TRTS = 0; // make RTS output
} // InitU2



/* configuration for internal Oscillator
 // Select Internal FRC at POR
_FOSCSEL(FNOSC_FRC & IESO_OFF);
// Enable Clock Switching and Configure Primary Oscillator in XT mode
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE);



void configOscillator()
{   //configuration for 120MHz:
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD=74; // 120Mhz:63 / 140Mhz:74
    CLKDIVbits.PLLPOST=0; // N2=2
    CLKDIVbits.PLLPRE=0; // N1=2
    
    // Initiate Clock Switch to FRC oscillator with PLL (NOSC=0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(OSCCON | 0x01);
    
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC!= 0b001);
    // Wait for PLL to lock
    while (OSCCONbits.LOCK!= 1);
}
 */

#endif
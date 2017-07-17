#include "edaPIC33ADC.h"
#include"edaPIC33Hardware.h"
#include <stdint.h>
#include <xc.h>


void initADC1()
{   //Automatic Sample and Manual Conversion 10Bit Mode
    AD1CON1 = 0x0004;
    AD1CON2 = 0x0000;
    AD1CON3 = 0x000F;
    AD1CON4 = 0x0000;
    AD1CHS123 = 0x0000;
    AD1CSSH = 0x0000;
    AD1CSSL = 0x0000;
    AD1CON1bits.AD12B = 0; //select 12Bit Mode, 0:10Bit Mode, 1:12Bit Mode
    AD1CON1bits.ADON = 1;
    
    uint16_t i=0;
    for(i=0; i<1000; i++) Nop();
}

int16_t analogRead(uint8_t ui8Port)
{
    AD1CHS0 = getAnalogPortBitNumb(ui8Port);
    AD1CON1bits.SAMP=0;         //start sampling, automatic conversion will follow
    while(!AD1CON1bits.DONE);   //wait to complete conversion
    AD1CON1bits.DONE = 0;
    return ADC1BUF0;            //return conversion result
}

uint8_t getAnalogPortBitNumb(uint8_t Port)
{
    switch(Port)
    {
    	case AN0:     return 0;
        case AN1:     return 1;
        case AN2:     return 2;   
        case AN3:     return 3;
        case AN4:     return 4;
        case AN5:     return 5;
        case AN6:     return 6;
        case AN7:     return 7;
        case AN8:     return 8;
        case AN9:     return 9;
        case AN10:    return 10;
        case AN11:    return 11;
        case AN12:    return 12;
        case AN13:    return 13;
        case AN14:    return 14;
        case AN15:    return 15;
        case AN16:    return 16;
        case AN17:    return 17;        
        case AN18:    return 18;
        case AN19:    return 19;
        case AN20:    return 20;
        case AN21:    return 21;
        case AN22:    return 22;  
        case AN23:    return 23;
        case AN24:    return 24;
        case AN25:    return 25;
        case AN26:    return 26;
        case AN27:    return 27;
        case AN28:    return 28;
        case AN29:    return 29;
        case AN30:    return 30;
        case AN31:    return 31;
        default:      break;
    }
    return 0;
}

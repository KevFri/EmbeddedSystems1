/*
 * File:   edaPIC33Hardware.c
 * Author: Kevin Fritz
 *
 * Created on 4. April 2017, 10:41
 */
#include "edaPIC33Hardware.h"
#include <stdint.h>
void pinMode(uint8_t ui8Port, uint8_t ui8Mode)
{
    switch(ui8Port)
    {
        case LED0:
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                break;

            case OUTPUT:
                //configure output
                ANSELBbits.ANSB8=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB8=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB8=0;     //Disable weak pullup
                CNPDBbits.CNPDB8=0;     //Disable weak pulldown
                TRISBbits.TRISB8=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default: 
                break;
            }
        break;
        
        case LED1:
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                break;

            case OUTPUT:
                //configure output
                ANSELBbits.ANSB9=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB9=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB9=0;     //Disable weak pullup
                CNPDBbits.CNPDB9=0;     //Disable weak pulldown
                TRISBbits.TRISB9=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default: 
                break;
            }
        break;
        
        case LED2:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                break;

            case OUTPUT:
                //configure output
                ANSELBbits.ANSB10=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB10=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB10=0;     //Disable weak pullup
                CNPDBbits.CNPDB10=0;     //Disable weak pulldown
                TRISBbits.TRISB10=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default: 
                break;
            }
        break;
        
        case LED3:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                break;

            case OUTPUT:
                //configure output
                ANSELBbits.ANSB11=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB11=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB11=0;     //Disable weak pullup
                CNPDBbits.CNPDB11=0;     //Disable weak pulldown
                TRISBbits.TRISB11=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default: 
                break;
            }
        break;

        case SW0:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG12=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG12=0;     //Disable weak pullup
                    CNPDGbits.CNPDG12=0;     //Disable weak pulldown
                    TRISGbits.TRISG12=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG12=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG12=0;     //Disable weak pullup
                    CNPDGbits.CNPDG12=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG12=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG12=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG12=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG12=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG12=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG12=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG12=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG12=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG12=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
        
        case SW1:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG13=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG13=0;     //Disable weak pullup
                    CNPDGbits.CNPDG13=0;     //Disable weak pulldown
                    TRISGbits.TRISG13=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG13=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG13=0;     //Disable weak pullup
                    CNPDGbits.CNPDG13=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG13=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG13=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG13=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG13=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG13=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG13=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG13=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG13=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG13=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
            
        case SW2:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG14=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG14=0;     //Disable weak pullup
                    CNPDGbits.CNPDG14=0;     //Disable weak pulldown
                    TRISGbits.TRISG14=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG14=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG14=0;     //Disable weak pullup
                    CNPDGbits.CNPDG14=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG14=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG14=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG14=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG14=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG14=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG14=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG14=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG14=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG14=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
            
        case SW3:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG15=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG15=0;     //Disable weak pullup
                    CNPDGbits.CNPDG15=0;     //Disable weak pulldown
                    TRISGbits.TRISG15=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG15=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG15=0;     //Disable weak pullup
                    CNPDGbits.CNPDG15=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG15=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG15=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG15=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG15=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG15=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG15=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG15=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG15=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG15=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
    }
            
}
                
                



void digitalWrite(uint8_t ui8Port,uint8_t ui8Value)
{
    switch(ui8Port)
    {
        case LED0:
            if(ui8Value==LOW)
                LATBbits.LATB8=LOW;
            else
                LATBbits.LATB8=HIGH;
            break;
            
        case LED1:
            if(ui8Value==LOW)
                LATBbits.LATB9=LOW;
            else
                LATBbits.LATB9=HIGH;
            break;
            
        case LED2:
            if(ui8Value==LOW)
                LATBbits.LATB10=LOW;
            else
                LATBbits.LATB10=HIGH;
            
            break;
            
        case LED3:
            if(ui8Value==LOW)
                LATBbits.LATB11=LOW;
            else
                LATBbits.LATB11=HIGH;
            break;
            
        default:
            break;
    
    
    }
}

uint8_t digitalRead(uint8_t ui8Port)
{
    switch(ui8Port)
    {
        case SW0:
            return PORTGbits.RG12;
            break;
            
        case SW1:
            return PORTGbits.RG13;
            break;
            
        case SW2:
            return PORTGbits.RG14;
            break;
            
        case SW3:
            return PORTGbits.RG15;
            break;
            
        default:
            return 0;
            break;
    
    
    }
    
}
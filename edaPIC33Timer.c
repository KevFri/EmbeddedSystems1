/*
 * File:   edaPIC33Hardware.c
 * Author: Kevin Fritz
 *
 * Created on 4. April 2017, 10:41
 */
#include "edaPIC33Hardware.h"
#include <stdint.h>
void pinMode(const uint8_t ui8Port,const uint8_t ui8Mode)
{
    switch(ui8Port)
    {
        case LED0:
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELBbits.ANSB8=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB8=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB8=0;     //Disable weak pullup
                CNPDBbits.CNPDB8=0;     //Disable weak pulldown
                TRISBbits.TRISB8=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELBbits.ANSB8=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB8=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB8=0;     //Disable weak pullup
                CNPDBbits.CNPDB8=1;     //Disable weak pulldown
                TRISBbits.TRISB8=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELBbits.ANSB8=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB8=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB8=1;     //Disable weak pullup
                CNPDBbits.CNPDB8=0;     //Disable weak pulldown
                TRISBbits.TRISB8=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
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
                ANSELBbits.ANSB9=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB9=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB9=0;     //Disable weak pullup
                CNPDBbits.CNPDB9=0;     //Disable weak pulldown
                TRISBbits.TRISB9=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELBbits.ANSB9=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB9=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB9=0;     //Disable weak pullup
                CNPDBbits.CNPDB9=1;     //Disable weak pulldown
                TRISBbits.TRISB9=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELBbits.ANSB9=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB9=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB9=1;     //Disable weak pullup
                CNPDBbits.CNPDB9=0;     //Disable weak pulldown
                TRISBbits.TRISB9=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
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
                ANSELBbits.ANSB10=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB10=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB10=0;     //Disable weak pullup
                CNPDBbits.CNPDB10=0;     //Disable weak pulldown
                TRISBbits.TRISB10=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELBbits.ANSB10=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB10=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB10=0;     //Disable weak pullup
                CNPDBbits.CNPDB10=1;     //Disable weak pulldown
                TRISBbits.TRISB10=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                //configure input pullup
                ANSELBbits.ANSB10=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB10=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB10=1;     //Disable weak pullup
                CNPDBbits.CNPDB10=0;     //Disable weak pulldown
                TRISBbits.TRISB10=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
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
                ANSELBbits.ANSB11=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB11=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB11=0;     //Disable weak pullup
                CNPDBbits.CNPDB11=0;     //Disable weak pulldown
                TRISBbits.TRISB11=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    //configure input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELBbits.ANSB11=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB11=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB11=0;     //Disable weak pullup
                CNPDBbits.CNPDB11=1;     //Disable weak pulldown
                TRISBbits.TRISB11=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELBbits.ANSB11=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB11=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB11=1;     //Disable weak pullup
                CNPDBbits.CNPDB11=0;     //Disable weak pulldown
                TRISBbits.TRISB11=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
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

        case DIP0:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG6=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG6=0;     //Disable weak pullup
                    CNPDGbits.CNPDG6=0;     //Disable weak pulldown
                    TRISGbits.TRISG6=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG6=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG6=0;     //Disable weak pullup
                    CNPDGbits.CNPDG6=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG6=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG6=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG6=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG6=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG6=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG6=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG6=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG6=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG6=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
            
        case DIP1:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG7=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG7=0;     //Disable weak pullup
                    CNPDGbits.CNPDG7=0;     //Disable weak pulldown
                    TRISGbits.TRISG7=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG7=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG7=0;     //Disable weak pullup
                    CNPDGbits.CNPDG7=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG7=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG7=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG7=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG7=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG7=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG7=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG7=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG7=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG7=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
            
        case INCA:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG0=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG0=0;     //Disable weak pullup
                    CNPDGbits.CNPDG0=0;     //Disable weak pulldown
                    TRISGbits.TRISG0=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG0=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG0=0;     //Disable weak pullup
                    CNPDGbits.CNPDG0=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG0=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG0=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG0=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG0=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG0=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG0=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG0=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG0=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG0=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
            
        case INCB:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG1=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG1=0;     //Disable weak pullup
                    CNPDGbits.CNPDG1=0;     //Disable weak pulldown
                    TRISGbits.TRISG1=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG1=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG1=0;     //Disable weak pullup
                    CNPDGbits.CNPDG1=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG1=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG1=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG1=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG1=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG1=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG1=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG1=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG1=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG1=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
            
        case INCSW:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG9=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG9=0;     //Disable weak pullup
                    CNPDGbits.CNPDG9=0;     //Disable weak pulldown
                    TRISGbits.TRISG9=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG9=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG9=0;     //Disable weak pullup
                    CNPDGbits.CNPDG9=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG9=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG9=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG9=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG9=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG9=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG9=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG9=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG9=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG9=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
            
        case PIEZO:
            switch(ui8Mode) 
            {
                case INPUT:
                    //configure input
                    //ANSELBbits.ANSB8=0;   //unimplemented read as 0   //Digital I/O    0 for Digital / 1 for Analog
                    CNENGbits.CNIEG8=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG8=0;     //Disable weak pullup
                    CNPDGbits.CNPDG8=0;     //Disable weak pulldown
                    TRISGbits.TRISG8=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

                case INPUT_PULLDOWN:
                    //configure input pulldown
                    CNENGbits.CNIEG8=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG8=0;     //Disable weak pullup
                    CNPDGbits.CNPDG8=1;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG8=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case INPUT_PULLUP:
                    //configure input pullup  
                    CNENGbits.CNIEG8=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG8=1;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG8=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG8=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                case OUTPUT:
                    //configure output
                    CNENGbits.CNIEG8=0;     //Disable change notification interrupt
                    CNPUGbits.CNPUG8=0;     //pullup    0 off / 1 on
                    CNPDGbits.CNPDG8=0;     //pulldown  0 off / 1 on
                    TRISGbits.TRISG8=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                    break;

                default: 
                    break;
            }
            break;
            
        default:
            break;
    }
            
}
                
              
void digitalWrite(const uint8_t ui8Port,const uint8_t ui8Value)
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
            
        case PIEZO:
            if(ui8Value==LOW)
                LATGbits.LATG8=LOW;
            else
                LATGbits.LATG8=HIGH;
            break;
            
        default:
            break;      
    }
}


void digitalToggle(const uint8_t ui8Port)
{
    switch(ui8Port)
    {
        case LED0:
                LATBbits.LATB8=!(digitalRead(LED0));
            break;
            
        case LED1:
                LATBbits.LATB9=!(digitalRead(LED1));
            break;
            
        case LED2:
                LATBbits.LATB10=!(digitalRead(LED2));          
            break;
            
        case LED3:
                LATBbits.LATB11=!(digitalRead(LED3));
            break;
            
        case PIEZO:
                LATGbits.LATG8=!(digitalRead(PIEZO));
            break;
            
        default:
            break;      
    }
}

uint8_t digitalRead(const uint8_t ui8Port)
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
         
        case LED0:
            return PORTBbits.RB8;
            break;
            
        case LED1:
            return PORTBbits.RB9;
            break;
            
        case LED2:
            return PORTBbits.RB10;
            break;
            
        case LED3:
            return PORTBbits.RB11;
            break;
            
        case DIP0:
            return PORTGbits.RG6;
            break;
            
        case DIP1:
            return PORTGbits.RG7;
            break;

        case INCA:
            return PORTGbits.RG0;
            break;
            
        case INCB:
            return PORTGbits.RG1;
            break;
            
        case INCSW:
            return PORTGbits.RG9;
            break;
            
        case PIEZO:
            return PORTGbits.RG8;
            break;
        
        default:
            return 0;
            break;  
    }
}
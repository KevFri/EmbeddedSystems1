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
        
        case RE_0: //LCD_D0
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELEbits.ANSE0=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE0=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE0=0;     //Disable weak pullup
                CNPDEbits.CNPDE0=0;     //Disable weak pulldown
                TRISEbits.TRISE0=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELEbits.ANSE0=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE0=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE0=0;     //Disable weak pullup
                CNPDEbits.CNPDE0=1;     //Disable weak pulldown
                TRISEbits.TRISE0=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELEbits.ANSE0=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE0=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE0=1;     //Disable weak pullup
                CNPDEbits.CNPDE0=0;     //Disable weak pulldown
                TRISEbits.TRISE0=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELEbits.ANSE0=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE0=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE0=0;     //Disable weak pullup
                CNPDEbits.CNPDE0=0;     //Disable weak pulldown
                TRISEbits.TRISE0=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;    

        case RE_1: //LCD_D1
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELEbits.ANSE1=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE1=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE1=0;     //Disable weak pullup
                CNPDEbits.CNPDE1=0;     //Disable weak pulldown
                TRISEbits.TRISE1=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELEbits.ANSE1=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE1=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE1=0;     //Disable weak pullup
                CNPDEbits.CNPDE1=1;     //Disable weak pulldown
                TRISEbits.TRISE1=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELEbits.ANSE1=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE1=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE1=1;     //Disable weak pullup
                CNPDEbits.CNPDE1=0;     //Disable weak pulldown
                TRISEbits.TRISE1=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELEbits.ANSE1=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE1=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE1=0;     //Disable weak pullup
                CNPDEbits.CNPDE1=0;     //Disable weak pulldown
                TRISEbits.TRISE1=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;

        case RE_2: //LCD_D2
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELEbits.ANSE2=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE2=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE2=0;     //Disable weak pullup
                CNPDEbits.CNPDE2=0;     //Disable weak pulldown
                TRISEbits.TRISE2=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELEbits.ANSE2=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE2=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE2=0;     //Disable weak pullup
                CNPDEbits.CNPDE2=1;     //Disable weak pulldown
                TRISEbits.TRISE2=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELEbits.ANSE2=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE2=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE2=1;     //Disable weak pullup
                CNPDEbits.CNPDE2=0;     //Disable weak pulldown
                TRISEbits.TRISE2=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELEbits.ANSE2=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE2=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE2=0;     //Disable weak pullup
                CNPDEbits.CNPDE2=0;     //Disable weak pulldown
                TRISEbits.TRISE2=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;

        case RE_3: //LCD_D3
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELEbits.ANSE3=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE3=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE3=0;     //Disable weak pullup
                CNPDEbits.CNPDE3=0;     //Disable weak pulldown
                TRISEbits.TRISE3=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELEbits.ANSE3=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE3=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE3=0;     //Disable weak pullup
                CNPDEbits.CNPDE3=1;     //Disable weak pulldown
                TRISEbits.TRISE3=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELEbits.ANSE3=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE3=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE3=1;     //Disable weak pullup
                CNPDEbits.CNPDE3=0;     //Disable weak pulldown
                TRISEbits.TRISE3=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELEbits.ANSE3=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE3=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE3=0;     //Disable weak pullup
                CNPDEbits.CNPDE3=0;     //Disable weak pulldown
                TRISEbits.TRISE3=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;

        case RE_4: //LCD_D4
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELEbits.ANSE4=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE4=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE4=0;     //Disable weak pullup
                CNPDEbits.CNPDE4=0;     //Disable weak pulldown
                TRISEbits.TRISE4=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELEbits.ANSE4=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE4=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE4=0;     //Disable weak pullup
                CNPDEbits.CNPDE4=1;     //Disable weak pulldown
                TRISEbits.TRISE4=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELEbits.ANSE4=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE4=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE4=1;     //Disable weak pullup
                CNPDEbits.CNPDE4=0;     //Disable weak pulldown
                TRISEbits.TRISE4=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELEbits.ANSE4=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE4=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE4=0;     //Disable weak pullup
                CNPDEbits.CNPDE4=0;     //Disable weak pulldown
                TRISEbits.TRISE4=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;        

        case RE_5: //LCD_D5
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELEbits.ANSE5=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE5=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE5=0;     //Disable weak pullup
                CNPDEbits.CNPDE5=0;     //Disable weak pulldown
                TRISEbits.TRISE5=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELEbits.ANSE5=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE5=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE5=0;     //Disable weak pullup
                CNPDEbits.CNPDE5=1;     //Disable weak pulldown
                TRISEbits.TRISE5=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELEbits.ANSE5=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE5=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE5=1;     //Disable weak pullup
                CNPDEbits.CNPDE5=0;     //Disable weak pulldown
                TRISEbits.TRISE5=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELEbits.ANSE5=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE5=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE5=0;     //Disable weak pullup
                CNPDEbits.CNPDE5=0;     //Disable weak pulldown
                TRISEbits.TRISE5=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;        
        
        case RE_6: //LCD_D6
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELEbits.ANSE6=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE6=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE6=0;     //Disable weak pullup
                CNPDEbits.CNPDE6=0;     //Disable weak pulldown
                TRISEbits.TRISE6=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELEbits.ANSE6=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE6=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE6=0;     //Disable weak pullup
                CNPDEbits.CNPDE6=1;     //Disable weak pulldown
                TRISEbits.TRISE6=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELEbits.ANSE6=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE6=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE6=1;     //Disable weak pullup
                CNPDEbits.CNPDE6=0;     //Disable weak pulldown
                TRISEbits.TRISE6=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELEbits.ANSE6=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE6=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE6=0;     //Disable weak pullup
                CNPDEbits.CNPDE6=0;     //Disable weak pulldown
                TRISEbits.TRISE6=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;
        
        case RE_7: //LCD_D7
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELEbits.ANSE7=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE7=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE7=0;     //Disable weak pullup
                CNPDEbits.CNPDE7=0;     //Disable weak pulldown
                TRISEbits.TRISE7=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELEbits.ANSE7=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE7=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE7=0;     //Disable weak pullup
                CNPDEbits.CNPDE7=1;     //Disable weak pulldown
                TRISEbits.TRISE7=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELEbits.ANSE7=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE7=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE7=1;     //Disable weak pullup
                CNPDEbits.CNPDE7=0;     //Disable weak pulldown
                TRISEbits.TRISE7=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELEbits.ANSE7=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENEbits.CNIEE7=0;     //Disable change notification interrupt
                CNPUEbits.CNPUE7=0;     //Disable weak pullup
                CNPDEbits.CNPDE7=0;     //Disable weak pulldown
                TRISEbits.TRISE7=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;

        case RD_4: //LCD_E
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                //ANSELDbits.ANSD4=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENDbits.CNIED4=0;     //Disable change notification interrupt
                CNPUDbits.CNPUD4=0;     //Disable weak pullup
                CNPDDbits.CNPDD4=0;     //Disable weak pulldown
                TRISDbits.TRISD4=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                //ANSELDbits.ANSD4=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENDbits.CNIED4=0;     //Disable change notification interrupt
                CNPUDbits.CNPUD4=0;     //Disable weak pullup
                CNPDDbits.CNPDD4=1;     //Disable weak pulldown
                TRISDbits.TRISD4=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                //ANSELDbits.ANSD4=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENDbits.CNIED4=0;     //Disable change notification interrupt
                CNPUDbits.CNPUD4=1;     //Disable weak pullup
                CNPDDbits.CNPDD4=0;     //Disable weak pulldown
                TRISDbits.TRISD4=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                //ANSELDbits.ANSD4=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENDbits.CNIED4=0;     //Disable change notification interrupt
                CNPUDbits.CNPUD4=0;     //Disable weak pullup
                CNPDDbits.CNPDD4=0;     //Disable weak pulldown
                TRISDbits.TRISD4=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;

        case RD_5: //LCD_RW
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                //ANSELDbits.ANSD5=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENDbits.CNIED5=0;     //Disable change notification interrupt
                CNPUDbits.CNPUD5=0;     //Disable weak pullup
                CNPDDbits.CNPDD5=0;     //Disable weak pulldown
                TRISDbits.TRISD5=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                //ANSELDbits.ANSD5=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENDbits.CNIED5=0;     //Disable change notification interrupt
                CNPUDbits.CNPUD5=0;     //Disable weak pullup
                CNPDDbits.CNPDD5=1;     //Disable weak pulldown
                TRISDbits.TRISD5=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                //ANSELDbits.ANSD5=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENDbits.CNIED5=0;     //Disable change notification interrupt
                CNPUDbits.CNPUD5=1;     //Disable weak pullup
                CNPDDbits.CNPDD5=0;     //Disable weak pulldown
                TRISDbits.TRISD5=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                //ANSELDbits.ANSD5=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENDbits.CNIED5=0;     //Disable change notification interrupt
                CNPUDbits.CNPUD5=0;     //Disable weak pullup
                CNPDDbits.CNPDD5=0;     //Disable weak pulldown
                TRISDbits.TRISD5=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            default:
                break;
            }
        break;
        
        case RB_15: //LCD_RS
            switch(ui8Mode) 
            {
            case INPUT:
                    //configure input
                ANSELBbits.ANSB15=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB15=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB15=0;     //Disable weak pullup
                CNPDBbits.CNPDB15=0;     //Disable weak pulldown
                TRISBbits.TRISB15=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLDOWN:
                    //configure input pulldown
                ANSELBbits.ANSB15=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB15=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB15=0;     //Disable weak pullup
                CNPDBbits.CNPDB15=1;     //Disable weak pulldown
                TRISBbits.TRISB15=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case INPUT_PULLUP:
                    //configure input pullup
                ANSELBbits.ANSB15=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB15=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB15=1;     //Disable weak pullup
                CNPDBbits.CNPDB15=0;     //Disable weak pulldown
                TRISBbits.TRISB15=1;     //Pin B8: Digital Output   0 for Output / 1 for Input
                break;

            case OUTPUT:
                //configure output
                ANSELBbits.ANSB15=0;     //Digital I/O    0 for Digital / 1 for Analog
                CNENBbits.CNIEB15=0;     //Disable change notification interrupt
                CNPUBbits.CNPUB15=0;     //Disable weak pullup
                CNPDBbits.CNPDB15=0;     //Disable weak pulldown
                TRISBbits.TRISB15=0;     //Pin B8: Digital Output   0 for Output / 1 for Input
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
            
        case RE_0:
            if(ui8Value==LOW)
                LATEbits.LATE0=LOW;
            else
                LATEbits.LATE0=HIGH;
            break;
            
        case RE_1:
            if(ui8Value==LOW)
                LATEbits.LATE1=LOW;
            else
                LATEbits.LATE1=HIGH;
            break;
            
        case RE_2:
            if(ui8Value==LOW)
                LATEbits.LATE2=LOW;
            else
                LATEbits.LATE2=HIGH;
            break;

        case RE_3:
            if(ui8Value==LOW)
                LATEbits.LATE3=LOW;
            else
                LATEbits.LATE3=HIGH;
            break;
            
        case RE_4:
            if(ui8Value==LOW)
                LATEbits.LATE4=LOW;
            else
                LATEbits.LATE4=HIGH;
            break;
            
        case RE_5:
            if(ui8Value==LOW)
                LATEbits.LATE5=LOW;
            else
                LATEbits.LATE5=HIGH;
            break;
            
        case RE_6:
            if(ui8Value==LOW)
                LATEbits.LATE6=LOW;
            else
                LATEbits.LATE6=HIGH;
            break;
            
        case RE_7:
            if(ui8Value==LOW)
                LATEbits.LATE7=LOW;
            else
                LATEbits.LATE7=HIGH;
            break;
            
        case RD_4:
            if(ui8Value==LOW)
                LATDbits.LATD4=LOW;
            else
                LATDbits.LATD4=HIGH;
            break;

        case RD_5:
            if(ui8Value==LOW)
                LATDbits.LATD5=LOW;
            else
                LATDbits.LATD5=HIGH;
            break;

        case RB_15:
            if(ui8Value==LOW)
                LATBbits.LATB15=LOW;
            else
                LATBbits.LATB15=HIGH;
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
        
        case RE_0:
            return PORTEbits.RE0;
            break;        
        
        case RE_1:
            return PORTEbits.RE1;
            break;  
        
        case RE_2:
            return PORTEbits.RE2;
            break;  
        
        case RE_3:
            return PORTEbits.RE3;
            break;  
        
        case RE_4:
            return PORTEbits.RE4;
            break;  
        
        case RE_5:
            return PORTEbits.RE5;
            break;  
        
        case RE_6:
            return PORTEbits.RE6;
            break;  
        
        case RE_7:
            return PORTEbits.RE7;
            break;
            
        case RD_4:
            return PORTDbits.RD4;
            break;   
            
        case RD_5:
            return PORTDbits.RD5;
            break;   
            
        case RB_15:
            return PORTBbits.RB15;
            break;   
        
        default:
            return 0;
            break;  
    }
}
const uint16_t cui16DebounceTime=1;
uint8_t isPressedSW0()
{
    static uint8_t ui8State = STATE_STABLE_HIGH; //default state
    static uint16_t ui16Counter=0;
    uint8_t ui8ReturnValue=1;
    switch(ui8State)
    {             
        case STATE_STABLE_HIGH:
            if(digitalRead(SW0)==LOW)
            {
                ui8State = STATE_INSTABLE_HIGH;
                ui16Counter=0;
            }
            ui8ReturnValue= HIGH;
            break;
                
        case STATE_INSTABLE_HIGH:
            ui16Counter++;
            if(digitalRead(SW0)==LOW)
            {
                if( ui16Counter>=cui16DebounceTime )
                {
                    ui8State = STATE_STABLE_LOW;
                    ui8ReturnValue= LOW;
                }
                else
                    ui8ReturnValue= HIGH;

            }
            else
            {
                ui8State = STATE_STABLE_HIGH;
                ui8ReturnValue= HIGH;
            }
            break;
        
        case STATE_STABLE_LOW:
            if(digitalRead(SW0)==HIGH)
            {
                ui8State = STATE_INSTABLE_LOW;
                ui16Counter=0;
            }
            ui8ReturnValue= LOW;
            break;
                
        case STATE_INSTABLE_LOW:
            ui16Counter++;
            if(digitalRead(SW0)==HIGH)
            {
                if(ui16Counter >= cui16DebounceTime)
                {
                    ui8State = STATE_STABLE_HIGH;
                    ui8ReturnValue= HIGH;
                }
                else
                    ui8ReturnValue= LOW;
            }
            else
            {
                ui8State = STATE_STABLE_LOW;
                ui8ReturnValue= LOW;
            }            
            break;
        default:
            ui8State = STATE_STABLE_HIGH;
            ui8ReturnValue= HIGH;
           break;
    }
    return ui8ReturnValue;
}
/* //Function without wait time
uint8_t isPressedSW0()
{
    static uint8_t ui8State = STATE_STABLE_HIGH; //default state
    switch(ui8State)
    {             
        case STATE_STABLE_HIGH:
            if(digitalRead(SW0)==LOW)
            {
                ui8State = STATE_INSTABLE_HIGH;
            }
            //digitalWrite(LED1, HIGH);
            return HIGH;
            break;
                
        case STATE_INSTABLE_HIGH:
            if(digitalRead(SW0)==LOW)
            {
                ui8State = STATE_STABLE_LOW;
                //digitalWrite(LED1, LOW);
                return LOW;
            }
            else
            {
                ui8State = STATE_STABLE_HIGH;
                //digitalWrite(LED1, HIGH);
                return HIGH;
            }
            break;
        
        case STATE_STABLE_LOW:
            if(digitalRead(SW0)==HIGH)
            {
                //digitalWrite(LED1, LOW);
                ui8State = STATE_INSTABLE_LOW;
            }
            return LOW;
            break;
                
        case STATE_INSTABLE_LOW:
            if(digitalRead(SW0)==HIGH)
            {
                ui8State = STATE_STABLE_HIGH;
                //digitalWrite(LED1, HIGH);
                return HIGH;
            }
            else
            {
                //digitalWrite(LED1, LOW);
                ui8State = STATE_STABLE_LOW;
                return LOW;
            }            
            break;
        default:
            ui8State = STATE_STABLE_HIGH;
            //digitalWrite(LED1, HIGH);
            return HIGH;
           break;
    }
    return HIGH;
}*/
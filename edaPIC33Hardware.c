/*
 * File:   edaPIC33Hardware.c
 * Author: Kevin Fritz
 *
 * Created on 4. April 2017, 10:41
 */
#include "edaPIC33Hardware.h"
#include <stdint.h>
#include <xc.h>

void pinMode(const uint8_t ui8Port,const uint8_t ui8Mode)
{
    uint16_t* pTRIS =  getpTRIS(ui8Port);    //Output/Input select, 0:output, 1:input
    uint16_t* pCNEN =  getpCNEN(ui8Port);    //Change Notification Interrupt Enable Bit, 0:disabled, 1:enabled
    uint16_t* pCNPU =  getpCNPU(ui8Port);    //Pull-Up enable Bit, 0:disabled, 1:enabled
    uint16_t* pCNPD =  getpCNPD(ui8Port);    //Pull-Down enable Bit, 0:disabled, 1:enabled
    uint16_t* pANSEL = getpANSEL(ui8Port);   //Analog select Bit, 0: digital, 1:analog
    uint16_t* pODC =   getpODC(ui8Port);     //open drain select Bit, 0: digital output, 1:open drain output
    uint16_t* pIOCON = getpIOCON(ui8Port);   //GPIO/PWM select: 0:GPIO module controls pins, 1:PWM module controls
    
    switch(ui8Mode)
    {   //set ANSEL, TRIS, CNEN, CNPU, CNPD and ODC bit
        case DIGITAL_INPUT:
            setBit(pANSEL,getPortBitNumb(ui8Port), 0);
            setBit(pTRIS, getPortBitNumb(ui8Port), 1);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 0);
            setBit(pCNPD, getPortBitNumb(ui8Port), 0);
            setBit(pODC,  getPortBitNumb(ui8Port), 0);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;
            
        case DIGITAL_INPUT_PULLUP:
            setBit(pANSEL,getPortBitNumb(ui8Port), 0);
            setBit(pTRIS, getPortBitNumb(ui8Port), 1);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 1);
            setBit(pCNPD, getPortBitNumb(ui8Port), 0);
            setBit(pODC,  getPortBitNumb(ui8Port), 0);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;
            
        case DIGITAL_INPUT_PULLDOWN:
            setBit(pANSEL,getPortBitNumb(ui8Port), 0);
            setBit(pTRIS, getPortBitNumb(ui8Port), 1);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 0);
            setBit(pCNPD, getPortBitNumb(ui8Port), 1);
            setBit(pODC,  getPortBitNumb(ui8Port), 0);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;
            
        case DIGITAL_OUTPUT:
            setBit(pANSEL,getPortBitNumb(ui8Port), 0);
            setBit(pTRIS, getPortBitNumb(ui8Port), 0);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 0);
            setBit(pCNPD, getPortBitNumb(ui8Port), 0);
            setBit(pODC,  getPortBitNumb(ui8Port), 0);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;
            
        case OPEN_DRAIN_OUTPUT:
            setBit(pANSEL,getPortBitNumb(ui8Port), 0);
            setBit(pTRIS, getPortBitNumb(ui8Port), 0);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 0);
            setBit(pCNPD, getPortBitNumb(ui8Port), 0);
            setBit(pODC,  getPortBitNumb(ui8Port), 1);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;
            
        case ANALOG_OUTPUT:
            setBit(pANSEL,getPortBitNumb(ui8Port), 1);
            setBit(pTRIS, getPortBitNumb(ui8Port), 0);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 0);
            setBit(pCNPD, getPortBitNumb(ui8Port), 0);
            setBit(pODC,  getPortBitNumb(ui8Port), 0);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;

        case ANALOG_INPUT:
            setBit(pANSEL,getPortBitNumb(ui8Port), 1);
            setBit(pTRIS, getPortBitNumb(ui8Port), 1);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 0);
            setBit(pCNPD, getPortBitNumb(ui8Port), 0);
            setBit(pODC,  getPortBitNumb(ui8Port), 0);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;

        case ANALOG_INPUT_PULLDOWN:
            setBit(pANSEL,getPortBitNumb(ui8Port), 1);
            setBit(pTRIS, getPortBitNumb(ui8Port), 1);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 0);
            setBit(pCNPD, getPortBitNumb(ui8Port), 1);
            setBit(pODC,  getPortBitNumb(ui8Port), 0);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;   

        case ANALOG_INPUT_PULLUP:
            setBit(pANSEL,getPortBitNumb(ui8Port), 1);
            setBit(pTRIS, getPortBitNumb(ui8Port), 1);      
            setBit(pCNEN, getPortBitNumb(ui8Port), 0);
            setBit(pCNPU, getPortBitNumb(ui8Port), 1);
            setBit(pCNPD, getPortBitNumb(ui8Port), 0);
            setBit(pODC,  getPortBitNumb(ui8Port), 0);
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 0);
            break;
            
        case PWM_OUTPUT:
            setBit(pIOCON,  getPwmPinEnRegisterBitNumb(ui8Port), 1);
            break;
                    
        default:
            break;
    }
}
              
void digitalWrite(const uint8_t ui8Port,const uint8_t ui8Value)
{  
    if(ui8Value)
        setBit(getpLAT(ui8Port), getPortBitNumb(ui8Port), 1); //set output to 1 if value is true (unlike zero)
    else
        setBit(getpLAT(ui8Port), getPortBitNumb(ui8Port), 0); //set output to 0 if value is false (zero)
}

void digitalToggle(const uint8_t ui8Port)
{
    digitalWrite(ui8Port, !digitalRead(ui8Port));
}

uint8_t digitalRead(const uint8_t ui8Port)
{
    return getBit(*getpPORT(ui8Port), getPortBitNumb(ui8Port));
    //return (*getpPORT(ui8Port) & ( 1 << getPortBitNumb(ui8Port) )) >> getPortBitNumb(ui8Port);
}

uint8_t getPortBitNumb(uint8_t Port)
{
    switch(Port)
    {
    	case RA0:  return 0;
		case RA1:  return 1;
		case RA2:  return 2;
		case RA3:  return 3;
		case RA4:  return 4;
		case RA5:  return 5;
		case RA6:  return 6;
		case RA7:  return 7;
//		case RA8:  return 8;
		case RA9:  return 9;
		case RA10: return 10;
//		case RA11: return 11;
//		case RA12: return 12;
//		case RA13: return 13;
		case RA14: return 14;
		case RA15: return 15;
		
		case RB0:  return 0;
		case RB1:  return 1;
		case RB2:  return 2;
		case RB3:  return 3;
		case RB4:  return 4;
		case RB5:  return 5;
		case RB6:  return 6;
		case RB7:  return 7;
		case RB8:  return 8;
		case RB9:  return 9;
		case RB10: return 10;
		case RB11: return 11;
		case RB12: return 12;
		case RB13: return 13;
		case RB14: return 14;
		case RB15: return 15;

//      case RC0:  return 0;
		case RC1:  return 1;
		case RC2:  return 2;
		case RC3:  return 3;
		case RC4:  return 4;
//		case RC5:  return 5;
//		case RC6:  return 6;
//		case RC7:  return 7;
//		case RC8:  return 8;
//		case RC9:  return 9;
//		case RC10: return 10;
//		case RC11: return 11;
		case RC12: return 12;
		case RC13: return 13;
		case RC14: return 14;
		case RC15: return 15;
		
		case RD0:  return 0;
		case RD1:  return 1;
		case RD2:  return 2;
		case RD3:  return 3;
		case RD4:  return 4;
		case RD5:  return 5;
		case RD6:  return 6;
		case RD7:  return 7;
		case RD8:  return 8;
		case RD9:  return 9;
		case RD10: return 10;
		case RD11: return 11;
		case RD12: return 12;
		case RD13: return 13;
		case RD14: return 14;
		case RD15: return 15;
		
		case RE0:  return 0;
		case RE1:  return 1;
		case RE2:  return 2;
		case RE3:  return 3;
		case RE4:  return 4;
		case RE5:  return 5;
		case RE6:  return 6;
		case RE7:  return 7;
		case RE8:  return 8;
		case RE9:  return 9;
//		case RE10: return 10;
//		case RE11: return 11;
//		case RE12: return 12;
//		case RE13: return 13;
//		case RE14: return 14;
//		case RE15: return 15;
		
		case RF0:  return 0;
		case RF1:  return 1;
		case RF2:  return 2;
		case RF3:  return 3;
		case RF4:  return 4;
		case RF5:  return 5;
//		case RF6:  return 6;
//		case RF7:  return 7;
		case RF8:  return 8;
//		case RF9:  return 9;
//		case RF10: return 10;
//		case RF11: return 11;
		case RF12: return 12;
		case RF13: return 13;
//		case RF14: return 14;
//		case RF15: return 15;
		
		case RG0:  return 0;
		case RG1:  return 1;
		case RG2:  return 2;
		case RG3:  return 3;
//		case RG4:  return 4;
//		case RG5:  return 5;
		case RG6:  return 6;
		case RG7:  return 7;
		case RG8:  return 8;
		case RG9:  return 9;
//		case RG10: return 10;
//		case RG11: return 11;
		case RG12: return 12;
		case RG13: return 13;
		case RG14: return 14;
		case RG15: return 15;        
    }
    return 0;
}

uint16_t* getpTRIS(uint8_t Port)
{
	if( Port == RA0 ||  Port == RA1 ||  Port == RA2 ||  Port == RA3 ||  Port == RA4 ||  Port == RA5 ||  Port == RA6 ||  Port == RA7 ||  Port == RA9 ||  Port == RA10 || Port == RA14 || Port == RA15)
        return (uint16_t*)&TRISA;
    if( Port == RB0 ||  Port == RB1 ||  Port == RB2 ||  Port == RB3 ||  Port == RB4 ||  Port == RB5 ||  Port == RB6 ||  Port == RB7 ||  Port == RB8 ||  Port == RB9 ||  Port == RB10 ||  Port == RB11 || Port == RB12 || Port == RB13 || Port == RB14 || Port == RB15)
        return (uint16_t*)&TRISB;
    if( Port == RC1 ||  Port == RC2 ||  Port == RC3 ||  Port == RC4 ||  Port == RC12 || Port == RC13 || Port == RC14 || Port == RC15)
        return (uint16_t*)&TRISC;
    if( Port == RD0 ||  Port == RD1 ||  Port == RD2 ||  Port == RD3 ||  Port == RD4 ||  Port == RD5 ||  Port == RD6 ||  Port == RD7 ||  Port == RD8 ||  Port == RD9 ||  Port == RD10 ||  Port == RD11 || Port == RD12 || Port == RD13 || Port == RD14 || Port == RD15)
        return (uint16_t*)&TRISD;
    if( Port == RE0 ||  Port == RE1 ||  Port == RE2 ||  Port == RE3 ||  Port == RE4 ||  Port == RE5 ||  Port == RE6 ||  Port == RE7 ||  Port == RE8 ||  Port == RE9)
        return (uint16_t*)&TRISE;
	if( Port == RF0 ||  Port == RF1 ||  Port == RF2 ||  Port == RF3 ||  Port == RF4 ||  Port == RF5 ||  Port == RF8 ||  Port == RF12 || Port == RF13)
        return (uint16_t*)&TRISF;
	if( Port == RG0 ||  Port == RG1 ||  Port == RG2 ||  Port == RG3 ||  Port == RG6 ||  Port == RG7 ||  Port == RG8 ||  Port == RG9 ||  Port == RG12 || Port == RG13 || Port == RG14 || Port == RG15)
        return (uint16_t*)&TRISG;
    return 0;
}

uint16_t* getpPORT(uint8_t Port)
{
	if( Port == RA0 ||  Port == RA1 ||  Port == RA2 ||  Port == RA3 ||  Port == RA4 ||  Port == RA5 ||  Port == RA6 ||  Port == RA7 ||  Port == RA9 ||  Port == RA10 || Port == RA14 || Port == RA15)
        return (uint16_t*) &PORTA;
    if( Port == RB0 ||  Port == RB1 ||  Port == RB2 ||  Port == RB3 ||  Port == RB4 ||  Port == RB5 ||  Port == RB6 ||  Port == RB7 ||  Port == RB8 ||  Port == RB9 ||  Port == RB10 ||  Port == RB11 || Port == RB12 || Port == RB13 || Port == RB14 || Port == RB15)
        return (uint16_t*) &PORTB;
    if( Port == RC1 ||  Port == RC2 ||  Port == RC3 ||  Port == RC4 ||  Port == RC12 || Port == RC13 || Port == RC14 || Port == RC15)
        return (uint16_t*) &PORTC;
    if( Port == RD0 ||  Port == RD1 ||  Port == RD2 ||  Port == RD3 ||  Port == RD4 ||  Port == RD5 ||  Port == RD6 ||  Port == RD7 ||  Port == RD8 ||  Port == RD9 ||  Port == RD10 ||  Port == RD11 || Port == RD12 || Port == RD13 || Port == RD14 || Port == RD15)
        return (uint16_t*) &PORTD;
    if( Port == RE0 ||  Port == RE1 ||  Port == RE2 ||  Port == RE3 ||  Port == RE4 ||  Port == RE5 ||  Port == RE6 ||  Port == RE7 ||  Port == RE8 ||  Port == RE9)
        return (uint16_t*) &PORTE;
	if( Port == RF0 ||  Port == RF1 ||  Port == RF2 ||  Port == RF3 ||  Port == RF4 ||  Port == RF5 ||  Port == RF8 ||  Port == RF12 || Port == RF13)
        return (uint16_t*) &PORTF;
	if( Port == RG0 ||  Port == RG1 ||  Port == RG2 ||  Port == RG3 ||  Port == RG6 ||  Port == RG7 ||  Port == RG8 ||  Port == RG9 ||  Port == RG12 || Port == RG13 || Port == RG14 || Port == RG15)
        return (uint16_t*) &PORTG;
    return (uint16_t*) 0;
}
uint16_t* getpLAT(uint8_t Port)
{
	if( Port == RA0 ||  Port == RA1 ||  Port == RA2 ||  Port == RA3 ||  Port == RA4 ||  Port == RA5 ||  Port == RA6 ||  Port == RA7 ||  Port == RA9 ||  Port == RA10 || Port == RA14 || Port == RA15)
        return (uint16_t*) &LATA;
    if( Port == RB0 ||  Port == RB1 ||  Port == RB2 ||  Port == RB3 ||  Port == RB4 ||  Port == RB5 ||  Port == RB6 ||  Port == RB7 ||  Port == RB8 ||  Port == RB9 ||  Port == RB10 ||  Port == RB11 || Port == RB12 || Port == RB13 || Port == RB14 || Port == RB15)
        return (uint16_t*) &LATB;
    if( Port == RC1 ||  Port == RC2 ||  Port == RC3 ||  Port == RC4 ||  Port == RC12 || Port == RC13 || Port == RC14 || Port == RC15)
        return (uint16_t*) &LATC;
    if( Port == RD0 ||  Port == RD1 ||  Port == RD2 ||  Port == RD3 ||  Port == RD4 ||  Port == RD5 ||  Port == RD6 ||  Port == RD7 ||  Port == RD8 ||  Port == RD9 ||  Port == RD10 ||  Port == RD11 || Port == RD12 || Port == RD13 || Port == RD14 || Port == RD15)
        return (uint16_t*) &LATD;
    if( Port == RE0 ||  Port == RE1 ||  Port == RE2 ||  Port == RE3 ||  Port == RE4 ||  Port == RE5 ||  Port == RE6 ||  Port == RE7 ||  Port == RE8 ||  Port == RE9)
        return (uint16_t*) &LATE;
	if( Port == RF0 ||  Port == RF1 ||  Port == RF2 ||  Port == RF3 ||  Port == RF4 ||  Port == RF5 ||  Port == RF8 ||  Port == RF12 || Port == RF13)
        return (uint16_t*) &LATF;
	if( Port == RG0 ||  Port == RG1 ||  Port == RG2 ||  Port == RG3 ||  Port == RG6 ||  Port == RG7 ||  Port == RG8 ||  Port == RG9 ||  Port == RG12 || Port == RG13 || Port == RG14 || Port == RG15)
        return (uint16_t*) &LATG;
    return (uint16_t*) 0;    
}

uint16_t* getpODC(uint8_t Port)
{
	if( Port == RA0 ||  Port == RA1 ||  Port == RA2 ||  Port == RA3 ||  Port == RA4 ||  Port == RA5 ||  Port == RA6 ||  Port == RA7 ||  Port == RA9 ||  Port == RA10 || Port == RA14 || Port == RA15)
        return (uint16_t*) &ODCA;
//    if( Port == RB0 ||  Port == RB1 ||  Port == RB2 ||  Port == RB3 ||  Port == RB4 ||  Port == RB5 ||  Port == RB6 ||  Port == RB7 ||  Port == RB8 ||  Port == RB9 ||  Port == RB10 ||  Port == RB11 || Port == RB12 || Port == RB13 || Port == RB14 || Port == RB15)
//        return (uint16_t*) &ODCB;
//    if( Port == RC1 ||  Port == RC2 ||  Port == RC3 ||  Port == RC4 ||  Port == RC12 || Port == RC13 || Port == RC14 || Port == RC15)
//        return (uint16_t*) &ODCC;
    if( Port == RD0 ||  Port == RD1 ||  Port == RD2 ||  Port == RD3 ||  Port == RD4 ||  Port == RD5 ||  Port == RD6 ||  Port == RD7 ||  Port == RD8 ||  Port == RD9 ||  Port == RD10 ||  Port == RD11 || Port == RD12 || Port == RD13 || Port == RD14 || Port == RD15)
        return (uint16_t*) &ODCD;
//    if( Port == RE0 ||  Port == RE1 ||  Port == RE2 ||  Port == RE3 ||  Port == RE4 ||  Port == RE5 ||  Port == RE6 ||  Port == RE7 ||  Port == RE8 ||  Port == RE9)
//        return (uint16_t*) &ODCE;
	if( Port == RF0 ||  Port == RF1 ||  Port == RF2 ||  Port == RF3 ||  Port == RF4 ||  Port == RF5 ||  Port == RF8 ||  Port == RF12 || Port == RF13)
        return (uint16_t*) &ODCF;
	if( Port == RG0 ||  Port == RG1 ||  Port == RG2 ||  Port == RG3 ||  Port == RG6 ||  Port == RG7 ||  Port == RG8 ||  Port == RG9 ||  Port == RG12 || Port == RG13 || Port == RG14 || Port == RG15)
        return (uint16_t*) &ODCG;
    return 0;
}

uint16_t* getpCNEN(uint8_t Port)
{
    if( Port == RA0 ||  Port == RA1 ||  Port == RA2 ||  Port == RA3 ||  Port == RA4 ||  Port == RA5 ||  Port == RA6 ||  Port == RA7 ||  Port == RA9 ||  Port == RA10 || Port == RA14 || Port == RA15)
        return (uint16_t*) &CNENA;
    if( Port == RB0 ||  Port == RB1 ||  Port == RB2 ||  Port == RB3 ||  Port == RB4 ||  Port == RB5 ||  Port == RB6 ||  Port == RB7 ||  Port == RB8 ||  Port == RB9 ||  Port == RB10 ||  Port == RB11 || Port == RB12 || Port == RB13 || Port == RB14 || Port == RB15)
        return (uint16_t*) &CNENB;
    if( Port == RC1 ||  Port == RC2 ||  Port == RC3 ||  Port == RC4 ||  Port == RC12 || Port == RC13 || Port == RC14 || Port == RC15)
        return (uint16_t*) &CNENC;
    if( Port == RD0 ||  Port == RD1 ||  Port == RD2 ||  Port == RD3 ||  Port == RD4 ||  Port == RD5 ||  Port == RD6 ||  Port == RD7 ||  Port == RD8 ||  Port == RD9 ||  Port == RD10 ||  Port == RD11 || Port == RD12 || Port == RD13 || Port == RD14 || Port == RD15)
        return (uint16_t*) &CNEND;
    if( Port == RE0 ||  Port == RE1 ||  Port == RE2 ||  Port == RE3 ||  Port == RE4 ||  Port == RE5 ||  Port == RE6 ||  Port == RE7 ||  Port == RE8 ||  Port == RE9)
        return (uint16_t*) &CNENE;
	if( Port == RF0 ||  Port == RF1 ||  Port == RF2 ||  Port == RF3 ||  Port == RF4 ||  Port == RF5 ||  Port == RF8 ||  Port == RF12 || Port == RF13)
        return (uint16_t*) &CNENF;
	if( Port == RG0 ||  Port == RG1 ||  Port == RG2 ||  Port == RG3 ||  Port == RG6 ||  Port == RG7 ||  Port == RG8 ||  Port == RG9 ||  Port == RG12 || Port == RG13 || Port == RG14 || Port == RG15)
        return (uint16_t*) &CNENG;
    return 0;
}

uint16_t* getpCNPU(uint8_t Port)
{
	if( Port == RA0 ||  Port == RA1 ||  Port == RA2 ||  Port == RA3 ||  Port == RA4 ||  Port == RA5 ||  Port == RA6 ||  Port == RA7 ||  Port == RA9 ||  Port == RA10 || Port == RA14 || Port == RA15)
        return (uint16_t*) &CNPUA;
    if( Port == RB0 ||  Port == RB1 ||  Port == RB2 ||  Port == RB3 ||  Port == RB4 ||  Port == RB5 ||  Port == RB6 ||  Port == RB7 ||  Port == RB8 ||  Port == RB9 ||  Port == RB10 ||  Port == RB11 || Port == RB12 || Port == RB13 || Port == RB14 || Port == RB15)
        return (uint16_t*) &CNPUB;
    if( Port == RC1 ||  Port == RC2 ||  Port == RC3 ||  Port == RC4 ||  Port == RC12 || Port == RC13 || Port == RC14 || Port == RC15)
        return (uint16_t*) &CNPUC;
    if( Port == RD0 ||  Port == RD1 ||  Port == RD2 ||  Port == RD3 ||  Port == RD4 ||  Port == RD5 ||  Port == RD6 ||  Port == RD7 ||  Port == RD8 ||  Port == RD9 ||  Port == RD10 ||  Port == RD11 || Port == RD12 || Port == RD13 || Port == RD14 || Port == RD15)
        return (uint16_t*) &CNPUD;
    if( Port == RE0 ||  Port == RE1 ||  Port == RE2 ||  Port == RE3 ||  Port == RE4 ||  Port == RE5 ||  Port == RE6 ||  Port == RE7 ||  Port == RE8 ||  Port == RE9)
        return (uint16_t*) &CNPUE;
	if( Port == RF0 ||  Port == RF1 ||  Port == RF2 ||  Port == RF3 ||  Port == RF4 ||  Port == RF5 ||  Port == RF8 ||  Port == RF12 || Port == RF13)
        return (uint16_t*) &CNPUF;
	if( Port == RG0 ||  Port == RG1 ||  Port == RG2 ||  Port == RG3 ||  Port == RG6 ||  Port == RG7 ||  Port == RG8 ||  Port == RG9 ||  Port == RG12 || Port == RG13 || Port == RG14 || Port == RG15)
        return (uint16_t*) &CNPUG;
    return 0;    
}

uint16_t* getpCNPD(uint8_t Port)
{
    if( Port == RA0 ||  Port == RA1 ||  Port == RA2 ||  Port == RA3 ||  Port == RA4 ||  Port == RA5 ||  Port == RA6 ||  Port == RA7 ||  Port == RA9 ||  Port == RA10 || Port == RA14 || Port == RA15)
        return (uint16_t*) &CNPDA;
    if( Port == RB0 ||  Port == RB1 ||  Port == RB2 ||  Port == RB3 ||  Port == RB4 ||  Port == RB5 ||  Port == RB6 ||  Port == RB7 ||  Port == RB8 ||  Port == RB9 ||  Port == RB10 ||  Port == RB11 || Port == RB12 || Port == RB13 || Port == RB14 || Port == RB15)
        return (uint16_t*) &CNPDB;
    if( Port == RC1 ||  Port == RC2 ||  Port == RC3 ||  Port == RC4 ||  Port == RC12 || Port == RC13 || Port == RC14 || Port == RC15)
        return (uint16_t*) &CNPDC;
    if( Port == RD0 ||  Port == RD1 ||  Port == RD2 ||  Port == RD3 ||  Port == RD4 ||  Port == RD5 ||  Port == RD6 ||  Port == RD7 ||  Port == RD8 ||  Port == RD9 ||  Port == RD10 ||  Port == RD11 || Port == RD12 || Port == RD13 || Port == RD14 || Port == RD15)
        return (uint16_t*) &CNPDD;
    if( Port == RE0 ||  Port == RE1 ||  Port == RE2 ||  Port == RE3 ||  Port == RE4 ||  Port == RE5 ||  Port == RE6 ||  Port == RE7 ||  Port == RE8 ||  Port == RE9)
        return (uint16_t*) &CNPDE;
	if( Port == RF0 ||  Port == RF1 ||  Port == RF2 ||  Port == RF3 ||  Port == RF4 ||  Port == RF5 ||  Port == RF8 ||  Port == RF12 || Port == RF13)
        return (uint16_t*) &CNPDF;
	if( Port == RG0 ||  Port == RG1 ||  Port == RG2 ||  Port == RG3 ||  Port == RG6 ||  Port == RG7 ||  Port == RG8 ||  Port == RG9 ||  Port == RG12 || Port == RG13 || Port == RG14 || Port == RG15)
        return (uint16_t*) &CNPDG;
    return 0;
}

uint16_t* getpANSEL(uint8_t Port)
{
	if( Port == RA0 ||  Port == RA1 ||  Port == RA2 ||  Port == RA3 ||  Port == RA4 ||  Port == RA5 ||  Port == RA6 ||  Port == RA7 ||  Port == RA9 ||  Port == RA10 || Port == RA14 || Port == RA15)
        return (uint16_t*) &ANSELA;
    if( Port == RB0 ||  Port == RB1 ||  Port == RB2 ||  Port == RB3 ||  Port == RB4 ||  Port == RB5 ||  Port == RB6 ||  Port == RB7 ||  Port == RB8 ||  Port == RB9 ||  Port == RB10 ||  Port == RB11 || Port == RB12 || Port == RB13 || Port == RB14 || Port == RB15)
        return (uint16_t*) &ANSELB;
    if( Port == RC1 ||  Port == RC2 ||  Port == RC3 ||  Port == RC4 ||  Port == RC12 || Port == RC13 || Port == RC14 || Port == RC15)
        return (uint16_t*) &ANSELC;
    if( Port == RD0 ||  Port == RD1 ||  Port == RD2 ||  Port == RD3 ||  Port == RD4 ||  Port == RD5 ||  Port == RD6 ||  Port == RD7 ||  Port == RD8 ||  Port == RD9 ||  Port == RD10 ||  Port == RD11 || Port == RD12 || Port == RD13 || Port == RD14 || Port == RD15)
        return (uint16_t*) &ANSELD;
    if( Port == RE0 ||  Port == RE1 ||  Port == RE2 ||  Port == RE3 ||  Port == RE4 ||  Port == RE5 ||  Port == RE6 ||  Port == RE7 ||  Port == RE8 ||  Port == RE9)
        return (uint16_t*) &ANSELE;
//	if( Port == RF0 ||  Port == RF1 ||  Port == RF2 ||  Port == RF3 ||  Port == RF4 ||  Port == RF5 ||  Port == RF8 ||  Port == RF12 || Port == RF13)
//        return (uint16_t*) &ANSELF;
	if( Port == RG0 ||  Port == RG1 ||  Port == RG2 ||  Port == RG3 ||  Port == RG6 ||  Port == RG7 ||  Port == RG8 ||  Port == RG9 ||  Port == RG12 || Port == RG13 || Port == RG14 || Port == RG15)
        return (uint16_t*) &ANSELG;
    return 0;
}	

void setBit(uint16_t* pui16Var, uint8_t ui8Bit, uint8_t ui8Value)
{
    if(ui8Bit < 16 && ui8Value<2)
    {
        if(ui8Value)
             *pui16Var |= (0x0001 << ui8Bit); //set to 1
        else
            *pui16Var &= (~(0x0001 << ui8Bit)); //set to 0
    }
}

uint8_t getBit(uint16_t ui16Var, uint8_t ui8Bit)
{
    return (ui16Var & ( 1 << ui8Bit )) >> ui8Bit;
}

uint16_t* getpIOCON(uint8_t Port)
{
   if(Port==RE0 || Port==RE0 )
       return (uint16_t*) &IOCON1;
   if(Port==RE2 || Port==RE3 )
       return (uint16_t*) &IOCON2;
   if(Port==RE4 || Port==RE5 )
       return (uint16_t*) &IOCON3;
   if(Port==RE6 || Port==RE7 )
       return (uint16_t*) &IOCON4;
   if(Port==RC1 || Port==RC2 )
       return (uint16_t*) &IOCON5;
   if(Port==RC3 || Port==RC4 )
       return (uint16_t*) &IOCON6;   
   return 0;
}


uint8_t getPwmPinEnRegisterBitNumb(uint8_t Port)
{
    switch(Port)
    {
		case RC1:  return 14;
		case RC2:  return 15;
		case RC3:  return 14;
		case RC4:  return 15;
	
		case RE0:  return 14;
		case RE1:  return 15;
		case RE2:  return 14;
		case RE3:  return 15;
		case RE4:  return 14;
		case RE5:  return 15;
		case RE6:  return 14;
		case RE7:  return 15;     
    }
    return 0;
}
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

#define STATE_STABLE_HIGH   0
#define STATE_INSTABLE_HIGH 1
#define STATE_STABLE_LOW    2
#define STATE_INSTABLE_LOW  3
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
uint8_t isPressed(uint8_t ui8Port)
{
    static uint8_t ui8State = STATE_STABLE_HIGH; //default state
    static uint16_t ui16Counter=0;
    uint8_t ui8ReturnValue=1;
    switch(ui8State)
    {             
        case STATE_STABLE_HIGH:
            if(digitalRead(ui8Port)==LOW)
            {
                ui8State = STATE_INSTABLE_HIGH;
                ui16Counter=0;
            }
            ui8ReturnValue= HIGH;
            break;
                
        case STATE_INSTABLE_HIGH:
            ui16Counter++;
            if(digitalRead(ui8Port)==LOW)
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
            if(digitalRead(ui8Port)==HIGH)
            {
                ui8State = STATE_INSTABLE_LOW;
                ui16Counter=0;
            }
            ui8ReturnValue= LOW;
            break;
                
        case STATE_INSTABLE_LOW:
            ui16Counter++;
            if(digitalRead(ui8Port)==HIGH)
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

#define STATE_A0_B0 0
#define STATE_A1_B0 1
#define STATE_A0_B1 2
#define STATE_A1_B1 3
int8_t rotaryEncode()
{
    static int8_t ui8Mode=IDLE;
    //static uint8_t ui8State= (!digitalRead(INCA)) + 2*(!digitalRead(INCB));
    static uint8_t ui8State=STATE_A0_B0;
    int8_t i8Return = 0;
    
    switch(ui8State)
    {
        case STATE_A0_B0:
            if((digitalRead(INCA))==1){
                ui8State=STATE_A1_B0;
                ui8Mode=RIGTH;
            }
            else if((digitalRead(INCB))==1)
            {
                ui8State=STATE_A0_B1;
                ui8Mode=LEFT;
            }
            else
            {
                //nothing to do
            } 
            break;
            
        case STATE_A1_B0:
            if((digitalRead(INCA))==0)
            {
                ui8State=STATE_A0_B0;
                if(ui8Mode==LEFT)
                {
                    i8Return=LEFT;
                    ui8Mode=IDLE;
                }
                else
                {
                    ui8Mode=IDLE;
                }
            }
            else if((digitalRead(INCB))==1)
            {
                ui8State=STATE_A1_B1;
                if(ui8Mode==RIGTH)
                {
                    i8Return=RIGTH;
                    ui8Mode=IDLE;
                }
                else
                {
                    ui8Mode=IDLE;
                }
            }
            else
            {
                //nothing to do
            }                
            break;
            
        case STATE_A0_B1:
            if((digitalRead(INCA))==1)
            {
                ui8State=STATE_A1_B1;
                if(ui8Mode==LEFT)
                {
                    i8Return=LEFT;
                    ui8Mode=IDLE;
                }
                else
                {
                    ui8Mode=IDLE;
                }
            }
            else if((digitalRead(INCB))==0)
            {
                ui8State=STATE_A0_B0;
                if(ui8Mode==RIGTH)
                {
                    i8Return=RIGTH;
                    ui8Mode=IDLE;
                }
                else
                {
                    ui8Mode=IDLE;
                }
            }
            else
            {
                //nothing to do
            }                
            break;
            break; //TODO delete
            
        case STATE_A1_B1:
            if((digitalRead(INCA))==0){
                ui8State=STATE_A0_B1;
                ui8Mode=RIGTH;
            }
            else if((digitalRead(INCB))==0)
            {
                ui8State=STATE_A1_B0;
                ui8Mode=LEFT;
            }
            else
            {
                //nothing to do
            } 
            break;

        default:
            break;
    }
    return i8Return;
}

//in engineering:
void initADC1()
{
    AD1CON1 = 0x0004;
    AD1CON2 = 0x0000;
    AD1CON3 = 0x000F;
    AD1CON4 = 0x0000;
    AD1CHS123 = 0x0000;
    AD1CSSH = 0x0000;
    AD1CSSL = 0x0000;
    //AD1CON1bits.AD12B = 1; //select 12Bit Mode, 0:10Bit Mode, 1:12Bit Mode
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

void initPwmModul()
{
    /* Set PWM Period on Primary Time Base */
    //PTPER = 1023;
    // Set PWM Perios with Function: void setPwmPeriodValue(uint16_t ui16PeriodValue)
    
    /* Set all Phase Shift to zero*/
    PHASE1 = 0;
    SPHASE1 = 0;
    PHASE2 = 0;
    SPHASE2 = 0;
    PHASE3 = 0;
    SPHASE3 = 0;
    PHASE4 = 0;
    SPHASE4 = 0;
    PHASE5 = 0;
    SPHASE5 = 0;
    PHASE6 = 0;
    SPHASE6 = 0;
    
    /* Set Duty Cycles */
    //set duty cycles with function setPwmDutyCycle
    
    /* Set Dead Time Values */
    DTR1 = DTR2 = DTR3 = DTR4 = DTR5 = DTR6 =0;
    ALTDTR1 = ALTDTR2 = ALTDTR3 = ALTDTR4 = ALTDTR5 = ALTDTR6 =0;
    
      
    /* Set PWM Mode to Independent */
    // GPIO module controls PWM Pins
    // PinMode has to be set to PWM_OUTPUT with function PinMode(Pin, PWM_OUTPUT)
    IOCON1 = IOCON2 = IOCON3 = IOCON4 = IOCON5 = IOCON6 = 0x0C00;
    
    
    /* Set Primary Time Base, Edge-Aligned Mode and Independent Duty Cycles */
    PWMCON1 = PWMCON2 = PWMCON3 = PWMCON4 = PWMCON5 = PWMCON6 = 0x0000;
    /* Configure Faults */
    FCLCON1 = FCLCON2 = FCLCON3 = FCLCON4 = FCLCON5 = FCLCON6 =0x0003;
    /* 1:1 Prescaler */
    PTCON2 = 0x0000;
    /* Enable PWM Module */
    PTCON = 0x8000;
    
    uint16_t i=0;
    for(i=0; i<1000; i++) Nop();
}

void setPwmPeriodValue(uint16_t ui16PeriodValue)
{
    PTPER=ui16PeriodValue;
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

void setPwmDutyCycle(uint8_t ui8Port, uint16_t ui16DutyCycle)
{
    switch(ui8Port)
    {
		case RC1:  SDC5 = ui16DutyCycle; break;
		case RC2:  PDC5 = ui16DutyCycle; break;
		case RC3:  SDC6 = ui16DutyCycle; break;
		case RC4:  PDC6 = ui16DutyCycle; break;
	
		case RE0:  SDC1 = ui16DutyCycle; break;
		case RE1:  PDC1 = ui16DutyCycle; break;
		case RE2:  SDC2 = ui16DutyCycle; break;
		case RE3:  PDC2 = ui16DutyCycle; break;
		case RE4:  SDC3 = ui16DutyCycle; break;
		case RE5:  PDC3 = ui16DutyCycle; break;
		case RE6:  SDC4 = ui16DutyCycle; break;
		case RE7:  PDC4 = ui16DutyCycle; break;
        default:  break;
    }
}

/*
void initOutputCompare()
{
    OC1CON1 = OC2CON1 = OC3CON1 = OC4CON1 = OC5CON1 = OC6CON1 = OC7CON1 = OC8CON1 = OC9CON1 = OC10CON1 = OC11CON1 = OC12CON1 = OC13CON1 = OC14CON1 = OC15CON1 = OC16CON1 = 0;
    OC1CON2 = OC2CON2 = OC3CON2 = OC4CON2 = OC5CON2 = OC6CON2 = OC7CON2 = OC8CON2 = OC9CON2 = OC10CON2 = OC11CON2 = OC12CON2 = OC13CON2 = OC14CON2 = OC15CON2 = OC16CON2 = 0;
    
    OC1CON1bits.OCTSEL = OC2CON1bits.OCTSEL = OC3CON1bits.OCTSEL = OC4CON1bits.OCTSEL = OC5CON1bits.OCTSEL = OC6CON1bits.OCTSEL = OC7CON1bits.OCTSEL = OC8CON1bits.OCTSEL = OC9CON1bits.OCTSEL = OC10CON1bits.OCTSEL = OC11CON1bits.OCTSEL = OC12CON1bits.OCTSEL = OC13CON1bits.OCTSEL = OC14CON1bits.OCTSEL = OC15CON1bits.OCTSEL = OC16CON1bits.OCTSEL =0x07;
        
    OC1R = OC2R = OC3R = OC4R = OC5R = OC6R = OC7R = OC8R = OC9R = OC10R = OC11R = OC12R = OC13R = OC14R = OC15R = OC16R = 1000;
    OC1RS = OC2RS = OC3RS = OC4RS = OC5RS = OC6RS = OC7RS = OC8RS = OC9RS = OC10RS = OC11RS = OC12RS = OC13RS = OC14RS = OC15RS = OC16RS = 2000;
    
    OC1CON2bits.SYNCSEL = OC2CON2bits.SYNCSEL = OC3CON2bits.SYNCSEL = OC4CON2bits.SYNCSEL = OC5CON2bits.SYNCSEL = OC6CON2bits.SYNCSEL = OC7CON2bits.SYNCSEL = OC8CON2bits.SYNCSEL = OC9CON2bits.SYNCSEL = OC10CON2bits.SYNCSEL = OC11CON2bits.SYNCSEL = OC12CON2bits.SYNCSEL = OC13CON2bits.SYNCSEL = OC14CON2bits.SYNCSEL = OC15CON2bits.SYNCSEL = OC16CON2bits.SYNCSEL = 0x1F;
       
    OC1CON1bits.OCM = OC2CON1bits.OCM = OC3CON1bits.OCM = OC4CON1bits.OCM = OC5CON1bits.OCM = OC6CON1bits.OCM = OC7CON1bits.OCM = OC8CON1bits.OCM = OC9CON1bits.OCM = OC10CON1bits.OCM = OC11CON1bits.OCM = OC12CON1bits.OCM = OC13CON1bits.OCM = OC14CON1bits.OCM = OC15CON1bits.OCM = OC16CON1bits.OCM =6;

    //OUTPUT Port Mapping
    __builtin_write_OSCCONL(OSCCON & ~(1<<6));
    _RP64R = 0b010000; //OC1
    _RP65R = 0b010001; //OC2
    __builtin_write_OSCCONL(OSCCON | (1<<6));
}*/

void initOutputCompare()
{
    OC1CON1 = 0;
    OC1CON2 = 0;
    
    OC1CON1bits.OCTSEL  =0x07;
        
    OC1R =  7500;
    OC1RS = 35000;
    
    OC1CON2bits.SYNCSEL = 0x1F;
       
    OC1CON1bits.OCM =6;

    //OUTPUT Port Mapping
    __builtin_write_OSCCONL(OSCCON & ~(1<<6));
    _RP64R = 0b010000; //OC1
    //_RP65R = 0b010001; //OC2
    __builtin_write_OSCCONL(OSCCON | (1<<6));
}

void initOutputComparePwm(uint8_t OC_Pin)
{
    switch(OC_Pin)
    {
        case OC1_Pin:
            OC1CON1 = 0;
            OC1CON2 = 0;
            OC1CON1bits.OCTSEL  =0x07;
            OC1R =  1750;
            OC1RS = 3500;
            OC1CON2bits.SYNCSEL = 0x1F;
            OC1CON1bits.OCM =6;
            break;

        case OC2_Pin:
            OC2CON1 = 0;
            OC2CON2 = 0;
            OC2CON1bits.OCTSEL  =0x07;
            OC2R =  1750;
            OC2RS = 3500;
            OC2CON2bits.SYNCSEL = 0x1F;
            OC2CON1bits.OCM =6;
            break;
            
        case OC3_Pin:
            OC3CON1 = 0;
            OC3CON2 = 0;
            OC3CON1bits.OCTSEL  =0x07;
            OC3R =  1750;
            OC3RS = 3500;
            OC3CON2bits.SYNCSEL = 0x1F;
            OC3CON1bits.OCM =6;
            break;

        case OC4_Pin:
            OC4CON1 = 0;
            OC4CON2 = 0;
            OC4CON1bits.OCTSEL  =0x07;
            OC4R =  1750;
            OC4RS = 3500;
            OC4CON2bits.SYNCSEL = 0x1F;
            OC4CON1bits.OCM =6;
            break;

        case OC5_Pin:
            OC5CON1 = 0;
            OC5CON2 = 0;
            OC5CON1bits.OCTSEL  =0x07;
            OC5R =  1750;
            OC5RS = 3500;
            OC5CON2bits.SYNCSEL = 0x1F;
            OC5CON1bits.OCM =6;
            break;

        case OC6_Pin:
            OC6CON1 = 0;
            OC6CON2 = 0;
            OC6CON1bits.OCTSEL  =0x07;
            OC6R =  1750;
            OC6RS = 3500;
            OC6CON2bits.SYNCSEL = 0x1F;
            OC6CON1bits.OCM =6;
            break;

        case OC7_Pin:
            OC7CON1 = 0;
            OC7CON2 = 0;
            OC7CON1bits.OCTSEL  =0x07;
            OC7R =  1750;
            OC7RS = 3500;
            OC7CON2bits.SYNCSEL = 0x1F;
            OC7CON1bits.OCM =6;
            break;

        case OC8_Pin:
            OC8CON1 = 0;
            OC8CON2 = 0;
            OC8CON1bits.OCTSEL  =0x07;
            OC8R =  1750;
            OC8RS = 3500;
            OC8CON2bits.SYNCSEL = 0x1F;
            OC8CON1bits.OCM =6;
            break;
        
        case OC9_Pin:
            OC9CON1 = 0;
            OC9CON2 = 0;
            OC9CON1bits.OCTSEL  =0x07;
            OC9R =  1750;
            OC9RS = 3500;
            OC9CON2bits.SYNCSEL = 0x1F;
            OC9CON1bits.OCM =6;
            break;
            
        case OC10_Pin:
            OC10CON1 = 0;
            OC10CON2 = 0;
            OC10CON1bits.OCTSEL  =0x07;
            OC10R =  1750;
            OC10RS = 3500;
            OC10CON2bits.SYNCSEL = 0x1F;
            OC10CON1bits.OCM =6;
            break;
            
        case OC11_Pin:
            OC11CON1 = 0;
            OC11CON2 = 0;
            OC11CON1bits.OCTSEL  =0x07;
            OC11R =  1750;
            OC11RS = 3500;
            OC11CON2bits.SYNCSEL = 0x1F;
            OC11CON1bits.OCM =6;
            break;
            
        case OC12_Pin:
            OC12CON1 = 0;
            OC12CON2 = 0;
            OC12CON1bits.OCTSEL  =0x07;
            OC12R =  1750;
            OC12RS = 3500;
            OC12CON2bits.SYNCSEL = 0x1F;
            OC12CON1bits.OCM =6;
            break;
            
        case OC13_Pin:
            OC13CON1 = 0;
            OC13CON2 = 0;
            OC13CON1bits.OCTSEL  =0x07;
            OC13R =  1750;
            OC13RS = 3500;
            OC13CON2bits.SYNCSEL = 0x1F;
            OC13CON1bits.OCM =6;
            break;
            
        case OC14_Pin:
            OC14CON1 = 0;
            OC14CON2 = 0;
            OC14CON1bits.OCTSEL  =0x07;
            OC14R =  1750;
            OC14RS = 3500;
            OC14CON2bits.SYNCSEL = 0x1F;
            OC14CON1bits.OCM =6;
            break;
            
        case OC15_Pin:
            OC15CON1 = 0;
            OC15CON2 = 0;
            OC15CON1bits.OCTSEL  =0x07;
            OC15R =  1750;
            OC15RS = 3500;
            OC15CON2bits.SYNCSEL = 0x1F;
            OC15CON1bits.OCM =6;
            break;
            
        case OC16_Pin:
            OC16CON1 = 0;
            OC16CON2 = 0;
            OC16CON1bits.OCTSEL  =0x07;
            OC16R =  1750;
            OC16RS = 3500;
            OC16CON2bits.SYNCSEL = 0x1F;
            OC16CON1bits.OCM =6;
            break;
    }
}

void setOutputCompareValues(uint8_t OC_Pin, uint16_t ui16PeriodTime, uint16_t ui16HighTime)
{
    switch(OC_Pin)
    {
        case OC1_Pin:
            OC1R = ui16HighTime;
            OC1RS = ui16PeriodTime;
            break;
        case OC2_Pin:
            OC2R = ui16HighTime;
            OC2RS = ui16PeriodTime;
            break;
        case OC3_Pin:
            OC3R = ui16HighTime;
            OC3RS = ui16PeriodTime;
            break;
        case OC4_Pin:
            OC4R = ui16HighTime;
            OC4RS = ui16PeriodTime;
            break;
        case OC5_Pin:
            OC5R = ui16HighTime;
            OC5RS = ui16PeriodTime;
            break;
        case OC6_Pin:
            OC6R = ui16HighTime;
            OC6RS = ui16PeriodTime;
            break;
        case OC7_Pin:
            OC7R = ui16HighTime;
            OC7RS = ui16PeriodTime;
            break;
        case OC8_Pin:
            OC8R = ui16HighTime;
            OC8RS = ui16PeriodTime;
            break;
        case OC9_Pin:
            OC9R = ui16HighTime;
            OC9RS = ui16PeriodTime;
            break;
        case OC10_Pin:
            OC10R = ui16HighTime;
            OC10RS = ui16PeriodTime;
            break;
        case OC11_Pin:
            OC11R = ui16HighTime;
            OC11RS = ui16PeriodTime;
            break;
        case OC12_Pin:
            OC12R = ui16HighTime;
            OC12RS = ui16PeriodTime;
            break;
        case OC13_Pin:
            OC13R = ui16HighTime;
            OC13RS = ui16PeriodTime;
            break;
        case OC14_Pin:
            OC14R = ui16HighTime;
            OC14RS = ui16PeriodTime;
            break;
        case OC15_Pin:
            OC15R = ui16HighTime;
            OC15RS = ui16PeriodTime;
            break;
        case OC16_Pin:
            OC16R = ui16HighTime;
            OC16RS = ui16PeriodTime;
            break;
    }
}

void EdaBoardOutputMapping()
{
    __builtin_write_OSCCONL(OSCCON & ~(1<<6));
    _RP64R = 0b010000; //OC1
    _RP65R = 0b010001; //OC2
    __builtin_write_OSCCONL(OSCCON | (1<<6));
}

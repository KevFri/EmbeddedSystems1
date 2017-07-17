#include"edaPIC33PWM.h"
#include<xc.h>



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
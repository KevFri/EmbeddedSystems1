
#include"edaPIC33OutputCompare.h"

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


void initOutputComparePwm(uint8_t OC_Pin)
{
    switch(OC_Pin) //SETUP FOR PWM OPERATION
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

//setOutputCompareValues(OC1_Pin, msPeriod ,msPeriod/2);
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




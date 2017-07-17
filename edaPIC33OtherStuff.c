
#include "edaPIC33OtherStuff.h"
#include<stdint.h>
#include<xc.h>
#include"edaPIC33Hardware.h"
#include<math.h>
#include<stdio.h>
#include"edaPIC33OutputCompare.h"
#include"edaPIC33Setup.h"

void FlipFlopLED0(uint8_t ui8SwitchState)
{
    static uint8_t ui8OldSwitchState = HIGH;
    
    if(ui8OldSwitchState == HIGH && ui8SwitchState == LOW) //Flanke von HIGH auf LOW
    {
        digitalToggle(LED0);
    }
    ui8OldSwitchState=ui8SwitchState;
    
}

void digitalCountLED0to3(uint8_t ui8SwitchState)
{
    static uint8_t ui8OldSwitchState = HIGH;
    static uint8_t ui8CountValue=0;
    
    if(ui8OldSwitchState == HIGH && ui8SwitchState == LOW) //Flanke von HIGH auf LOW
    {
        ui8CountValue++;
        digitalWrite(LED0, ui8CountValue&0x01);
        digitalWrite(LED1, ui8CountValue&0x02); 
        digitalWrite(LED2, ui8CountValue&0x04);
        digitalWrite(LED3, ui8CountValue&0x08);
    }
    ui8OldSwitchState=ui8SwitchState;
}


void Treppenlichtautomat(uint8_t ui8SwitchState, uint8_t ui8LedPin, const uint32_t cui32OnTime, const uint32_t cui32TurnOffTime)
{
    #define STATE_LIGHT_ON 0
    #define STATE_LIGHT_OFF 1
    #define STATE_LIGTH_TURNOFF 2
    static uint8_t ui8OldSwitchState = HIGH;
    static uint32_t ui32CountValue=0;
    static uint8_t ui8State = STATE_LIGHT_OFF;
    
    if(ui8OldSwitchState == HIGH && ui8SwitchState == LOW) //Flanke von HIGH auf LOW
    {
        //nachtriggern
        ui32CountValue=0;
        digitalWrite(ui8LedPin, HIGH);
        ui8State=STATE_LIGHT_ON;
    }
    else
    {
        switch(ui8State)
        {
            case STATE_LIGHT_ON:
                ui32CountValue++;
                if(ui32CountValue >= cui32OnTime)
                {
                    ui32CountValue=0;
                    ui8State=STATE_LIGTH_TURNOFF;
                }
                break;
            case STATE_LIGTH_TURNOFF:
                ui32CountValue++;
                uint8_t ui8DutyCycle = (uint8_t)((ui32CountValue*100)/(cui32TurnOffTime));
                SoftwarePwm(ui8LedPin,25, 100-ui8DutyCycle);
                
                if(ui32CountValue>=cui32TurnOffTime)
                {
                    ui32CountValue=0;
                    digitalWrite(ui8LedPin, LOW);
                    ui8State=STATE_LIGHT_OFF;
                }
                break;
            case STATE_LIGHT_OFF:
                //do nothing wait for state change with falling edge
                break;
            default:
                //do nothing
                break;                
        }
    } 
    ui8OldSwitchState=ui8SwitchState;
}

/*
void SoftwarePwm(uint8_t ui8Pin, const uint8_t cui8PeriodTime, uint8_t ui8DutyCycle)
{
    static uint8_t ui8Count=0;
    uint8_t ui8OutputState=digitalRead(ui8Pin);
    uint8_t ui8OnTime  = (uint8_t)((((uint16_t)cui8PeriodTime)*((uint16_t) ui8DutyCycle)/100));
    uint8_t ui8OffTime = cui8PeriodTime-ui8OnTime;
    ui8Count++;
    if(ui8OutputState == HIGH)
    {  
        if(ui8Count >= ui8OnTime)
        {
            digitalWrite(ui8Pin, LOW);
            ui8Count=0;
        }
    }
    else //ui8OutputState == LOW
    {
        if(ui8Count >= ui8OffTime)
        {
            digitalWrite(ui8Pin, HIGH);
            ui8Count=0;
        }        
    }    
}*/

void SoftwarePwm(uint8_t ui8Pin, const uint8_t cui8PeriodTime, uint8_t ui8DutyCycle)
{
    static uint8_t ui8Count=0;
    static uint8_t ui8OutputState=LOW;
    uint8_t ui8OnTime  = (uint8_t)((((uint16_t)cui8PeriodTime)*((uint16_t) ui8DutyCycle)/100));
    uint8_t ui8OffTime = cui8PeriodTime-ui8OnTime;
    ui8Count++;
    if(ui8OutputState == HIGH)
    {  
        if(ui8Count >= ui8OnTime)
        {
            digitalWrite(ui8Pin, LOW);
            ui8OutputState=LOW;
            ui8Count=0;
        }
    }
    else //ui8OutputState == LOW
    {
        if(ui8Count >= ui8OffTime)
        {
            digitalWrite(ui8Pin, HIGH);
            ui8OutputState=HIGH;
            ui8Count=0;
        }        
    }    
}



#define HYSTERESE_ON 524
#define HYSTERESE_OFF 500
#define STATE_ON 1
#define STATE_OFF 0
uint8_t createHystere(int16_t  i16InputValue)
{
    static uint8_t ui8State = STATE_OFF;
    
    if(ui8State == STATE_OFF)
    {
        if(i16InputValue >= HYSTERESE_ON)
        {
            ui8State = STATE_ON;
            return STATE_ON;
        }
        else
        {
            return STATE_OFF;
        }
        
    }
   else //(ui8State == STATE_ON)
   {
        if(i16InputValue <= HYSTERESE_OFF)
        {
            ui8State = STATE_OFF;
            return STATE_OFF;
        }
        else
        {
            return STATE_ON;
        }
   }
   return STATE_OFF;
}

#define COMPARATOR_THRESHOLD 512
uint8_t createComparator(int16_t  i16InputValue)
{
    if(i16InputValue>=COMPARATOR_THRESHOLD)
        return 1;
    else
        return 0;
}

#define Vss 1024
#define Pi 3.14159265359
#define T 20
void sinusGenerator(uint8_t OutputComparePort)
{
    static uint16_t t=0;
    uint16_t ui16Magnitude = (uint16_t) ((Vss/2)*(1.0+sin(2.0*Pi*((double)t)/((double)T)))) ;
    
    setOutputCompareValues(OutputComparePort, Vss, ui16Magnitude);
    t++;
    if(t >= T)
        t=0;
}

//sinusGeneratorTimeBase(OC1_Pin, msPeriod);
void sinusGeneratorTimeBase(uint8_t OutputComparePort, uint16_t msPeriod)
{
    static uint16_t t=0;
    uint16_t ui16Magnitude = (uint16_t) ((Vss/2)*(1.0+sin(2.0*Pi*((double)t)/((double)msPeriod)))) ;
    
    setOutputCompareValues(OutputComparePort, Vss, ui16Magnitude);
    t++;
    if(t >= msPeriod)
        t=0;
}

void sawtoothGenerator(uint8_t OutputComparePort)
{
    static uint16_t t=0;
    uint16_t ui16Magnitude = (((float)Vss*(float)t)/(float)T);
    setOutputCompareValues(OutputComparePort, Vss, ui16Magnitude);
    t++;
    if(t >= T)
        t=0;
}
void sawtoothGeneratorTimeBase(uint8_t OutputComparePort, uint16_t msPeriod)
{
    static uint16_t t=0;
    uint16_t ui16Magnitude = (((float)Vss*(float)t)/(float)msPeriod);
    setOutputCompareValues(OutputComparePort, Vss, ui16Magnitude);
    t++;
    if(t >= msPeriod)
        t=0;
}

//triangleGenerator(OC1_Pin);     
void triangleGenerator(uint8_t OutputComparePort)
{
    static uint16_t t=0;
    uint16_t ui16Magnitude = 0;
    
    if(t < T/2)
        ui16Magnitude = (uint16_t) Vss*(1.0-(2*(float)t)/(float)T);
    else
        ui16Magnitude = (uint16_t) Vss*(((2*(float)t)/(float)T)-1.0);
    
    setOutputCompareValues(OutputComparePort, Vss, ui16Magnitude);
    t++;
    if(t >= T)
        t=0;
}


#define STOPWATCH_ON  1
#define STOPWATCH_OFF 0
uint8_t stopWatch(char* str, uint8_t Switch)
{
    static uint8_t STATE = STOPWATCH_OFF;
    static uint8_t ui8OldSwitch=0;
    static uint32_t ui32MilliCounts=0;
    if(ui8OldSwitch == 0 && Switch == 1) //rising Edge
    {
        (STATE == STOPWATCH_ON) ? (STATE = STOPWATCH_OFF) : (STATE = STOPWATCH_ON);
        if( STATE==STOPWATCH_ON )
            ui32MilliCounts=0;
    }
    
    if( STATE==STOPWATCH_ON )
    {
        ui32MilliCounts++;
    }
    
    uint8_t NumOfPrintedChar = (uint8_t) sprintf(str,"%02lu:%02lu:%03lu",(ui32MilliCounts/60000)%60,(ui32MilliCounts/1000)%60,ui32MilliCounts%1000);
    
    //fill the rest rest of line (16) with ' ' 
    for(;NumOfPrintedChar<16;NumOfPrintedChar++)
        str[NumOfPrintedChar]=' ';
    
    ui8OldSwitch = Switch;
    return STATE;
}
//stopWatch(&DataString[16], !isPressed(INCSW)) == 0 ? setLCDLine("OFF",1):setLCDLine("ON",1);         

char* createFortschrittsbalken(char *pStr, int16_t i16Value)
{
        uint8_t i; 
        for(i=0; i<(i16Value/64);i++)
            pStr[i] = 0xFF; 
        pStr[i++] = (uint8_t)(i16Value%64)/12;
        for(; i<16;i++)
            pStr[i] = ' '; 
        return pStr;
}

char* createFortschrittsbalken2(char *pStr, uint16_t ui16Value, uint16_t ui16MaxValue)
{
        uint8_t i;
        uint16_t uiDivider = ui16MaxValue/16;
        for(i=0; i<(ui16Value/uiDivider);i++)
            pStr[i] = 0xFF; 
        pStr[i++] = (uint8_t)((ui16Value%uiDivider)/(uiDivider/5));
        for(; i<16;i++)
            pStr[i] = ' '; 
        return pStr;
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

uint8_t isPressed2(uint8_t ui8Port, uint8_t num)
{
    //static uint8_t ui8State = STATE_STABLE_HIGH; //default state
    static uint16_t ui16AllStates = 0xFFFF; //default all states to high
    static uint16_t ui16Counter=0;
    
    uint8_t ui8State = (uint8_t) ((ui16AllStates & (0x0003 << 2*num))>> 2*num); //read state
    
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
    
    //save states
    setBit(&ui16AllStates, (2*num), getBit((uint16_t) ui8State, 0));
    setBit(&ui16AllStates, (2*num+1), getBit((uint16_t) ui8State, 1));
    
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

uint8_t isPrim(uint32_t ui32Number){

    if(ui32Number==0 || ui32Number==1)
        return 0;

    if((ui32Number%2)==0)
    {
        if(ui32Number==2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    uint32_t ui32Divider;
    uint32_t ui32SqrtNumber =((uint32_t) sqrt((long double)(ui32Number)))+1;

    for(ui32Divider=3; ui32Divider<ui32SqrtNumber; ui32Divider+=2)
    {
        if((ui32Number%ui32Divider) == 0) //check if ui32Divider is a in whole divider of ui32Number
        {
            return 0; //uiNumber32 isn't a prime number
        }
    }
    return 1; //ui32Number is a Prime Number
}
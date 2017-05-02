#include <stdint.h>
#include <xc.h> 
#include "edaPIC33SystemTime.h"
#include "edaPIC33Hardware.h"

void blinkLed0(uint16_t ui16ToggleTime)
{
    static uint16_t ui16Counter = 0;
    ui16Counter++;
    if(ui16Counter >= ui16ToggleTime)
    {
        ui16Counter=0;
        digitalToggle(LED0);
    }
}

void blinkLed1(uint16_t ui16ToggleTime)
{
    static uint16_t ui16Counter = 0;
    ui16Counter++;
    if(ui16Counter >= ui16ToggleTime)
    {
        ui16Counter=0;
        digitalToggle(LED1);
    }
}

void blinkLed2(uint16_t ui16ToggleTime)
{
    static uint16_t ui16Counter = 0;
    ui16Counter++;
    if(ui16Counter >= ui16ToggleTime)
    {
        ui16Counter=0;
        digitalToggle(LED2);
    }
}

void blinkLed3(uint16_t ui16ToggleTime)
{
    static uint16_t ui16Counter = 0;
    ui16Counter++;
    if(ui16Counter >= ui16ToggleTime)
    {
        ui16Counter=0;
        digitalToggle(LED3);
    }
}

uint16_t measureToggleTimeSW0()
{
    static uint16_t ui16ToggleTime=0;
    static uint8_t  ui8MeasureMode=0;
    
    if(digitalRead(SW0)==LOW && (ui8MeasureMode==0))
    {
        ui16ToggleTime=0;
        ui8MeasureMode=1;
    }
    
    if(ui8MeasureMode==1)
    {
        ui16ToggleTime++;
        if(digitalRead(SW0)==HIGH)
            ui8MeasureMode=0;
    }
    
    return ui16ToggleTime;
}

uint16_t measureToggleTimeSW1()
{
    static uint16_t ui16ToggleTime=0;
    static uint8_t  ui8MeasureMode=0;
    
    if(digitalRead(SW1)==LOW && (ui8MeasureMode==0))
    {
        ui16ToggleTime=0;
        ui8MeasureMode=1;
    }
    
    if(ui8MeasureMode==1)
    {
        ui16ToggleTime++;
        if(digitalRead(SW1)==HIGH)
            ui8MeasureMode=0;
    }
    
    return ui16ToggleTime;
}

uint16_t measureToggleTimeSW2()
{
    static uint16_t ui16ToggleTime=0;
    static uint8_t  ui8MeasureMode=0;
    
    if(digitalRead(SW2)==LOW && (ui8MeasureMode==0))
    {
        ui16ToggleTime=0;
        ui8MeasureMode=1;
    }
    
    if(ui8MeasureMode==1)
    {
        ui16ToggleTime++;
        if(digitalRead(SW2)==HIGH)
            ui8MeasureMode=0;
    }
    
    return ui16ToggleTime;
}

uint16_t measureToggleTimeSW3()
{
    static uint16_t ui16ToggleTime=0;
    static uint8_t  ui8MeasureMode=0;
    
    if(digitalRead(SW3)==LOW && (ui8MeasureMode==0))
    {
        ui16ToggleTime=0;
        ui8MeasureMode=1;
    }
    
    if(ui8MeasureMode==1)
    {
        ui16ToggleTime++;
        if(digitalRead(SW3)==HIGH)
            ui8MeasureMode=0;
    }
    
    return ui16ToggleTime;
}

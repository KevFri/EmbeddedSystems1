#include "edaPIC33LCD.h"
#include "edaPIC33Hardware.h"
#include <string.h>

char ShadowString[32];  
//char* pShadowStringLine1 = &ShadowString[0];
//char* pShadowStringLine2 = &ShadowString[16];

//uint8_t ui8LineUpdateFlag=0; // Bit0: Line1, Bit1: Line2

void initMyLCD()
{
    // 15mS delay after Vdd reaches nnVdc before proceeding with LCD initialization
    // not always required and is based on system Vdd rise rate
    //Delay( Delay_15mS_Cnt );        // 15ms delay
    uint16_t ui16I=0;
    while(ui16I++<0xFFFF)Nop();

    /* set initial states for the data and control pins */
    DATA &= 0xFF00; //set RE0-RE7 low
    RW = 0;                         // R/W state set low
    RS = 0;                         // RS state set low
    E = 0;                          // E state set low

    /* set data and control pins to outputs */
    TRISE &= 0xFF00;                //set RE0-RE7 to output
    RW_TRIS = 0;                    // RW pin set as output
    RS_TRIS = 0;                    // RS pin set as output
    E_TRIS = 0;                     // E pin set as output

    /* 1st LCD initialization sequence */
    DATA &= 0xFF00;                 //set RE0-RE7 low
    DATA |= 0x0038;                  //set lcd type: 8-bit,2lines,5x7
    clockLCDenable();                       // toggle E signal
    //Delay( Delay_5mS_Cnt );         // 5ms delay
    ui16I=0;
    while(ui16I++<23256)Nop();

    // 2nd LCD initialization sequence
    DATA &= 0xFF00;
    DATA |= 0x0038;
    clockLCDenable();                        // toggle E signal
    //Delay_Us( Delay200uS_count );   // 200uS delay
    ui16I=0;
    while(ui16I++<4651)Nop();

    // 3rd LCD initialization sequence
    DATA &= 0xFF00;
    DATA |= 0x0038;
    clockLCDenable();
    //Delay_Us( Delay200uS_count );   // 200uS delay
    ui16I=0;
    while(ui16I++<4651)Nop();

    sendCommandLCD( 0x38 );                // function set 8bit, 2lines
    sendCommandLCD( 0x0C );                // Display on control, cursor blink off (0x0C), cursor off
    sendCommandLCD( 0x06 );                // entry mode set (0x06), increment cursor, no shift 
}



void sendCommandLCD(uint8_t ui8data)
{
    DATA &= 0xFF00;         // prepare RD0 - RD7 , set RE7-RE0 to LOW
    DATA |= ui8data;        // command byte to lcd , wirte data to RE7-RE0
    RW = 0;                 // ensure RW is 0
    RS = 0;
    clockLCDenable();
    //Delay( Delay_5mS_Cnt ); // 5ms delay
    uint16_t ui16I=0;
    while(ui16I++<23256)Nop();
}

void sendCommandLCDNonBlocking(uint8_t ui8data)
{
    DATA &= 0xFF00;         // prepare RD0 - RD7 , set RE7-RE0 to LOW
    DATA |= ui8data;        // command byte to lcd , wirte data to RE7-RE0
    RW = 0;                 // ensure RW is 0
    RS = 0;
    clockLCDenable();
}


void writeDataLCD(uint8_t ui8data)
{
    RW = 0;         // ensure RW is 0
    RS = 1;         // assert register select to 1
    DATA &= 0xFF00; // prepare RD0 - RD7 set RE7-RE0 to LOW
    DATA |= ui8data;   // data byte to lcd,  write data to RE7-RE0
    clockLCDenable();
    RS = 0;         // negate register select to 0
    //Delay_Us( Delay200uS_count );   // 200uS delay
    //Delay_Us( Delay200uS_count );   // 200uS delay
    uint16_t ui16I=0;
    while(ui16I++<4651)Nop();
}

void writeDataLCDNonBlocking(uint8_t ui8data)
{
    RW = 0;         // ensure RW is 0
    RS = 1;         // assert register select to 1
    DATA &= 0xFF00; // prepare RD0 - RD7 set RE7-RE0 to LOW
    DATA |= ui8data;   // data byte to lcd,  write data to RE7-RE0
    clockLCDenable();
    RS = 0;         // negate register select to 0
    //Delay_Us( Delay200uS_count );   // 200uS delay
    //Delay_Us( Delay200uS_count );   // 200uS delay
    //uint16_t ui16I=0;
    //while(ui16I++<4651)Nop();
}

void clockLCDenable()
{
    E = 1;
    Nop();
    Nop();
    Nop();
    Nop();
    E = 0;          // toggle E signal
    
}

void setDDRAMAddressLCD(uint8_t ui8address)
{
    
}


uint8_t readBusyFlagLCD()
{
 
    uint8_t ui8ReturnValue=0;
    RS = 0;
    RW = 1;

   //set RE7-RE0 to PinMode Digital Input, Pulldown
   ANSELE &= 0xFF00;
   CNENE &= 0xFF00;
   CNPUE &= 0xFF00;
   CNPDE &= 0xFF00;
   TRISE |= 0x00FF;
   CNPDE |= 0x00FF;
   
   clockLCDenable();
   
   //read busy flag
   if(PORTE&0x0080) 
   {
       ui8ReturnValue=1;
       
   }
   
    //set RE7-RE0 to PinMode Digital Output
   ANSELE &= 0xFF00;
   CNENE &= 0xFF00;
   CNPUE &= 0xFF00;  
   CNPDE &= 0xFF00;
   TRISE &= 0xFF00;

    RS = 0;
    RW = 0;
   return ui8ReturnValue;
}



/*void putcLCD(uint8_t *buffer, uint8_t ui8count)
{
    while (ui8count)
    {
        writeDataLCD(*buffer++);
        ui8count--;
    }
}*/

void putcLCD(char c)
{
    writeDataLCD((uint8_t)c);
}

void putsLCD(char* pData)
{
    //uint8_t ui8Count=0;
    //for(ui8Count=0; pData[ui8Count]!='\0'; ui8Count++);
    //putcLCD((uint8_t*)pData, ui8Count);
    
    /*uint8_t ui8Count=0;
    while(pData[ui8Count] != '\0')
    {
        writeDataLCD(pData[ui8Count++]);
        if(ui8Count==16)
            line_2();
    }*/
    while(*pData != '\0')
        writeDataLCD(*pData++);
}

void putncLCD(char* pData, uint8_t ui8n)
{
    //uint8_t ui8Count=0;
    //for(ui8Count=0; pData[ui8Count]!='\0'; ui8Count++);
    //putcLCD((uint8_t*)pData, ui8Count);
    
    uint8_t ui8Count=0;
    while(ui8Count<ui8n)
        writeDataLCD(pData[ui8Count++]);
}

void clearShadowString()
{
    ShadowString[0]='\0';
    ShadowString[16]='\0';
}

#define STATE_WRITE_LINE_1 0
#define STATE_WRITE_LINE_2 1
#define STATE_WRITE_LINE_1_SPACES 2
#define STATE_WRITE_LINE_2_SPACES 3
//#define STATE_IDLE 4

void writeShadowStringToLCD()
{
    //static variables
    static uint8_t ui8Position=0;
    static uint8_t ui8State=0;
    
    if (readBusyFlagLCD())
    {
        //return; //break if LCD is busy
    }
    else
    {
        //LATBbits.LATB8=0;
        switch(ui8State)
        {          
            case STATE_WRITE_LINE_1:
                
                if(ShadowString[ui8Position] != '\0' && ui8Position<16)
                {
                    writeDataLCDNonBlocking((uint8_t) ShadowString[ui8Position]);
                    ui8Position++;
                }
                else
                {
                    if(ui8Position == 16)
                    {
                        sendCommandLCDNonBlocking( 0xC0 ); //line_2(); //set cursor line 
                        ui8State = STATE_WRITE_LINE_2;
                    }
                    else                       
                        ui8State=STATE_WRITE_LINE_1_SPACES;
                }
                
                break;
            
            case STATE_WRITE_LINE_1_SPACES:
                
                if(ui8Position<16)
                {
                    writeDataLCD((uint8_t) ' ');
                    ui8Position++;
                }
                else
                {
                       sendCommandLCDNonBlocking( 0xC0 ); //line_2(); //set cursor line 
                       ui8State = STATE_WRITE_LINE_2;
                       ui8Position=16;
                }                
                break;
            
            case STATE_WRITE_LINE_2:
                
                if(ShadowString[ui8Position] != '\0' && ui8Position<32)
                {
                    writeDataLCD((uint8_t) ShadowString[ui8Position]);
                    ui8Position++;
                }
                else
                {
                    ui8State=STATE_WRITE_LINE_2_SPACES;
                }
                
                break;
            
            case STATE_WRITE_LINE_2_SPACES:
                
                if(ui8Position<32)
                {
                    writeDataLCD((uint8_t) ' ');
                    ui8Position++;
                }
                else
                {
                    sendCommandLCDNonBlocking( 0x02 );
                    ui8State = STATE_WRITE_LINE_1;
                    ui8Position=0;
                    
                    //ui8LineUpdateFlag &= 0xFD; //clear Flag
                }                
                break;
        }
    }   
}

void setLineLCD(const char* pStr, uint8_t ui8Line)
{
    if(ui8Line==1)
        strncpy(&ShadowString[0],pStr,16);
    else if(ui8Line == 2)
        strncpy(&ShadowString[16],pStr,16);
    else; //do nothing
}

void setLCDLine1(const char* pString)
{   
    strncpy(&ShadowString[0],pString,16);
    //ui8LineUpdateFlag |= 0x01; //set Flag
}
void setLCDLine2(const char* pString)
{
    strncpy(&ShadowString[16],pString,16);
    //ui8LineUpdateFlag |= 0x02; //set Flag
}

/* old Function
void writeShadowStringToLCD()
{
    //static variables
    static uint8_t ui8Position=0;
    static uint8_t ui8State=0;
    
    if (readBusyFlagAndAddressLCD())
    {
        return; //break if LCD is busy
    }
    else
    {
        switch(ui8State)
        {
            case STATE_IDLE:
                if(ui8LineUpdateFlag&0x01)
                {
                    
                    sendCommandLCDNonBlocking(0x02);//home_it(); //set cursor line 1
                    ui8State = STATE_WRITE_LINE_1;
                    ui8Position=0;
                }
                else if(ui8LineUpdateFlag&0x02)
                {
                   
                   sendCommandLCDNonBlocking( 0xC0 ); //line_2(); //set cursor line 2
                   ui8State = STATE_WRITE_LINE_2;
                   ui8Position=16;
                }
                break;
            
            case STATE_WRITE_LINE_1:
                
                if(ShadowString[ui8Position] != '\0' && ui8Position<16)
                {
                    writeDataLCD((uint8_t) ShadowString[ui8Position]);
                    ui8Position++;
                }
                else
                {
                    if(ui8Position == 16)
                    {
                        sendCommandLCDNonBlocking( 0xC0 ); //line_2(); //set cursor line 
                        ui8State = STATE_WRITE_LINE_2;
                    }
                    else                       
                        ui8State=STATE_WRITE_LINE_1_SPACES;
                }
                
                break;
            
            case STATE_WRITE_LINE_1_SPACES:
                
                if(ui8Position<16)
                {
                    writeDataLCD((uint8_t) ' ');
                    ui8Position++;
                }
                else
                {
                    if(ui8LineUpdateFlag&0x02)
                    {
                       sendCommandLCDNonBlocking( 0xC0 ); //line_2(); //set cursor line 
                       ui8State = STATE_WRITE_LINE_2;
                       ui8Position=16;
                    }
                    else
                    {
                        ui8State = STATE_IDLE;
                    }
                    ui8LineUpdateFlag &= 0xFE; //clear Flag
                }                
                break;
            
            case STATE_WRITE_LINE_2:
                
                if(ShadowString[ui8Position] != '\0' && ui8Position<32)
                {
                    writeDataLCD((uint8_t) ShadowString[ui8Position]);
                    ui8Position++;
                }
                else
                {
                    ui8State=STATE_WRITE_LINE_2_SPACES;
                }
                
                break;
            
            case STATE_WRITE_LINE_2_SPACES:
                
                if(ui8Position<32)
                {
                    writeDataLCD((uint8_t) ' ');
                    ui8Position++;
                }
                else
                {
                    ui8State = STATE_IDLE;
                    ui8LineUpdateFlag &= 0xFD; //clear Flag
                }                
                break;
        }
    }   
}
*/
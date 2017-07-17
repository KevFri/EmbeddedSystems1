#include "edaPIC33LCD.h"
#include "edaPIC33Hardware.h"
#include <string.h>

char DataString[32];  

//uint8_t ui8LineUpdateFlag=0; // Bit0: Line1, Bit1: Line2

void initMyLCD()
{
    // 15mS delay after Vdd reaches nnVdc before proceeding with LCD initialization
    // not always required and is based on system Vdd rise rate
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

void clearLCDStorage()
{
    uint8_t i;
    for(i=0;i<32;DataString[i++]=' ');
}

void sendDataToLCD()
{
        static uint8_t ui8position = 0;
    static uint8_t ui8setCursor = 0;
    
    //READS BUSY FLAG IF LCD IS READY TO GET CHAR
    if(readBusyFlagLCD() == 0)
    {
        //CHECKS THE CURSOR POSITION
        if(ui8setCursor == 1)
        {
            //CHECKS WHICH LINE HAS BEEN WRITTEN AND WHICH IS NEXT
            if(ui8position == 16)
            {
                //WRITES TO SECOND LINE
                sendCommandLCDNonBlocking(0xC0);
            }
            else
            {
                //WRITES TO FIRST LINE
                sendCommandLCDNonBlocking(0x02);
                ui8position = 0;
            }
            ui8setCursor = 0;
            return;
        }
        
        //ACUTALLY WRITES DATA TO LCD;

        writeDataLCDNonBlocking((uint8_t) DataString[ui8position]);
        
        ui8position++;
        
        //IF POSITION IS END OF LINE THE CURSOR HAS TO BE SET TO THE OTHER LINE
        if(ui8position == 16 || ui8position == 32)
        {
            ui8setCursor = 1;
        }
    }
}

void setLCDLine(const char* pStr, uint8_t ui8Line)
{
    //write to storage
    uint8_t ui8counter = 0;
    //*ui8dataPoint = 0;
    char* pStorage;
    if(ui8Line==1)
        pStorage=&DataString[0];
    else if(ui8Line==2)
        pStorage=&DataString[16];
    else
        return;
        
    //strncpy(*cStorage[32], *ui8dataPoint, 32);
    //differentiate between two lines
    
    //Schreibt die Daten in den Schattenspeicher
    while(pStr[ui8counter] != '\0' && ui8counter < 16)
    {
        pStorage[ui8counter] = pStr[ui8counter];
        ui8counter++;
    }
        
    //Springt hier nur rein, falls das Endezeichen vor dem Ende des Speichers kommt
    while(ui8counter < 16)
    {
        pStorage[ui8counter] = ' ';
        ui8counter++;
    }
}

void setLCDLine1(const char* pString)
{
    setLCDLine(pString,1);
}

void setLCDLine2(const char* pString)
{
    setLCDLine(pString,2);
}

void Schreibmaschine( int8_t i8RotaryEncode, uint8_t ui8SWState )
{
    #define STATE_SET_POSITION 1
    #define STATE_SET_CHAR 0

    static int8_t i8Position = 0;
    static uint8_t ui8State = STATE_SET_CHAR;
    static uint8_t ui8SWStateOld=0;
    static char c = 0;
    static uint8_t ui8BlinkMode=0;
    
    if(c==0)
        c=DataString[i8Position];
    
    static uint16_t ui16Calls=0;
    ui16Calls++;
    
    //ui8OldSwitchState == HIGH && ui8SwitchState == LOW
    if( ui8SWStateOld == LOW && ui8SWState==HIGH )
    {
        switch(ui8State)
        {
            case STATE_SET_CHAR:
                ui8State=STATE_SET_POSITION;
                break;
                
            case STATE_SET_POSITION:
                ui8State=STATE_SET_CHAR;
                break;           
        }
    }
    
    switch(ui8State)
    {
            case STATE_SET_POSITION:
                
                if(ui8BlinkMode==0)
                {
                    i8Position += i8RotaryEncode;
                    if(i8Position >= 32)
                        i8Position=0;             
                    if(i8Position<0)
                        i8Position=31;
                    
                    c=DataString[i8Position];
                }
                                

                              
                break;
                
            case STATE_SET_CHAR:
                
                c = c+i8RotaryEncode;
                if(c<32)
                    c=126;
                else if(c>126)
                    c=32;
                
                break;
                
        default:
            break;
    } 
    if(ui16Calls >= 700)
    {
        if(c!=' ')
            DataString[i8Position]=' ';
        else
            DataString[i8Position]='_';
        ui8BlinkMode=1;
        if(ui16Calls>=800)
            ui16Calls=0;
            
    }
    else
    {
        DataString[i8Position]=c;
        ui8BlinkMode=0;
    }
        
    ui8SWStateOld=ui8SWState;
}

void createNewChar()
{
    #define SetLCDG(a) sendCommandLCD((a&0x3F)|0x40)
    #define SetLCDC(a) sendCommandLCD((a&0x7F)|0x80)
    #define putLCD(d) writeDataLCD(d)
    
    SetLCDG(0);

    /*
    {
    putLCD(0x00);
    putLCD(0x17);
    putLCD(0x14);
    putLCD(0x1F);
    putLCD(0x05);
    putLCD(0x1D);
    putLCD(0x00);    
    putLCD(0); 
    }

    */
    
    //0
    putLCD(0b00000);
    putLCD(0b00000);
    putLCD(0b00000);
    putLCD(0b00000);
    putLCD(0b00000);
    putLCD(0b00000);
    putLCD(0b00000);
    putLCD(0b00000);
    //putLCD(0);
    
    //1
    putLCD(0b10000);
    putLCD(0b10000);
    putLCD(0b10000);
    putLCD(0b10000);
    putLCD(0b10000);
    putLCD(0b10000);
    putLCD(0b10000);
    putLCD(0b10000);
    //putLCD(0);
    
    //2
    putLCD(0b11000);
    putLCD(0b11000);
    putLCD(0b11000);
    putLCD(0b11000);
    putLCD(0b11000);
    putLCD(0b11000);
    putLCD(0b11000);
    putLCD(0b11000);
    //putLCD(0);
    
    //3
    putLCD(0b11100);
    putLCD(0b11100);
    putLCD(0b11100);
    putLCD(0b11100);
    putLCD(0b11100);
    putLCD(0b11100);
    putLCD(0b11100);
    putLCD(0b11100);
    //putLCD(0);

    //4
    putLCD(0b11110);
    putLCD(0b11110);
    putLCD(0b11110);
    putLCD(0b11110);
    putLCD(0b11110);
    putLCD(0b11110);
    putLCD(0b11110);
    putLCD(0b11110);
    //putLCD(0);

    //5
    putLCD(0b11111);
    putLCD(0b11111);
    putLCD(0b11111);
    putLCD(0b11111);
    putLCD(0b11111);
    putLCD(0b11111);
    putLCD(0b11111);
    putLCD(0b11111);
    //putLCD(0);
    

    
    SetLCDC(0x40);
}
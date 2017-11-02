
#include"edaPIC33Protocol.h"
#include<stdint.h>
#include<stdbool.h>

void handleMessage(char* psMessage)
{
    uint16_t ui16Dst;
    uint16_t ui16Src;
    
    char pStrReturnMessage[100];
    
    //TODO: check is message is valid
    
    //TODO: check CRC-Checksum!
    
    //return if destination mismatch with device adress
    if (!getDst(psMessage, &ui16Dst))
        return;
    
    //return error message, if source is not allowed to send command to device
    if (!getSrc(psMessage, &ui16Src))
    {       
        //Error Messege E05 Absender ist nicht befugt Befehle zu erteilen
        sprintf("%04lu%04luE05",ui16Dst,ui16Src);   
                
        //TODO: calculate and add CRC to string
        putStrUart1(pStrReturnMessage);
    }
    
    sprintf("Message received: %s",pStrReturnMessage);
    putStrUart1(pStrReturnMessage);
}

bool getDst(char* psMessage, uint16_t* pui16Destination)
{
    *pui16Destination = (psMessage[0] - 30)*1000 + (psMessage[1] - 30) * 100 + (psMessage[2] - 30) * 10 + (psMessage[3] - 30);
    
    if(*pui16Destination == DEVICEADRESS)
        return true;
    else
        return false;
}

bool getSrc(char* psMessage, uint16_t* pui16Source)
{
    *pui16Source = (psMessage[4] - 30)*1000 + (psMessage[5] - 30) * 100 + (psMessage[6] - 30) * 10 + (psMessage[7] - 30);
    
    if(*pui16Source == SOURCEADRESS)
        return true;
    else
        return false;
}

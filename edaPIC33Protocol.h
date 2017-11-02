/* 
 * File:   edaPIC33Protocol.h
 * Author: Kevin
 *
 * Created on 2. November 2017, 21:48
 */

#ifndef EDAPIC33PROTOCOL_H
#define	EDAPIC33PROTOCOL_H

#include"edaPIC33UART1.h"
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define DEVICEADRESS 1001
#define SOURCEADRESS 1002



void handleMessage(char* psMessage);
bool getSrc(char* psMessage, uint16_t* pui16Source);
bool getDst(char* psMessage, uint16_t* pui16Destination);


#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33PROTOCOL_H */


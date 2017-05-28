/* 
 * File:   setLCD.h
 * Author: jenskehl
 *
 * Created on May 16, 2017, 10:28 AM
 */

#ifndef SETLCD_H
#define	SETLCD_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> 

// Control signal data pins
#define RW  LATDbits.LATD5  // LCD R/W signal
#define RS  LATBbits.LATB15 // LCD RS signal
#define E   LATDbits.LATD4  // LCD E signal

// Control signal pin direction
#define RW_TRIS TRISDbits.TRISD5
#define RS_TRIS TRISBbits.TRISB15
#define E_TRIS  TRISDbits.TRISD4

// Data signals and pin direction
#define DATA        LATE    // Port for LCD data
#define DATAPORT    PORTE
#define TRISDATA    TRISE   // I/O setup for data Port
    
#define cursor_right()  sendCommandLCD( 0x14 )
#define cursor_left()   sendCommandLCD( 0x10 )
#define display_shift() sendCommandLCD( 0x1C )
#define home_clr()      sendCommandLCD( 0x01 )
#define home_it()       sendCommandLCD( 0x02 )
#define line_2()        sendCommandLCD( 0xC0 ) //0b 1100 0000

extern char ShadowString[32]; 

/** 
 * @brief Initialisiere LCD Display
 * @param void
 * @return void
 * @details Funktion initialisiert das LCD Display.  Legt Pin Modes fest, initialisiert display mit cursor blink off & cursor off
 * @attention Blocking Code
 */
void initMyLCD();

/** 
 * @brief clockLCDenable
 * @param void
 * @return void
 * @details Funktion setzt setzt den Enable Eingang des LCD auf High und 4 Taktzyklen Sp�ter wieder auf Low
 */
void clockLCDenable();

/** 
 * @brief Sendet Character an den LCD
 * @param char c Character der an den LCD gesendet werden soll
 * @return void
 * @attention Blocking Code!
 */
void putcLCD(char c);

/** 
 * @brief Sendet String an den LCD
 * @param char* pData String der an den LCD gesendet werden soll
 * @return void
 * @attention Blocking Code!
 */
void putsLCD(char* pData);

/** 
 * @brief Sendet ein Command an den LCD
 * @param uint8_t ui8data Command das an den LCD gesendet werden
 * @return void
 * @attention Blocking Code!
 */
void sendCommandLCD(uint8_t ui8data);

/** 
 * @brief Sendet ein Command an den LCD
 * @param uint8_t ui8data Command das an den LCD gesendet werden
 * @return void
 * @attention NonBlocking Code!, readBusyFlagAndAddressLCD() has to be checked after calling this function!
 */

void sendCommandLCDNonBlocking(uint8_t ui8data);

/** 
 * @brief Sendet Daten an den LCD
 * @param uint8_t ui8data Daten die an den LCD gesendet werden sollen
 * @return void
 * @attention Blocking Code!
 */
void writeDataLCD(uint8_t ui8data);

/** 
 * @brief Sendet Daten an den LCD
 * @param uint8_t ui8data Daten die an den LCD gesendet werden sollen
 * @return void
 * @attention NonBlocking Code!, readBusyFlagAndAddressLCD() has to be checked after calling this function!
 */
void writeDataLCDNonBlocking(uint8_t ui8data);

/** 
 * @brief setzt DDRAM Adresse des LCD's
 * @param uint8_t ui8data Daten die an den LCD gesendet werden sollen
 * @return void
 * @attention Blocking Code!
 */
void setDDRAMAddressLCD(uint8_t ui8address);

uint8_t readBusyFlagLCD();

void putncLCD(char* pData, uint8_t ui8n);

void printShadowStorageToLCD();

void clearShadowString();

void writeShadowStringToLCD();

void setLineLCD(const char* pStr, uint8_t ui8Line);

void setLCDLine1(const char* pString);

void setLCDLine2(const char* pString);

//void putCharLCD(char c);

#ifdef	__cplusplus
}
#endif

#endif	/* SETLCD_H */

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

//dijasio    
#define SetLCDG(a) sendCommandLCD((a&0x3F)|0x40)
#define SetLCDC(a) sendCommandLCD((a&0x7F)|0x80)
#define putLCD(d) writeDataLCD(d)


extern char DataString[32];
extern char* pLCDDataStringLine1;
extern char* pLCDDataStringLine2;

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
 * @details Funktion setzt setzt den Enable Eingang des LCD auf High und 4 Taktzyklen Später wieder auf Low
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

/** 
 * @brief read busy flag
 * @param void
 * @return uint8_t BusyFlag
 * @details function reads the busy flag from lcd controller 1:controller is busy
 */
uint8_t readBusyFlagLCD();

/** 
 * @brief Sendet n Zeichen eines Strings an den LCD
 * @param char* pData String der an den LCD gesendet werden soll
 * @param uint8_t ui8n Anzahl der Zeichen die auf dem LCD angezeigt werden
 * @return void
 * @attention Blocking Code!
 */
void putncLCD(char* pData, uint8_t ui8n);

/** 
 * @brief clear LCD char storage
 * @param void
 * @return void
 * @details Funktion überschreibt den Schattenspeicher des LCDs
 */
void clearLCDStorage();

/** 
 * @brief Send Data to LCD
 * @param void
 * @return void
 * @details Funktion sendet bei jedem Aufruf einen Character des Schattenspeichers an den LCD
 * @attention Funktion muss zyklisch aufgerufen werden. Non-Blocking Funktion, liest das Busy Flag des LCD aus
 */
void sendDataToLCD();

/** 
 * @brief setLCDLine
 * @param const char* pStr String der in den Schattenspeicher gespeichert werden soll
 * @param uint8_t ui8Line Zeile in welcher der String gespeichert werden soll
 * @return void
 * @detail Funktion kopiert einen String in den Schattenspeicher des LCDs
 * @attention Funktion überschreibt den Schattenspeicher des LCDs
 */
void setLCDLine(const char* pStr, uint8_t ui8Line);

/** 
 * @brief setLCDLine1
 * @param const char* pStr String der in den Schattenspeicher gespeichert werden soll
 * @return void
 * @detail Funktion kopiert einen String in den Schattenspeicher (Line1) des LCDs
 * @attention Funktion überschreibt den Schattenspeicher des LCDs
 */
void setLCDLine1(const char* pString);

/** 
 * @brief setLCDLine2
 * @param const char* pStr String der in den Schattenspeicher gespeichert werden soll
 * @return void
 * @detail Funktion kopiert einen String in den Schattenspeicher (Line2) des LCDs
 * @attention Funktion überschreibt den Schattenspeicher des LCDs
 */
void setLCDLine2(const char* pString);

//void putCharLCD(char c);


void Schreibmaschine( int8_t i8RotaryEncode, uint8_t ui8SWState );

void createNewChar();

char* createFortschrittsbalken(char *pStr, int16_t i16Value);

char* createFortschrittsbalken2(char *pStr, uint16_t ui16Value, uint16_t ui16MaxValue);

#ifdef	__cplusplus
}
#endif

#endif	/* SETLCD_H */


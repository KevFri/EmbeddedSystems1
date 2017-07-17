/* 
 * File:   edaPIC33OtherStuff.h
 * Author: Kevin
 *
 * Created on 17. Mai 2017, 10:12
 */

#ifndef EDAPIC33OTHERSTUFF_H
#define	EDAPIC33OTHERSTUFF_H

#include<stdint.h>
#include<xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

    /** 
 * @brief FlipFlopLED0
 * @param uint8_t ui8SwitchState   Taster State
 * @details Funktion die LED0 toggled, bei fallender Flanke des übergebenen Tasters.
 * @details Die Funktion sollte zyklisch aufgerufen werden
 * @attention   ui8SwitchState sollte entprellt sein
 */
void FlipFlopLED0(uint8_t ui8SwitchState);

/** 
 * @brief digitalCountLED0to3
 * @param uint8_t ui8SwitchState   Taster State
 * @details Funktion die LED3(MSB) - LED0(LSB) binär hochzählt.
 * @details Bei einem Wechsel des Zustandes von ui8SwitchState von High auf Low wird incrementiert
 * @details Die Funktion sollte zyklisch aufgerufen werden
 * @attention   ui8SwitchState sollte entprellt sein
 */
void digitalCountLED0to3(uint8_t ui8SwitchState);

/** 
 * @brief Treppenlichtautomat
 * @param uint8_t ui8SwitchState Taster State
 * @param uint8_t ui8LedPin Pin an der LED angeschlossen ist
 * @param  const uint32_t cui32OnTime Leuchtdauer nach Einschalten in Funktionsaufrufen
 * @param  const uint32_t cui32TurnOffTime Dimm-Dauer zum Ausschalten in Funktionsaufrufen
 * @details Treppenlichtautomat Funktion. Bei einer Zustandsnderung von 
 *          ui8SwitchState wird die LED an ui8LedPin auf High geschaltet und 
 *          leuchtet dann durchgehend für cui32OnTime [Funkionsaufrufe], 
 *          anschließend wird die LED mit einer PWM gedimmt, bis diese 
 *          vollständig aus ist (Zeitdauer: cui32TurnOffTime [Funktionsaufrufe]).  
 * @attention Die Funktion muss zyklisch mit einem konstanten Intervall aufgerufen werden!
 */
void Treppenlichtautomat(uint8_t ui8SwitchState, uint8_t ui8LedPin, const uint32_t cui32OnTime, const uint32_t cui32TurnOffTime);

/** 
 * @brief SoftwarePwm an ui8Pin
 * @param uint8_t ui8Pin Pin für die Software PWM
 * @param const uint8_t cui8PeriodTime Periodendauer [Funktionsaufrufe]
 * @param uint8_t ui8DutyCycle Tastgrad
 * @details Die Funktion erzeugt anhand der Periodendauer und dem Tastgrad eine PWM an dem Asgangspin.
 * @attention Die Funktion muss zyklisch mit einem konstanten Intervall aufgerufen werden!
 * @attention Pin sollte vorher als Output initalisiert werden!
 */
void SoftwarePwm(uint8_t ui8Pin, const uint8_t cui8PeriodTime, uint8_t ui8DutyCycle);

/**
 * 
 * @param i16InputValue 0..1023
 * @details  HYSTERESE_ON 524
 * @details  HYSTERESE_OFF 500
 * @return Hysterese Value LOW/HIGH
 */
uint8_t createHystere(int16_t  i16InputValue);


/**
 * @brief Function creates Comparator
 * @details Threshold 512
 * @param i16InputValue 0..1023
 * @return Comparator Value LOW/HIGH
 */
uint8_t createComparator(int16_t  i16InputValue);

/**
 * @brief Function generates Sinus signal with OutputCompareModule
 * @details Periode Value 20 
 * @param OutputComparePort Output Port for PWM
 */
void sinusGenerator(uint8_t OutputComparePort);

/**
 * @brief Function generates sinus signal with OutputCompareModule
 * @param OutputComparePort Output Port for PWM
 * @param msPeriod Periode Value in [Functioncalls]
 * @attention Function have to be called consistent
 */
void sinusGeneratorTimeBase(uint8_t OutputComparePort, uint16_t msPeriod);

/**
 * @brief Function generates sawtooth signal with OutputCompareModule
 * @details Periode Value 20 
 * @param OutputComparePort Output Port for PWM
 */
void sawtoothGenerator(uint8_t OutputComparePort);

/**
 * @brief Function generates sawtooth signal with OutputCompareModule
 * @param OutputComparePort Output Port for PWM
 * @param msPeriod Periode Value in [Functioncalls]
 * @attention Function have to be called consistent
 */
void sawtoothGeneratorTimeBase(uint8_t OutputComparePort, uint16_t msPeriod);

/**
 * @brief Function generates triangle signal with OutputCompareModule
 * @details Periode Value 20 
 * @param OutputComparePort Output Port for PWM
 */
void triangleGenerator(uint8_t OutputComparePort);

/**
 * @brief StopWatch. Counts the Time in mm:ss:ms ms ms
 * @details Stopwatch. Counts the Time during On and write result to string str, fills the rest of string, to width 16, with ' '
 * @param str Source String
 * @param Switch Switch State to start/hold stopwatch
 * @return 1:Stopwatch is running 0:Stopwatch off
 */
uint8_t stopWatch(char* str, uint8_t Switch);


/**
 * @brief erzeuge Fortschrittsbalken
 * @param pStr String in den der Fortschrittsbalken gespeichert werden soll, Balken: 0..1024
 * @param i16Value Wert der als Fortschrittsbalken ausgegeben werden soll 0..1024
 * @return pointer to String
 */
char* createFortschrittsbalken(char *pStr, int16_t i16Value);

/**
 * @brief erzeuge Fortschrittsbalken
 * @param pStr String in den der Fortschrittsbalken gespeichert werden soll, Balken: 0..MaxValue
 * @param ui16Value Wert der als Fortschrittsbalken ausgegeben werden soll 0..MaxValue
 * @param ui16MaxValue Maximalwert für Fortschrittsbalken
 * @return pointer to String 
 */
char* createFortschrittsbalken2(char *pStr, uint16_t ui16Value, uint16_t ui16MaxValue);


/** 
 * @brief Funktion zum Entprellen des Tasters SW0 (Pin 96)
 * @param const uint16_t cui16DebounceTime Entprelldauer kann in edaPIC33Hardware.c festgelegt werden [Funktionsaufrufe].
 * @details Funktion Entprellt den Taster SWO (Pin 96)
 * @attention Funktion muss zyklisch in konstanten Zeitabständen aufgerufen werden!
 * @attention SW0 muss vorher als Eingang deklariert werden
 */
uint8_t isPressedSW0();

/** 
 * @brief Funktion zum Entprellen eines beliebigen Tasters/Schalter
 * @param const uint16_t cui16DebounceTime Entprelldauer kann in edaPIC33Hardware.c festgelegt werden [Einheit: Funktionsaufrufe].
 * @details Funktion Entprellt einen beliebigen Eingang
 * @attention Funktion muss zyklisch in konstanten Zeitabständen aufgerufen werden!
 * @attention Funktion kann nur für einen Pin verwendet werden
 * @attention Pin muss vorher als Eingang deklariert werden
 */
uint8_t isPressed(uint8_t ui8Port);

/**
 * @brief Funktion zum Entprellen mehrerer beliebiger Tasters/Schalter (num 0..7)
 * @detail isPressed2 kann parallel bis zu 8 Taster entprellen, jedem Taster muss eine Nummer 0..7 zugewiesen werden!
 * @param ui8Port Hardware Port des zu entprellenden Tasters
 * @param num Nummer des Tasters, kann frei gewählt werden (0..7)
 * @return HIGH/LOW (entprelled)
 * @attention Funktion muss zyklisch in konstanten Zeitabständen aufgerufen werden!
 * @attention Num darf nicht öfters verwendet werden
 * @attention Pin muss vorher als Eingang deklariert werden
 */
uint8_t isPressed2(uint8_t ui8Port, uint8_t num);

extern const uint16_t cui16DebounceTime;


/** 
 * @brief Incrementalencoder
 * @param void
 * @return int8_t value: -1: Links, 0:unverändert, 1:Rechts
 * @details Funktionen wertet den Inkrementalencoder auf dem Board auf. Funktion muss zyklisch aufgerufen werden, damit ein drehen festgestellt werden kann
 * @attention Funktion muss zur initalisierung (mindestens) zweimal aufgerufen werden um den STATE richtig zu definieren!
 * @attention Pins INCA und INCB müssen vorher als INPUT_PULLUP definiert werden 
 */
int8_t rotaryEncode();
#define LEFT -1
#define RIGTH 1
#define IDLE 0


#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33OTHERSTUFF_H */


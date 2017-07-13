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

uint8_t createHystere(int16_t  i16InputValue);
uint8_t createComparator(int16_t  i16InputValue);


void sinusGenerator(uint8_t OutputComparePort);
void sawtoothGenerator(uint8_t OutputComparePort);
void triangleGenerator(uint8_t OutputComparePort);


#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33OTHERSTUFF_H */


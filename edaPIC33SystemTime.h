/* 
 * File:   edaPIC33SystemTime.h
 * Author: Kevin
 *
 * Created on 25. April 2017, 10:37
 */
#include <xc.h>         //Include appropriate controller specific headers
#include <stdint.h>

#ifndef EDAPIC33SYSTEMTIME_H
#define	EDAPIC33SYSTEMTIME_H


uint32_t getSystemTimeMillis();

void configSystemTimeMillis();

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void);

/*
uint32_t getSystemTimeSeconds();

void configSystemTimeSeconds();

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void);
*/
#endif	/* EDAPIC33SYSTEMTIME_H */


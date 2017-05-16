/* 
 * File:   edaPIC33FiniteStateMachine.h
 * Author: Kevin
 *
 * Created on 8. Mai 2017, 19:19
 */

#include <xc.h>         //Include appropriate controller specific headers
#include <stdint.h>     //Standard typedefs
#include "edaPIC33Hardware.h"

#ifndef EDAPIC33FINITESTATEMACHINE_H
#define	EDAPIC33FINITESTATEMACHINE_H

#ifdef	__cplusplus

extern "C" {
#endif

#define LED_OFF 0
#define LED_ON  1

controlLED0()
{
    if(isPressed(SWO))
    {
        digitalToggle(LED0);
    }
}

    

#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33FINITESTATEMACHINE_H */


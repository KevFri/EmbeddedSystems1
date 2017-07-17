/* 
 * File:   edaPIC33RingBuffer.h
 * Author: Kevin
 *
 * Created on 15. Juli 2017, 14:08
 */

#ifndef EDAPIC33RINGBUFFER_H
#define	EDAPIC33RINGBUFFER_H

#include<stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define BUFFERTYPE int16_t
#define BUFFERSIZE 100
    
    BUFFERTYPE  BufferStorage[BUFFERSIZE]={0};

    /**
     * @brief store new value in FIFO buffer 
     * @param newValue new value to store in RingBuffer
     */
    void writeRingBuffer(BUFFERTYPE newValue);
    
    /**
     * @brief read value from FIFO
     * @return read value from RingBuffer 
     */
    BUFFERTYPE readRingBuffer(void);
    
    /**
     * @brief FIFO Buffer Function
     * @param Read_nWrite 1:reads value, 0:write value
     * @param nValue new value to write into budder, Read_nWrite musst be 0
     * @return read value from RingBuffer ,Read_nWrite must be 1, otherwise 0 is returned 
     */
    BUFFERTYPE RingBuffer(uint8_t Read_nWrite, BUFFERTYPE nValue); 

#ifdef	__cplusplus
}
#endif

#endif	/* EDAPIC33RINGBUFFER_H */


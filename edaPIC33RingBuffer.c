#include"edaPIC33RingBuffer.h"

extern BUFFERTYPE  BufferStorage[BUFFERSIZE];

void writeRingBuffer(BUFFERTYPE newValue)
{
  RingBuffer(0, newValue);
}

BUFFERTYPE readRingBuffer(void)
{
    return RingBuffer(1, 0);
}

BUFFERTYPE RingBuffer(uint8_t Read_nWrite, BUFFERTYPE nValue)
{
    static BUFFERTYPE* pNextRead = BufferStorage; //pointer to next read value
    static BUFFERTYPE* pNextWrite= BufferStorage; //pointer to next written value
    static BUFFERTYPE* pLastRead = BufferStorage+BUFFERSIZE; //pointer to last read value
    static BUFFERTYPE* pLastWrite= BufferStorage; //pointer to last written value
    static uint8_t firstWriteFlag = 0;

    BUFFERTYPE returnValue = 0;

    if(Read_nWrite == 1) //read
    {
        if(firstWriteFlag==0)
            return 0;

        returnValue = *pNextRead;
        pLastRead = pNextRead;
        if(pLastRead == pLastWrite)
        {

        }
        else
        {
            pNextRead++;
            if(pNextRead == BufferStorage+BUFFERSIZE)
            {
                pNextRead=BufferStorage;
            }
        }
    }
    else //write
    {
        if(pNextWrite == pNextRead && firstWriteFlag==1)
        {
            pNextRead++;
            if(pNextRead == BufferStorage+BUFFERSIZE)
            {
                pNextRead=BufferStorage;
            }
        }
        else
        {
            if(pLastRead == pLastWrite && firstWriteFlag==1)
            {
                pNextRead++;
                if(pNextRead == BufferStorage+BUFFERSIZE)
                {
                    pNextRead=BufferStorage;
                }
            }
        }

        *pNextWrite = nValue;
        pLastWrite = pNextWrite;
        firstWriteFlag=1;

        pNextWrite++;
        if(pNextWrite == BufferStorage+BUFFERSIZE)
            pNextWrite=BufferStorage;
    }
    return returnValue;
}
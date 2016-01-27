#include "BSP.h"

#ifndef __SystemClock_H
  #define __SystemClock_H

#include "SystemTimer.h"

class SystemClock
{
    public: 
     
        // Constructor
        SystemClock();
        // Destructor
        virtual ~SystemClock();       
      
        ///void tick();

/**        uint8_t getSeconds();
        
        uint8_t getMinutes();
        
        uint8_t getHours();*/
        
        void setStartTics();
        
        uint16_t milliSecondsPassed();      
      
    private: 
      
        uint16_t clockTicks;
        uint16_t startTicks;
};

inline SystemClock::SystemClock()
{
    clockTicks = 0;   
    startTicks = 0;
}

inline SystemClock::~SystemClock()
{

}

#endif
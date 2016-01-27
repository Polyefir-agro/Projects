#include "BSP.h"

#ifndef __Sensor_H
  #define __Sensor_H

class Sensor {
    //SystemClock systemClock;
  
    public:
        // Constructor
        Sensor();
        // Destructor
        virtual ~Sensor();
      
        uint16_t getValue();
        
        Boolean getTurnOn();
        
        virtual void handle();
               
//    private:
//        static uint64_t startTicks;        
        
    protected:
      
        uint16_t value; 
        Boolean turnOn;
};    

inline Sensor::Sensor()
{
    value = 0;  
}  

inline Sensor::~Sensor()
{

}

#endif
#include "BSP.h"

#ifndef __PowerSwitch_H
  #define __PowerSwitch_H

enum SwitchStatus {ON, OFF, P_ERROR};

class PowerSwitch{
     
    public:               
       
        SystemClock switchHandleClock[4];
      
        // Constructor
        PowerSwitch();
        // Destructor
        virtual ~PowerSwitch();          
  
        void init(); 
        
        void handle();
        
        void turn_on(uint8_t switchIndex);
        
        void turn_off(uint8_t switchIndex);
        
        SwitchStatus getPowerSwitchStatus(uint8_t switchIndex);
        
        void scanSenseValue();
        
        uint16_t getSenseValue();       
                      
    private:    
        
        SwitchStatus switchStatus[4];                 
        
        uint16_t senseValue;
        
        uint8_t senseChNum;
        
        void switchSet(uint8_t switchIndex, Boolean setValue);
        
        Boolean getSwitchPinStatus(uint8_t switchIndex);
};

inline PowerSwitch::PowerSwitch()
{
 
}

inline PowerSwitch::~PowerSwitch()
{

}

#endif
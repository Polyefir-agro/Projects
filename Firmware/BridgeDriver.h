#include "BSP.h"

#ifndef __BridgeDriver_H
  #define __BridgeDriver_H

enum BridgeStatus {STOP, FORWARD, REVERSE, ERROR};


class BridgeDriver {
    
    public:
    
        // Constructor
        BridgeDriver(uint8_t senseForwardChNum, uint8_t senseReverseChNum);
        // Destructor
        virtual ~BridgeDriver();          
        
        void init(); 
        
        void forward();
        
        void reverse();
        
        void stop();  
        
        BridgeStatus getBridgeStatus();
        
        void scanSenseForwardValue();
        
        void scanSenseReverseValue();
        
        uint16_t getSenseForwardValue();      

        uint16_t getSenseReverseValue();      
                      
     private:                       
        
        BridgeStatus bridgeStatus;                 
        
        uint16_t senseForwardValue;
        
        uint16_t senseReverseValue;
        
        uint8_t senseForwardCh;
        
        uint8_t senseReverseCh;
        
        //Boolean senseError;
       
        void inhibitSet(Boolean set);     
                    
        void forwardSet(Boolean set);    

        void reverseSet(Boolean set);          
};

//class BridgeFarwDirection : public BridgeDriver{
     
//------------------------------------------------------------------------------
inline BridgeDriver::BridgeDriver(uint8_t senseForwardChNum, uint8_t senseReverseChNum)
{
    senseForwardCh = senseForwardChNum;     
    senseReverseCh = senseReverseChNum;
    
    bridgeStatus = STOP;
}

inline BridgeDriver::~BridgeDriver()
{

}

#endif
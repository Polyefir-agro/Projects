#include "BridgeDriver.h"

#ifndef __BridgeDriver_H
#error [E030] Не определен заголовочный файл BridgeDriver.h
#endif 

#ifndef __BRIDGE_PINS_H
#error [E030] Не определен заголовочный файл BridgeDriver_PINS.h
#endif 
  
#include "ADC.h"

//-----------public----------------------------
void BridgeDriver::init()
{
    BRIDGE_INH_DR(1);
    BRIDGE_FORW_START_DR(1);
    BRIDGE_BACK_START_DR(1);
    BRIDGE_BACK_SENSE_DR(0);

    inhibitSet(FALSE);
    forwardSet(FALSE);
    reverseSet(FALSE);      
}  

void BridgeDriver::forward()
{
    if(bridgeStatus == STOP)
    {  
        forwardSet(TRUE);  
        
        bridgeStatus = FORWARD;
    }     
}  

void BridgeDriver::reverse()
{
    if(bridgeStatus == STOP)
    {  
        reverseSet(TRUE);  
        
        bridgeStatus = REVERSE;
    }    
}  

void BridgeDriver::stop()
{
    inhibitSet(FALSE);
    forwardSet(FALSE);
    reverseSet(FALSE);   
    
    bridgeStatus = STOP;
}  

BridgeStatus BridgeDriver::getBridgeStatus()
{
    return bridgeStatus;  
} 

void BridgeDriver::scanSenseForwardValue()
{      
    ADC_SetChannel(senseForwardCh); 
    
    senseForwardValue = ADC_GetAdcResult();    
}  

void BridgeDriver::scanSenseReverseValue()
{     
    ADC_SetChannel(senseReverseCh); 
    
    senseReverseValue = ADC_GetAdcResult();    
}  

//---------private------------------------------
void BridgeDriver::inhibitSet(Boolean set)
{
    if(set == TRUE)
    {  
        BRIDGE_INH_PT(1);
    }
    else
    {
        BRIDGE_INH_PT(0);      
    }  
} 

void BridgeDriver::forwardSet(Boolean set)
{
    if(set == TRUE)
    {  
        BRIDGE_FORW_START_PT(1);
        
        bridgeStatus = FORWARD;
    }
    else
    {
        BRIDGE_FORW_START_PT(0);      
        
        bridgeStatus = STOP;
    }   
}  

void BridgeDriver::reverseSet(Boolean set)
{
    if(set == TRUE)
    {  
        BRIDGE_BACK_START_PT(1);
        
        bridgeStatus = REVERSE;
    }
    else
    {
        BRIDGE_BACK_START_PT(0); 
        
        bridgeStatus = STOP;
    }  
}  
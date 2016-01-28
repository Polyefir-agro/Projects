#include "SensorButton.h"

#ifndef __SensorMux_H
#error [E030] Не определен заголовочный файл SensorMux.h
#endif 

//#include "HCF4067B.h"

/**void SensorMux::handle()
{  
    if(sensorMuxHandleClock.milliSecondsPassed() >= 100)
    {  
        //value = HCF4067B_GetAdcFromChannel(chNum);
        //turnOn = HCF4067B_GetInputState(value, turnOnThreshold);    
		for(uint8_t index = 0; index < 4; index++)
		{
			scanMuxChLevel(index);
		}
        
        sensorMuxHandleClock.setStartTics();
    }      
} */ 


Boolean SensorButton::getPin()
{
    Boolean result = NONE;   	 
	 
	if(HCF4067B_GetChannelLevel(pinNumber) == HIGH) 
	{
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}
	       
	return result; 
}


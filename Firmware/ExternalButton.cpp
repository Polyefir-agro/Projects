#include "ExternalButton.h"

#ifndef __ExternalButton_H
#error [E030] Не определен заголовочный файл ExternalButton.h
#endif 

Boolean ExternalButton::getPin()
{
    uint8_t data[] = {0,0};
    Boolean result = NONE;
    	 
	usart.getRxData(&data[0]);
      
    //sensorMux.scanMuxChLevel(pinNumber); 
	if(data[0] == pinNumber) 
	{           
		if(data[1] == 1)
		//if(sensorMux.getMuxChLevel(pinNumber) == HIGH)
		{
			result = TRUE;
		}
		else
		{
			result = FALSE;
		}
	}
	       
	return result; 
}
	   

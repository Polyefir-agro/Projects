#include "Keyboard.h"

#ifndef __Keyboard_H
#error [E030] Не определен заголовочный файл Keyboard.h
#endif 

uint8_t _msg_btn_on[]  = "MSG:Sense ON";


void Keyboard::handle()
{
  static int8_t m[SENSOR_BUTTON_COUNT] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        
	for (int8_t i = 0; i < SENSOR_BUTTON_COUNT; i++)
	{
		//externalButton[i].handle();
		sensorButton[i].handle(); 
                
		if(buttonPressed(i))
        {
			if(m[i] == 0)
			{  
				usart.printLn(&i, sizeof(i), NUMBER);
				usart.print(&_msg_btn_on, sizeof(_msg_btn_on), STRING);
				                        
				m[i] = 1;
			}                 
		}
		else
		{
			m[i] = 0; 
		}  
	}
}
// ------------------------------------------------------------------------------------------ //
    
// ------------------------------------------------------------------------------------------ //
uint8_t Keyboard::buttonPressed(int8_t buttonNum)
{
   //return externalButton[buttonNum].pressed();
	return sensorButton[buttonNum].pressed();
}
// ------------------------------------------------------------------------------------------ //

#include "BSP.h"

#ifndef __RemoteControl_H
  #define __RemoteControl_H

class RemoteControl {

   public: 

	   //uint8_t ext_button[9];

	   RemoteControl();

	   //void scanMuxChLevel(uint8_t chIndex);

	   //PinLevel getMuxChLevel(uint8_t chIndex);

	   void handle();

	   Boolean buttonPressed(int8_t buttonNum);   

   private: 

	   Boolean button[REMOTE_BUTTON_COUNT];

	   
};


inline RemoteControl::RemoteControl()
{
	for(uint8_t i = 0; i < REMOTE_BUTTON_COUNT; i++)
	{
		button[i] = NONE;
	}
}

#endif

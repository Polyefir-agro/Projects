#include "RemoteControl.h"

#ifndef __RemoteControl_H
#error [E030] Не определен заголовочный файл RemoteControl.h
#endif  


void RemoteControl::handle()
{
	enum BUTTON {INDEX = 0, VALUE};

    uint8_t data[] = {0,0};
    	 
	usart.getRxData(&data[0]);

	if(data[INDEX] < REMOTE_BUTTON_COUNT)
	{
		if(data[VALUE] == 0)
		{
			button[data[INDEX]] = FALSE;
		}
		else if(data[VALUE] == 1)
		{
			button[data[INDEX]] = TRUE;
		}
	}
}

Boolean RemoteControl::buttonPressed(int8_t buttonNum)
{
	return button[buttonNum];
}

void RemoteControl::resetButtonPressed(int8_t buttonNum)
{
	button[buttonNum] = NONE;
}

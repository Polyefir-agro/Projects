#include "Table.h"

#ifndef __Table_H
#error [E030] Не определен заголовочный файл Table.h
#endif  

void Table::handle()
{
	remoteControlHandle();

	sensorKeyboardHandle();
}

void Table::remoteControlHandle()
{
	for(uint8_t i = 0; i < REMOTE_BUTTON_COUNT; i++)
	{
		if(remoteControl.buttonPressed(i) == TRUE)
		{
			switch (i)
			{
			case 0:
				powerSwitch.turn_on(FIRST);

				remoteControl.resetButtonPressed(0);

				break;
			case 1:
				powerSwitch.turn_on(SECOND);

				remoteControl.resetButtonPressed(1);

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			case 9:

				break;
			default: 

				break;
			}
		}
	}
}

void Table::sensorKeyboardHandle()
{
	for(uint8_t i = 0; i < SENSOR_BUTTON_COUNT; i++)
	{
		if(sensorKeyboard.buttonPressed(i) == TRUE)
		{
			switch (i)
			{
			case 0:

				powerSwitch.turn_off(FIRST); 

				break;
			case 1:
				//powerSwitch.turn_off(SECOND);  

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			case 9:

				break;
			case 10:

				break;
			case 11:

				break;
			case 12:

				powerSwitch.turn_off(SECOND); 
				 
				break;
			case 13:

				break;
			case 14:

				break;
			case 15:

				break;
			default: 

				break;
			}
		}
	}
}



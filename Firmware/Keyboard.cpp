#include "Keyboard.h"

#ifndef __Keyboard_H
#error [E030] Не определен заголовочный файл Keyboard.h
#endif 

void Keyboard::handle()
{
	//int8_t i = 0;
	for (int8_t i = 0; i < 9; i++)
	{
		//externalButton[i].handle();
		sensorButton[i].handle();
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

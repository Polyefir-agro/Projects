/*
Поведение 1: без автонажатия при удержании кнопки.
Событие keyWasPressed генерируется после 1) Кнопка была постоянно нажата в течение _keyConfirmTimeMs
2) Кнопка отжата до того, как прошло время _keyReleaseTimeMs или прошло время _keyReleaseTimeMs.
3) Обработка повторного нажатия происходит только после отжатия кнопки.

Поведение 2: с автонажатием при удержании кнопки.
После того, как прошло время _keyReleaseTimeMs, до тех пор, пока нажата кнопка через каждые
_keyRepeatTimeMs генерируется событие keyWasPressed.
*/

#include "BSP.h"

#ifndef __Button_H
  #define __Button_H


#define _keyConfirmTimeMs 40
#define _keyReleaseTimeMs 800
#define _keyRepeatTimeMs  150

class Button {

   public: 

	   //const static uint16_t _keyConfirmTimeMs = 250;
	   //const static uint16_t _keyReleaseTimeMs = 800;
	   //const static uint16_t _keyRepeatTimeMs  = 150;
	   Button(uint8_t autoPress);

	   virtual Boolean getPin();
   
       void handle();

	   uint8_t pressed();

	   void setAutoPressing(uint8_t flag);

	   //uint8_t getOnceFlag();

   private: 

	   //uint8_t autoPressFlag;
	   uint8_t lastKeyState;
	   uint8_t keyWasPressed;
	   uint8_t onceFlag;
	   //uint32_t nextAutoPressTime;

	   SystemClock buttonHandleClock;
};

inline Button::Button(uint8_t autoPress)
{
	//autoPressFlag = autoPress;
    lastKeyState = 0;
    keyWasPressed = 0;
    onceFlag = 1;         // 1 - чтобы при загрузке не генерировать нажатие кнопки
    //nextAutoPressTime = _keyReleaseTimeMs;
}

#endif


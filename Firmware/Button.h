/*
��������� 1: ��� ����������� ��� ��������� ������.
������� keyWasPressed ������������ ����� 1) ������ ���� ��������� ������ � ������� _keyConfirmTimeMs
2) ������ ������ �� ����, ��� ������ ����� _keyReleaseTimeMs ��� ������ ����� _keyReleaseTimeMs.
3) ��������� ���������� ������� ���������� ������ ����� ������� ������.

��������� 2: � ������������ ��� ��������� ������.
����� ����, ��� ������ ����� _keyReleaseTimeMs, �� ��� ���, ���� ������ ������ ����� ������
_keyRepeatTimeMs ������������ ������� keyWasPressed.
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
    onceFlag = 1;         // 1 - ����� ��� �������� �� ������������ ������� ������
    //nextAutoPressTime = _keyReleaseTimeMs;
}

#endif


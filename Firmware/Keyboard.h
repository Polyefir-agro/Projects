
#include "BSP.h"

#ifndef __Keyboard_H
  #define __Keyboard_H

class Keyboard
{
/*
   TCK PF4 57 - 1� ������ �����
   TMS PF5 56 - 2� ������ -
   TDO PF6 55 - 3� ������ +
   TDI PF7 54 - 4� ������ ����
*/



   public: 

       Keyboard();

	   void handle();

	   uint8_t buttonPressed(int8_t buttonNum);       
};


inline Keyboard::Keyboard()
{
	  /**selectButton(1),                           // 1- � ��������� 
	  ��� ��� ���������              // previousButton(1), 
      nextButton(1),
      enterButton(1)*/
}

#endif

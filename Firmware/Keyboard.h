
#include "BSP.h"

#ifndef __Keyboard_H
  #define __Keyboard_H

class Keyboard
{
/*
   TCK PF4 57 - 1я кнопка ВЫБОР
   TMS PF5 56 - 2я кнопка -
   TDO PF6 55 - 3я кнопка +
   TDI PF7 54 - 4я кнопка ВВОД
*/



   public: 

       Keyboard();

	   void handle();

	   uint8_t buttonPressed(int8_t buttonNum);       
};


inline Keyboard::Keyboard()
{
	  /**selectButton(1),                           // 1- с автонажат 
	  ием при удержании              // previousButton(1), 
      nextButton(1),
      enterButton(1)*/
}

#endif

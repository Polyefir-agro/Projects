#include "Button.h"

#ifndef __Button_H
#error [E030] Не определен заголовочный файл Button.h
#endif 

//uint8_t _msg_btn_off[]  = "MSG:Button OFF";

Boolean Button::getPin()
{
	return NONE;
}

// ------------------------------------------------------------------------------------------ //
void Button::handle()
{
      Boolean pinState = getPin();

      if (pinState == TRUE)       // Если нажата кнопка
      {
         if(lastKeyState == 0)        // Состояние кнопки было - "отжата"
         {
			//usart.printLn(&_msg_btn_on, sizeof(_msg_btn_on), STRING);

            buttonHandleClock.setStartTics();           // Запоминаем значение таймера
            lastKeyState = 1;         // Записываем, что кнопка "нажата"
            onceFlag = 0;
            //nextAutoPressTime = _keyReleaseTimeMs;  //
         }
         else                          // Состояние кнопки было - "нажата"   //
         {
            /**if ((onceFlag == 0) &&
                (buttonHandleClock.milliSecondsPassed() >= _keyReleaseTimeMs)
               )
            {
               if (autoPressFlag == 0)  // Без автонажатия
               {
                  keyWasPressed = 1;
                  onceFlag = 1;
               }
               else
               {
                  if (buttonHandleClock.milliSecondsPassed() >= nextAutoPressTime)
                  {
                     keyWasPressed = 1;
                     nextAutoPressTime = nextAutoPressTime + _keyRepeatTimeMs;
                  }
               }
            }*/
            if ((onceFlag == 0) &&
                (buttonHandleClock.milliSecondsPassed() >= _keyConfirmTimeMs)
               )
			{
				keyWasPressed = 1;
				onceFlag = 1;
			}
            

			/**else if (onceFlag == 0 &&
                    buttonHandleClock.milliSecondsPassed(_keyConfirmTimeMs))
			{
				            
                keyWasPressed = 1;
                onceFlag = 1;
			}*/

         }
      }
      else if(pinState == FALSE)                            // Если кнопка  не нажата            //
      {
         if(lastKeyState == 1)
		 {
             keyWasPressed = 0;
			 lastKeyState = 0;            // Состояние кнопки - "отжата"        //
		 }

         /**if (
               (onceFlag == 0) &&
               (buttonHandleClock.milliSecondsPassed() >= _keyConfirmTimeMs) &&
               (buttonHandleClock.milliSecondsPassed() < _keyReleaseTimeMs)
            )
         {
            keyWasPressed = 1;
            onceFlag = 1;
         }*/
      }
}
// ------------------------------------------------------------------------------------------ //


// ------------------------------------------------------------------------------------------ //
uint8_t Button::pressed()
{
      if (keyWasPressed > 0)
      {
         //keyWasPressed = 0;    // Сброс флага нажатия кнопки после обработки
                        
         return 1;             // Кнопка была нажата
      }
      else
      {
         return 0;
      }
}
// ------------------------------------------------------------------------------------------ //


// ------------------------------------------------------------------------------------------ //
// flag == 0 - нет автонажатия; flag == 1 - есть автонажатие
// ------------------------------------------------------------------------------------------ //
void Button::setAutoPressing(uint8_t flag)
{
      //autoPressFlag = flag;
}
// ------------------------------------------------------------------------------------------ //


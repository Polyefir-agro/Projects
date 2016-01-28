#include "Button.h"

#ifndef __Button_H
#error [E030] �� ��������� ������������ ���� Button.h
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

      if (pinState == TRUE)       // ���� ������ ������
      {
         if(lastKeyState == 0)        // ��������� ������ ���� - "������"
         {
			//usart.printLn(&_msg_btn_on, sizeof(_msg_btn_on), STRING);

            buttonHandleClock.setStartTics();           // ���������� �������� �������
            lastKeyState = 1;         // ����������, ��� ������ "������"
            onceFlag = 0;
            //nextAutoPressTime = _keyReleaseTimeMs;  //
         }
         else                          // ��������� ������ ���� - "������"   //
         {
            /**if ((onceFlag == 0) &&
                (buttonHandleClock.milliSecondsPassed() >= _keyReleaseTimeMs)
               )
            {
               if (autoPressFlag == 0)  // ��� �����������
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
      else if(pinState == FALSE)                            // ���� ������  �� ������            //
      {
         if(lastKeyState == 1)
		 {
             keyWasPressed = 0;
			 lastKeyState = 0;            // ��������� ������ - "������"        //
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
         //keyWasPressed = 0;    // ����� ����� ������� ������ ����� ���������
                        
         return 1;             // ������ ���� ������
      }
      else
      {
         return 0;
      }
}
// ------------------------------------------------------------------------------------------ //


// ------------------------------------------------------------------------------------------ //
// flag == 0 - ��� �����������; flag == 1 - ���� �����������
// ------------------------------------------------------------------------------------------ //
void Button::setAutoPressing(uint8_t flag)
{
      //autoPressFlag = flag;
}
// ------------------------------------------------------------------------------------------ //


#include "BSP.h"

#ifndef __ExternalButton_H
  #define __ExternalButton_H


class ExternalButton : public Button {

   public: 

	   //uint8_t ext_button[9];

	   ExternalButton (uint8_t autoPress, uint8_t pinNum);

	   Boolean getPin();

   private: 

	   uint8_t pinNumber;

	   
};


inline ExternalButton::ExternalButton (uint8_t autoPress, uint8_t pinNum): Button(autoPress)
{
	pinNumber = pinNum;
}

#endif

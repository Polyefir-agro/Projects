#include "BSP.h"

#ifndef __SensorMux_H
  #define __SensorMux_H

//#include "Sensor.h"

/**class SensorMux : public Button {
     
    public:
      
		PinLevel chLevel[16];
		      
        SystemClock sensorMuxHandleClock;
      
        // Constructor
        SensorMux(uint16_t setTurnOnThreshold);
        // Destructor
        virtual ~SensorMux();          
  
        void handle();

		void scanMuxChLevel(uint8_t chIndex);

		PinLevel getMuxChLevel(uint8_t chIndex);
                      
    private:    
        
        uint16_t turnOnThreshold;
		
               
};

inline SensorMux::SensorMux(uint16_t setTurnOnThreshold)
{
    turnOnThreshold = setTurnOnThreshold;   

	for(int8_t chIndex = 0; chIndex < 16; chIndex++)
	{
		chLevel[chIndex] = LOW;
	}
}

inline SensorMux::~SensorMux()
{

}*/

class SensorButton : public Button {

   public: 

	   //uint8_t ext_button[9];

	   SensorButton (uint8_t autoPress, uint8_t pinNum);

	   //void scanMuxChLevel(uint8_t chIndex);

	   //PinLevel getMuxChLevel(uint8_t chIndex);

	   Boolean getPin();

   private: 

	   uint8_t pinNumber;

	   
};


inline SensorButton::SensorButton (uint8_t autoPress, uint8_t pinNum): Button(autoPress)
{
	pinNumber = pinNum;
}

#endif
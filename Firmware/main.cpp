#include "BSP.h"


void main()
{              
    BSP_init();   
      
    //bridgeDriver.forward();  
         
    //uint8_t _char = 'I';
    //uint8_t _massive[] = {0xAA, 0xBB, 0xCC, 0xDD}; 
    //uint8_t _number_8t = 250;
    //uint16_t _number_16t = 1456;
    //uint16_t x  = 0;
    //uint32_t _number_32t = 67005;
    
    
    //usart.printLn(&_number_8t, sizeof(_number_8t), NUMBER);
    //usart.printLn(&_char, sizeof(_char), STRING);
    //usart.printLn(&_string, sizeof(_string), STRING);
    //usart.print(&_number_16t, sizeof(_number_16t), NUMBER);
    //usart.printLn(&_number_32t, sizeof(_number_32t), NUMBER);    
    //usart.printLn(&_massive, sizeof(_massive), NUMBER);        
    while(1)
    {        
        //if(systemClock.milliSecondsPassed() >= 1000)
        //{     

            //sensorMux.handle();

            powerSwitch.handle();
  
            sensorKeyboard.handle();

            remoteControl.handle();
			

		    usart.transmitManager();
		   
            /**if(sensorMux.getMuxChLevel(0) == HIGH) 
			{
				uint8_t i = 0;
			}*/

			//if(sensorKeyboard.buttonPressed(HALF_DOWN))
			if(remoteControl.buttonPressed(HALF_DOWN) == TRUE)
            {              
				if(powerSwitch.getPowerSwitchStatus(FIRST) == OFF)
				{  
					powerSwitch.turn_on(FIRST);
				}	               
            }
			else
			{
				if(powerSwitch.getPowerSwitchStatus(FIRST) == ON) 
				{
					powerSwitch.turn_off(FIRST);                                
				}
			}

			//if(sensorKeyboard.buttonPressed(HALF_UP))
			if(remoteControl.buttonPressed(HALF_UP) == TRUE)
            {              
				if(powerSwitch.getPowerSwitchStatus(SECOND) == OFF)
				{  
					powerSwitch.turn_on(SECOND);
				}                
            }
			else
			{
				if(powerSwitch.getPowerSwitchStatus(SECOND) == ON) 
				{
					powerSwitch.turn_off(SECOND);                                
				}
			}

                    //if(bridgeDriver.getBridgeStatus() == STOP)
                    //{  
                    //    bridgeDriver.reverse();
                    //}
                    //else
                    //{  
                    //    bridgeDriver.stop();        
                    //}  
          
           /** if(bridgeDriver.getBridgeStatus() == STOP)
            {  
                bridgeDriver.forward();
            }
            else
            {  
                bridgeDriver.stop();        
            } 
            
            systemClock.setStartTics();
        }*/    
    }
}

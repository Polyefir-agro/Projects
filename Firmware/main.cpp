#include "BSP.h"

void main()
{              
    BSP_init();   
          
    while(1)
    {           
		powerSwitch.handle();
  
		sensorKeyboard.handle();

		remoteControl.handle();		
		
		table.handle();	

		usart.transmitManager();
		   
		


                    //if(bridgeDriver.getBridgeStatus() == STOP)
                    //{  
                    //    bridgeDriver.reverse();
					//    bridgeDriver.forward();
                    //}
                    //else
                    //{  
                    //    bridgeDriver.stop();        
                    //}  
            
    }
}



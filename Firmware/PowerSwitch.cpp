#include "PowerSwitch.h"

#ifndef __PowerSwitch_H
#error [E030] Не определен заголовочный файл PowerSwitch.h
#endif 

#ifndef __POWER_SWITCH_PINS_H
#error [E030] Не определен заголовочный файл PowerSwitch_PINS.h
#endif 

uint8_t _msg_pswitch_on[]  = "MSG:Pout ON:";
uint8_t _msg_pswitch_off[] = "MSG:Pout OFF:";

//-----------public----------------------------
void PowerSwitch::init()
{
    POWER_SWITCH_1_TURN_DR(1);
	POWER_SWITCH_2_TURN_DR(1);
	//POWER_SWITCH_3_TURN_DR(1);
	//POWER_SWITCH_4_TURN_DR(1);
    POWER_SWITCH_SENSE_DR(0);

	for(uint8_t index = 0; index < 4; index++)
	{
		switchStatus[index] = OFF; 		
		switchSet(index, FALSE);
	}
} 

void PowerSwitch::handle()
{    
	for(uint8_t index = 0; index < 4; index++)
	{
		if(getPowerSwitchStatus(index) == ON)
		{  
			if(switchHandleClock[index].milliSecondsPassed() >= 500)
			{
				if(getSwitchPinStatus(index) == TRUE)
				{
					switchSet(index, FALSE);  				
				}
				else
				{
					switchSet(index, TRUE);          
				}  
			  
				switchHandleClock[index].setStartTics();
			} 
		}      
	}
}

void PowerSwitch::turn_on(uint8_t switchIndex)
{
	if((int8_t)switchIndex >= 0 && switchIndex < 4)
	{
		if(getPowerSwitchStatus(switchIndex) == OFF)
		{
			switchStatus[switchIndex] = ON; 

            //_msg_on = _msg_on + "-"; //+ (switchIndex + 0x30);


			usart.printLn(&switchIndex, sizeof(switchIndex), NUMBER);
			usart.print(&_msg_pswitch_on, sizeof(_msg_pswitch_on), STRING); 
		}
	}

    
    
    //switchSet(TRUE);  
}  

void PowerSwitch::turn_off(uint8_t switchIndex)
{    
	if((int8_t)switchIndex >= 0 && switchIndex < 4)
	{
		if(getPowerSwitchStatus(switchIndex) == ON)
		{
			switchStatus[switchIndex] = OFF; 
			
			switchSet(switchIndex, FALSE);

			usart.printLn(&switchIndex, sizeof(switchIndex), NUMBER);
			usart.print(&_msg_pswitch_off, sizeof(_msg_pswitch_off), STRING);
		}
	}
}  

SwitchStatus PowerSwitch::getPowerSwitchStatus(uint8_t switchIndex)
{
	if((int8_t)switchIndex >= 0 && switchIndex < 4)
	{
		return switchStatus[switchIndex];  
	}

	return P_ERROR;
} 

void PowerSwitch::scanSenseValue()
{      
    ADC_SetChannel(senseChNum); 
    
    senseValue = ADC_GetAdcResult();    
}  


//---------private------------------------------
void PowerSwitch::switchSet(uint8_t switchIndex, Boolean setValue)
{
	switch (switchIndex)
	{
	case 0:
		if(setValue == TRUE)
		{  
			POWER_SWITCH_1_TURN_PT(1);
		}
		else
		{
			POWER_SWITCH_1_TURN_PT(0);      
		} 
		break;

	case 1:
		if(setValue == TRUE)
		{  
			POWER_SWITCH_2_TURN_PT(1);
		}
		else
		{
			POWER_SWITCH_2_TURN_PT(0);      
		} 
		break;

	case 2:
		if(setValue == TRUE)
		{  
			POWER_SWITCH_3_TURN_PT(1);
		}
		else
		{
			POWER_SWITCH_3_TURN_PT(0);      
		} 
		break;

	case 3:
		if(setValue == TRUE)
		{  
			POWER_SWITCH_4_TURN_PT(1);
		}
		else
		{
			POWER_SWITCH_4_TURN_PT(0);      
		} 
		break;

	default:
		break;
	}
} 

Boolean PowerSwitch::getSwitchPinStatus(uint8_t switchIndex)
{  
    Boolean status;    
    
	switch (switchIndex)
	{
	case 0:
		if(POWER_SWITCH_1_TURN_PN())
		{
			status = TRUE;  
		}  
		else
		{
			status = FALSE;   
		}  
		break;

	case 1:
		if(POWER_SWITCH_2_TURN_PN())
		{
			status = TRUE;  
		}  
		else
		{
			status = FALSE;   
		}  
		break;

	case 2:
		if(POWER_SWITCH_3_TURN_PN())
		{
			status = TRUE;  
		}  
		else
		{
			status = FALSE;   
		}  
		break;

	case 3:
		if(POWER_SWITCH_4_TURN_PN())
		{
			status = TRUE;  
		}  
		else
		{
			status = FALSE;   
		}  
		break;

	default:
		break;
	}

	return status;
} 
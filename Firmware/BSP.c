#include "BSP.h"

#ifndef __BSP_H
#error [E030] Не определен заголовочный файл BSP.h
#endif 


SystemClock systemClock;
BridgeDriver bridgeDriver(BR_SENSE_1_CH, BR_SENSE_2_CH);
PowerSwitch powerSwitch;
Usart usart;
//SensorMux sensorMux(MUX_TURN_ON_THRESHOLD);
SensorButton sensorButton[16] = {
	SensorButton(0, 0),
	SensorButton(0, 1),
	SensorButton(0, 2),
	SensorButton(0, 3),
	SensorButton(0, 4),
	SensorButton(0, 5),
	SensorButton(0, 6),
	SensorButton(0, 7),
	SensorButton(0, 8),
	SensorButton(0, 9),
	SensorButton(0, 10),
	SensorButton(0, 11),
	SensorButton(0, 12),
	SensorButton(0, 13),
	SensorButton(0, 14),
	SensorButton(0, 15)
};

Keyboard sensorKeyboard;
RemoteControl remoteControl;
Table table;

void BSP_init(void)
{
    uint8_t _setup[]      = "MSG:Power ON";

    SystemTimer::init10msInterrupt();
    ADC_Init(ADC_AVCC, ADC_CHANNEL, ADC_PRESCALER);
    HCF4067B_Init();
    bridgeDriver.init();  
    usart.init(38400, 8, 1, ASYNHRO, P_OFF, POL_RISE, X2_OFF);
    powerSwitch.init();
    //Delay_100msec;

    usart.printLn(&_setup, sizeof(_setup), STRING); 
    
    __enable_interrupt();
}  
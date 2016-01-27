#include <iom16.h>

#include <intrinsics.h>  // Заголовочный файл библиотеки для доступа к низкоуровневым функциям

#include <avr_macros.h>  // Заголовочный файл библиотеки для доступа к функциям макросов

#include <ioavr.h>       // Заголовочный файл определений входов/выходов всех AVR

#include <stdint.h>

#ifndef __BSP_H
  #define __BSP_H

#define MUX_USED_CH_COUNT       2
#define POWER_SWITCH_COUNT      4
#define REMOTE_BUTTON_COUNT     10
#define MUX_TURN_ON_THRESHOLD   700
#define MUX_OUT_CH              0
#define BR_SENSE_1_CH           1
#define BR_SENSE_2_CH           2
#define ADC_CHANNEL             1 
#define ADC_PRESCALER           32 

//Тактовая частота процессора
#define SYSTEM_CLK_HZ   (16000000) 
// Заддержки
//#define Delay_100ms()    __delay_cycles((unsigned long)(SYSTEM_CLK_HZ * 0.1))
#define Delay_125usec    __delay_cycles((unsigned long)(SYSTEM_CLK_HZ * 0.000125))
#define Delay_1msec    __delay_cycles((unsigned long)(SYSTEM_CLK_HZ * 0.01))

enum Boolean {FALSE = 0, TRUE = 1, NONE};
enum PinLevel {HIGH = 1, LOW = 0};
enum RemoteButtons {HALF_DOWN = 0, HALF_UP, FULL_DOWN, FULL_UP};
enum Pswitch {FIRST = 0, SECOND, THIRD, FOURTH};

#include "SystemTimer.h"
#include "SystemClock.h"
#include "BridgeDriver.h"
#include "PowerSwitch.h"
#include "ADC.h"  
#include "HCF4067B.h"
//#include "Sensor.h"

//#include "Serial.h"
#include "Usart.h"
#include "DebugMsg.h"
#include "Button.h"
//#include "ExternalButton.h"
#include "SensorMux.h"
#include "Keyboard.h"
#include "RemoteControl.h"

//--------------Used PINS-------------------------------------------------------
#include "BridgeDriver_PINS.h"
#include "PowerSwitch_PINS.h"
#include "Usart_PINS.h"
#include "HCF4067B_PINS.h"

//extern SystemTimer systemTimer;
extern SystemClock systemClock;
extern BridgeDriver bridgeDriver;
extern PowerSwitch powerSwitch;
extern Usart usart;
//extern SensorMux sensorMux;
extern SensorButton sensorButton[16];
//extern ExternalButton externalButton[10];
extern Keyboard sensorKeyboard;
extern RemoteControl remoteControl;


extern void BSP_init(void);

#endif
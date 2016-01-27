#include <intrinsics.h>  // Заголовочный файл библиотеки для доступа к низкоуровневым функциям

#include <avr_macros.h>  // Заголовочный файл библиотеки для доступа к функциям макросов

#include <ioavr.h>       // Заголовочный файл определений входов/выходов всех AVR

#ifndef __HCF4067B_PINS_H
  #define __HCF4067B_PINS_H

// ------Определение портов HCF4067B
// COM - PA0 - Общий вход
//-----------------------------------------------------------------------
//------ HCF4067B_COM - Общий вход
//-----------------------------------------------------------------------
/// Регистр настройки для HCF4067B_COM
#define  HCF4067B_COM_DDR   DDRA   
/// Порт для HCF4067B_COM
#define  HCF4067B_COM_PORT  PORTA  
/// Выводы порта для HCF4067B_COM
#define  HCF4067B_COM_PIN   PINA  
/// Вывод HCF4067B_COM 
#define  HCF4067B_COM_LINE  PA3    

/// <summary>
/// Настройка направления линии HCF4067B_COM - Общий вход.
/// </summary>
/// <param name="x"> 0 - линия настроена на ввод, 1 - настроена на вывод</param>
#define HCF4067B_COM_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_COM_DDR, HCF4067B_COM_LINE);\
    else CLEARBIT(HCF4067B_COM_DDR, HCF4067B_COM_LINE);\
  }

/// <summary>
/// Управление линией HCF4067B_COM - Общий вход.
/// </summary>
/// <param name="x"> 0 - на линию выводится 0, 1 - на линию выводится 1</param>
#define HCF4067B_COM_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_COM_PORT, HCF4067B_COM_LINE);\
    else CLEARBIT(HCF4067B_COM_PORT, HCF4067B_COM_LINE);\
  }

/// <summary>
/// Проверка линии HCF4067B_COM - Общий вход. 
/// </summary>
/// <returns>0 - на линии установлен 0-й уровень, 1 - на линии установлен 1-й уровень</returns>
#define HCF4067B_COM_PN() TESTBIT(HCF4067B_COM_PIN, HCF4067B_COM_LINE)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Регистр настройки для HCF4067B_A
#define  HCF4067B_A_DDR   DDRB   
/// Порт для HCF4067B_A
#define  HCF4067B_A_PORT  PORTB  
/// Выводы порта для HCF4067B_A
#define  HCF4067B_A_PIN   PINB  
/// Вывод HCF4067B_A 
#define  HCF4067B_A_LINE  PB0    

/// <summary>
/// Настройка направления линии HCF4067B_A - Общий вход.
/// </summary>
/// <param name="x"> 0 - линия настроена на ввод, 1 - настроена на вывод</param>
#define HCF4067B_A_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_A_DDR, HCF4067B_A_LINE);\
    else CLEARBIT(HCF4067B_A_DDR, HCF4067B_A_LINE);\
  }

/// <summary>
/// Управление линией HCF4067B_A - Общий вход.
/// </summary>
/// <param name="x"> 0 - на линию выводится 0, 1 - на линию выводится 1</param>
#define HCF4067B_A_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_A_PORT, HCF4067B_A_LINE);\
    else CLEARBIT(HCF4067B_A_PORT, HCF4067B_A_LINE);\
  }

/// <summary>
/// Проверка линии HCF4067B_A - Общий вход. 
/// </summary>
/// <returns>0 - на линии установлен 0-й уровень, 1 - на линии установлен 1-й уровень</returns>
#define HCF4067B_A_PN() TESTBIT(HCF4067B_A_PIN, HCF4067B_A_LINE)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Регистр настройки для HCF4067B_B
#define  HCF4067B_B_DDR   DDRC   
/// Порт для HCF4067B_B
#define  HCF4067B_B_PORT  PORTC  
/// Выводы порта для HCF4067B_B
#define  HCF4067B_B_PIN   PINC  
/// Вывод HCF4067B_B 
#define  HCF4067B_B_LINE  PC0    

/// <summary>
/// Настройка направления линии HCF4067B_B - Общий вход.
/// </summary>
/// <param name="x"> 0 - линия настроена на ввод, 1 - настроена на вывод</param>
#define HCF4067B_B_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_B_DDR, HCF4067B_B_LINE);\
    else CLEARBIT(HCF4067B_B_DDR, HCF4067B_B_LINE);\
  }

/// <summary>
/// Управление линией HCF4067B_B - Общий вход.
/// </summary>
/// <param name="x"> 0 - на линию выводится 0, 1 - на линию выводится 1</param>
#define HCF4067B_B_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_B_PORT, HCF4067B_B_LINE);\
    else CLEARBIT(HCF4067B_B_PORT, HCF4067B_B_LINE);\
  }

/// <summary>
/// Проверка линии HCF4067B_B - Общий вход. 
/// </summary>
/// <returns>0 - на линии установлен 0-й уровень, 1 - на линии установлен 1-й уровень</returns>
#define HCF4067B_B_PN() TESTBIT(HCF4067B_B_PIN, HCF4067B_B_LINE)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Регистр настройки для HCF4067B_C
#define  HCF4067B_C_DDR   DDRB   
/// Порт для HCF4067B_C
#define  HCF4067B_C_PORT  PORTB  
/// Выводы порта для HCF4067B_C
#define  HCF4067B_C_PIN   PINB  
/// Вывод HCF4067B_C 
#define  HCF4067B_C_LINE  PB2    

/// <summary>
/// Настройка направления линии HCF4067B_C - Общий вход.
/// </summary>
/// <param name="x"> 0 - линия настроена на ввод, 1 - настроена на вывод</param>
#define HCF4067B_C_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_C_DDR, HCF4067B_C_LINE);\
    else CLEARBIT(HCF4067B_C_DDR, HCF4067B_C_LINE);\
  }

/// <summary>
/// Управление линией HCF4067B_C - Общий вход.
/// </summary>
/// <param name="x"> 0 - на линию выводится 0, 1 - на линию выводится 1</param>
#define HCF4067B_C_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_C_PORT, HCF4067B_C_LINE);\
    else CLEARBIT(HCF4067B_C_PORT, HCF4067B_C_LINE);\
  }

/// <summary>
/// Проверка линии HCF4067B_C - Общий вход. 
/// </summary>
/// <returns>0 - на линии установлен 0-й уровень, 1 - на линии установлен 1-й уровень</returns>
#define HCF4067B_C_PN() TESTBIT(HCF4067B_C_PIN, HCF4067B_C_LINE)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Регистр настройки для HCF4067B_D
#define  HCF4067B_D_DDR   DDRB   
/// Порт для HCF4067B_D
#define  HCF4067B_D_PORT  PORTB  
/// Выводы порта для HCF4067B_D
#define  HCF4067B_D_PIN   PINB 
/// Вывод HCF4067B_D 
#define  HCF4067B_D_LINE  PB2   

/// <summary>
/// Настройка направления линии HCF4067B_D - Общий вход.
/// </summary>
/// <param name="x"> 0 - линия настроена на ввод, 1 - настроена на вывод</param>
#define HCF4067B_D_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_D_DDR, HCF4067B_D_LINE);\
    else CLEARBIT(HCF4067B_D_DDR, HCF4067B_D_LINE);\
  }

/// <summary>
/// Управление линией HCF4067B_D - Общий вход.
/// </summary>
/// <param name="x"> 0 - на линию выводится 0, 1 - на линию выводится 1</param>
#define HCF4067B_D_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_D_PORT, HCF4067B_D_LINE);\
    else CLEARBIT(HCF4067B_D_PORT, HCF4067B_D_LINE);\
  }

/// <summary>
/// Проверка линии HCF4067B_D - Общий вход. 
/// </summary>
/// <returns>0 - на линии установлен 0-й уровень, 1 - на линии установлен 1-й уровень</returns>
#define HCF4067B_D_PN() TESTBIT(HCF4067B_D_PIN, HCF4067B_D_LINE)
//------------------------------------------------------------------------------

#endif
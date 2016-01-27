#include <intrinsics.h>  // Заголовочный файл библиотеки для доступа к низкоуровневым функциям

#include <avr_macros.h>  // Заголовочный файл библиотеки для доступа к функциям макросов

#include <ioavr.h>       // Заголовочный файл определений входов/выходов всех AVR

#ifndef __POWER_SWITCH_PINS_H
  #define __POWER_SWITCH_PINS_H

//------------------------------------------------------------------------------
#define  POWER_SWITCH_1_TURN_DDR    DDRD  
#define  POWER_SWITCH_1_TURN_PORT   PORTD  
#define  POWER_SWITCH_1_TURN_PIN    PIND   
#define  POWER_SWITCH_1_TURN_LINE   PD6

#define POWER_SWITCH_1_TURN_DR(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_1_TURN_DDR, POWER_SWITCH_1_TURN_LINE);\
    else CLEARBIT(POWER_SWITCH_1_TURN_DDR, POWER_SWITCH_1_TURN_LINE);\
  }

#define POWER_SWITCH_1_TURN_PT(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_1_TURN_PORT, POWER_SWITCH_1_TURN_LINE);\
    else CLEARBIT(POWER_SWITCH_1_TURN_PORT, POWER_SWITCH_1_TURN_LINE);\
  }

#define POWER_SWITCH_1_TURN_PN() TESTBIT(POWER_SWITCH_1_TURN_PIN, POWER_SWITCH_1_TURN_LINE)  
//------------------------------------------------------------------------------
#define  POWER_SWITCH_2_TURN_DDR    DDRD  
#define  POWER_SWITCH_2_TURN_PORT   PORTD  
#define  POWER_SWITCH_2_TURN_PIN    PIND   
#define  POWER_SWITCH_2_TURN_LINE   PD7

#define POWER_SWITCH_2_TURN_DR(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_2_TURN_DDR, POWER_SWITCH_2_TURN_LINE);\
    else CLEARBIT(POWER_SWITCH_2_TURN_DDR, POWER_SWITCH_2_TURN_LINE);\
  }

#define POWER_SWITCH_2_TURN_PT(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_2_TURN_PORT, POWER_SWITCH_2_TURN_LINE);\
    else CLEARBIT(POWER_SWITCH_2_TURN_PORT, POWER_SWITCH_2_TURN_LINE);\
  }

#define POWER_SWITCH_2_TURN_PN() TESTBIT(POWER_SWITCH_2_TURN_PIN, POWER_SWITCH_2_TURN_LINE)  
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#define  POWER_SWITCH_3_TURN_DDR    DDRD  
#define  POWER_SWITCH_3_TURN_PORT   PORTD  
#define  POWER_SWITCH_3_TURN_PIN    PIND   
#define  POWER_SWITCH_3_TURN_LINE   PD7

#define POWER_SWITCH_3_TURN_DR(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_3_TURN_DDR, POWER_SWITCH_3_TURN_LINE);\
    else CLEARBIT(POWER_SWITCH_3_TURN_DDR, POWER_SWITCH_3_TURN_LINE);\
  }

#define POWER_SWITCH_3_TURN_PT(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_3_TURN_PORT, POWER_SWITCH_3_TURN_LINE);\
    else CLEARBIT(POWER_SWITCH_3_TURN_PORT, POWER_SWITCH_3_TURN_LINE);\
  }

#define POWER_SWITCH_3_TURN_PN() TESTBIT(POWER_SWITCH_3_TURN_PIN, POWER_SWITCH_3_TURN_LINE)  
//------------------------------------------------------------------------------
#define  POWER_SWITCH_4_TURN_DDR    DDRD  
#define  POWER_SWITCH_4_TURN_PORT   PORTD  
#define  POWER_SWITCH_4_TURN_PIN    PIND   
#define  POWER_SWITCH_4_TURN_LINE   PD7

#define POWER_SWITCH_4_TURN_DR(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_4_TURN_DDR, POWER_SWITCH_4_TURN_LINE);\
    else CLEARBIT(POWER_SWITCH_4_TURN_DDR, POWER_SWITCH_4_TURN_LINE);\
  }

#define POWER_SWITCH_4_TURN_PT(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_4_TURN_PORT, POWER_SWITCH_4_TURN_LINE);\
    else CLEARBIT(POWER_SWITCH_4_TURN_PORT, POWER_SWITCH_4_TURN_LINE);\
  }

#define POWER_SWITCH_4_TURN_PN() TESTBIT(POWER_SWITCH_4_TURN_PIN, POWER_SWITCH_4_TURN_LINE)  
//------------------------------------------------------------------------------
#define  POWER_SWITCH_SENSE_DDR    DDRA   
#define  POWER_SWITCH_SENSE_PORT   PORTA  
#define  POWER_SWITCH_SENSE_PIN    PINA   
#define  POWER_SWITCH_SENSE_LINE   PA2  

#define POWER_SWITCH_SENSE_DR(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_SENSE_DDR, POWER_SWITCH_SENSE_LINE);\
    else CLEARBIT(POWER_SWITCH_SENSE_DDR, POWER_SWITCH_SENSE_LINE);\
  }

#define POWER_SWITCH_SENSE_PT(x)\
  {\
    if (x) SETBIT(POWER_SWITCH_SENSE_PORT, POWER_SWITCH_SENSE_LINE);\
    else CLEARBIT(POWER_SWITCH_SENSE_PORT, POWER_SWITCH_SENSE_LINE);\
  }

#define POWER_SWITCH_SENSE_PN() TESTBIT(POWER_SWITCH_SENSE_PIN, POWER_SWITCH_SENSE_LINE)  
//------------------------------------------------------------------------------

#endif
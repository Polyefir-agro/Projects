#include <intrinsics.h>  // Заголовочный файл библиотеки для доступа к низкоуровневым функциям

#include <avr_macros.h>  // Заголовочный файл библиотеки для доступа к функциям макросов

#include <ioavr.h>       // Заголовочный файл определений входов/выходов всех AVR

#ifndef __BRIDGE_PINS_H
  #define __BRIDGE_PINS_H

#define  BRIDGE_INH_DDR    DDRB   
#define  BRIDGE_INH_PORT   PORTB  
#define  BRIDGE_INH_PIN    PINB   
#define  BRIDGE_INH_LINE   PB4 

#define BRIDGE_INH_DR(x)\
  {\
    if (x) SETBIT(BRIDGE_INH_DDR, BRIDGE_INH_LINE);\
    else CLEARBIT(BRIDGE_INH_DDR, BRIDGE_INH_LINE);\
  }

#define BRIDGE_INH_PT(x)\
  {\
    if (x) SETBIT(BRIDGE_INH_PORT, BRIDGE_INH_LINE);\
    else CLEARBIT(BRIDGE_INH_PORT, BRIDGE_INH_LINE);\
  }

#define BRIDGE_INH_PN() TESTBIT(BRIDGE_INH_PIN, BRIDGE_INH_LINE)  
//------------------------------------------------------------------------------
#define  BRIDGE_FORW_START_DDR    DDRB   
#define  BRIDGE_FORW_START_PORT   PORTB  
#define  BRIDGE_FORW_START_PIN    PINB   
#define  BRIDGE_FORW_START_LINE   PB4 

#define BRIDGE_FORW_START_DR(x)\
  {\
    if (x) SETBIT(BRIDGE_FORW_START_DDR, BRIDGE_FORW_START_LINE);\
    else CLEARBIT(BRIDGE_FORW_START_DDR, BRIDGE_FORW_START_LINE);\
  }

#define BRIDGE_FORW_START_PT(x)\
  {\
    if (x) SETBIT(BRIDGE_FORW_START_PORT, BRIDGE_FORW_START_LINE);\
    else CLEARBIT(BRIDGE_FORW_START_PORT, BRIDGE_FORW_START_LINE);\
  }

#define BRIDGE_FORW_START_PN() TESTBIT(BRIDGE_FORW_START_PIN, BRIDGE_FORW_START_LINE)  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#define  BRIDGE_FORW_SENSE_DDR    DDRA   
#define  BRIDGE_FORW_SENSE_PORT   PORTA  
#define  BRIDGE_FORW_SENSE_PIN    PINA   
#define  BRIDGE_FORW_SENSE_LINE   PA2  

#define BRIDGE_FORW_SENSE_DR(x)\
  {\
    if (x) SETBIT(BRIDGE_FORW_SENSE_DDR, BRIDGE_FORW_SENSE_LINE);\
    else CLEARBIT(BRIDGE_FORW_SENSE_DDR, BRIDGE_FORW_SENSE_LINE);\
  }

#define BRIDGE_FORW_SENSE_PT(x)\
  {\
    if (x) SETBIT(BRIDGE_FORW_SENSE_PORT, BRIDGE_FORW_SENSE_LINE);\
    else CLEARBIT(BRIDGE_FORW_SENSE_PORT, BRIDGE_FORW_SENSE_LINE);\
  }

#define BRIDGE_FORW_SENSE_PN() TESTBIT(BRIDGE_FORW_SENSE_PIN, BRIDGE_FORW_SENSE_LINE)  
//------------------------------------------------------------------------------
#define  BRIDGE_BACK_START_DDR    DDRB   
#define  BRIDGE_BACK_START_PORT   PORTB  
#define  BRIDGE_BACK_START_PIN    PINB   
#define  BRIDGE_BACK_START_LINE   PB4  

#define BRIDGE_BACK_START_DR(x)\
  {\
    if (x) SETBIT(BRIDGE_BACK_START_DDR, BRIDGE_BACK_START_LINE);\
    else CLEARBIT(BRIDGE_BACK_START_DDR, BRIDGE_BACK_START_LINE);\
  }

#define BRIDGE_BACK_START_PT(x)\
  {\
    if (x) SETBIT(BRIDGE_BACK_START_PORT, BRIDGE_BACK_START_LINE);\
    else CLEARBIT(BRIDGE_BACK_START_PORT, BRIDGE_BACK_START_LINE);\
  }

#define BRIDGE_BACK_START_PN() TESTBIT(BRIDGE_BACK_START_PIN, BRIDGE_BACK_START_LINE)  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#define  BRIDGE_BACK_SENSE_DDR    DDRA   
#define  BRIDGE_BACK_SENSE_PORT   PORTA  
#define  BRIDGE_BACK_SENSE_PIN    PINA   
#define  BRIDGE_BACK_SENSE_LINE   PA2  

#define BRIDGE_BACK_SENSE_DR(x)\
  {\
    if (x) SETBIT(BRIDGE_BACK_SENSE_DDR, BRIDGE_BACK_SENSE_LINE);\
    else CLEARBIT(BRIDGE_BACK_SENSE_DDR, BRIDGE_BACK_SENSE_LINE);\
  }

#define BRIDGE_BACK_SENSE_PT(x)\
  {\
    if (x) SETBIT(BRIDGE_BACK_SENSE_PORT, BRIDGE_BACK_SENSE_LINE);\
    else CLEARBIT(BRIDGE_BACK_SENSE_PORT, BRIDGE_BACK_SENSE_LINE);\
  }

#define BRIDGE_BACK_SENSE_PN() TESTBIT(BRIDGE_BACK_SENSE_PIN, BRIDGE_BACK_SENSE_LINE)  
//------------------------------------------------------------------------------

#endif
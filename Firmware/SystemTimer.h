#include <intrinsics.h>  // Заголовочный файл библиотеки для доступа к низкоуровневым функциям

#include <avr_macros.h>  // Заголовочный файл библиотеки для доступа к функциям макросов

#include <ioavr.h>       // Заголовочный файл определений входов/выходов всех AVR
  
#include "BSP.h"

#ifndef __SystemTimer_H
  #define __SystemTimer_H

class SystemTimer {
    
    public:
    
        // Constructor
        SystemTimer();
        // Destructor
        virtual ~SystemTimer();          
                
        static void init10msInterrupt();
        
        static void handleTickInterrupt();  
                
        static uint64_t getTicks();
                                            
    private:
      
        static uint64_t ticks;      
              
};



inline SystemTimer::SystemTimer()
{

}

inline SystemTimer::~SystemTimer()
{

}



#endif
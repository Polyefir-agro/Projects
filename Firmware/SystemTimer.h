#include <intrinsics.h>  // ������������ ���� ���������� ��� ������� � �������������� ��������

#include <avr_macros.h>  // ������������ ���� ���������� ��� ������� � �������� ��������

#include <ioavr.h>       // ������������ ���� ����������� ������/������� ���� AVR
  
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
#include "SystemClock.h"

#ifndef __SystemClock_H
#error [E030] Не определен заголовочный файл SystemClock.h
#endif 


/*void SystemClock::tick()
{
     clockTicks = SystemTimer::getTicks();
}*/

/**uint8_t SystemClock::getSeconds()
{
      
    return (clockTicks/100)%60;
}

uint8_t SystemClock::getMinutes()
{
    return (clockTicks/6000)%60;
}

uint8_t SystemClock::getHours()
{
    return (clockTicks/360000)%24;
}*/


void SystemClock::setStartTics()
{
    startTicks = SystemTimer::getTicks(); 
}  


uint16_t SystemClock::milliSecondsPassed()
{
    clockTicks = SystemTimer::getTicks();    
 
    //Boolean msecondsPassed = FALSE;
    
    uint16_t dif = clockTicks - startTicks;
  
    /*if(clockTicks - startTicks >= mseconds/10)
    {
        msecondsPassed = TRUE;  
        
        startTicks = 0;
    } */ 
      
    return dif*10;
}

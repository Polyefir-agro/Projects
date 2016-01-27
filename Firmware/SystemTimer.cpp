#include "SystemTimer.h"

#ifndef __SystemTimer_H
#error [E030] Не определен заголовочный файл SystemTimer.h
#endif 

uint64_t SystemTimer::ticks = 0;

//-----------public----------------------------
void SystemTimer::init10msInterrupt()
{
    OCR2 = 158-1;                                 // Записываю регистр сравнения                  //
    TCCR2 = 0;                                   // Выход таймера отключен                       //
    TCCR2 = 1<<WGM21;                            // Режим CTC - сброс при совпадении             //
    TCCR2 |= (1<<CS22)|(1<<CS21)|(1<<CS20);      // Коэффициент предделителя = 1024              //
    TIMSK = (1<<OCIE2);                         // Разрешаю прерывание при совпадении регистров //     
}  

//---------private------------------------------
void SystemTimer::handleTickInterrupt()
{
    ticks++;  
}  


uint64_t SystemTimer::getTicks()
{
    return ticks;  
}  


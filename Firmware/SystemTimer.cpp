#include "SystemTimer.h"

#ifndef __SystemTimer_H
#error [E030] �� ��������� ������������ ���� SystemTimer.h
#endif 

uint64_t SystemTimer::ticks = 0;

//-----------public----------------------------
void SystemTimer::init10msInterrupt()
{
    OCR2 = 158-1;                                 // ��������� ������� ���������                  //
    TCCR2 = 0;                                   // ����� ������� ��������                       //
    TCCR2 = 1<<WGM21;                            // ����� CTC - ����� ��� ����������             //
    TCCR2 |= (1<<CS22)|(1<<CS21)|(1<<CS20);      // ����������� ������������ = 1024              //
    TIMSK = (1<<OCIE2);                         // �������� ���������� ��� ���������� ��������� //     
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


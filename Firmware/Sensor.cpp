#include "Sensor.h"

#ifndef __Sensor_H
#error [E030] �� ��������� ������������ ���� Sensor.h
#endif 

void Sensor::handle()
{
  
} 

uint16_t Sensor::getValue()
{
    return value;  
}  



Boolean Sensor::getTurnOn()
{
    return turnOn;  
}  
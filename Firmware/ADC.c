//  ADC.c
//  Исходный код драйвера ADC - внутренний АЦП МК. Версия 1.0 от 29 апреля 2011 года.
//  Поддерживает все МК AVR с достаточным количеством выводов.
//  Разработчик: Евгений belmel@tut.by

// Подключаем заголовочные файлы

#include "ADC.h"  

#ifndef __ADC_DRIVER_H
#error [E030] Не определен заголовочный файл ADC.h
#endif 

//-------------------------------------------------------------------------------------
/// <summary>
/// Функция инициализации внутреннего АЦП.
/// </summary>
/// <param name="ref">Источник опорного напряжения:0 - внешний ИОН, 1 - внутренний ИОН 5В, 
/// 3 - внутренний ИОН 2.56В</param>
/// <param name="prescaler">Предделитель тактовой частоты: деление частоты на 2, 4 ,
///  8 , 16 , 32, 64 или 128</param>
/// <returns></returns>
void ADC_Init(uint8_t ref, uint8_t adcChannel, uint8_t prescaler)
{
    ADC_SetVoltageReference(ref);  // ИОН - AVcc
    ADC_SetPrescaler(prescaler);   // Преддел. - 128, частота = 14.7456 МГц/128 = 115 кГц
    ADC_SetChannel(adcChannel);   // Установка первого канала АЦП
    
    SETBIT(ADCSRA, ADEN);          // Разрешить АЦП преобразование
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// Функция выбора канала АЦП
/// </summary>
/// <param name="chIndex">номер канала от 0 до 7</param>
/// <returns></returns>
void ADC_SetChannel(uint8_t chIndex)
{
    switch (chIndex)
    {
    case 0:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        CLEARBIT(ADMUX, MUX2);
        CLEARBIT(ADMUX, MUX1);
        CLEARBIT(ADMUX, MUX0); 
        break;
    case 1:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        CLEARBIT(ADMUX, MUX2);
        CLEARBIT(ADMUX, MUX1);
        SETBIT(ADMUX, MUX0); 
        break;
    case 2:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        CLEARBIT(ADMUX, MUX2);
        SETBIT(ADMUX, MUX1);
        CLEARBIT(ADMUX, MUX0); 
        break;
    case 3:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        CLEARBIT(ADMUX, MUX2);
        SETBIT(ADMUX, MUX1);
        SETBIT(ADMUX, MUX0); 
        break;
    case 4:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        SETBIT(ADMUX, MUX2);
        CLEARBIT(ADMUX, MUX1);
        CLEARBIT(ADMUX, MUX0); 
        break;
    case 5:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        SETBIT(ADMUX, MUX2);
        CLEARBIT(ADMUX, MUX1);
        SETBIT(ADMUX, MUX0); 
        break;
    case 6:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        SETBIT(ADMUX, MUX2);
        SETBIT(ADMUX, MUX1);
        CLEARBIT(ADMUX, MUX0); 
        break;
    case 7:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        SETBIT(ADMUX, MUX2);
        SETBIT(ADMUX, MUX1);
        SETBIT(ADMUX, MUX0); 
        break;
    default:
        CLEARBIT(ADMUX, MUX4);
        CLEARBIT(ADMUX, MUX3);
        CLEARBIT(ADMUX, MUX2);
        CLEARBIT(ADMUX, MUX1);
        CLEARBIT(ADMUX, MUX0); 
        break;
    }
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// Функция выбора источника опорного напряжения
/// </summary>
/// <param name="voltRef">0 - внешний ИОН, 1 - внутренний ИОН 5В, 3 - внутренний ИОН 2.56В</param>
/// <returns></returns>
void ADC_SetVoltageReference(uint8_t voltRef)
{
    switch (voltRef)
    {
    case 0:
        CLEARBIT(ADMUX, REFS1);
        CLEARBIT(ADMUX, REFS0);
        break;
    case 1:
        CLEARBIT(ADMUX, REFS1);
        SETBIT(ADMUX, REFS0);
        break;
    case 3:
        SETBIT(ADMUX, REFS1);
        SETBIT(ADMUX, REFS0);
        break;
    default:
        CLEARBIT(ADMUX, REFS1);
        CLEARBIT(ADMUX, REFS0);
        break;
    }
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// Функция установки предделителя частоты АЦП
/// </summary>
/// <param name="divider">деление частоты на 2, 4 , 8 , 16 , 32, 64 или 128</param>
/// <returns></returns>
void ADC_SetPrescaler(uint8_t divider)
{
    switch (divider)
    {
    case 2:
        CLEARBIT(ADCSRA, ADPS2);
        CLEARBIT(ADCSRA, ADPS1);
        SETBIT(ADCSRA, ADPS0);
        break;
    case 4:
        CLEARBIT(ADCSRA, ADPS2);
        SETBIT(ADCSRA, ADPS1);
        CLEARBIT(ADCSRA, ADPS0);
        break;
    case 8:
        CLEARBIT(ADCSRA, ADPS2);
        SETBIT(ADCSRA, ADPS1);
        SETBIT(ADCSRA, ADPS0);
        break;
    case 16:
        SETBIT(ADCSRA, ADPS2);
        CLEARBIT(ADCSRA, ADPS1);
        CLEARBIT(ADCSRA, ADPS0);
        break;
    case 32:
        SETBIT(ADCSRA, ADPS2);
        CLEARBIT(ADCSRA, ADPS1);
        SETBIT(ADCSRA, ADPS0);
        break;
    case 64:
        SETBIT(ADCSRA, ADPS2);
        SETBIT(ADCSRA, ADPS1);
        CLEARBIT(ADCSRA, ADPS0);
        break;
    case 128:
        SETBIT(ADCSRA, ADPS2);
        SETBIT(ADCSRA, ADPS1);
        SETBIT(ADCSRA, ADPS0);
        break;
    default:
        CLEARBIT(ADCSRA, ADPS2);
        CLEARBIT(ADCSRA, ADPS1);
        SETBIT(ADCSRA, ADPS0);
        break;
    }
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// Функция возврата результата АЦП
/// </summary>
/// <returns>Результат АЦП</returns>
uint16_t ADC_GetAdcResult(void)
{
    uint16_t adcResult;     // Результат АЦП
    uint8_t adcResultLow;  // Младший байт АЦП
    uint8_t adcResultHigh; // Старший байт АЦП
        
    SETBIT(ADCSRA, ADSC);          // Запуск преобразования
    while(TESTBIT(ADCSRA, ADSC));  // Если преобразование завершено         
    SETBIT(ADCSRA, ADIF);          // Сброс флага окончания преобразования
         
    adcResultLow = ADCL;         
    adcResultHigh = ADCH;
         
    adcResult = adcResultHigh;
    adcResult = (adcResult << 8) + adcResultLow;                
         
    return adcResult;  // Возврат результата АЦП
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// Функция предназначена для внесения поправки в результат 
/// АЦП в связи с ошибкой преобразования.(Cодержит задержку 125 мкс)
/// </summary>
/// <param name="data">Результат преобразования</param>
/// <returns>Истинное значение результата преобразования</returns>
uint16_t ADC_CorrectAdcResult(uint16_t data)
{
    uint16_t correctionVoltage;  // Измеренное опорное напряжение для корректировки
    uint16_t correctedData;      // Скорректированные данные

    SETBIT(ADMUX, MUX4);  // Выбор напряжения 1.1В на входе АЦП
    SETBIT(ADMUX, MUX3);
    SETBIT(ADMUX, MUX2);
    SETBIT(ADMUX, MUX1);
    CLEARBIT(ADMUX, MUX0); 

    Delay_125usec;

    correctionVoltage = ADC_GetAdcResult(); // Измерить корректировочное напряжение

    if(correctionVoltage > ADC_CORRECT_REF)
    {
        correctedData = data - (correctionVoltage - ADC_CORRECT_REF);
    }
    else if(correctionVoltage < ADC_CORRECT_REF)
    {
        correctedData = data + (ADC_CORRECT_REF - correctionVoltage);
    }

    ADC_SetChannel(ADC_IN1);

    return correctedData;
}
//-------------------------------------------------------------------------------------
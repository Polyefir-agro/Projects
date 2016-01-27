//  ADC.c
//  �������� ��� �������� ADC - ���������� ��� ��. ������ 1.0 �� 29 ������ 2011 ����.
//  ������������ ��� �� AVR � ����������� ����������� �������.
//  �����������: ������� belmel@tut.by

// ���������� ������������ �����

#include "ADC.h"  

#ifndef __ADC_DRIVER_H
#error [E030] �� ��������� ������������ ���� ADC.h
#endif 

//-------------------------------------------------------------------------------------
/// <summary>
/// ������� ������������� ����������� ���.
/// </summary>
/// <param name="ref">�������� �������� ����������:0 - ������� ���, 1 - ���������� ��� 5�, 
/// 3 - ���������� ��� 2.56�</param>
/// <param name="prescaler">������������ �������� �������: ������� ������� �� 2, 4 ,
///  8 , 16 , 32, 64 ��� 128</param>
/// <returns></returns>
void ADC_Init(uint8_t ref, uint8_t adcChannel, uint8_t prescaler)
{
    ADC_SetVoltageReference(ref);  // ��� - AVcc
    ADC_SetPrescaler(prescaler);   // �������. - 128, ������� = 14.7456 ���/128 = 115 ���
    ADC_SetChannel(adcChannel);   // ��������� ������� ������ ���
    
    SETBIT(ADCSRA, ADEN);          // ��������� ��� ��������������
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// ������� ������ ������ ���
/// </summary>
/// <param name="chIndex">����� ������ �� 0 �� 7</param>
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
/// ������� ������ ��������� �������� ����������
/// </summary>
/// <param name="voltRef">0 - ������� ���, 1 - ���������� ��� 5�, 3 - ���������� ��� 2.56�</param>
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
/// ������� ��������� ������������ ������� ���
/// </summary>
/// <param name="divider">������� ������� �� 2, 4 , 8 , 16 , 32, 64 ��� 128</param>
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
/// ������� �������� ���������� ���
/// </summary>
/// <returns>��������� ���</returns>
uint16_t ADC_GetAdcResult(void)
{
    uint16_t adcResult;     // ��������� ���
    uint8_t adcResultLow;  // ������� ���� ���
    uint8_t adcResultHigh; // ������� ���� ���
        
    SETBIT(ADCSRA, ADSC);          // ������ ��������������
    while(TESTBIT(ADCSRA, ADSC));  // ���� �������������� ���������         
    SETBIT(ADCSRA, ADIF);          // ����� ����� ��������� ��������������
         
    adcResultLow = ADCL;         
    adcResultHigh = ADCH;
         
    adcResult = adcResultHigh;
    adcResult = (adcResult << 8) + adcResultLow;                
         
    return adcResult;  // ������� ���������� ���
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// ������� ������������� ��� �������� �������� � ��������� 
/// ��� � ����� � ������� ��������������.(C������� �������� 125 ���)
/// </summary>
/// <param name="data">��������� ��������������</param>
/// <returns>�������� �������� ���������� ��������������</returns>
uint16_t ADC_CorrectAdcResult(uint16_t data)
{
    uint16_t correctionVoltage;  // ���������� ������� ���������� ��� �������������
    uint16_t correctedData;      // ����������������� ������

    SETBIT(ADMUX, MUX4);  // ����� ���������� 1.1� �� ����� ���
    SETBIT(ADMUX, MUX3);
    SETBIT(ADMUX, MUX2);
    SETBIT(ADMUX, MUX1);
    CLEARBIT(ADMUX, MUX0); 

    Delay_125usec;

    correctionVoltage = ADC_GetAdcResult(); // �������� ���������������� ����������

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
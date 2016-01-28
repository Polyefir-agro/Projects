//  HCF4067B.c
//  �������� ��� �������� HCF4067B - 16-�� ��������� �������������. ������ 1.0 �� 18.12.2015 ����.
//  ������������ ��� �� AVR � ����������� ����������� �������.
//  �����������: ������� belmel@yandex.ru


#include "HCF4067B.h"
#include "ADC.h"

#ifndef __HCF4067B_H
#error [E030] �� ��������� ������������ ���� HCF4067B.h
#endif 

#ifndef __HCF4067B_PINS_H
#error [E030] �� ��������� ������������ ���� HCF4067B_PINS.h
#endif 

//-------------------------------------------------------------------------------------
/// <summary>
/// ������� ������������� �������� HCF4067B.
/// ����-�� ��������� ����� COM, ��������� ������� ������ ��������������.
/// </summary>
/// <returns></returns>
void HCF4067B_Init(void)
{
    HCF4067B_COM_DR(0);  // ��������� �� ���� 
    HCF4067B_COM_PT(0);  // ��� �������������� ���������
    
    HCF4067B_A_DR(1);         
    HCF4067B_B_DR(1);      
    HCF4067B_C_DR(1);      
    HCF4067B_D_DR(1);         
 
    HCF4067B_SetChannel(HCF4067B_IN1);  // ��������� ������� ������ �������� ��������������
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// ������� ��������� ������� ������ �������� ��������������.
/// </summary>
/// <param name="channelNum">����� ������: �� 0 �� 15</param>
/// <returns></returns>
void HCF4067B_SetChannel(uint8_t channelNum)
{
    switch (channelNum)
    {
    case 0:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(0);
        break;
    case 1:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(1);
        break;
    case 2:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(1);   
        HCF4067B_A_PT(0);
        break;
    case 3:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(1);   
        HCF4067B_A_PT(1);
        break;
    case 4:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(1);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(0);
        break;
    case 5:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(1);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(1);
        break;
    case 6:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(1);
        HCF4067B_B_PT(1);   
        HCF4067B_A_PT(0);
        break;    
    case 7:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(1);
        HCF4067B_B_PT(1);   
        HCF4067B_A_PT(1);
        break;     
    case 8:
        HCF4067B_D_PT(1);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(0);
        break;
    case 9:
        HCF4067B_D_PT(1);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(1);
        break;           
    case 10:
        HCF4067B_D_PT(1);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(1);   
        HCF4067B_A_PT(0);
        break;
    case 11:
        HCF4067B_D_PT(1);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(1);   
        HCF4067B_A_PT(1);
        break;
    case 12:
        HCF4067B_D_PT(1);
        HCF4067B_C_PT(1);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(0);
        break;
    case 13:
        HCF4067B_D_PT(1);
        HCF4067B_C_PT(1);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(1);
        break;
    case 14:
        HCF4067B_D_PT(1);
        HCF4067B_C_PT(1);
        HCF4067B_B_PT(1);   
        HCF4067B_A_PT(0);
        break;           
    case 15:
        HCF4067B_D_PT(1);
        HCF4067B_C_PT(1);
        HCF4067B_B_PT(1);   
        HCF4067B_A_PT(1);
        break;          
    default:
        HCF4067B_D_PT(0);
        HCF4067B_C_PT(0);
        HCF4067B_B_PT(0);   
        HCF4067B_A_PT(0);
        break;
    }
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// ������� �������� ���������� ��� �� ��������� ������.
/// (��� ������ ������� ���������� ��������������� ������������� �������� ���)
/// </summary>
/// <param name="channelNum">����� ������ : �� 0 �� 15</param>
/// <returns>��������� ��� �� ��������� ������</returns>
uint16_t HCF4067B_GetAdcFromChannel(uint8_t channelNum)
{
    uint16_t adcResult;     // ��������� ���
  
    HCF4067B_SetChannel(channelNum);
    
    adcResult = ADC_GetAdcResult();
    
    return adcResult;
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
PinLevel HCF4067B_GetChannelLevel(uint8_t channelNum)
{
    PinLevel level = LOW;     // ��������� ���

	if((int8_t)channelNum >= 0 && channelNum < 16)
	{
		HCF4067B_SetChannel(channelNum);  

		Delay_10usec;

		if(HCF4067B_COM_PN())
		{
			level = HIGH;
		}
		else
		{
			level = LOW;
		}
		
	}

	return level;
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
/// <summary>
/// ������� �������� ��������� ���������� ������ �������� ��������������.
/// </summary>
/// <param name="channelNum">����� ������: �� 0 �� 15</param>
/// <returns>��������� ���������� ������ �������� ��������������:0 - �� ����� 
/// ���������� ���.0 ��� !=0 - �� ����� ����-� ���.1</returns>
Boolean HCF4067B_GetInputState(uint16_t adcResult, uint16_t adcThreshold)
{   
    Boolean inputState;
  
    if(adcResult > adcThreshold) //todo
    {  
        inputState = TRUE; 
    }        
    else
    {
        inputState = FALSE;  
    }  
 
    return inputState;
}
//-------------------------------------------------------------------------------------

/*
   adc_long = Get_ADC_Arifm_Average(&AnDigConv); // �������� ������� �������� ���
   adc_long = (adc_long * 5058) / 1024;//adc_long = (adc_long * 2618) / 1024;           // ������������� � ������
   adc_transmit_h = (byte)(adc_long >> 8);        
   adc_transmit_l = (byte)(adc_long & 0x000000FF);
*/

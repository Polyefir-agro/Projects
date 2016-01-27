//  HCF4067B.h
//  �������� ��� �������� HCF4067B - 16-�� ��������� �������������. ������ 1.0 �� 18.12.2015 ����.
//  ������������ ��� �� AVR � ����������� ����������� �������.
//  �����������: ������� belmel@yandex.ru

// ���������� ������������ �����
#include <intrinsics.h>  // ������������ ���� ���������� ��� ������� � �������������� ��������

#include <avr_macros.h>  // ������������ ���� ���������� ��� ������� � �������� ��������

#include <ioavr.h>   // ������������ ���� ����������� ������/������� ���� AVR

#include <stdint.h>

#include "BSP.h"

/// ���������, ��� ������������ ������� HCT4051
#ifndef __HCF4067B_H
  #define __HCF4067B_H

//------- ������ �������� �������������� ----------------
#define   HCF4067B_IN1     0 
#define   HCF4067B_IN2     1 
#define   HCF4067B_IN3     2 
#define   HCF4067B_IN4     3 
#define   HCF4067B_IN5     4 
#define   HCF4067B_IN6     5 
#define   HCF4067B_IN7     6 
#define   HCF4067B_IN8     7 
#define   HCF4067B_IN9     8 
#define   HCF4067B_IN10    9 
#define   HCF4067B_IN11    10 
#define   HCF4067B_IN12    11 
#define   HCF4067B_IN13    12 
#define   HCF4067B_IN14    13 
#define   HCF4067B_IN15    14 
#define   HCF4067B_IN16    15 

//-------------------------------------------------------------------------------------
// ��������� ������� � ������� ������� ������ ��� ������� ����������� HCF4067B_DRIVER_1
//-------------------------------------------------------------------------------------
/// <summary>
/// ������� ������������� �������� HCF4067B.
/// ����-�� ��������� ����� COM, ��������� ������� ������ ��������������.
/// </summary>
/// <returns></returns>
extern void HCF4067B_Init(void); 
//-------------------------------------------------------------------------------------
/// <summary>
/// ������� ��������� ������� ������ �������� ��������������.
/// </summary>
/// <param name="channelNum">����� ������</param>
/// <returns></returns>
extern void HCF4067B_SetChannel(uint8_t channelNum);
//-------------------------------------------------------------------------------------
/// <summary>
/// ������� �������� ���������� ��� �� ��������� ������
/// (��� ������ ������� ���������� ��������������� ������������� �������� ���)
/// </summary>
/// <param name="channelNum">����� ������</param>
/// <returns>��������� ��� �� ��������� ������</returns>
extern uint16_t HCF4067B_GetAdcFromChannel(uint8_t channelNum);
//-------------------------------------------------------------------------------------
/// <summary>
/// ������� �������� ��������� ���������� ������ �������� ��������������.
/// </summary>
/// <param name="channelNum">����� ������</param>
/// <returns>��������� ���������� ������ �������� ��������������:0 - �� ����� 
/// ���������� ���.0 ��� !=0 - �� ����� ����-� ���.1</returns>
extern Boolean HCF4067B_GetInputState(uint16_t adcResult, uint16_t adcThreshold);

extern PinLevel HCF4067B_GetChannelLevel(uint8_t channelNum);

#endif
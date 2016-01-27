#include <intrinsics.h>  // ������������ ���� ���������� ��� ������� � �������������� ��������

#include <avr_macros.h>  // ������������ ���� ���������� ��� ������� � �������� ��������

#include <ioavr.h>       // ������������ ���� ����������� ������/������� ���� AVR

#ifndef __HCF4067B_PINS_H
  #define __HCF4067B_PINS_H

// ------����������� ������ HCF4067B
// COM - PA0 - ����� ����
//-----------------------------------------------------------------------
//------ HCF4067B_COM - ����� ����
//-----------------------------------------------------------------------
/// ������� ��������� ��� HCF4067B_COM
#define  HCF4067B_COM_DDR   DDRA   
/// ���� ��� HCF4067B_COM
#define  HCF4067B_COM_PORT  PORTA  
/// ������ ����� ��� HCF4067B_COM
#define  HCF4067B_COM_PIN   PINA  
/// ����� HCF4067B_COM 
#define  HCF4067B_COM_LINE  PA3    

/// <summary>
/// ��������� ����������� ����� HCF4067B_COM - ����� ����.
/// </summary>
/// <param name="x"> 0 - ����� ��������� �� ����, 1 - ��������� �� �����</param>
#define HCF4067B_COM_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_COM_DDR, HCF4067B_COM_LINE);\
    else CLEARBIT(HCF4067B_COM_DDR, HCF4067B_COM_LINE);\
  }

/// <summary>
/// ���������� ������ HCF4067B_COM - ����� ����.
/// </summary>
/// <param name="x"> 0 - �� ����� ��������� 0, 1 - �� ����� ��������� 1</param>
#define HCF4067B_COM_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_COM_PORT, HCF4067B_COM_LINE);\
    else CLEARBIT(HCF4067B_COM_PORT, HCF4067B_COM_LINE);\
  }

/// <summary>
/// �������� ����� HCF4067B_COM - ����� ����. 
/// </summary>
/// <returns>0 - �� ����� ���������� 0-� �������, 1 - �� ����� ���������� 1-� �������</returns>
#define HCF4067B_COM_PN() TESTBIT(HCF4067B_COM_PIN, HCF4067B_COM_LINE)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// ������� ��������� ��� HCF4067B_A
#define  HCF4067B_A_DDR   DDRB   
/// ���� ��� HCF4067B_A
#define  HCF4067B_A_PORT  PORTB  
/// ������ ����� ��� HCF4067B_A
#define  HCF4067B_A_PIN   PINB  
/// ����� HCF4067B_A 
#define  HCF4067B_A_LINE  PB0    

/// <summary>
/// ��������� ����������� ����� HCF4067B_A - ����� ����.
/// </summary>
/// <param name="x"> 0 - ����� ��������� �� ����, 1 - ��������� �� �����</param>
#define HCF4067B_A_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_A_DDR, HCF4067B_A_LINE);\
    else CLEARBIT(HCF4067B_A_DDR, HCF4067B_A_LINE);\
  }

/// <summary>
/// ���������� ������ HCF4067B_A - ����� ����.
/// </summary>
/// <param name="x"> 0 - �� ����� ��������� 0, 1 - �� ����� ��������� 1</param>
#define HCF4067B_A_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_A_PORT, HCF4067B_A_LINE);\
    else CLEARBIT(HCF4067B_A_PORT, HCF4067B_A_LINE);\
  }

/// <summary>
/// �������� ����� HCF4067B_A - ����� ����. 
/// </summary>
/// <returns>0 - �� ����� ���������� 0-� �������, 1 - �� ����� ���������� 1-� �������</returns>
#define HCF4067B_A_PN() TESTBIT(HCF4067B_A_PIN, HCF4067B_A_LINE)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// ������� ��������� ��� HCF4067B_B
#define  HCF4067B_B_DDR   DDRC   
/// ���� ��� HCF4067B_B
#define  HCF4067B_B_PORT  PORTC  
/// ������ ����� ��� HCF4067B_B
#define  HCF4067B_B_PIN   PINC  
/// ����� HCF4067B_B 
#define  HCF4067B_B_LINE  PC0    

/// <summary>
/// ��������� ����������� ����� HCF4067B_B - ����� ����.
/// </summary>
/// <param name="x"> 0 - ����� ��������� �� ����, 1 - ��������� �� �����</param>
#define HCF4067B_B_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_B_DDR, HCF4067B_B_LINE);\
    else CLEARBIT(HCF4067B_B_DDR, HCF4067B_B_LINE);\
  }

/// <summary>
/// ���������� ������ HCF4067B_B - ����� ����.
/// </summary>
/// <param name="x"> 0 - �� ����� ��������� 0, 1 - �� ����� ��������� 1</param>
#define HCF4067B_B_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_B_PORT, HCF4067B_B_LINE);\
    else CLEARBIT(HCF4067B_B_PORT, HCF4067B_B_LINE);\
  }

/// <summary>
/// �������� ����� HCF4067B_B - ����� ����. 
/// </summary>
/// <returns>0 - �� ����� ���������� 0-� �������, 1 - �� ����� ���������� 1-� �������</returns>
#define HCF4067B_B_PN() TESTBIT(HCF4067B_B_PIN, HCF4067B_B_LINE)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// ������� ��������� ��� HCF4067B_C
#define  HCF4067B_C_DDR   DDRB   
/// ���� ��� HCF4067B_C
#define  HCF4067B_C_PORT  PORTB  
/// ������ ����� ��� HCF4067B_C
#define  HCF4067B_C_PIN   PINB  
/// ����� HCF4067B_C 
#define  HCF4067B_C_LINE  PB2    

/// <summary>
/// ��������� ����������� ����� HCF4067B_C - ����� ����.
/// </summary>
/// <param name="x"> 0 - ����� ��������� �� ����, 1 - ��������� �� �����</param>
#define HCF4067B_C_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_C_DDR, HCF4067B_C_LINE);\
    else CLEARBIT(HCF4067B_C_DDR, HCF4067B_C_LINE);\
  }

/// <summary>
/// ���������� ������ HCF4067B_C - ����� ����.
/// </summary>
/// <param name="x"> 0 - �� ����� ��������� 0, 1 - �� ����� ��������� 1</param>
#define HCF4067B_C_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_C_PORT, HCF4067B_C_LINE);\
    else CLEARBIT(HCF4067B_C_PORT, HCF4067B_C_LINE);\
  }

/// <summary>
/// �������� ����� HCF4067B_C - ����� ����. 
/// </summary>
/// <returns>0 - �� ����� ���������� 0-� �������, 1 - �� ����� ���������� 1-� �������</returns>
#define HCF4067B_C_PN() TESTBIT(HCF4067B_C_PIN, HCF4067B_C_LINE)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// ������� ��������� ��� HCF4067B_D
#define  HCF4067B_D_DDR   DDRB   
/// ���� ��� HCF4067B_D
#define  HCF4067B_D_PORT  PORTB  
/// ������ ����� ��� HCF4067B_D
#define  HCF4067B_D_PIN   PINB 
/// ����� HCF4067B_D 
#define  HCF4067B_D_LINE  PB2   

/// <summary>
/// ��������� ����������� ����� HCF4067B_D - ����� ����.
/// </summary>
/// <param name="x"> 0 - ����� ��������� �� ����, 1 - ��������� �� �����</param>
#define HCF4067B_D_DR(x)\
  {\
    if (x) SETBIT(HCF4067B_D_DDR, HCF4067B_D_LINE);\
    else CLEARBIT(HCF4067B_D_DDR, HCF4067B_D_LINE);\
  }

/// <summary>
/// ���������� ������ HCF4067B_D - ����� ����.
/// </summary>
/// <param name="x"> 0 - �� ����� ��������� 0, 1 - �� ����� ��������� 1</param>
#define HCF4067B_D_PT(x)\
  {\
    if (x) SETBIT(HCF4067B_D_PORT, HCF4067B_D_LINE);\
    else CLEARBIT(HCF4067B_D_PORT, HCF4067B_D_LINE);\
  }

/// <summary>
/// �������� ����� HCF4067B_D - ����� ����. 
/// </summary>
/// <returns>0 - �� ����� ���������� 0-� �������, 1 - �� ����� ���������� 1-� �������</returns>
#define HCF4067B_D_PN() TESTBIT(HCF4067B_D_PIN, HCF4067B_D_LINE)
//------------------------------------------------------------------------------

#endif
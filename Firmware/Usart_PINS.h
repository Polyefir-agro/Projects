#include <intrinsics.h>  // ������������ ���� ���������� ��� ������� � �������������� ��������

#include <avr_macros.h>  // ������������ ���� ���������� ��� ������� � �������� ��������

#include <ioavr.h>       // ������������ ���� ����������� ������/������� ���� AVR

#ifndef __USART_PINS_H
  #define __USART_PINS_H

// ���������� ��������
#define USART_ENABLE_TRANSMIT() (UCSRB |=  (1 << TXEN))

// ������ ��������
#define USART_DISABLE_TRANSMIT() (UCSRB &= ~(1 <<TXEN))

// ���������� ������
#define USART_ENABLE_RECEIVE()     (UCSRB |=  (1 << RXEN))

// ������ ������ 
#define USART_DISABLE_RECEIVE()     (UCSRB &= ~(1 << RXEN)) 

// ���������� ���������� �� ������ �����
#define USART_ENABLE_RX_INT()     (UCSRB |=  (1 << RXCIE))

// ������ ���������� �� ������ �����
#define USART_DISABLE_RX_INT()     (UCSRB &= ~(1 << RXCIE)) 

// ���������� ���������� �� ���������� �������� �����(�� ����� TXC)
#define USART_ENABLE_TX_INT()     (UCSRB |=  (1 << TXCIE))

// ������ ���������� �� ���������� �������� �����
#define USART_DISABLE_TX_INT()     (UCSRB &= ~(1 << TXCIE))

// ���������� ���������� ���� ������� ������ ����(�� ����� UDRE)
#define USART_ENABLE_UDR_INT()     (UCSRB |=  (1 << UDRIE))

// ������ ���������� ���� ������� ������ ����(�� ����� UDRE)
#define USART_DISABLE_UDR_INT()     (UCSRB &= ~(1 << UDRIE))

//������ � ������� ������
#define USART_BYTE_WRITE(DATA)       (UDR = DATA)

//������ �� �������� ������
#define USART_BYTE_READ()            (UDR) 

#endif

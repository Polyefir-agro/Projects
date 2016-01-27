#include <intrinsics.h>  // Заголовочный файл библиотеки для доступа к низкоуровневым функциям

#include <avr_macros.h>  // Заголовочный файл библиотеки для доступа к функциям макросов

#include <ioavr.h>       // Заголовочный файл определений входов/выходов всех AVR

#ifndef __USART_PINS_H
  #define __USART_PINS_H

// Разрешение передачи
#define USART_ENABLE_TRANSMIT() (UCSRB |=  (1 << TXEN))

// Запрет передачи
#define USART_DISABLE_TRANSMIT() (UCSRB &= ~(1 <<TXEN))

// Разрешение приема
#define USART_ENABLE_RECEIVE()     (UCSRB |=  (1 << RXEN))

// Запрет приема 
#define USART_DISABLE_RECEIVE()     (UCSRB &= ~(1 << RXEN)) 

// Разрешение прерывания по приему байта
#define USART_ENABLE_RX_INT()     (UCSRB |=  (1 << RXCIE))

// Запрет прерывания по приему байта
#define USART_DISABLE_RX_INT()     (UCSRB &= ~(1 << RXCIE)) 

// Разрешение прерывания по завершении передачи байта(по флагу TXC)
#define USART_ENABLE_TX_INT()     (UCSRB |=  (1 << TXCIE))

// Запрет прерывания по завершении передачи байта
#define USART_DISABLE_TX_INT()     (UCSRB &= ~(1 << TXCIE))

// Разрешение прерывания если регистр данных пуст(по флагу UDRE)
#define USART_ENABLE_UDR_INT()     (UCSRB |=  (1 << UDRIE))

// Запрет прерывания если регистр данных пуст(по флагу UDRE)
#define USART_DISABLE_UDR_INT()     (UCSRB &= ~(1 << UDRIE))

//Запись в регистр данных
#define USART_BYTE_WRITE(DATA)       (UDR = DATA)

//Чтение из регистра данных
#define USART_BYTE_READ()            (UDR) 

#endif

#include "SystemTimer.h"
//#include "Serial.h"

#pragma vector = TIMER2_COMP_vect                // Прерывание по переполнению таймера 2         //
__interrupt void _10msInterrupt_ (void)              // Прошло 10 миллисекунд                    //
{
    SystemTimer::handleTickInterrupt();
} 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Обработчик прерывания передатчика 
#pragma vector = USART_UDRE_vect                 // Регистр UDR0 пуст!                           
__interrupt void _DataRegisterEmptyInterrupt_ (void)              
{
    //Начинаем передачу данных
    usart.handleStartTxInterrupt();
}
//------------------------------------------------------------------------------
 
//------------------------------------------------------------------------------ 
// Обработчик прерывания окончания передачи  
#pragma vector = USART_TXC_vect                   // Передача посылки USART0 завершена!           
__interrupt void _TxCompleteInterrupt_ (void)             // Cообщение для УДЗ отправлено!                
{       
    usart.handleTxCompleteInterrupt();  
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Обработчик прерывания приемника  
#pragma vector = USART_RXC_vect                   // Вектор прерывания приемника USART0          
__interrupt void _RxCompleteInterrupt_ (void)        // В регистре приемника USART0 есть данные!     
{
    usart.handleRxCompleteInterrupt();    
}
//------------------------------------------------------------------------------
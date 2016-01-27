#include "SystemTimer.h"
//#include "Serial.h"

#pragma vector = TIMER2_COMP_vect                // ���������� �� ������������ ������� 2         //
__interrupt void _10msInterrupt_ (void)              // ������ 10 �����������                    //
{
    SystemTimer::handleTickInterrupt();
} 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  ���������� ���������� ����������� 
#pragma vector = USART_UDRE_vect                 // ������� UDR0 ����!                           
__interrupt void _DataRegisterEmptyInterrupt_ (void)              
{
    //�������� �������� ������
    usart.handleStartTxInterrupt();
}
//------------------------------------------------------------------------------
 
//------------------------------------------------------------------------------ 
// ���������� ���������� ��������� ��������  
#pragma vector = USART_TXC_vect                   // �������� ������� USART0 ���������!           
__interrupt void _TxCompleteInterrupt_ (void)             // C�������� ��� ��� ����������!                
{       
    usart.handleTxCompleteInterrupt();  
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ���������� ���������� ���������  
#pragma vector = USART_RXC_vect                   // ������ ���������� ��������� USART0          
__interrupt void _RxCompleteInterrupt_ (void)        // � �������� ��������� USART0 ���� ������!     
{
    usart.handleRxCompleteInterrupt();    
}
//------------------------------------------------------------------------------
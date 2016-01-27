#include "Usart.h"

#ifndef __USART_H
#error [E030] �� ��������� ������������ ���� Usart.h
#endif 

#ifndef __USART_PINS_H
#error [E030] �� ��������� ������������ ���� Usart_PINS.h
#endif 

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::init(uint16_t baud, uint8_t dataSize, uint8_t stopBits, 
                 Mode mode, Parity par, Polarity pol, X2speed speed)
{
  
   uint8_t state_INT;                               // ��������� �������� ����������                //
   uint32_t ubrr;
   //uint8_t error = 0;                               // ������ ���������� �������                    //
   //float realBR;                                 // �������� �������                             //

   // ������������� ��������, ������ ���� �� ���� �������� (TXC = 0) ��� ����� (RXC = 0) ������: //
   if ((TESTBIT(UCSRA, RXC) == 0) && (TESTBIT(UCSRA, TXC) == 0))
   {
      state_INT = __save_interrupt();            // ��������� ����������                         //
      __disable_interrupt();                     // �������� ���������� �� ����� �������������   //

      // ������� �������� ...................................................................... //
      if (speed == X2_ON)                        // ����� ���������� ������� ��������            //
      {
         if (mode == ASYNHRO)                  // ����������� ����� ������                     //
            SETBIT(UCSRA, U2X);                // ������������ ������� ��������                //
         else if (mode == SYNHRO)                                     // ���������� ����� ������                      //
         {
            CLEARBIT(UCSRA, U2X);                // ������������ ���������� ��������             //
            //SETBIT (error, 2);                   // ������ ���������� �������� 2� � ����� ������ //
         }
      }
      else if (speed == X2_OFF)                                       // ����� ���������� ������� ��������            //
      {
         CLEARBIT(UCSRA, U2X);                   // ������������ ������� ��������                //
      }

      // ������������������ ����� ������ ������� ............................................... //
      //if (MPC_mode == _MPCon)                    // ����� ���������� ������������������ �����    //
      //   SETBIT(UCSR1A, U2X1);                   // ������������ ������������������ �����        //
      //else                                       // ����� ��������� ������������������ �����     //
      //   CLEARBIT(UCSRA, U2X);                   // ������������ ���������� ��������             //

      // ���������� ��� ������ � ������� ....................................................... //
      switch (dataSize)
      {
         case  5: CLEARBIT(UCSRB, UCSZ2);        // 5 ��� -------------------------------------- //
                  CLEARBIT(UCSRC, UCSZ1);
                  CLEARBIT(UCSRC, UCSZ0); break;

         case  6: CLEARBIT(UCSRB, UCSZ2);        // 6 ��� -------------------------------------- //
                  CLEARBIT(UCSRC, UCSZ1);
                  SETBIT(UCSRC, UCSZ0); break;

         case  7: CLEARBIT(UCSRB, UCSZ2);        // 7 ��� -------------------------------------- //
                  SETBIT(UCSRC, UCSZ1);
                  CLEARBIT(UCSRC, UCSZ0); break;

         case  8: CLEARBIT(UCSRB, UCSZ2);        // 8 ��� -------------------------------------- //
                  SETBIT(UCSRC, UCSZ1);
                  SETBIT(UCSRC, UCSZ0); break;

         case  9: SETBIT(UCSRB, UCSZ2);        // 9 ��� -------------------------------------- //
                  SETBIT(UCSRC, UCSZ1);
                  SETBIT(UCSRC, UCSZ0); break;
                  	
         default: CLEARBIT(UCSRB, UCSZ2);        // 8 ��� �� ��������� ��� �������� ���������    //
                  SETBIT(UCSRC, UCSZ1);
                  SETBIT(UCSRC, UCSZ0);
                  //SETBIT (error, 3);             // ������! �������� ���������� ���!             //
      }

      // �������� �������� ..................................................................... //
      switch (par)
      {
         case P_OFF: CLEARBIT(UCSRC, UPM1);    // ����� ��� �������� ��������                  //
                       CLEARBIT(UCSRC, UPM0);
                       break;
         case P_EVEN  : SETBIT(UCSRC, UPM1);    // ������� �������� ��������                    //
                       CLEARBIT(UCSRC, UPM0);
                       break;
         case P_ODD   : SETBIT(UCSRC, UPM1);    // ������� �������� ����������                  //
                       SETBIT(UCSRC, UPM0);
                       break;
         default     : CLEARBIT(UCSRC, UPM1);    // ����� ��� �������� �������� �� ���������     //
                       CLEARBIT(UCSRC, UPM0);
                       //SETBIT (error, 4);        // ������! �������� ����� ��������!             //
      }

      // ���������� �������� ����� ............................................................. //
      if (stopBits == 1)                        // 1 ����-���                                   //
         CLEARBIT(UCSRC, USBS);
      else                                       // �� 1 ����-���                                //
      {
         if (stopBits == 2)                     // 2 ����-����                                  //
            SETBIT(UCSRC, USBS);
         else                                    // �������� ���������� �������� �����           //
         {
            CLEARBIT(UCSRC, USBS);               // �� ��������� ������������ 1 ����-���         //
            //SETBIT (error, 5);                   // ������! �������� ���������� �������� �����!  //
         }
      }
      // --------------------------------------------------------------------------------------- //
      // ����� ������ ����������������� (���������� ��� �����������) ........................... //
      if (mode == SYNHRO)                      // ���������� ����� ������                      //
         SETBIT(UCSRC, UMSEL);                 // ������������ ���������� ����� ������         //
      else if(mode == ASYNHRO)  
         CLEARBIT(UCSRC, UMSEL);                 // ������������ ����������� ����� ������        //

      // --------------------------------------------------------------------------------------- //
      // ���������� ��������� ������� � ���������� ������ ...................................... //
      if (pol == POL_RISE)	                 // ���������� �����                             //
         CLEARBIT(UCSRC, UCPOL);                 // ��������� ������ �� ����������� ������       //
      else if (pol == POL_FALL)	                                      // ���������� �����                             //
      {
         if (mode == SYNHRO)                   // ���������� ����� ������                      //
            SETBIT(UCSRC, UCPOL);              // ��������� ������ �� ����������� ������       //
         else if(mode == ASYNHRO)                                   // ����������� ����� ������                     //
            CLEARBIT(UCSRC, UMSEL);              // � ����������� ������ ��������� ��� UMSELn    //
      }
      // --------------------------------------------------------------------------------------- //
      // ������� ............................................................................... //
      //UBRR1 = UBRR_reg(baud, SYSTEM_CLK_HZ, _AsNormalMode);  // �������� �������-�������           //
      //realBR = baudrate(UBRR1, SYSTEM_CLK_HZ, _AsNormalMode);    // �������� �������� �������          //
      
      if(mode == ASYNHRO && speed == X2_OFF)
      {  
          ubrr = 16;
          ubrr = (SYSTEM_CLK_HZ / (ubrr * baud)) - 1;
      }    
      else if(mode == ASYNHRO && speed == X2_ON)
      {
          ubrr = 8;
          ubrr = (SYSTEM_CLK_HZ / (ubrr * baud)) - 1;
      }  
      else if(mode == SYNHRO)
      {
          ubrr = 2;
          ubrr = (SYSTEM_CLK_HZ / (ubrr * baud)) - 1;
      }       
      
      UBRRH = (uint8_t)(ubrr >> 8);
      UBRRL = (uint8_t)ubrr;
      
      /*float BR_error;
      BR_error = (1.0 - realBR/BaudRate)*100;
      if ((BR_error > 1.5)||(BR_error < -1.5))             // ������ �������� > +/- 1.5%         //
      {
         SETBIT (error, 6);                                // ��������� ���� ������              //
      }*/
      // --------------------------------------------------------------------------------------- //

      CLEARBIT(UCSRA, FE);  // ����� ������ ������
      CLEARBIT(UCSRA, DOR);
      CLEARBIT(UCSRA, PE);
      
      CLEARBIT(DDRD, PD0);
      CLEARBIT(PORTD, PD0); 
      
      CLEARBIT(PORTD, PD1); 
      //SETBIT(DDRD, PD1);
      
      SETBIT(UCSRA, TXC);  // ����� ����� ��������� ��������
      
                           
               
      
      USART_DISABLE_TRANSMIT(); 
      //USART_DISABLE_RECEIVE(); 
      
      USART_DISABLE_UDR_INT();  // ������ ����������
      USART_DISABLE_TX_INT();     
      //USART_DISABLE_RX_INT();   
    
    // ���������� ������ ��������� USART0
    USART_ENABLE_RECEIVE();          
    // �������� ���������� ���������� ������ �����       
    USART_ENABLE_RX_INT();      
    
    __restore_interrupt(state_INT); 
      
      
   }
   /*else
     // ������ ����������������-���� �������� ������ //
   {
      if (TESTBIT(UCSR1A, RXC1))                  // � ������ ��������� ���� ������!              //
         SETBIT (error, 0);
      if (TESTBIT(UCSR1A, TXC1))                  // � ������ ����������� ���� ������!            //
         SETBIT (error, 1);
   }*/

   //return error;                                 // ��������� ��� ������                         //  
}  
//------------------------------------------------------------------------------

void Usart::transmitManager()
{
	if(transmitStart == FALSE)
	{        
        if(txMessageCount > 0)
		{      
            Delay_1msec;

            for(uint8_t i = 0; i < MESSAGE_SIZE; i++)
			{
				txCurrentBuffer[i] = txBuffer[txMessageCount - 1][i];
			}

			txCurrentSize = txSize[txMessageCount - 1];

			for(uint8_t i = 0; i < MESSAGE_SIZE; i++) 
			{
				txBuffer[txMessageCount - 1][i] = 0;      
			}

			txSize[txMessageCount - 1] = 0;

			if(txMessageCount > 0)
			{
				txMessageCount -= 1;
			}

            txBufferBytePointer = 0;			

			transmitStart = TRUE;

			// ������ ������ �� USART
		    USART_DISABLE_RX_INT();   
        
            USART_DISABLE_RECEIVE(); 
		    // ���������� �������� �� USART
			USART_ENABLE_TRANSMIT();   
		
			USART_ENABLE_UDR_INT();
		}
	}
}

//------------------------------------------------------------------------------
void Usart::print(void *message, uint8_t size, MessageType type)
{  
    if(txMessageCount < MESSAGE_COUNT)
	{

		fillTxBuffer(message, size, type);
		
		txBuffer[txMessageCount][txSize[txMessageCount]] = 32; // Space - ������
		
		txSize[txMessageCount]++;

		txMessageCount++;
	}
}  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::printLn(void *message, uint8_t size, MessageType type)
{  
	if(txMessageCount < MESSAGE_COUNT)
	{
		fillTxBuffer(message, size, type);

		txBuffer[txMessageCount][txSize[txMessageCount]] = 13; // CR - ������� �������
		
		txSize[txMessageCount]++;    
		
		txBuffer[txMessageCount][txSize[txMessageCount]] = 10; // LF - ������� ������
		
		txSize[txMessageCount]++;   

		txMessageCount++; 
	}
} 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::handleStartTxInterrupt()
{      
//	while(TESTBIT(UCSRA, TXC) != 0);

    //���� ����� ���� ������ 0, �� ����� ����������
    if (txCurrentSize > 0)
    {
        //��������, ��� ����� �����
        //gDrvMainUsart0Tx.redy = FALSE;
        // ������ ����� � ������� ������             
        USART_BYTE_WRITE(readByteFromTxBuffer());
    }
    else
    {
		txBufferBytePointer = 0;

        //���� ����� 0, �� ��� ��� ��������
        //������ ���������� ���� ������� ������ ����
        USART_DISABLE_UDR_INT();                                  
        // ���������� ���������� �� ���������� �������� �����
        USART_ENABLE_TX_INT();            		
    }   
}  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::handleTxCompleteInterrupt()
{
    // ������ ���������� �� ���������� �������� �����
    USART_DISABLE_TX_INT();   
    // ������ �������� �� USART
    USART_DISABLE_TRANSMIT();  
	
    for(uint8_t i = 0; i < MESSAGE_SIZE; i++)
	{
		txCurrentBuffer[i] = 0;
	}

	txCurrentSize = 0;	     
	
	transmitStart = FALSE;    
    //� ��������, ��� ����� �����
    //gDrvMainUsart0Rx.redy = FALSE;    
    // ������������� ���� ���������� ������
    //gDrvUsart0ModuleCycle.Tx_Rx_En_Flag = 1;
    flush();    
    // ���������� ������ ��������� USART0
    USART_ENABLE_RECEIVE();          
    // �������� ���������� ���������� ������ �����       
    USART_ENABLE_RX_INT(); 
       
    
    // ������� ����� ��� ��������� �������� USART0
    //usart0_start_timeout_cnt(get_globtimer());    
}  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::handleRxCompleteInterrupt()
{
    // ��� ����������� ����������� ��������    
    //interruptModuleCnt++;
    
    // �������� ������� � ������� ������            
    if(UCSRA &((1<<FE)|(1<<DOR)|(1<<PE)))   // ��������� ������ ��� ������ ������           
    {        
//        reg = UCSRA &((1<<FE)|(1<<DOR)|(1<<PE));
        // ��������� ������ ������  
        //USART0_SetErr_flags(reg);  
        
        // �������� ���������� ���������� ������ �����
//        USART_DISABLE_RX_INT();   
        // ������ ������ �� USART
//        USART_DISABLE_RECEIVE();  
                         
        //gDrvMainUsart0Rx.redy = TRUE;  

        // ��������� ����� ������ ���������
        //USART_SetReceiveCompleteFlag(1);   
        //flush();
    }
    else  // ����� ������ ��� ������                      
    {
        //������������ �������� ����
        //drv_usart0_bus_rx_event(); 
//		USART_DISABLE_RX_INT();   
        // ������ ������ �� USART
//        USART_DISABLE_RECEIVE();  
		recieveEventHandler();				
    }
    
    flush();
}  

Boolean Usart::getRxData(uint8_t *data)
{
    Boolean result = FALSE;
  
	if(recieveEvent == TRUE)
	{
		usart.printLn(&rxCurrentBuffer[0], rxCurrentBuffer[6] + 9, STRING);   
		
		result = TRUE; 

		recieveEvent = FALSE;
	}		  		
          
	for (uint8_t i = 0; i < rxCurrentBuffer[6]; i++)
	{
		*(data + i) = rxCurrentBuffer[7 + i];
	}
                					
	return result;
}

//----------------private-------------------------------------------------------
void Usart::flush(void)
{
    uint8_t dummy;
    while ( UCSRA & (1<<RXC) ) 
      dummy = UDR;
    

    TESTBIT(UCSRA, FE);
    TESTBIT(UCSRA, DOR);
    TESTBIT(UCSRA, PE);    
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::recieveEventHandler()
{
	rxBuffer[rxBytesCounter] = UDR;
	rxBytesCounter++;

	switch (rxBuffer[rxBytesCounter])                         // �������� ������ ���������                    //
	{
		case 1: if (rxBuffer[0] != 0x20)
			rxBytesCounter = 0;                       // ��������� ������� ���������                  //
			break;

		case 2: if (rxBuffer[1] != 0x83)
			if (rxBuffer[1] == 0x20)
			{
				rxBuffer[0] = 0x20;
				rxBytesCounter = 1;                    // ��������� ������� ���������                  //
			}
			else rxBytesCounter = 0;                  // ������� ��������� ��������� � ������         //
			break;

		case 3: if (rxBuffer[2] != 0xB8)
			if (rxBuffer[2] == 0x20)
			{
				rxBuffer[0] = 0x20;
				rxBytesCounter = 1;                    // ��������� ������� ���������                  //
			}
			else rxBytesCounter = 0;                  // ������� ��������� ��������� � ������         //
			break;

		case 4: if (rxBuffer[3] != 0xED)
			if (rxBuffer[3] == 0x20)
			{
				rxBuffer[0] = 0x20;
				rxBytesCounter = 1;                    // ��������� ������� ���������                  //
			}
			else rxBytesCounter = 0;                  // ������� ��������� ��������� � ������         //
			break;
            
		case 5:  // �����
			/*if (Usart1Rbuff(4) > UDZnumOfDM() + 100)
			{
				SetUsart1Flag(RxCf, 1);                 // ��������� ���� "����� ������� ��������"      //
				RxCI1Disable();                         // �������� ���������� ���������� ������ �����  //
				SetUsart1Rcnt(0);                             // ������� ������� ���������  
			}*/  
			break;      
            
		case 6:  // ���               
			break;              
            
		case 7:  // ����� ��������� 
			break;  
            
		default:
			if (rxBytesCounter >= rxBuffer[6] + 9)//Usart1Rsize())         // ���� ������ ��������� ���� �������           //
			{
				for(uint8_t i = 0; i < MESSAGE_SIZE; i++)
				{
					rxCurrentBuffer[i] = rxBuffer[i];
				}

				for(uint8_t i = 0; i < MESSAGE_SIZE; i++) 
				{
					rxBuffer[i] = 0;      
				}
				rxBytesCounter = 0;
				//SetUsart1Flag(RxCf, 1);                 // ��������� ���� "����� ������� ��������"      //
//				USART_DISABLE_RX_INT();   
				// ������ ������ �� USART
//				USART_DISABLE_RECEIVE(); 
				//SetUsart1Rcnt(0);                             // ������� ������� ���������                    //
				recieveEvent = TRUE;			
			}              
			break; 
	}
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::fillTxBuffer(void *message, uint8_t size, MessageType type)
{
    uint16_t number = 0;
	uint16_t digit[5];
        
    
    txBufferBytePointer = 0;


	if(size > MESSAGE_SIZE - 2)
	{
		size = MESSAGE_SIZE - 2;
	}
     
    if(type != STRING)  // �����
    {

		for(uint8_t i = 0; i < size; i++)
		{
			number = *((uint8_t*)message + size - i - 1) + (number << 8);
		}
		
		digit[0] = number / 10000;			
		digit[1] = number / 1000 - (digit[0] * 10); 
		digit[2] = number / 100 - ((digit[0] * 100) + (digit[1] * 10));
		digit[3] = number / 10 -  ((digit[0] * 1000) + (digit[1] * 100) + (digit[2] * 10));
		digit[4] = number % 10;			
						

		if(digit[0] == 0 && digit[1] == 0 && 
		   digit[2] == 0 && digit[3] == 0)
		{
			txBuffer[txMessageCount][0] = numbByteIntoAscii(digit[4]);
		}
		else if(digit[0] == 0 && digit[1] == 0 && digit[2] == 0)
		{
			txBuffer[txMessageCount][0] = numbByteIntoAscii(digit[3]);
			txBuffer[txMessageCount][1] = numbByteIntoAscii(digit[4]);
		}
		else if(digit[0] == 0 && digit[1] == 0)
		{
			txBuffer[txMessageCount][0] = numbByteIntoAscii(digit[2]);
			txBuffer[txMessageCount][1] = numbByteIntoAscii(digit[3]);
			txBuffer[txMessageCount][2] = numbByteIntoAscii(digit[4]);
		}
		else if(digit[0] == 0)
		{
			txBuffer[txMessageCount][0] = numbByteIntoAscii(digit[1]);
			txBuffer[txMessageCount][1] = numbByteIntoAscii(digit[2]);
			txBuffer[txMessageCount][2] = numbByteIntoAscii(digit[3]);
			txBuffer[txMessageCount][3] = numbByteIntoAscii(digit[4]);
		}
		else
		{
			txBuffer[txMessageCount][0] = numbByteIntoAscii(digit[0]);
			txBuffer[txMessageCount][1] = numbByteIntoAscii(digit[1]);
			txBuffer[txMessageCount][2] = numbByteIntoAscii(digit[2]);
			txBuffer[txMessageCount][3] = numbByteIntoAscii(digit[3]);
			txBuffer[txMessageCount][4] = numbByteIntoAscii(digit[4]);
		}
			
		txSize[txMessageCount] = size*2 + 1;	
	}           
    else  // ������
    {
		for(uint8_t i = 0; i < size; i++)
		{
			txBuffer[txMessageCount][i] = *((uint8_t*)message + i);    
		}

		txSize[txMessageCount] = size; 
    } 
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
uint8_t Usart::readByteFromTxBuffer()
{
    uint8_t data = 0;   

    //���� ����, ��� ������, �� ������
    if (txCurrentSize > 0)
    {
        data = txCurrentBuffer[txBufferBytePointer];
        
        txCurrentSize--;

        txBufferBytePointer++;                             
    }

    return data;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::addByteIntoTxBuffer(uint8_t dataByte)
{
    /**txBuffer[txBufferPointer] = dataByte;    
      
    txBufferPointer++;
    
    if(txBufferPointer < sizeof(txBuffer))
    {
        setTxBufferPointer(txBufferPointer);
    }*/  
}  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
uint8_t Usart::numbByteIntoAscii(int8_t numbByte)
{
	uint8_t ascii;

	if(numbByte >= 0 && numbByte <= 9)
	{
		ascii = numbByte + 0x30; 
	}
	else
	{
		ascii = 0;
	}

	return ascii;
}
//------------------------------------------------------------------------------


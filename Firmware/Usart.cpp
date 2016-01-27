#include "Usart.h"

#ifndef __USART_H
#error [E030] Не определен заголовочный файл Usart.h
#endif 

#ifndef __USART_PINS_H
#error [E030] Не определен заголовочный файл Usart_PINS.h
#endif 

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::init(uint16_t baud, uint8_t dataSize, uint8_t stopBits, 
                 Mode mode, Parity par, Polarity pol, X2speed speed)
{
  
   uint8_t state_INT;                               // Состояние векторов прерывания                //
   uint32_t ubrr;
   //uint8_t error = 0;                               // Ошибки выполнения функции                    //
   //float realBR;                                 // Реальный бодрейт                             //

   // Инициализация начнется, только если не идет передача (TXC = 0) или прием (RXC = 0) данных: //
   if ((TESTBIT(UCSRA, RXC) == 0) && (TESTBIT(UCSRA, TXC) == 0))
   {
      state_INT = __save_interrupt();            // Запоминаю прерывания                         //
      __disable_interrupt();                     // Запрещаю прерывания на время инициализации   //

      // Двойная скорость ...................................................................... //
      if (speed == X2_ON)                        // Нужно установить двойную скорость            //
      {
         if (mode == ASYNHRO)                  // Асинхронный режим работы                     //
            SETBIT(UCSRA, U2X);                // Устанавливаю двойную скорость                //
         else if (mode == SYNHRO)                                     // Синхронный режим работы                      //
         {
            CLEARBIT(UCSRA, U2X);                // Устанавливаю нормальную скорость             //
            //SETBIT (error, 2);                   // Нельзя установить скорость 2х в синхр режиме //
         }
      }
      else if (speed == X2_OFF)                                       // Нужно установить обычную скорость            //
      {
         CLEARBIT(UCSRA, U2X);                   // Устанавливаю обычную скорость                //
      }

      // Мультипроцессорный режим обмена данными ............................................... //
      //if (MPC_mode == _MPCon)                    // Нужно установить мультипроцессорный режим    //
      //   SETBIT(UCSR1A, U2X1);                   // Устанавливаю мультипроцессорный режим        //
      //else                                       // Нужно отключить мультипроцессорный режим     //
      //   CLEARBIT(UCSRA, U2X);                   // Устанавливаю нормальную скорость             //

      // Количество бит данных в посылке ....................................................... //
      switch (dataSize)
      {
         case  5: CLEARBIT(UCSRB, UCSZ2);        // 5 бит -------------------------------------- //
                  CLEARBIT(UCSRC, UCSZ1);
                  CLEARBIT(UCSRC, UCSZ0); break;

         case  6: CLEARBIT(UCSRB, UCSZ2);        // 6 бит -------------------------------------- //
                  CLEARBIT(UCSRC, UCSZ1);
                  SETBIT(UCSRC, UCSZ0); break;

         case  7: CLEARBIT(UCSRB, UCSZ2);        // 7 бит -------------------------------------- //
                  SETBIT(UCSRC, UCSZ1);
                  CLEARBIT(UCSRC, UCSZ0); break;

         case  8: CLEARBIT(UCSRB, UCSZ2);        // 8 бит -------------------------------------- //
                  SETBIT(UCSRC, UCSZ1);
                  SETBIT(UCSRC, UCSZ0); break;

         case  9: SETBIT(UCSRB, UCSZ2);        // 9 бит -------------------------------------- //
                  SETBIT(UCSRC, UCSZ1);
                  SETBIT(UCSRC, UCSZ0); break;
                  	
         default: CLEARBIT(UCSRB, UCSZ2);        // 8 бит по умолчанию при неверном параметре    //
                  SETBIT(UCSRC, UCSZ1);
                  SETBIT(UCSRC, UCSZ0);
                  //SETBIT (error, 3);             // Ошибка! Неверное количество бит!             //
      }

      // Контроль четности ..................................................................... //
      switch (par)
      {
         case P_OFF: CLEARBIT(UCSRC, UPM1);    // Режим без контроля четности                  //
                       CLEARBIT(UCSRC, UPM0);
                       break;
         case P_EVEN  : SETBIT(UCSRC, UPM1);    // Включен контроль четности                    //
                       CLEARBIT(UCSRC, UPM0);
                       break;
         case P_ODD   : SETBIT(UCSRC, UPM1);    // Включен контроль НЕчетности                  //
                       SETBIT(UCSRC, UPM0);
                       break;
         default     : CLEARBIT(UCSRC, UPM1);    // Режим без контроля четности по умолчанию     //
                       CLEARBIT(UCSRC, UPM0);
                       //SETBIT (error, 4);        // Ошибка! Неверный режим четности!             //
      }

      // Количество стоповых битов ............................................................. //
      if (stopBits == 1)                        // 1 стоп-бит                                   //
         CLEARBIT(UCSRC, USBS);
      else                                       // Не 1 стоп-бит                                //
      {
         if (stopBits == 2)                     // 2 стоп-бита                                  //
            SETBIT(UCSRC, USBS);
         else                                    // Неверное количество стоповых битов           //
         {
            CLEARBIT(UCSRC, USBS);               // По умолчанию устанавливаю 1 стоп-бит         //
            //SETBIT (error, 5);                   // Ошибка! Неверное количество стоповых битов!  //
         }
      }
      // --------------------------------------------------------------------------------------- //
      // Режим работы приемопередатчика (синхронный или асинхронный) ........................... //
      if (mode == SYNHRO)                      // Синхронный режим работы                      //
         SETBIT(UCSRC, UMSEL);                 // Устанавливаю синхронный режим работы         //
      else if(mode == ASYNHRO)  
         CLEARBIT(UCSRC, UMSEL);                 // Устанавливаю асинхронный режим работы        //

      // --------------------------------------------------------------------------------------- //
      // Полярность тактового сигнала в синхронном режиме ...................................... //
      if (pol == POL_RISE)	                 // Восходящий фронт                             //
         CLEARBIT(UCSRC, UCPOL);                 // Изменение данных по восходящему фронту       //
      else if (pol == POL_FALL)	                                      // Нисходящий фронт                             //
      {
         if (mode == SYNHRO)                   // Синхронный режим работы                      //
            SETBIT(UCSRC, UCPOL);              // Изменение данных по нисходящему фронту       //
         else if(mode == ASYNHRO)                                   // Асинхронный режим работы                     //
            CLEARBIT(UCSRC, UMSEL);              // В асинхронном режиме сбрасываю бит UMSELn    //
      }
      // --------------------------------------------------------------------------------------- //
      // Бодрейт ............................................................................... //
      //UBRR1 = UBRR_reg(baud, SYSTEM_CLK_HZ, _AsNormalMode);  // Заполняю бодрейт-регистр           //
      //realBR = baudrate(UBRR1, SYSTEM_CLK_HZ, _AsNormalMode);    // Вычисляю реальный бодрейт          //
      
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
      if ((BR_error > 1.5)||(BR_error < -1.5))             // Ошибка бодрейта > +/- 1.5%         //
      {
         SETBIT (error, 6);                                // Выставляю флаг ошибки              //
      }*/
      // --------------------------------------------------------------------------------------- //

      CLEARBIT(UCSRA, FE);  // сброс ошибок приема
      CLEARBIT(UCSRA, DOR);
      CLEARBIT(UCSRA, PE);
      
      CLEARBIT(DDRD, PD0);
      CLEARBIT(PORTD, PD0); 
      
      CLEARBIT(PORTD, PD1); 
      //SETBIT(DDRD, PD1);
      
      SETBIT(UCSRA, TXC);  // сброс флага окончания передачи
      
                           
               
      
      USART_DISABLE_TRANSMIT(); 
      //USART_DISABLE_RECEIVE(); 
      
      USART_DISABLE_UDR_INT();  // запрет прерываний
      USART_DISABLE_TX_INT();     
      //USART_DISABLE_RX_INT();   
    
    // разрешение работы приемника USART0
    USART_ENABLE_RECEIVE();          
    // Разрешаю прерывание завершения приема байта       
    USART_ENABLE_RX_INT();      
    
    __restore_interrupt(state_INT); 
      
      
   }
   /*else
     // Нельзя инициализировать-идет передача данных //
   {
      if (TESTBIT(UCSR1A, RXC1))                  // В буфере приемника есть данные!              //
         SETBIT (error, 0);
      if (TESTBIT(UCSR1A, TXC1))                  // В буфере передатчика есть данные!            //
         SETBIT (error, 1);
   }*/

   //return error;                                 // Возвращаю код ошибки                         //  
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

			// запрет приема по USART
		    USART_DISABLE_RX_INT();   
        
            USART_DISABLE_RECEIVE(); 
		    // разрешение передачи по USART
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
		
		txBuffer[txMessageCount][txSize[txMessageCount]] = 32; // Space - пробел
		
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

		txBuffer[txMessageCount][txSize[txMessageCount]] = 13; // CR - возврат каретки
		
		txSize[txMessageCount]++;    
		
		txBuffer[txMessageCount][txSize[txMessageCount]] = 10; // LF - перевод строки
		
		txSize[txMessageCount]++;   

		txMessageCount++; 
	}
} 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::handleStartTxInterrupt()
{      
//	while(TESTBIT(UCSRA, TXC) != 0);

    //Если число байт больше 0, то можно передавать
    if (txCurrentSize > 0)
    {
        //Помечаем, что пакет занят
        //gDrvMainUsart0Tx.redy = FALSE;
        // запись байта в регистр данных             
        USART_BYTE_WRITE(readByteFromTxBuffer());
    }
    else
    {
		txBufferBytePointer = 0;

        //Если число 0, то все уже передано
        //Запрет прерывания если регистр данных пуст
        USART_DISABLE_UDR_INT();                                  
        // Разрешение прерывания по завершении передачи байта
        USART_ENABLE_TX_INT();            		
    }   
}  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::handleTxCompleteInterrupt()
{
    // Запрет прерывания по завершении передачи байта
    USART_DISABLE_TX_INT();   
    // запрет передачи по USART
    USART_DISABLE_TRANSMIT();  
	
    for(uint8_t i = 0; i < MESSAGE_SIZE; i++)
	{
		txCurrentBuffer[i] = 0;
	}

	txCurrentSize = 0;	     
	
	transmitStart = FALSE;    
    //И помечаем, что пакет занят
    //gDrvMainUsart0Rx.redy = FALSE;    
    // устанавливаем флаг разрешения приема
    //gDrvUsart0ModuleCycle.Tx_Rx_En_Flag = 1;
    flush();    
    // разрешение работы приемника USART0
    USART_ENABLE_RECEIVE();          
    // Разрешаю прерывание завершения приема байта       
    USART_ENABLE_RX_INT(); 
       
    
    // Засекаю время для обработки таймаута USART0
    //usart0_start_timeout_cnt(get_globtimer());    
}  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void Usart::handleRxCompleteInterrupt()
{
    // Для копирования содержимого регистра    
    //interruptModuleCnt++;
    
    // Сохраняю регистр с флагами ошибок            
    if(UCSRA &((1<<FE)|(1<<DOR)|(1<<PE)))   // Произошла ошибка при приеме фрейма           
    {        
//        reg = UCSRA &((1<<FE)|(1<<DOR)|(1<<PE));
        // установка флагов ошибок  
        //USART0_SetErr_flags(reg);  
        
        // Запрещаю прерывание завершения приема байта
//        USART_DISABLE_RX_INT();   
        // запрет приема по USART
//        USART_DISABLE_RECEIVE();  
                         
        //gDrvMainUsart0Rx.redy = TRUE;  

        // установка флага приема сообщения
        //USART_SetReceiveCompleteFlag(1);   
        //flush();
    }
    else  // Фрейм принят без ошибок                      
    {
        //Обрабатываем принятый байт
        //drv_usart0_bus_rx_event(); 
//		USART_DISABLE_RX_INT();   
        // запрет приема по USART
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

	switch (rxBuffer[rxBytesCounter])                         // Проверяю начало сообщения                    //
	{
		case 1: if (rxBuffer[0] != 0x20)
			rxBytesCounter = 0;                       // Сбрасываю счетчик приемника                  //
			break;

		case 2: if (rxBuffer[1] != 0x83)
			if (rxBuffer[1] == 0x20)
			{
				rxBuffer[0] = 0x20;
				rxBytesCounter = 1;                    // Сбрасываю счетчик приемника                  //
			}
			else rxBytesCounter = 0;                  // Начинаю принимать сообщение с начала         //
			break;

		case 3: if (rxBuffer[2] != 0xB8)
			if (rxBuffer[2] == 0x20)
			{
				rxBuffer[0] = 0x20;
				rxBytesCounter = 1;                    // Сбрасываю счетчик приемника                  //
			}
			else rxBytesCounter = 0;                  // Начинаю принимать сообщение с начала         //
			break;

		case 4: if (rxBuffer[3] != 0xED)
			if (rxBuffer[3] == 0x20)
			{
				rxBuffer[0] = 0x20;
				rxBytesCounter = 1;                    // Сбрасываю счетчик приемника                  //
			}
			else rxBytesCounter = 0;                  // Начинаю принимать сообщение с начала         //
			break;
            
		case 5:  // адрес
			/*if (Usart1Rbuff(4) > UDZnumOfDM() + 100)
			{
				SetUsart1Flag(RxCf, 1);                 // Выставляю флаг "прием посылки завершен"      //
				RxCI1Disable();                         // Запрещаю прерывание завершения приема байта  //
				SetUsart1Rcnt(0);                             // Обнуляю счетчик приемника  
			}*/  
			break;      
            
		case 6:  // код               
			break;              
            
		case 7:  // длина сообщения 
			break;  
            
		default:
			if (rxBytesCounter >= rxBuffer[6] + 9)//Usart1Rsize())         // Если принят последний байт посылки           //
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
				//SetUsart1Flag(RxCf, 1);                 // Выставляю флаг "прием посылки завершен"      //
//				USART_DISABLE_RX_INT();   
				// запрет приема по USART
//				USART_DISABLE_RECEIVE(); 
				//SetUsart1Rcnt(0);                             // Обнуляю счетчик приемника                    //
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
     
    if(type != STRING)  // числа
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
    else  // строки
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

    //Если есть, что читать, то читаем
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


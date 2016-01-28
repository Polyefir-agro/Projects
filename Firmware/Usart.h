#include "BSP.h"

#ifndef __USART_H
  #define __USART_H

#define MESSAGE_COUNT 6
#define MESSAGE_SIZE 15

//baud : 9600, 19200, 38400, 115200;
//dataSize : 5,6,7,8,9
//stopBits : 1,2
enum Mode {ASYNHRO, SYNHRO};
enum Parity {P_OFF, P_EVEN, P_ODD};
enum Polarity {POL_RISE, POL_FALL};
enum X2speed {X2_OFF, X2_ON};
enum MessageType {NUMBER, STRING};

class Usart {//: public Serial {

    public:     
        
        /*struct Data
        {
            uint8_t txBuffer[32];            
        };*/      
      
        // Constructor
        Usart();
        // Destructor
        virtual ~Usart();          
             
        void init(uint16_t baud, uint8_t dataSize, uint8_t stopBits, 
                  Mode mode, Parity par, Polarity pol, X2speed speed);        
        
        void handleStartTxInterrupt();               
        void handleTxCompleteInterrupt();
        void handleRxCompleteInterrupt();         
        
		void transmitManager();
        void print(void *message, uint8_t size, MessageType type); // Вывод данных в ASCII-коде
        void printLn(void *message, uint8_t size, MessageType type);  // Вывод данных в ASCII-коде с переводом строки

		Boolean getRxData(uint8_t *data);

		
                      
    private:                

        uint8_t txBuffer[MESSAGE_COUNT][MESSAGE_SIZE];		
        uint8_t txSize[MESSAGE_COUNT];
		uint8_t txCurrentBuffer[MESSAGE_SIZE];
		uint8_t txCurrentSize;
        uint8_t txBufferBytePointer;
        uint8_t txMessageCount;
        Boolean transmitStart;

        uint8_t rxBuffer[MESSAGE_SIZE];
		uint8_t rxCurrentBuffer[MESSAGE_SIZE];
		uint8_t rxBytesCounter;
		Boolean recieveEvent;
		

        void fillTxBuffer(void *message, uint8_t size, MessageType type);

        void addByteIntoTxBuffer(uint8_t dataByte); 
        uint8_t readByteFromTxBuffer();     

		uint8_t numbByteIntoAscii(int8_t numbByte);
        void flush();
                
        void recieveEventHandler(); 
      
};      

inline Usart::Usart()
{
    txBufferBytePointer = 0;
	//txBufferMessagePointer = 0;
}

inline Usart::~Usart()
{

}

#endif
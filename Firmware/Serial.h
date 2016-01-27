#include "BSP.h"

#ifndef __SERIAL_H
  #define __SERIAL_H

//baud : 9600, 19200, 38400, 115200;
//dataSize : 5,6,7,8,9
//stopBits : 1,2
enum Mode {ASYNHRO, SYNHRO};
enum Parity {P_OFF, P_EVEN, P_ODD};
enum Polarity {POL_RISE, POL_FALL};
enum X2speed {X2_OFF, X2_ON};
enum MessageType {NUMBER, STRING};

class Serial{
     
    public:     
        // Constructor
        Serial();
        // Destructor
        virtual ~Serial();          
  
        virtual void init(uint16_t baud, uint8_t dataSize, uint8_t stopBits, 
                          Mode mode, Parity par, Polarity pol, X2speed speed);
        
        virtual void handleStartTxInterrupt();               
        virtual void handleTxCompleteInterrupt();
        virtual void handleRxCompleteInterrupt();        
        
        
        
        void read();
        void readBytes();
        void parseInt();
        void write();
        void print();
        void printLn();
                      
    private:    
        
              
};

inline Serial::Serial()
{
  
}

inline Serial::~Serial()
{

}

#endif
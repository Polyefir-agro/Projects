#ifndef ATMEGA16_port_cpp                          // Защита от повторного включения файла         //
   #define ATMEGA16_port_cpp

#ifndef ENABLE_BIT_DEFINITIONS
  #define ENABLE_BIT_DEFINITIONS                   // Разрешение символьных обозначений битов      //
#endif

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
#include <ioavr.h>                               // Заголовочный файл микроконтроллера           //
#include <stdint.h>
// ............................................................................................. //
// ............................................................................................. //
template <uint8_t volatile* portName, uint8_t volatile* ddrName, uint8_t volatile* pinName>
class PORT
{

   public:
      inline static void  Set(uint8_t value)        { *portName = value;     }
      inline static void  SetMask(uint8_t value)    { *portName |= value;    }
      inline static void  ClrMask(uint8_t value)    { *portName &= ~(value); }
      inline static void  Toggle(uint8_t value)     { *portName ^= value;    }
      inline static void  DDrSet(uint8_t value)     { *ddrName = value;      }
      inline static void  DDrSetMask(uint8_t value) { *ddrName |= value;     }
      inline static void  DDrClrMask(uint8_t value) { *ddrName &= ~(value);  }
      inline static void  DDrToggle(uint8_t value)  { *ddrName ^= value;     }
      inline static uint8_t PortGet()               { return *portName;      }
      inline static uint8_t DDrGet()                { return *ddrName;       }
      inline static uint8_t PinGet()                { return *pinName;       }
};
// ============================================================================================= //


// Определение всех портов микроконтроллера: ................................................... //
// ............................................................................................. //
typedef PORT<&PORTA, &DDRA, &PINA> PortA;
typedef PORT<&PORTB, &DDRB, &PINB> PortB;
typedef PORT<&PORTC, &DDRC, &PINC> PortC;
typedef PORT<&PORTD, &DDRD, &PIND> PortD;
// ============================================================================================= //


// ............................................................................................. //
// ............................................................................................. //
template<class PORT, uint8_t PIN>
class TPin
{
   public:
      inline static void Set()        { PORT::SetMask(1 << PIN);                             }
      inline static void Clr()        { PORT::ClrMask(1 << PIN);                             }
      inline static void Toggle()     { PORT::Toggle(1 << PIN);                              }
      inline static uint8_t PortGet()   { return (PORT::PortGet() & (1 << PIN));               }
      inline static uint8_t DDrGet()    { return (PORT::DDrGet() & (1 << PIN));                }
      inline static uint8_t PinGet()    { return (PORT::PinGet() & (1 << PIN));                }
      inline static void MakeIN()     { PORT::ClrMask(1 << PIN); PORT::DDrClrMask(1 << PIN); }
      inline static void MakeOUT()    { PORT::ClrMask(1 << PIN); PORT::DDrSetMask(1 << PIN); }
      inline static void MakePullUp() { PORT::DDrClrMask(1 << PIN); PORT::SetMask(1 << PIN); }
};
// ============================================================================================= //


// Определение выводов всех портов микроконтроллера: ........................................... //
// ............................................................................................. //
typedef TPin<PortA, PA0> Pa0;
typedef TPin<PortA, PA1> Pa1;
typedef TPin<PortA, PA2> Pa2;
typedef TPin<PortA, PA3> Pa3;
typedef TPin<PortA, PA4> Pa4;
typedef TPin<PortA, PA5> Pa5;
typedef TPin<PortA, PA6> Pa6;
typedef TPin<PortA, PA7> Pa7;

typedef TPin<PortB, PB0> Pb0;
typedef TPin<PortB, PB1> Pb1;
typedef TPin<PortB, PB2> Pb2;
typedef TPin<PortB, PB3> Pb3;
typedef TPin<PortB, PB4> Pb4;
typedef TPin<PortB, PB5> Pb5;
typedef TPin<PortB, PB6> Pb6;
typedef TPin<PortB, PB7> Pb7;

typedef TPin<PortC, PC0> Pc0;
typedef TPin<PortC, PC1> Pc1;
typedef TPin<PortC, PC2> Pc2;
typedef TPin<PortC, PC3> Pc3;
typedef TPin<PortC, PC4> Pc4;
typedef TPin<PortC, PC5> Pc5;
typedef TPin<PortC, PC6> Pc6;
typedef TPin<PortC, PC7> Pc7;

typedef TPin<PortD, PD0> Pd0;
typedef TPin<PortD, PD1> Pd1;
typedef TPin<PortD, PD2> Pd2;
typedef TPin<PortD, PD3> Pd3;
typedef TPin<PortD, PD4> Pd4;
typedef TPin<PortD, PD5> Pd5;
typedef TPin<PortD, PD6> Pd6;
typedef TPin<PortD, PD7> Pd7;
// ============================================================================================= //

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
#endif
#include "BSP.h"

#ifndef __Table_H
  #define __Table_H

class Table {

   public: 

	   Table();

	   void handle();

   private: 

	   void remoteControlHandle();

	   void sensorKeyboardHandle();
   
};


inline Table::Table()
{

}

#endif
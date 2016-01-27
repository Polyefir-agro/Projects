#include "BSP.h"

#ifndef __Subject_H
  #define __Subject_H

#include "Observer.h"
//#include <iostream>
#include <vector>
 
class Subject {
    vector < class Observer * > views; 
    int value;
  public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify();
}; 



/*inline Subject::~Subject()
{
  
}*/

#endif
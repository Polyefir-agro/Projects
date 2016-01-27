#include "BSP.h"

#ifndef __Observer_H
  #define __Observer_H

#include "Subject.h"

class Subject;

class Observer {
    Subject *model;
    int denom;
  public:
    Observer(Subject *mod, int div) {
        model = mod;
        denom = div;
        model->attach(this);
    }
    virtual void update() = 0;
  protected:
    Subject *getSubject() {
        return model;
    }
    int getDivisor() {
        return denom;
    }
};

class DivObserver: public Observer {
  public:
    DivObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
        //cout << v << " div " << d << " is " << v/d << '\n';
    }
};
 
class ModObserver: public Observer {
  public:
    ModObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
        //cout << v << " mod " << d << " is " << v%d << '\n';
    }
};

/*inline Observer::~Observer()
{
  
}*/

#endif
#include "Subject.h"

#ifndef __Subject_H
#error [E030] �� ��������� ������������ ���� Subject.h
#endif 

void Subject::notify() {
  for (int i = 0; i < views.size(); i++)
    views[i]->update();
}



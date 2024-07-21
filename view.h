#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "observer.h"

class View: public Observer {
 public:
  virtual void notify() = 0;
  virtual ~View() = default;
};

#endif

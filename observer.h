#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "move.h"

class Observer {
 public:
  virtual void notify(Move move) = 0;
  virtual void initNotify() = 0;
  virtual ~Observer() = default;
};

#endif

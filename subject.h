#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "move.h"
#include <memory>

class Observer; // forward declaration

class Subject {

  std::vector<std::shared_ptr<Observer>> observers;
 public:
  void attach( std::shared_ptr<Observer> o );
  void detach( std::shared_ptr<Observer> o );
  void notifyObservers(Move move, bool onlyNotifyView = false) const;
  virtual char getState( int col, int row ) const = 0;
  virtual ~Subject() = default;
  void printInit() const;
};

#endif

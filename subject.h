#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class Observer; // forward declaration

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach( Observer* o );
  void detach( Observer* o );
  void notifyObservers() const;
  virtual char getState( int row, int col ) const = 0;
  virtual ~Subject() = default;
};

#endif

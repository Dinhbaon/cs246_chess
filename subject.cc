#include "subject.h"
#include "observer.h"
#include <iostream>
#include <vector>

void Subject::attach( Observer* o ) { /*** FILL IN ***/
    observers.emplace_back(o);
}

void Subject::detach( Observer* o ) { /*** FILL IN ***/ 
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers(Move move) const { /*** FILL IN ***/ 
    for (auto ob : observers) ob->notify(move);
}

void Subject::printInit() const {
    for (auto ob : observers) ob->initNotify();
}

#include "subject.h"
#include "observer.h"
#include "text.h"
#include "graphic.h"
#include <iostream>
#include <vector>

void Subject::attach( std::shared_ptr<Observer> o ) { /*** FILL IN ***/
    observers.emplace_back(o);
}

void Subject::detach( std::shared_ptr<Observer> o ) { /*** FILL IN ***/ 
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers(Move move, bool onlyNotifyView) const { /*** FILL IN ***/
    if (onlyNotifyView) {
       for (auto ob: observers) {
        std::shared_ptr<Observer>observer = ob;
        std::shared_ptr<Text> text = std::dynamic_pointer_cast<Text>(observer);
        std::shared_ptr<Graphic> graphic = std::dynamic_pointer_cast<Graphic>(observer);
        if (text) {
            ob->notify(move);
        } else if (graphic) {
            ob->notify(move);
        }
       }
    } else {
        for (auto ob : observers) ob->notify(move);
    }
}

void Subject::printInit() const {
    for (auto ob : observers) ob->initNotify();
}

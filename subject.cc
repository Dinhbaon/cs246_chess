#include "subject.h"
#include "observer.h"
#include "text.h"
#include "graphic.h"
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

void Subject::notifyObservers(Move move, bool onlyNotifyView) const { /*** FILL IN ***/
    if (onlyNotifyView) {
       for (auto ob: observers) {
        Observer *observer = ob;
        Text *text = dynamic_cast<Text*>(observer);
        Graphic *graphic = dynamic_cast<Graphic*>(observer);
        if (text) {
            text->notify(move);
        } else if (graphic) {
            graphic->notify(move);
        }
       }
    } else {
        for (auto ob : observers)  ob->notify(move);
    }
}

void Subject::printInit() const {
    for (auto ob : observers) ob->initNotify();
}

#include <iostream>
#include "observer.h"
#include "controller.h"
#include "text.h"

using namespace std;

Text::Text(Controller *s) : subject{s} {
    subject->attach(this);
}

Text::~Text() {
    subject->detach(this);
}

void Text::notify() {
    for (int i = 0; i < bottom; ++i) {
        cout << (8 - i) << ' ';
        for (int j = 0; j < right; ++j) {
            cout << subject->getState(i, j);
        }
        cout << endl;
    }
}
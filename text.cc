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
    int start_top_index = 8;
    for (int i = 0; i < bottom; ++i) {
        cout << (8 - i) << ' ';
        for (int j = 0; j < right; ++j) {
            start_top_index - j;
            cout << subject->getState(i, start_top_index);
        }
        cout << endl;
    }
}
#include <iostream>
#include "observer.h"
#include "controller.h"
#include "text.h"

using namespace std;

Text::Text(Controller *s) : subject{s} {
}

Text::~Text() {
}

void Text::notify(Move move) {
    int start_top_index = 7;
    for (int i = 0; i < bottom; ++i) {
        cout << (start_top_index + 1 - i) << ' ';
        for (int j = 0; j < right; ++j) {
            cout << subject->getState(j, start_top_index - i);
        }
        cout << endl;
    }
    cout << endl;
}

void Text::initNotify() {
    int start_top_index = 7;
    for (int i = 0; i < bottom; ++i) {
        cout << (start_top_index + 1 - i) << ' ';
        for (int j = 0; j < right; ++j) {
            cout << subject->getState(j, start_top_index - i);
        }
        cout << endl;
    }
    cout << endl;
}

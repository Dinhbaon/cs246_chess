#include <iostream>
#include "observer.h"
#include "controller.h"
#include "graphic.h"
#include <sstream>

using namespace std;

Graphic::Graphic(Controller *s) : subject{s}, window{bottom * squareDim, right * squareDim} {
    subject->attach(this);
}

Graphic::~Graphic() {
    subject->detach(this);
}

void Graphic::printRook(int c_background, int color, int x, int y) {
    int eachPixelDim = squareDim / 10;
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x * eachPixelDim, (y + i) * eachPixelDim , eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    window.fillRectangle((x + 2) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 2) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 3) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    for (int i = 4; i < 7; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 2) * eachPixelDim, (y + 7) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 3; i < 9; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 3) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 4) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 4) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 4) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 5) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 5) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 3; i < 9; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 6) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 7) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 7) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 7) * eachPixelDim, (y + 2) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 7) * eachPixelDim, (y + 3) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    for (int i = 4; i < 7; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 7) * eachPixelDim, (y + 7) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 7) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 7) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

     for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

     for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 9) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
}

void Graphic::printKnight(int c_background, int color, int x, int y) {
    int eachPixelDim = squareDim / 10;
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 4; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 2) * eachPixelDim, (y + 4) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 5) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 7) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 6) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 3) * eachPixelDim, (y + 6) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 7) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    
    window.fillRectangle((x + 4) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 4) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 4) * eachPixelDim, (y + 2) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 2; i < 5; ++i) {
        window.fillRectangle((x + 4) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 5; i < 7; ++i) {
        window.fillRectangle((x + 4) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 4) * eachPixelDim, (y + 7) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 4) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 4) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 5) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 5; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 5; i < 7; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 5) * eachPixelDim, (y + 7) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 5) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 5) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 6) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 2; i < 9; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 6) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 3; i < 9; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 7) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 4; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 4; i < 8; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 8) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 8) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 9) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
}

void Graphic::printBishop(int c_background, int color, int x, int y) {
    int eachPixelDim = squareDim / 10;
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 2) * eachPixelDim, (y + 6) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 7) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 2) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 3) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    for (int i = 2; i < 9; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 3) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 4) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 4) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 4) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 5) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 3; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 3; i < 5; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 5; i < 9; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 5) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 6) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 2; i < 9; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 6) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 7) * eachPixelDim, (y + 6) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 7) * eachPixelDim, (y + 7) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 7) * eachPixelDim, (y + 8) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 7) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 9) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
}

void Graphic::printKing(int c_background, int color, int x, int y) {
    int eachPixelDim = squareDim / 10;
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 6; i < 10; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 2) * eachPixelDim, (y + 3) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    for (int i = 4; i < 6; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 2) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 3) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 2) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 3) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 4) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 5) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 3) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 4) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 4) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 4) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 5) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 5) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 6) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 2) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 3) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 4) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 5) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 6) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 7) * eachPixelDim, (y + 3) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    for (int i = 4; i < 6; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 7) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 8) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 9) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
}

void Graphic::printQueen(int c_background, int color, int x, int y) {
    int eachPixelDim = squareDim / 10;
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    window.fillRectangle((x + 1) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 1) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 2; i < 5; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 5; i < 9; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 1) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 4; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 4; i < 9; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 2) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 3) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    for (int i = 2; i < 6; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 3) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 4) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 4) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 4) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 5) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 5) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 6) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    for (int i = 2; i < 6; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 6) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 4; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 4; i < 9; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 7) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 8) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 8) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 2; i < 5; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 5; i < 9; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    window.fillRectangle((x + 8) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 9) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
}

void Graphic::printPawn(int c_background, int color, int x, int y) {
    int eachPixelDim = squareDim / 10;
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 1) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }

    for (int i = 0; i < 7; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 7; i < 9; ++i) {
        window.fillRectangle((x + 2) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 2) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 3) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 3) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 2; i < 4; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 4; i < 6; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 3) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 3) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 4) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 4) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 4) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 5) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle((x + 5) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 5) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    window.fillRectangle((x + 6) * eachPixelDim, y * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    window.fillRectangle((x + 6) * eachPixelDim, (y + 1) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    for (int i = 2; i < 4; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    for (int i = 4; i < 6; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle((x + 6) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }
    window.fillRectangle((x + 6) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 7; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    }
    for (int i = 7; i < 9; ++i) {
        window.fillRectangle((x + 7) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, color);
    }   
    window.fillRectangle((x + 7) * eachPixelDim, (y + 9) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 8) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    } 

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle((x + 9) * eachPixelDim, (y + i) * eachPixelDim, eachPixelDim, eachPixelDim, c_background);
    } 
}

void Graphic::printSquare(int c_background, int x, int y) {
    window.fillRectangle(x, y, squareDim, squareDim, c_background);
}

void Graphic::notify(Move move) {
    int c_background;
    int color;
    PieceType pieceType;
    if (move.start.getX() == move.end.getX() && 
        move.start.getY() == move.end.getY()) {
        return;
    }
    c_background = getBackgroundColor(move.start.getX(), move.start.getY());

    printSquare(c_background, move.start.getX() * squareDim, (bottom - 1 - move.start.getY()) * squareDim);

    c_background = getBackgroundColor(move.end.getX(), move.end.getY());
    if (subject->getSquare(move.end.getX(), move.end.getY())->isEmpty()) {
        printSquare(c_background, move.end.getX() * squareDim, (bottom - 1 - move.end.getY()) * squareDim);
        return;
    }
    
    color = getPieceColor(move.end.getX(), move.end.getY());
    pieceType = subject->getSquare(move.end.getX(), move.end.getY())->getPiece()->getPieceType();

    if (pieceType == ROOK) {
        printRook(c_background, color, move.end.getX() * pieceDim, (bottom - 1 - move.end.getY()) * pieceDim);
    } else if (pieceType == KNIGHT) {
        printKnight(c_background, color, move.end.getX() * pieceDim, (bottom - 1 - move.end.getY()) * pieceDim);
    } else if (pieceType == BISHOP) {
        printBishop(c_background, color, move.end.getX() * pieceDim, (bottom - 1 - move.end.getY()) * pieceDim);
    } else if (pieceType == QUEEN) {
        printQueen(c_background, color, move.end.getX() * pieceDim, (bottom - 1 - move.end.getY()) * pieceDim);
    } else if (pieceType == KING) {
        printKing(c_background, color, move.end.getX() * pieceDim, (bottom - 1 - move.end.getY()) * pieceDim);
    } else {
        printPawn(c_background, color, move.end.getX() * pieceDim, (bottom - 1 - move.end.getY()) * pieceDim);
    }

    if (subject->getIsEnpassent()) {
        c_background = getBackgroundColor(move.end.getX(), move.start.getY());
        printSquare(c_background, move.end.getX() * squareDim, (bottom - 1 - move.start.getY()) * squareDim);
    }

    if (subject->getIsCastle()) {
        int dx = move.end.getX() - move.start.getX(); 

        if (dx > 0) {
            printRook(getBackgroundColor(5, move.end.getY()), getPieceColor(5, move.end.getY()), 5 * pieceDim, (bottom - 1 - move.end.getY()) * pieceDim);
            printSquare(getBackgroundColor(7, move.end.getY()), 7 * squareDim, (bottom - 1 - move.end.getY()) * squareDim);
        } else {
            printRook(getBackgroundColor(3, move.end.getY()), getPieceColor(3, move.end.getY()), 3 * pieceDim, (bottom - 1 - move.end.getY()) * pieceDim);
            printSquare(getBackgroundColor(0, move.end.getY()), 0 * squareDim, (bottom - 1 - move.end.getY()) * squareDim);
        }   
    }    
}

void Graphic::initNotify() {
    Square *sq;
    int c_background;
    PieceType pieceType;
    for (int i = 0; i < bottom; ++i) {
        for (int j = 0; j < right; ++j) {
            sq = subject->getSquare(j, bottom - 1 - i);
            c_background = getBackgroundColor(j, bottom - 1 - i);
            if (sq->isEmpty()) {
                printSquare(c_background, j * squareDim, i * squareDim);
            } else {
                int color;
                color = getPieceColor(j, bottom - 1 - i);
                pieceType = sq->getPiece()->getPieceType();
                if (pieceType == ROOK) {
                    printRook(c_background, color, j * pieceDim, i * pieceDim);
                } else if (pieceType == KNIGHT) {
                    printKnight(c_background, color, j * pieceDim, i * pieceDim);
                } else if (pieceType == BISHOP) {
                    printBishop(c_background, color, j * pieceDim, i * pieceDim);
                } else if (pieceType == QUEEN) {
                    printQueen(c_background, color, j * pieceDim, i * pieceDim);
                } else if (pieceType == KING) {
                    printKing(c_background, color, j * pieceDim, i * pieceDim);
                } else {
                    printPawn(c_background, color, j * pieceDim, i * pieceDim);
                }
            }
            
        }
    }   
}

int Graphic::getPieceColor(int x, int y) {
    if (subject->getSquare(x, y)->getPiece()->getColor() == WHITE) {
        return 2; // making white pieces red so it can be seen
    } else {
        return 3; // making black pieces green so it can be seen
    }
}
int Graphic::getBackgroundColor(int x, int y) {
    if (subject->getSquare(x, y)->isBlack()) {
        return 1; // black
    } else {
        return 0; // white
    }
}



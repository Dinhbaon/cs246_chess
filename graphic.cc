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
    std::cout << "notify() called" << std::endl;
    int c_background;
    int color;
    if (move.start.getX() == move.end.getX() && 
        move.start.getY() == move.end.getY()) {
        return;
    }

    if (subject->getSquare(move.start.getX(), move.start.getY())->isBlack()) {
        c_background = 1;
    } else {
        c_background = 0;
    }
    printSquare(c_background, move.start.getX() * squareDim, (bottom - 1 - move.start.getY()) * squareDim);

    if (subject->getSquare(move.end.getX(), move.end.getY())->isBlack()) {
        c_background = 1;
    } else {
        c_background = 0;
    }

    if (subject->getSquare(move.end.getX(), move.end.getY())->getPiece()->getColor() == WHITE) {
        color = 2; // making white pieces red so it can be seen
    } else {
        color = 3; // making black pieces green so it can be seen
    }

    if (subject->getSquare(move.end.getX(), move.end.getY())->getPiece()->getPieceType() == ROOK) {
        std::cout << "printRook called" << std::endl;
        printRook(c_background, color, move.end.getX() * 10, (bottom - 1 - move.end.getY()) * 10);
    } else if (subject->getSquare(move.end.getX(), move.end.getY())->getPiece()->getPieceType() == KNIGHT) {
        std::cout << "printKnight called" << std::endl;
        printKnight(c_background, color, move.end.getX() * 10, (bottom - 1 - move.end.getY()) * 10);
    } else if (subject->getSquare(move.end.getX(), move.end.getY())->getPiece()->getPieceType() == BISHOP) {
        std::cout << "printBishop called" << std::endl;
        printBishop(c_background, color, move.end.getX() * 10, (bottom - 1 - move.end.getY()) * 10);
    } else if (subject->getSquare(move.end.getX(), move.end.getY())->getPiece()->getPieceType() == QUEEN) {
        std::cout << "printQueen called" << std::endl;
        printQueen(c_background, color, move.end.getX() * 10, (bottom - 1 - move.end.getY()) * 10);
    } else if (subject->getSquare(move.end.getX(), move.end.getY())->getPiece()->getPieceType() == KING) {
        std::cout << "printQueen called" << std::endl;
        printKing(c_background, color, move.end.getX() * 10, (bottom - 1 - move.end.getY()) * 10);
    } else {
        std::cout << "printPawn called" << std::endl;
        printPawn(c_background, color, move.end.getX() * 10, (bottom - 1 - move.end.getY()) * 10);
    }

    if (subject->getIsEnpassent()) {
        if (subject->getSquare(move.end.getX(), move.start.getY())->isBlack()) {
            c_background = 1;
        } else {
            c_background = 0;
        }
        printSquare(c_background, move.end.getX() * squareDim, (bottom - 1 - move.start.getY()) * squareDim);
    }

    if (subject->getIsCastle()) {
        int dx = move.end.getX() - move.start.getX(); 

        if (dx > 0) {
            printRook(getBackgroundColor(5, move.end.getY()), getPieceColor(5, move.end.getY()), 5 * 10, (bottom - 1 - move.end.getY()) * 10);
            printSquare(getBackgroundColor(7, move.end.getY()), 7 * squareDim, (bottom - 1 - move.end.getY()) * squareDim);
        } else {
            printRook(getBackgroundColor(3, move.end.getY()), getPieceColor(3, move.end.getY()), 3 * 10, (bottom - 1 - move.end.getY()) * 10);
            printSquare(getBackgroundColor(0, move.end.getY()), 0 * squareDim, (bottom - 1 - move.end.getY()) * squareDim);
        }   
    }


    
}

void Graphic::initNotify() {
    Square *sq;
    int c_background;
    for (int i = 0; i < bottom; ++i) {
        for (int j = 0; j < right; ++j) {
            sq = subject->getSquare(j, bottom - 1 - i);
            if (sq->isBlack()) {
                c_background = 1;
            } else {
                c_background = 0;
            }
            if (sq->isEmpty()) {
                printSquare(c_background, j * squareDim, i * squareDim);
            } else {
                int color;
                if (sq->getPiece()->getColor() == WHITE) {
                    color = 2; // making white pieces red so it can be seen
                } else {
                    color = 3; // making black pieces green so it can be seen
                }
                if (sq->getPiece()->getPieceType() == ROOK) {
                    printRook(c_background, color, j * 10, i * 10);
                } else if (sq->getPiece()->getPieceType() == KNIGHT) {
                    printKnight(c_background, color, j * 10, i * 10);
                } else if (sq->getPiece()->getPieceType() == BISHOP) {
                    printBishop(c_background, color, j * 10, i * 10);
                } else if (sq->getPiece()->getPieceType() == QUEEN) {
                    printQueen(c_background, color, j * 10, i * 10);
                } else if (sq->getPiece()->getPieceType() == KING) {
                    printKing(c_background, color, j * 10, i * 10);
                } else {
                    printPawn(c_background, color, j * 10, i * 10);
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
        return 1;
    } else {
        return 0;
    }
}



#include <iostream>
#include "observer.h"
#include "controller.h"
#include "graphic.h"
#include <sstream>

using namespace std;

Graphic::Graphic(Controller *s) : subject{s}, window{bottom * 10, right * 10} {
    subject->attach(this);
}

Graphic::~Graphic() {
    subject->detach(this);
}

void Graphic::printRook(int c_background, int color, int x, int y) {
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, c_background);
    }

    window.fillRectangle(x + 2, y, 1, 1, c_background);
    window.fillRectangle(x + 2, y + 1, 1, 1, color);
    window.fillRectangle(x + 2, y + 2, 1, 1, color);
    window.fillRectangle(x + 2, y + 3, 1, 1, color);
    for (int i = 4; i < 7; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 2, y + 7, 1, 1, color);
    window.fillRectangle(x + 2, y + 8, 1, 1, color);
    window.fillRectangle(x + 2, y + 9, 1, 1, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, c_background);
    }
    for (int i = 3; i < 9; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 3, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 4, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 4, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 4, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 5, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 5, y + 9, 1, 1, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, c_background);
    }
    for (int i = 3; i < 9; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 6, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 7, y, 1, 1, c_background);
    window.fillRectangle(x + 7, y + 1, 1, 1, color);
    window.fillRectangle(x + 7, y + 2, 1, 1, color);
    window.fillRectangle(x + 7, y + 3, 1, 1, color);
    for (int i = 4; i < 7; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 7, y + 7, 1, 1, color);
    window.fillRectangle(x + 7, y + 8, 1, 1, color);
    window.fillRectangle(x + 7, y + 9, 1, 1, c_background);

     for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, c_background);
    }

     for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 9, y + i, 1, 1, c_background);
    }
}

void Graphic::printKnight(int c_background, int color, int x, int y) {
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 4; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 2, y + 4, 1, 1, color);
    window.fillRectangle(x + 2, y + 5, 1, 1, color);
    window.fillRectangle(x + 2, y + 7, 1, 1, color);
    window.fillRectangle(x + 2, y + 6, 1, 1, c_background);
    window.fillRectangle(x + 2, y + 8, 1, 1, color);
    window.fillRectangle(x + 2, y + 9, 1, 1, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 3, y + 6, 1, 1, c_background);
    window.fillRectangle(x + 3, y + 7, 1, 1, color);
    window.fillRectangle(x + 3, y + 8, 1, 1, color);
    window.fillRectangle(x + 3, y + 9, 1, 1, c_background);
    
    window.fillRectangle(x + 4, y, 1, 1, c_background);
    window.fillRectangle(x + 4, y + 1, 1, 1, c_background);
    window.fillRectangle(x + 4, y + 2, 1, 1, c_background);
    for (int i = 2; i < 5; ++i) {
        window.fillRectangle(x + 4, y + i, 1, 1, color);
    }
    for (int i = 5; i < 7; ++i) {
        window.fillRectangle(x + 4, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 4, y + 7, 1, 1, color);
    window.fillRectangle(x + 4, y + 8, 1, 1, color);
    window.fillRectangle(x + 4, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 5, y, 1, 1, c_background);
    for (int i = 1; i < 5; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, color);
    }
    for (int i = 5; i < 7; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 5, y + 7, 1, 1, color);
    window.fillRectangle(x + 5, y + 8, 1, 1, color);
    window.fillRectangle(x + 5, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 6, y, 1, 1, c_background);
    window.fillRectangle(x + 6, y + 1, 1, 1, c_background);
    for (int i = 2; i < 9; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 6, y + 9, 1, 1, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, c_background);
    }
    for (int i = 3; i < 9; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 7, y + 9, 1, 1, c_background);

    for (int i = 0; i < 4; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, c_background);
    }
    for (int i = 4; i < 8; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 8, y + 8, 1, 1, c_background);
    window.fillRectangle(x + 8, y + 9, 1, 1, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 9, y + i, 1, 1, c_background);
    }
}

void Graphic::printBishop(int c_background, int color, int x, int y) {
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 2, y + 6, 1, 1, c_background);
    window.fillRectangle(x + 2, y + 7, 1, 1, color);
    window.fillRectangle(x + 2, y + 8, 1, 1, color);
    window.fillRectangle(x + 2, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 3, y, 1, 1, c_background);
    window.fillRectangle(x + 3, y + 1, 1, 1, color);
    for (int i = 2; i < 9; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 3, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 4, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 4, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 4, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 5, y, 1, 1, c_background);
    for (int i = 1; i < 3; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, color);
    }
    for (int i = 3; i < 5; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, c_background);
    }
    for (int i = 5; i < 9; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 5, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 6, y, 1, 1, c_background);
    window.fillRectangle(x + 6, y + 1, 1, 1, c_background);
    for (int i = 2; i < 9; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 6, y + 9, 1, 1, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 7, y + 6, 1, 1, c_background);
    window.fillRectangle(x + 7, y + 7, 1, 1, color);
    window.fillRectangle(x + 7, y + 8, 1, 1, color);
    window.fillRectangle(x + 7, y + 9, 1, 1, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 9, y + i, 1, 1, c_background);
    }
}

void Graphic::printQueen(int c_background, int color, int x, int y) {
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, color);
    }
    for (int i = 6; i < 10; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 2, y + 3, 1, 1, color);
    for (int i = 4; i < 6; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 2, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 3, y, 1, 1, c_background);
    window.fillRectangle(x + 3, y + 1, 1, 1, c_background);
    window.fillRectangle(x + 3, y + 2, 1, 1, color);
    window.fillRectangle(x + 3, y + 3, 1, 1, c_background);
    window.fillRectangle(x + 3, y + 4, 1, 1, color);
    window.fillRectangle(x + 3, y + 5, 1, 1, c_background);
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 3, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 4, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 4, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 4, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 5, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 5, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 6, y, 1, 1, c_background);
    window.fillRectangle(x + 6, y + 1, 1, 1, c_background);
    window.fillRectangle(x + 6, y + 2, 1, 1, color);
    window.fillRectangle(x + 6, y + 3, 1, 1, c_background);
    window.fillRectangle(x + 6, y + 4, 1, 1, color);
    window.fillRectangle(x + 6, y + 5, 1, 1, c_background);
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 6, y + 9, 1, 1, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 7, y + 3, 1, 1, color);
    for (int i = 4; i < 6; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 7, y + 9, 1, 1, c_background);

    for (int i = 0; i < 3; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, c_background);
    }
    for (int i = 3; i < 6; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, color);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 8, y + 9, 1, 1, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 9, y + i, 1, 1, c_background);
    }
}

void Graphic::printKing(int c_background, int color, int x, int y) {
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x, y + i, 1, 1, c_background);
    }

    window.fillRectangle(x + 1, y, 1, 1, c_background);
    window.fillRectangle(x + 1, y + 1, 1, 1, c_background);
    for (int i = 2; i < 5; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, color);
    }
    for (int i = 5; i < 9; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 1, y + 9, 1, 1, c_background);

    for (int i = 0; i < 4; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, c_background);
    }
    for (int i = 4; i < 9; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 2, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 3, y, 1, 1, c_background);
    window.fillRectangle(x + 3, y + 1, 1, 1, color);
    for (int i = 2; i < 6; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 3, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 4, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 4, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 4, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 5, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 5, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 6, y, 1, 1, c_background);
    window.fillRectangle(x + 6, y + 1, 1, 1, color);
    for (int i = 2; i < 6; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 6, y + 9, 1, 1, c_background);

    for (int i = 0; i < 4; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, c_background);
    }
    for (int i = 4; i < 9; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 7, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 8, y, 1, 1, c_background);
    window.fillRectangle(x + 8, y + 1, 1, 1, c_background);
    for (int i = 2; i < 5; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, color);
    }
    for (int i = 5; i < 9; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, c_background);
    }
    window.fillRectangle(x + 8, y + 9, 1, 1, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 9, y + i, 1, 1, c_background);
    }
}

void Graphic::printPawn(int c_background, int color, int x, int y) {
    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 1, y + i, 1, 1, c_background);
    }

    for (int i = 0; i < 7; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, c_background);
    }
    for (int i = 7; i < 9; ++i) {
        window.fillRectangle(x + 2, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 2, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 3, y, 1, 1, c_background);
    window.fillRectangle(x + 3, y + 1, 1, 1, c_background);
    for (int i = 2; i < 4; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, color);
    }
    for (int i = 4; i < 6; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 3, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 3, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 4, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 4, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 4, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 5, y, 1, 1, c_background);
    for (int i = 1; i < 9; ++i) {
        window.fillRectangle(x + 5, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 5, y + 9, 1, 1, c_background);

    window.fillRectangle(x + 6, y, 1, 1, c_background);
    window.fillRectangle(x + 6, y + 1, 1, 1, c_background);
    for (int i = 2; i < 4; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, color);
    }
    for (int i = 4; i < 6; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, c_background);
    }
    for (int i = 6; i < 9; ++i) {
        window.fillRectangle(x + 6, y + i, 1, 1, color);
    }
    window.fillRectangle(x + 6, y + 9, 1, 1, c_background);

    for (int i = 0; i < 7; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, c_background);
    }
    for (int i = 7; i < 9; ++i) {
        window.fillRectangle(x + 7, y + i, 1, 1, color);
    }   
    window.fillRectangle(x + 7, y + 9, 1, 1, c_background);

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 8, y + i, 1, 1, c_background);
    } 

    for (int i = 0; i < 10; ++i) {
        window.fillRectangle(x + 9, y + i, 1, 1, c_background);
    } 
}

void Graphic::printSquare(int c_background, int x, int y) {
    window.fillRectangle(x, y, 10, 10, c_background);
}

void Graphic::notify(Move move) {
    int c_background;
    int color;
    if (move.start.getX() == move.end.getX() && 
        move.start.getY() == move.start.getY()) {
        return;
    }
    if (move.start.isBlack()) {
        c_background = 1;
    } else {
        c_background = 0;
    }
    printSquare(c_background, move.start.getX(), move.start.getY());

    if (move.start.getPiece()->getColor() == WHITE) {
        color = 2; // making white pieces red so it can be seen
    } else {
        color = 3; // making black pieces green so it can be seen
    }

    if (move.start.getPiece()->getPieceType() == ROOK) {
        printRook(c_background, color, move.start.getX() * 10, (bottom - 1 - move.start.getY()) * 10);
    } else if (move.start.getPiece()->getPieceType() == KNIGHT) {
        printKnight(c_background, color, move.start.getX() * 10, (bottom - 1 - move.start.getY()) * 10);
    } else if (move.start.getPiece()->getPieceType() == BISHOP) {
        printBishop(c_background, color, move.start.getX() * 10, (bottom - 1 - move.start.getY()) * 10);
    } else if (move.start.getPiece()->getPieceType() == QUEEN) {
        printQueen(c_background, color, move.start.getX() * 10, (bottom - 1 - move.start.getY()) * 10);
    } else if (move.start.getPiece()->getPieceType() == KING) {
        printKing(c_background, color, move.start.getX() * 10, (bottom - 1 - move.start.getY()) * 10);
    } else {
        printPawn(c_background, color, move.start.getX() * 10, (bottom - 1 - move.start.getY()) * 10);
    }
    
}

void Graphic::initNotify() {
    /// add stuff
    std::shared_ptr<Square>sq;
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
                printSquare(c_background, j * 10, i * 10);
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



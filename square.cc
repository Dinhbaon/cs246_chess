#include "square.h"
#include "move.h"

Square::Square(int x, int y, Piece* piece): x{x}, y{y}, piece{piece} {
    if (y == 7 || y == 5 || y == 3 || y == 1) {
        for (int i = 1; i < dim; i += 2) {
            if (x == i) {
                black = true;
            }
        }
    } else {
        for (int i = 0; i < dim; i += 2) {
            if (x == i) {
                black = true;
            }
        }
    }
    black = false;
}

char Square::charAt(int row, int col) {
    if (isEmpty()) {
        if (isBlack()) {
            return '_';
        } else {
            return ' ';
        }
    }
    return piece->name();
}

Piece* Square::getPiece() const {
    return piece;
}

void Square::setPiece(Piece* piece) {
    this->piece = piece; 
}

std::vector<int> Square::getCoords() {
    std::vector<int> v = {x, y};
    return v;
}

int Square::getX() const {
    return x; 
}

int Square::getY() const {
    return y; 
}

bool Square::isEmpty() const {
    return piece == nullptr; 
}

Square& Square::operator=(const Square& other) {
    if (this == &other) {
        return *this; 
    }
    
    x = other.x; 
    y = other.y; 
    piece = other.piece;
    return *this;
}

bool Square::isBlack() {
    return black;
}

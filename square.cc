#include "square.h"
#include "move.h"

Square::Square(int x, int y, Piece* piece): x{x}, y{y}, piece{piece} {}


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
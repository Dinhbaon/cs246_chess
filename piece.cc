#include "piece.h"

Color Piece::getColor() const {
    return color; 
}

Piece::~Piece() {}

Piece::Piece(Color color): color{color} {}


bool Piece::getHasMoved() const {
    return hasMoved; 
}

void Piece::setHasMoved(bool hasMoved) {
    this->hasMoved = hasMoved; 
}



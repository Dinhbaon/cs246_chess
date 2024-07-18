#include "piece.h"

Color Piece::getColor() const {
    return color; 
}

Piece::~Piece() {}

Piece::Piece(Color color): color{color} {}
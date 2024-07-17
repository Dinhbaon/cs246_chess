#include "piece.h"

bool Piece::getIsWhite() const {
    return isWhite; 
}

Piece::~Piece() {}

Piece::Piece(bool isWhite): isWhite{isWhite} {}
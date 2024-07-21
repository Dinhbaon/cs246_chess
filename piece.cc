#include "piece.h"

Color Piece::getColor() const {
    return color; 
}

Piece::~Piece() {}

Piece::Piece(Color color): color{color} {}

char Piece::name() {
    if (color == BLACK) {
        if (pieceType == ROOK) {
            return 'r';
        } else if (pieceType == KNIGHT) {
            return 'n';
        } else if (pieceType == BISHOP) {
            return 'b';
        } else if (pieceType == QUEEN) {
            return 'q';
        } else if (pieceType == KING) {
            return 'k';
        } else {
            return 'p';
        }
    } else {
        if (pieceType == ROOK) {
            return 'R';
        } else if (pieceType == KNIGHT) {
            return 'N';
        } else if (pieceType == BISHOP) {
            return 'B';
        } else if (pieceType == QUEEN) {
            return 'Q';
        } else if (pieceType == KING) {
            return 'K';
        } else {
            return 'P';
        }
    }
}

bool Piece::getHasMoved() const {
    return hasMoved; 
}

void Piece::setHasMoved(bool hasMoved) {
    hasMoved = hasMoved; 
}



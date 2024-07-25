#include "queen.h"
#include "bishop.h"
#include "rook.h"

Queen::Queen(Color color): Piece{color} {}

char Queen::name() const {
    if (getColor() == BLACK) {
        return 'q';
    } else {
        return 'Q';
    }
}

bool Queen::canMove(const Move& move, const Board& board) const {
    Bishop tempBishop{this->getColor()}; 
    Rook tempRook{this->getColor()}; 
    return tempBishop.canMove(move, board) || tempRook.canMove(move, board);
}

bool Queen::canCapture(const Move& move, const Board& board) const {
    return canMove(move, board); 
}

PieceType Queen::getPieceType() const {
    return QUEEN; 
}

std::shared_ptr<Piece> Queen::copy() const {
    return std::make_shared<Queen>(*this); 
}
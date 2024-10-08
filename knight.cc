#include "knight.h"
#include "board.h" 
#include "move.h"
#include "square.h"
#include <stdlib.h> 


Knight::Knight(Color color) : Piece(color) {}

char Knight::name() const {
    if (getColor() == BLACK) {
        return 'n';
    } else {
        return 'N';
    }
}

bool Knight::canMove(const Move& move, const Board& board) const {
    int dx = move.end.getX() - move.start.getX();
    int dy = move.end.getY() - move.start.getY(); 
    if (!((abs(dx) == 2 && abs(dy) == 1) || (abs(dy) == 2 && abs(dx) == 1))) return false; 

    // Check if final square is friendly piece
    std::shared_ptr<Square> endSquare = board.getSquare(move.end.getX(), move.end.getY());
    return endSquare == nullptr || endSquare->isEmpty() || endSquare->getPiece()->getColor() != getColor();
}

bool Knight::canCapture(const Move& move, const Board& board) const {
    return canMove(move, board); 
}

PieceType Knight::getPieceType() const {
    return KNIGHT; 
}

std::shared_ptr<Piece> Knight::copy() const {
    return  std::make_shared<Knight>(*this); 
}
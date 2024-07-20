#include "knight.h"
#include "board.h" 
#include "move.h"
#include "square.h"
#include <stdlib.h> 

Knight::Knight(Color color) : Piece(color) {}

bool Knight::canMove(const Move& move, const Board& board) const {
    int dx = move.end.getX() - move.start.getX();
    int dy = move.end.getY() - move.start.getY(); 
    if (!((abs(dx) == 2 && abs(dy) == 1) || (abs(dy) == 2 && abs(dx) == 1))) return false; 

    // Check if final square is friendly piece
    Square* endSquare = board.getSquare(move.end.getX(), move.end.getY());
    return endSquare == nullptr || endSquare->isEmpty() || endSquare->getPiece()->getColor() != getColor();
}

PieceType Knight::getPieceType() const {
    return KNIGHT; 
}
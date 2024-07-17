#include "board.h"
#include "move.h"

Square* Board::getSquare(const int x, const int y) const {
    return board[xDimension*y + x];
}

void Board::movePiece(const int fromX, const int fromY, const int toX, const int toY) {
    Piece* piece = this->getSquare(fromX, fromY)->getPiece(); 
    Move move{Square{fromX, fromY}, Square{toX, toY}};
    if (piece->canMove(move, *this)) {
        this->getSquare(fromX, fromY)->setPiece(nullptr);
        this->getSquare(toX, toY)->setPiece(piece);
    } 
}


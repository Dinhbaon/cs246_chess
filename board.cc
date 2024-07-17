#include "board.h"

Square* Board::getSquare(const int x, const int y) const {
    return board[xDimension*y + x];
}

void Board::movePiece(const int fromX, const int fromY, const int toX, const int toY) {

}
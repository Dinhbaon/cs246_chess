#include "king.h"

King::King(Color color): Piece{color} {}

bool King::canMove(const Move& move, const Board& board) const {
    return true; 
}
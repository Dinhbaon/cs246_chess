#include "queen.h"

Queen::Queen(Color color): Piece{color} {}

bool Queen::canMove(const Move& move, const Board& board) const {
    return true;
}
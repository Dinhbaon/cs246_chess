#include "pawn.h"
#include "board.h" 
#include "move.h"
#include "square.h"
#include <stdlib.h> 

Pawn::Pawn(Color color) : Piece(color) {}

bool Pawn::canMove(const Move& move, const Board& board) const {
    return true; 
}

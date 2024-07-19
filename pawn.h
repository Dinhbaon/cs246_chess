#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "color.h"

class Pawn: public Piece {
    public:
        Pawn(Color color);
        bool canMove(const Move& move, const Board& board) const override;
};  

#endif
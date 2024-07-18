#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "color.h"

class Knight: public Piece {
    public:
        Knight(Color color);
        bool canMove(const Move& move, const Board& board) const override;
};  

#endif
#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece {
    public:
        Knight(bool isWhite);
        bool canMove(const Move& move, const Board& board) const override;
};  

#endif
#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop: public Piece {
    public:
        Bishop(bool isWhite);
        bool canMove(const Move& move, const Board& board) const override;
};  

#endif
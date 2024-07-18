#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook: public Piece {
    public:
        Rook(bool isWhite);
        bool canMove(const Move& move, const Board& board) const override;
};  

#endif
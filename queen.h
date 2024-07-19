#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece {
    
    public:
        Queen(Color color);
        bool canMove(const Move& move, const Board& board) const override;
};

#endif
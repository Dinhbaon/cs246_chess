#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "color.h"
#include "piecetype.h"

class Pawn: public Piece {
    bool isPromoting; 
    public:
        Pawn(Color color);
        bool canMove(const Move& move, const Board& board) const override;
        PieceType getPieceType() const override; 
        void promote(Board& board); 
};  

#endif
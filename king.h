#ifndef KING_H
#define KING_H

#include "piece.h"
#include "color.h"

class King: public Piece {
    public:
        King(Color color);
        bool canMove(const Move& move, const Board& board) const override;
        bool canCapture(const Move& move, const Board& board) const override; 
        PieceType getPieceType() const override; 
        Piece* copy() const override; 
};  

#endif
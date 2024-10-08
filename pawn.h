#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "color.h"
#include "piecetype.h"
#include <memory>

class Pawn: public Piece {
    public:
        Pawn(Color color);
        bool canMove(const Move& move, const Board& board) const override;
        bool canCapture(const Move& move, const Board& board) const override; 
        PieceType getPieceType() const override; 
        void promote(Board& board); 
        std::shared_ptr<Piece> copy() const override; 
        char name() const override;
};  

#endif
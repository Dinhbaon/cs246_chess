#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "color.h"
#include <memory>

class Rook: public Piece {
    public:
        Rook(Color color);
        bool canMove(const Move& move, const Board& board) const override;
        bool canCapture(const Move& move, const Board& board) const override; 
        PieceType getPieceType() const override; 
        std::shared_ptr<Piece> copy() const override; 
        char name() const override;
};  

#endif
#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <memory>

class Queen: public Piece {
    
    public:
        Queen(Color color);
        bool canMove(const Move& move, const Board& board) const override;
        bool canCapture(const Move& move, const Board& board) const override; 
        PieceType getPieceType() const override; 
        std::shared_ptr<Piece> copy() const override; 
        char name() const override;
};

#endif
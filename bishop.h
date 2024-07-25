#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <memory>

class Bishop: public Piece {
    public:
        Bishop(Color color);
        bool canMove(const Move& move, const Board& board) const override;
        bool canCapture(const Move& move, const Board& board) const override; 
        PieceType getPieceType() const override; 
        std::shared_ptr<Piece> copy() const override; 
        char name() const override;
        
};  

#endif
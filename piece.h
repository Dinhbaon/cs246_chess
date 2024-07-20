#ifndef PIECE_H
#define PIECE_H

#include "color.h"
#include "piecetype.h"

class Move;
class Board;

class Piece {
    bool hasMoved; 
    Color color; 
    PieceType pieceType; 
    public:
        virtual bool canMove(const Move& move, const Board& board) const = 0;
        Color getColor() const; 
        Piece(Color color); 
        virtual ~Piece();
        bool getHasMoved() const;
        void setHasMoved(bool hasMoved); 
        virtual PieceType getPieceType() const = 0; 
};

#endif
#ifndef PIECE_H
#define PIECE_H

#include "color.h"
#include "piecetype.h"
#include <memory>

class Move;
class Board;

class Piece {
    bool hasMoved = false; 
    Color color; 
    protected:
        PieceType pieceType;
    public:
        virtual char name() const = 0;
        // canMove returns if move is possible. 
        virtual bool canMove(const Move& move, const Board& board) const = 0;
        // canCapture returns if move is capture. All captures are moves but not all moves are captures. 
        // The implementation is exactly the same except for the pawn
        virtual bool canCapture(const Move& move, const Board& board) const = 0; 
        Color getColor() const; 
        Piece(Color color); 
        virtual ~Piece();
        bool getHasMoved() const;
        void setHasMoved(bool hasMoved); 
        virtual PieceType getPieceType() const = 0; 
        virtual std::shared_ptr<Piece> copy() const = 0; 
};

#endif
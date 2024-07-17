#ifndef PIECE_H
#define PIECE_H

class Move;
class Board;

class Piece {
    bool isWhite; 
    public:
        virtual bool canMove(const Move& move, const Board& board) const = 0;
        bool getIsWhite() const; 
        Piece(bool isWhite); 
        virtual ~Piece();
};

#endif
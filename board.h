#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "square.h"
#include "color.h"
#include "move.h"
#include <vector>
#include <map>
#include <string>

template class std::map<Color, std::vector<Piece*>>;

class Board {

    mutable std::map<Color, std::vector<Square*>> allSquaresWithPieces; 
    std::vector<Square*> board;
    int xDimension = 8;
    int yDimension = 8; 
    Move lastMove; 
    // Private utility methods 
    void clearBoard(); 
    // Castle related
    bool isMoveCastle(const Move& move) const;
    void Castle(const Move& move);  
    // En passent related
    bool isMoveEnpassent(const Move& move) const; 
    void Enpassent(const Move& move); 
    public:
        Board(); 
        // ~Board();
        Board(const Board& other);
        Board &operator=(const Board &other);
        char charAt(int col, int row);
        void movePiece(Move move, Color color);
        // Public utility methods
        bool isSquareUnderAttack(const Square& square, Color color) const;  
        bool isInCheck(Color color) const;
        bool isCheckAfterMove(Move move, Color color);
        // Getters and setters
        Square* getSquare(const int x, const int y) const;
        void setSquare(const int x, const int y, Piece* piece); 
        const std::map<Color, std::vector<Square*>>& getAllSquaresWithPieces() const;
        Move getLastMove() const;
        Square* getKingSquare(Color color) const;
        bool oneKing(const Color color) const;
};

#endif

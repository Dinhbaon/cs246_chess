#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "square.h"
#include "color.h"
#include "move.h"
#include <vector>
#include <map>
#include <string>

class Board {

    std::map<Color, std::vector<Piece*>> allPieces; 
    std::vector<Square*> board;
    int xDimension = 8;
    int yDimension = 8; 
    Move lastMove; 
    // Private utility methods
    void updateAllPieces();  
    // Castle related
    bool isMoveCastle(const Move& move) const;
    void Castle(const Move& move);  
    // En passent related
    bool isMoveEnpassent(const Move& move) const; 
    void Enpassent(const Move& move); 
    public:
        Board(); 
        ~Board();
        char charAt(int row, int col);
        void movePiece(Move move, Color color);
        // Public utility methods
        bool isSquareUnderAttack(const Square& square, Color color) const;  
        bool isInCheck(Color color) const;
        bool isPiecePinned(const Square& square, Color color);  
        // Getters and setters
        Square* getSquare(const int x, const int y) const;
        void setSquare(const int x, const int y, Piece* piece); 
        std::map<Color, std::vector<Piece*>> getPieces() const;
        Move getLastMove() const;
        Square* getKingSquare(Color color) const;

};

#endif

#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "square.h"
#include "color.h"
#include "move.h"
#include <vector>
#include <map>
#include <string>
#include <memory>

template class std::map<Color, std::vector<std::shared_ptr<Piece>>>;

class Board {

    mutable std::map<Color, std::vector<std::shared_ptr<Square>>> allSquaresWithPieces; 
    std::vector<std::shared_ptr<Square>> board;
    int xDimension = 8;
    int yDimension = 8; 
    Move lastMove; 
    // Private utility methods 
    void clearBoard(); 
    // Castle related
    void Castle(const Move& move);  
    // En passent related
    void Enpassent(const Move& move); 
    public:
        Board(); 
        Board(const Board& other);
        Board &operator=(const Board &other);
        bool operator==(const Board &other); 
        char charAt(int col, int row);
        void movePiece(Move move, Color color);
        // Public utility methods
        bool isSquareUnderAttack(const Square& square, Color color) const;  
        bool isSquareUnderAttackAfterMove(Move move, Color color) const;  
        bool isInCheck(Color color) const;
        bool isCheckAfterMove(Move move, Color color);
        bool oneKing(const Color color) const;
        bool isMoveCastle(const Move& move) const;
        bool isMoveEnpassent(const Move& move) const;
        bool checkPawnEdgeRows() const;
        // Getters and setters
        std::shared_ptr<Square> getSquare(const int x, const int y) const;
        std::shared_ptr<Square> getEmptySquare() const;
        void setSquare(const int x, const int y, std::shared_ptr<Piece> piece); 
        const std::map<Color, std::vector<std::shared_ptr<Square>>>& getAllSquaresWithPieces() const;
        Move getLastMove() const;
        std::shared_ptr<Square> getKingSquare(Color color) const;
        void emptyBoard();
 
};

#endif

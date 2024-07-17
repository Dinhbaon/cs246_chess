#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "square.h"
#include <vector>

class Board {
        std::vector<Piece> allPieces; 
        std::vector<Square*> board;
        int xDimension = 8;
        int yDimension = 8;
    public:
        Square* getSquare(const int x, const int y) const;
        void setSquare(const int x, const int y, Square* square); 
        void movePiece(const int fromX, const int fromY, const int toX, const int toY);
};

#endif
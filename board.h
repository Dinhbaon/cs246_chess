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
    void updateAllPieces();  
    public:
        Board(); 
        ~Board();
        void movePiece(Move move, Color color);
        Square* getSquare(const int x, const int y) const;
        void setSquare(const int x, const int y, Square* square); 
        
 
};

#endif

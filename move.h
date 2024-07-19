#ifndef MOVE_H
#define MOVE_H

#include "square.h"
#include "piece.h"


class Move {
    public: 
        Square start; 
        Square end;
        Move(Square start = Square(0, 0), Square end = Square(0, 0));
        Move& operator=(const Move& other); 
};

#endif
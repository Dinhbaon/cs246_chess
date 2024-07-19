#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "color.h"

class Player {
    Color color; 
    public:
        Player(Color color);
        virtual Move getNextMove() const = 0; 
        virtual bool getIsHuman() const = 0; 
};  

#endif
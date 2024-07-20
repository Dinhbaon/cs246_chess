#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "color.h"
#include "board.h"

class Player {
    protected:
        Color color;    
        Board* board; 
    public:
        Player(Color color, Board* board);
        virtual Move getNextMove() const = 0; 
        virtual bool getIsHuman() const = 0; 
        virtual void handlePromotion() = 0; 
};  

#endif
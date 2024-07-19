#ifndef HUMAN_H
#define HUMAN_

#include "player.h"
#include "board.h"
#include "color.h"

class Human: public Player {
    Board* board; 
    Color color; 
    public:
        Human(Color color, Board* Board);
        Move getNextMove() const override; 
        bool getIsHuman() const override; 
};  

#endif
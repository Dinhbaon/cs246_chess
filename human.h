#ifndef HUMAN_H
#define HUMAN_

#include "player.h"
#include "color.h"

class Human: public Player {
    public:
        Human(Color color, Board* Board);
        Move getNextMove() const override; 
        bool getIsHuman() const override; 
        void handlePromotion() override; 
};  

#endif
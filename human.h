#ifndef HUMAN_H
#define HUMAN_

#include "player.h"
#include "color.h"
#include <memory>

class Human: public Player {
    public:
        Human(Color color, std::shared_ptr<Board> Board);
        Move getNextMove() const override; 
        bool getIsHuman() const override; 
        void handlePromotion() override; 
};  

#endif
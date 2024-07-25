#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "color.h"
#include <memory>

class Player {
    protected:
        Color color;    
        std::shared_ptr<Board> board; 
    public:
        Player(Color color, std::shared_ptr<Board> board);
        virtual Move getNextMove() const = 0; 
        virtual bool getIsHuman() const = 0; 
        virtual void handlePromotion() = 0; 
};  

#endif
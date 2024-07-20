#ifndef BOT_H
#define BOT_H

#include "player.h"

class Bot: public Player{
    public:
        Bot(Color color, Board* board);
        bool getIsHuman() const override;
};

#endif
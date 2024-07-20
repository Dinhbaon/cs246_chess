#ifndef BOT_LEVEL1_H
#define BOT_LEVEL1_H

#include "bot.h"

class BotLevel1: public Bot{
    public:
        BotLevel1(Color color, Board* board);
        Move getNextMove() const override;
        void handlePromotion() override; 
};

#endif

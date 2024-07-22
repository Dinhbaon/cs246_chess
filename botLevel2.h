#ifndef BOT_LEVEL2_H
#define BOT_LEVEL2_H

#include "bot.h"

class BotLevel2: public Bot{
    public:
        BotLevel2(Color color, Board* board);
        Move getNextMove() const override;
};

#endif

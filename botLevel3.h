#ifndef BOT_LEVEL3_H
#define BOT_LEVEL3_H

#include "bot.h"

class BotLevel3: public Bot{
    public:
        BotLevel3(Color color, Board* board);
        Move getNextMove() const override;
};

#endif

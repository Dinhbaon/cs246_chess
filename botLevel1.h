#ifndef BOT_LEVEL1_H
#define BOT_LEVEL1_H

#include "bot.h"
#include <memory>

class BotLevel1: public Bot{
    public:
        BotLevel1(Color color, std::shared_ptr<Board> board);
        Move getNextMove() const override;
};

#endif

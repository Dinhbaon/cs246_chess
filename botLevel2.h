#ifndef BOT_LEVEL2_H
#define BOT_LEVEL2_H

#include "bot.h"
#include <memory>

class BotLevel2: public Bot{
    public:
        BotLevel2(Color color, std::shared_ptr<Board> board);
        Move getNextMove() const override;
};

#endif

#ifndef BOT_LEVEL3_H
#define BOT_LEVEL3_H

#include "bot.h"
#include <memory>

class BotLevel3: public Bot{
    public:
        BotLevel3(Color color, std::shared_ptr<Board> board);
        Move getNextMove() const override;
};

#endif

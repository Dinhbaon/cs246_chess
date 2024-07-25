#ifndef BOT_LEVEL4_H
#define BOT_LEVEL4_H

#include "bot.h"
#include <map>
#include <memory>

class BotLevel4: public Bot{
    public:
        BotLevel4(Color color, std::shared_ptr<Board> board);
        Move getNextMove() const override;
};

#endif

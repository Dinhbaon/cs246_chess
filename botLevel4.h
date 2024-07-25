#ifndef BOT_LEVEL4_H
#define BOT_LEVEL4_H

#include "bot.h"
#include <map>

class BotLevel4: public Bot{
    std::map<PieceType, int> allSquaresWithPieces; 
    public:
        BotLevel4(Color color, Board* board);
        Move getNextMove() const override;
};

#endif

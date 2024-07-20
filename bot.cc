#include "bot.h"

Bot::Bot(Color color, Board* board): Player{color, board}{};

bool Bot::getIsHuman() const{
    return false;
}

#ifndef BOT_H
#define BOT_H

#include "player.h"

class Bot: public Player{
    public:
        Bot(Color color, Board* board);
        bool getIsHuman() const override;
        void handlePromotion();
    protected:
        std::vector<Move> findGetCaptureMoves(std::vector<Square*> &squares, Color color) const;
        std::vector<Move> findCaptureMoves(std::vector<Square*> &squares, Color color) const;
        std::vector<Move> findCheckMoves(std::vector<Square*> &squares, Color color) const;
        std::vector<Move> findRandomMoves(std::vector<Square*> &squares, Color color) const;
};

#endif
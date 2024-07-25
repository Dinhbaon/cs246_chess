#ifndef BOT_H
#define BOT_H

#include "player.h"

class Bot: public Player{
    public:
        Bot(Color color, Board* board);
        bool getIsHuman() const override;
        void handlePromotion();
    protected:
        std::vector<Move> findRandomAvoidCaptureMoves(const std::vector<Square*> &squares, Color color) const;
        std::vector<Move> findCaptureMoves(const std::vector<Square*> &squares, Color color) const;
        std::vector<Move> findCheckMoves(const std::vector<Square*> &squares, Color color) const;
        std::vector<Move> findRandomMoves(const std::vector<Square*> &squares, Color color) const;
        std::vector<Move> findAvoidCaptureMoves(const std::vector<Square*> &squares, Color color) const;
};

#endif
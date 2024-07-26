#ifndef BOT_H
#define BOT_H

#include "player.h"
#include <memory>

class Bot: public Player{
    public:
        Bot(Color color, std::shared_ptr<Board> board);
        bool getIsHuman() const override;
        void handlePromotion();
    protected:
        std::map<const PieceType, int> piecesPoints; 
        std::vector<Move> findRandomAvoidCaptureMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const;
        std::vector<Move> findCaptureMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const;
        std::vector<Move> findCheckMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const;
        std::vector<Move> findRandomMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const;
        std::vector<Move> findAvoidCaptureMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const;
        std::vector<Move> findDefensiveMove(const std::vector<std::shared_ptr<Square>> &squares, Color color) const;
        Move findBetterCaptureMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const;
        Move findCheckMate(const std::vector<std::shared_ptr<Square>> &squares, Color color) const;
};

#endif
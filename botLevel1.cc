#include "botLevel1.h"
#include <random>

BotLevel1::BotLevel1(Color color, Board* board): Bot{color, board} {}

template <typename T>

T getRandom(const std::vector<T>& vector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrMoves(0, vector.size()-1);
    int ithElement = distrMoves(gen);
    return vector.at(ithElement);
}

Move BotLevel1::getNextMove() const {
    const std::vector<Square*> &squares = board->getAllSquaresWithPieces().at(color);
    std::vector<Move> moves;

    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, *board->getSquare(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && board->isCheckAfterMove(move, color)){
                    moves.emplace_back(move);
                }
            }
        }
    }

    return getRandom(moves);
}

#include "botLevel2.h"
#include "king.h"
#include <random>

BotLevel2::BotLevel2(Color color, Board* board): Bot{color, board}{}

template <typename T>
T getRandom(const std::vector<T>& vector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrMoves(0, vector.size()-1);
    int ithElement = distrMoves(gen);
    return vector.at(ithElement);
}

Move BotLevel2::getNextMove() const {
    const std::vector<Square*> &squares = board->getAllSquaresWithPieces().at(color);
    std::vector<Move> captureMoves = findCaptureMoves(squares, color);
    std::vector<Move> checkMoves = findCheckMoves(squares, color);
    std::vector<Move> getRandomMoves = findRandomMoves(squares, color);

    if(captureMoves.size() > 0){
        return getRandom(captureMoves);
    } else if(checkMoves.size() > 0){
        return getRandom(checkMoves);
    } else {
        return getRandom(getRandomMoves);
    }
}

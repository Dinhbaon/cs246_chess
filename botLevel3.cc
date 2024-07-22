#include "botLevel3.h"
#include "king.h"
#include <random>

template <typename T> T getRandom(std::vector<T> vector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrMoves(0, vector.size()-1);
    int ithElement = distrMoves(gen);
    return vector[ithElement];
}

BotLevel3::BotLevel3(Color color, Board* board): Bot{color, board}{}

Move BotLevel3::getNextMove() const {
    std::vector<Square*> &squares = board->getAllSquaresWithPieces()[color];
    std::vector<Move> captureMoves = findCaptureMoves(squares, color);
    std::vector<Move> checkMoves = findCheckMoves(squares, color);
    std::vector<Move> getCaptureMoves = findGetCaptureMoves(squares, color);
    std::vector<Move> getRandomMoves = findRandomMoves(squares, color);

    if(captureMoves.size() > 0){
        return getRandom<Move>(captureMoves);
    } else if(checkMoves.size() > 0){
        return getRandom<Move>(checkMoves);
    } else if (getCaptureMoves.size() > 0){
        return getRandom<Move>(getCaptureMoves);
    } else {
        return getRandom<Move>(getRandomMoves);
    }
}

#include "botLevel1.h"
#include <random>

BotLevel1::BotLevel1(Color color, std::shared_ptr<Board> board): Bot{color, board} {}

template <typename T>

T getRandom(const std::vector<T>& vector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrMoves(0, vector.size()-1);
    int ithElement = distrMoves(gen);
    return vector.at(ithElement);
}

Move BotLevel1::getNextMove() const {
    const std::vector<std::shared_ptr<Square>> &squares = board->getAllSquaresWithPieces().at(color);
    std::vector<Move> moves = findRandomMoves(squares, color);

    return getRandom(moves);
}

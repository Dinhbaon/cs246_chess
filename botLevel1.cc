#include "botLevel1.h"
#include <random>

BotLevel1::BotLevel1(Color color, Board* board): Bot{color, board}{}

template <typename T>

T getRandom(std::vector<T> vector){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrMoves(0, vector.size()-1);
    int ithElement = distrMoves(gen);
    return vector[ithElement];
}

Move BotLevel1::getNextMove() const {
    std::vector<Square*> &squares = board->getAllSquaresWithPieces()[color];
    std::vector<Move> moves;

    while(moves.size() == 0){
        Square* selectedSquare = getRandom<Square*>(squares);
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {*selectedSquare, Square(x, y)};
                if(selectedSquare->getPiece()->canMove(move, *board)){
                    moves.emplace_back(move);
                }
            }
        }
    }
    
    return getRandom<Move>(moves);
}

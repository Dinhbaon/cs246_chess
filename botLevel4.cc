#include "botLevel4.h"
#include "king.h"
#include <random>

template <typename T> 
T getRandom(std::vector<T> vector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrMoves(0, vector.size()-1);
    int ithElement = distrMoves(gen);
    return vector[ithElement];
}

BotLevel4::BotLevel4(Color color, std::shared_ptr<Board> board): Bot{color, board}{
    piecesPoints[QUEEN] = 9;
    piecesPoints[ROOK] = 5;
    piecesPoints[BISHOP] = 3;
    piecesPoints[KNIGHT] = 3;
    piecesPoints[PAWN] = 1;
}

Move BotLevel4::getNextMove() const {
    const std::vector<std::shared_ptr<Square>> &squares = board->getAllSquaresWithPieces().at(color);
    Move betterCaptureMove = findBetterCaptureMoves(squares, color);
    std::vector<Move> captureMoves = findCaptureMoves(squares, color);
    std::vector<Move> checkMoves = findCheckMoves(squares, color);
    std::vector<Move> avoidCapture = findAvoidCaptureMoves(squares, color);
    std::vector<Move> randomAvoidCaptureMoves = findRandomAvoidCaptureMoves(squares, color);
    std::vector<Move> getRandomMoves = findRandomMoves(squares, color);

    if (!(betterCaptureMove.start == Square(0,0) && betterCaptureMove.end == Square(0,0))){
        return betterCaptureMove;
    } else if(captureMoves.size() > 0){
        return getRandom(captureMoves);
    } else if(checkMoves.size() > 0){
        return getRandom(checkMoves);
    } else if (avoidCapture.size() > 0){
        return getRandom(avoidCapture);
    } else if (randomAvoidCaptureMoves.size() > 0){
        return getRandom(randomAvoidCaptureMoves);
    } else {
        return getRandom(getRandomMoves);
    }
}

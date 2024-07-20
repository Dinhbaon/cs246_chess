#include "botLevel1.h"
#include <random>

BotLevel1::BotLevel1(Color color, Board* board): Bot{color, board}{}

Move BotLevel1::getNextMove() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<Piece*> pieces = board->getPieces()[color];
    std::uniform_int_distribution<> distrPiece(0, pieces.size());
    int ithPiece = distrPiece(gen);
    Piece* selectedPiece = pieces[ithPiece];
    std::vector<Move> moves;

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; j++){
            Move move {i, j};
            if(selectedPiece->canMove(move, *board)){
                moves.emplace_back(move);
            }
        }
    }

    std::uniform_int_distribution<> distrMove(0, pieces.size());
    int ithMove = distrMove(gen);
    return moves[ithMove];
}

void BotLevel1::handlePromotion()  {
    return; 
}

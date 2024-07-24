#include "endgameservice.h"

EndGameService::EndGameService(Controller *controller, Board *board): controller{controller}, board{board} {
    controller->attach(this);
    isCheckMate = false;
}

void EndGameService::initNotify(){
    return;
}

EndGameService::~EndGameService() {
    controller->detach(this);
}

void EndGameService::resetCheckMate(){
    isCheckMate = false;
}

bool EndGameService::getIsCheckMate(){
    return isCheckMate;
}

void EndGameService::notify(Move move){
    Color color = controller->getPlayerColor();
    Color oppositionColor;
    if(color==WHITE){
        oppositionColor = BLACK;
    } else {
        oppositionColor = WHITE;
    }
    const std::vector<Square*> &squares = board->getAllSquaresWithPieces().at(oppositionColor);
    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Board tmpBoard = *board;
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)){
                    tmpBoard.movePiece(move, oppositionColor);
                    if(!(board->isCheckAfterMove(move, oppositionColor))){
                        isCheckMate = false;
                        return;
                    };
                }
            }
        }
    }
    isCheckMate = true;
}

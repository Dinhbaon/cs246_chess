#include "endgameservice.h"

EndGameService::EndGameService(Controller *controller, Board *board): controller{controller}, board{board} {
    controller->attach(this);
    isCheckMate = false;
    isStaleMate = false;
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

void EndGameService::resetStaleMate(){
    isStaleMate = false;
}

bool EndGameService::getIsCheckMate(){
    return isCheckMate;
}

bool EndGameService::getIsStaleMate(){
    return isStaleMate;
}


bool checkCanMove(Board *board, Controller *controller, Color oppositionColor){
    
    const std::vector<Square*> &squares = board->getAllSquaresWithPieces().at(oppositionColor);
    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && !(board->isCheckAfterMove(move, oppositionColor))){
                    return false;
                }
            }
        }
    }
    return true;
}

void EndGameService::reset(Board* board) {
    this->board = board; 
    resetCheckMate();
    resetStaleMate(); 
}

void EndGameService::notify(Move move){
    Color color = controller->getPlayerColor();
    Color oppositionColor;
    if(color==WHITE){
        oppositionColor = BLACK;
    } else {
        oppositionColor = WHITE;
    }
    if(checkCanMove(board, controller, oppositionColor)){
        if(board->isInCheck(oppositionColor)){
            isCheckMate = true;
        } else {
            isStaleMate = true;
        }
        
    }
}

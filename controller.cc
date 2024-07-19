#include "controller.h"
#include "board.h"

Controller::Controller(Board* board): board{board} {}

bool Controller::getIsInGame() const {
    return getIsInGame;
}

void Controller::setIsInGame(bool isInGame) {
    isInGame = isInGame; 
}

Player* Controller::getPlayerTurn() const {
    switch (playerTurn) {
        case WHITE: 
            return whitePlayer; 
        case BLACK: 
            return blackPlayer; 
    } 
}
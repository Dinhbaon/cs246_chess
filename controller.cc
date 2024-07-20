#include "controller.h"
#include "board.h"
#include "move.h"
#include "human.h"
#include <iostream>

Controller::Controller(Board* board): board{board} {}

bool Controller::getIsInGame() const {
    return isInGame;
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

void Controller::makeMove(Move move, Color color) {
    notifyObservers(); 
    switchTurn(); 
    board->movePiece(move, color); 
}

bool Controller::isValidMove(Move move, Color color) const {
    int fromX = move.start.getX(); 
    int fromY = move.start.getY();

    int toX = move.start.getX(); 
    int toY = move.start.getY(); 
    Square* startSquare = this->board->getSquare(fromX, fromY); 
    if (startSquare->isEmpty()) return false; 
    if (color != startSquare->getPiece()->getColor()) return false; 
    Piece* piece = this->board->getSquare(fromX, fromY)->getPiece(); 
    return piece->canMove(move, *this->board); 
}

Color Controller::getPlayerColor() const {
    return playerTurn; 
}

void Controller::setPlayers(Color color, std::string player) {
    if (player == "Human") {
        switch(color){
            case WHITE: 
                whitePlayer = new Human(WHITE, this->board); 
                break; 
            case BLACK: 
                blackPlayer = new Human(BLACK, this->board); 
                break; 
        }
    }

}

void Controller::setMode(Mode mode) {
    this->mode = mode; 
}

Mode Controller::getMode() const {
    return mode; 
}

void Controller::notifyObservers() {
    return ;
}

void Controller::switchTurn() {
    switch(playerTurn) {
        case WHITE: 
            playerTurn = BLACK; 
            break; 
        case BLACK:
            playerTurn = WHITE; 
            break; 
    }
}
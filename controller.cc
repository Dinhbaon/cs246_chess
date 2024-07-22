#include "controller.h"
#include "board.h"
#include "move.h"
#include <iostream>
#include "human.h"
#include <iostream>
#include "botLevel1.h"

Controller::Controller(Board* board): board{board} {}

char Controller::getState(int row, int col) const {
    return board->charAt(row, col);
}

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

    board->movePiece(move, color); 

    if (this->checkPromotion()) {
        this->getPlayerTurn()->handlePromotion();
    }

    notifyObservers(); 
    switchTurn(); 
}

bool Controller::isValidMove(Move move, Color color) const {
    int fromX = move.start.getX(); 
    int fromY = move.start.getY();

    int toX = move.start.getX(); 
    int toY = move.start.getY(); 
    Square* startSquare = this->board->getSquare(fromX, fromY); 
    if (board->isInCheck(color)) return false; 
    if (board->isPiecePinned(move.start, color)) return false; 
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
    } else if (player == "computer1"){
        switch(color){
            case WHITE: 
                whitePlayer = new BotLevel1(WHITE, this->board); 
                break; 
            case BLACK: 
                blackPlayer = new BotLevel1(BLACK, this->board); 
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

void Controller::switchTurn() {
    switch(playerTurn) {
        case WHITE: 
            playerTurn = BLACK; 
            std::cout << "It is now Blacks turn to move" << std::endl; 
            break; 
        case BLACK:
            playerTurn = WHITE; 
            std::cout << "It is now Whites turn to move" << std::endl; 
            break; 
    }
}

bool Controller::checkPromotion() const {
    Move lastMove = board->getLastMove(); 
    Piece* piece = board->getSquare(lastMove.end.getX(), lastMove.end.getY())->getPiece(); 
    if (piece->getPieceType() == PAWN) {
        switch(piece->getColor()) {
            case WHITE: 
                if (lastMove.end.getY() == 7) {
                    return true; 
                }
                break; 
            case BLACK: 
                if (lastMove.end.getY() == 0) {
                    return true; 
                }
        }
    }
    return false; 
    
}

void Controller::setPlayerTurn(Color color) {
    playerTurn = color;
}

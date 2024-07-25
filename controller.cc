#include "controller.h"
#include "board.h"
#include "move.h"
#include <iostream>
#include "human.h"
#include <iostream>
#include "botLevel1.h"
#include "botLevel2.h"
#include "botLevel3.h"

Controller::Controller(Board* board): board{board} {

}

char Controller::getState(int col, int row) const {
    return board->charAt(col, row);
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
    
    if (board->isMoveEnpassent(move)) {
        isEnpassent = true; 
    } else {
        isEnpassent = false; 
    }
    if (board->isMoveCastle(move)) {
        isCastle = true;
    } else {
        isCastle = false;
    }

    board->movePiece(move, color); 

    

    if (this->checkPromotion()) {
        this->getPlayerTurn()->handlePromotion();
    }

    notifyObservers(move); 
    
    switchTurn(); 
}

bool Controller::isValidMove(Move move, Color color) const {
    int fromX = move.start.getX(); 
    int fromY = move.start.getY();

    int toX = move.end.getX(); 
    int toY = move.end.getY(); 
    Square* startSquare = this->board->getSquare(fromX, fromY); 
    if (startSquare->isEmpty()) return false; 
    if (color != startSquare->getPiece()->getColor()) return false;
    if (board->isCheckAfterMove(move, color)) return false;  
    Piece* piece = this->board->getSquare(fromX, fromY)->getPiece(); 
    return piece->canMove(move, *this->board); 
}

Color Controller::getPlayerColor() const {
    return playerTurn; 
}

void Controller::setPlayers(Color color, std::string player) {
    if (player == "Human" || player == "human") {
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
    } else if (player == "computer2"){
        switch(color){
            case WHITE: 
                whitePlayer = new BotLevel2(WHITE, this->board); 
                break; 
            case BLACK: 
                blackPlayer = new BotLevel2(BLACK, this->board); 
                break; 
        }
    } else if (player == "computer3"){
        switch(color){
            case WHITE: 
                whitePlayer = new BotLevel3(WHITE, this->board); 
                break; 
            case BLACK: 
                blackPlayer = new BotLevel3(BLACK, this->board); 
                break; 
        }
    }

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
    if (piece != nullptr && piece->getPieceType() == PAWN) {
        if (lastMove.end.getY() == 7 || lastMove.end.getY() == 0) {
            return true; 
        }
    }
    return false; 
    
}

void Controller::reset(Board* board) {
    setBoard(board);
    setMode(START);
    whitePlayer = nullptr; 
    blackPlayer = nullptr; 
    playerTurn = WHITE; 
}

void Controller::setMode(Mode mode) {
    this->mode = mode; 
}

Mode Controller::getMode() const {
    return mode; 
}

void Controller::setPlayerTurn(Color color) {
    playerTurn = color;
}


Square * Controller::getSquare(const int x, const int y) const {
    return board->getSquare(x, y);
}

bool Controller::getIsEnpassent() const {
    return isEnpassent; 
}

bool Controller::getIsCastle() const {
    return isCastle;
}

Move Controller::getLastMove() const {
    return board->getLastMove(); 
}


void Controller::setBoard(Board* board) {
    this->board = board;
}

void Controller::emptyBoard() {
    board->emptyBoard();
}

bool Controller::checkPawnEdgeRows() const {
    return board->checkPawnEdgeRows();
}

Square *Controller::getEmptySquare() const {
    return board->getEmptySquare();
}


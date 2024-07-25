#include "historyservice.h"
#include "move.h"
#include <iostream>

HistoryService::HistoryService(Controller* controller, std::shared_ptr<Board> board) 
    : controller{controller}, currBoard{board}, currIndex{0} {
    boardHistory.emplace_back(*board); 

}

void HistoryService::notify(Move move) {
    // Remove future board states if currIndex is not at the end
    if (currIndex < boardHistory.size() - 1) {
        boardHistory.erase(boardHistory.begin() + currIndex + 1, boardHistory.end());
    }
    currIndex++;
    Board newBoard{*currBoard};
    boardHistory.emplace_back(newBoard);
}

void HistoryService::initNotify() {
    return ; 
}

Board HistoryService::getCurrBoard() const {
    return boardHistory.at(currIndex); 
}

void HistoryService::undo() {
    if (currIndex > 0) {
        currIndex--;
        Move controllerLastMove = controller->getLastMove(); 
        std::shared_ptr<Board> newBoard = std::make_shared<Board>(getCurrBoard()); 
        controller->setBoard(newBoard); 
        currBoard = newBoard; 
        controller->notifyObservers(Move{controllerLastMove.end, controllerLastMove.start}, true); 
        controller->switchTurn(); 
    } else {
        std::cout << "Nothing to undo" << std::endl; 
    }
}

void HistoryService::redo() {
    if (currIndex < boardHistory.size() - 1) {
        currIndex++; 
        Move controllerLastMove = controller->getLastMove(); 
        std::shared_ptr<Board> newBoard = std::make_shared<Board>(getCurrBoard()); 
        controller->setBoard(newBoard); 
        currBoard = newBoard; 
        controller->notifyObservers(Move{controllerLastMove.start, controllerLastMove.end}), true; 
        controller->switchTurn();
    } else {
        std::cout << "Nothing to redo" << std::endl; 
    }
}


void HistoryService::reset(std::shared_ptr<Board> board) {
    boardHistory.clear(); 
    currIndex = 0; 
    boardHistory.emplace_back(*board); 
}

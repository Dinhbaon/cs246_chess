#include "historyservice.h"
#include "move.h"

HistoryService::HistoryService(Controller* controller, Board* board): controller{controller}, currBoard{board} {
    boardHistory.emplace_back(*board); 
    controller->attach(this); 
}

void HistoryService::notify(Move move) {
    if (!(move.end == lastMove.start && move.start == lastMove.end)) {
        // Remove future board states if currIndex is not at the end
        if (currIndex < boardHistory.size() - 1) {
            boardHistory.erase(boardHistory.begin() + currIndex + 1, boardHistory.end());
        }

        Board newBoard{*currBoard};
        boardHistory.emplace_back(newBoard); 
        currIndex++; 
        setLastMove(move); 
    }
}

void HistoryService::initNotify() {
    // Implementation here if needed
}

Board HistoryService::getCurrBoard() const {
    return boardHistory.at(currIndex); 
}

void HistoryService::undo() {
    if (currIndex > 0) {  
        currIndex--; 
    } else {
        return ; 
    }
    Move controllerLastMove = controller->getLastMove(); 
    controller->setBoard(new Board{getCurrBoard()}); 
    setLastMove(controllerLastMove); 
    controller->notifyObservers(Move{controllerLastMove.end, controllerLastMove.start}); 
    controller->switchTurn(); 
}

void HistoryService::setLastMove(Move move) {
    lastMove = move; 
}

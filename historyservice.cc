#include "historyservice.h"
#include "move.h"
#include <iostream>

HistoryService::HistoryService(Controller* controller, Board* board) 
    : controller{controller}, currBoard{board}, currIndex{0}, notificationsEnabled{true} {
    boardHistory.emplace_back(*board); 
    controller->attach(this); 
}

void HistoryService::notify(Move move) {
    if (notificationsEnabled) {
        // Remove future board states if currIndex is not at the end

        if (currIndex < boardHistory.size() - 1) {
            boardHistory.erase(boardHistory.begin() + currIndex + 1, boardHistory.end());
        }
        currIndex++;
        // Create a new board state based on the current board
        Board newBoard{*currBoard};
        boardHistory.emplace_back(newBoard);
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
        notificationsEnabled = false; // Disable notifications
        currIndex--;
        Move controllerLastMove = controller->getLastMove(); 
        Board* newBoard = new Board{getCurrBoard()}; 
        controller->setBoard(newBoard); // Directly set the current board state from history
        currBoard = newBoard; 
        setLastMove(Move{controllerLastMove.end, controllerLastMove.start}); // Swap move for undo
        controller->notifyObservers(Move{controllerLastMove.end, controllerLastMove.start}); 
        controller->switchTurn(); 
        notificationsEnabled = true; // Re-enable notifications
    } else {
        std::cout << "Nothing to undo" << std::endl; 
    }
}

void HistoryService::redo() {
    if (currIndex < boardHistory.size() - 1) {
        notificationsEnabled = false; // Disable notifications
        currIndex++; 
        Move controllerLastMove = controller->getLastMove(); 
        Board* newBoard = new Board{getCurrBoard()}; 
        controller->setBoard(newBoard); // Directly set the current board state from history
        currBoard = newBoard; 
        setLastMove(Move{controllerLastMove.start, controllerLastMove.end}); // Use the original move for redo
        controller->notifyObservers(Move{controllerLastMove.start, controllerLastMove.end}); 
        controller->switchTurn();
        notificationsEnabled = true; // Re-enable notifications
    } else {
        std::cout << "Nothing to redo" << std::endl; 
    }
}

void HistoryService::setLastMove(Move move) {
    lastMove = move; 
}

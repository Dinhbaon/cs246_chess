#ifndef HISTORYSERVICE_H
#define HISTORYSERVICE_H

#include "observer.h"
#include "board.h"
#include "controller.h"
#include <vector>

class HistoryService: public Observer {
    int currIndex = 0; 
    Controller* controller; 
    Board* currBoard; 
    std::vector<Board> boardHistory; 
    Move lastMove; 
    bool notificationsEnabled; 

    void setLastMove(Move move); 
    public:
        explicit HistoryService(Controller* controller, Board* board); 
        void notify(Move move) override;
        void initNotify() override;
        Board getCurrBoard() const;
        void undo(); 
        void redo();
        void reset(Board* board); 


}; 

#endif
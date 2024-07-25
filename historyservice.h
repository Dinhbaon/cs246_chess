#ifndef HISTORYSERVICE_H
#define HISTORYSERVICE_H

#include "observer.h"
#include "board.h"
#include "controller.h"
#include <vector>
#include <memory>

class HistoryService: public Observer {
    int currIndex = 0; 
    Controller* controller; 
    std::shared_ptr<Board> currBoard; 
    std::vector<Board> boardHistory; 
    Move lastMove; 
    bool notificationsEnabled; 

    void setLastMove(Move move); 
    public:
        explicit HistoryService(Controller* controller, std::shared_ptr<Board> board); 
        void notify(Move move) override;
        void initNotify() override;
        Board getCurrBoard() const;
        void undo(); 
        void redo();
        void reset(std::shared_ptr<Board> board);  


}; 

#endif
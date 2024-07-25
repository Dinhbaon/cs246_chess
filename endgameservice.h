#ifndef EndGameService_H
#define EndGameService_H

#include "observer.h"
#include "controller.h"
#include <memory>

class EndGameService: public Observer {
    Controller *controller;
    std::shared_ptr<Board> board;
    bool isCheckMate; 
    bool isStaleMate;
    public:
        void notify(Move move) override;
        bool getIsCheckMate();
        bool getIsStaleMate();
        EndGameService(Controller *controller, std::shared_ptr<Board> board);
        void initNotify() override;
        void resetCheckMate();
        void resetStaleMate();
        void reset(std::shared_ptr<Board> board);
        ~EndGameService();
}; 

#endif
#ifndef EndGameService_H
#define EndGameService_H

#include "observer.h"
#include "controller.h"

class EndGameService: public Observer {
    Controller *controller;
    Board *board;
    bool isCheckMate; 
    public:
        void notify(Move move) override;
        bool getIsCheckMate();
        EndGameService(Controller *controller, Board *board);
        void initNotify() override;
        void resetCheckMate();
        ~EndGameService();
}; 

#endif
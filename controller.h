#ifndef CONTROLLER_H 
#define CONTROLLER_H


#include "color.h"
#include "player.h"
#include "mode.h"
#include <string>

class Controller {
    Player* whitePlayer;
    Player* blackPlayer;  
    Board* board; 
    Color playerTurn = WHITE; 
    Mode mode; 
    bool isInGame;
    void notify();  

    public: 
        explicit Controller(Board* board); 
        void makeMove(Move move, Color color);
        void setPlayers(Color color, std::string player);
        void setMode(Mode mode); 
        bool getIsInGame() const; 
        void setIsInGame(bool isInGame); 
        Player* getPlayerTurn() const; 
};

#endif
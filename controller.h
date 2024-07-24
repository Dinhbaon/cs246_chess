#ifndef CONTROLLER_H 
#define CONTROLLER_H


#include "color.h"
#include "player.h"
#include "mode.h"
#include <string>
#include "subject.h"

class Controller: public Subject {
    Player* whitePlayer;
    Player* blackPlayer;  
    Board* board;
    Color playerTurn = WHITE; 
    Mode mode = START; 
    bool isInGame; 
    void switchTurn(); 

    public: 
        Square *getSquare(const int x, const int y) const;
        char getState(int col, int row) const override;
        explicit Controller(Board* board); 
        bool checkPromotion() const;  
        void makeMove(Move move, Color color);
        void setPlayers(Color color, std::string player);
        void setMode(Mode mode); 
        Mode getMode() const;
        bool getIsInGame() const; 
        bool isValidMove(Move move, Color color) const; 
        void setIsInGame(bool isInGame); 
        Player* getPlayerTurn() const; 
        Color getPlayerColor() const;
        void setPlayerTurn(Color color); 
};

#endif
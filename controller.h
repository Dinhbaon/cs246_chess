#ifndef CONTROLLER_H 
#define CONTROLLER_H


#include "color.h"
#include "player.h"
#include "mode.h"
#include <string>
#include <map>
#include "subject.h"
#include <memory>

class Controller: public Subject {
    std::shared_ptr<Player>  whitePlayer;
    std::shared_ptr<Player> blackPlayer;  
    std::shared_ptr<Board> board;
    Color playerTurn = WHITE; 
    Mode mode = START; 
    bool isEnpassent; 
    bool isCastle;


    public: 
        std::map<const Color, float> score;
        std::shared_ptr<Square>getSquare(const int x, const int y) const;
        std::shared_ptr<Square>getEmptySquare() const;
        void switchTurn();
        char getState(int col, int row) const override;
        explicit Controller(std::shared_ptr<Board> board); 
        bool checkPromotion() const;  
        void makeMove(Move move, Color color);
        void emptyBoard();     
        void handleGameEnd(std::shared_ptr<Board> board); 
        // Getters and setters
        void setPlayers(Color color, std::string player);
        void setMode(Mode mode); 
        Mode getMode() const;
        bool getIsInGame() const; 
        bool isValidMove(Move move, Color color) const; 
        bool checkPawnEdgeRows() const;
        void setIsInGame(bool isInGame); 
        std::shared_ptr<Player>  getPlayerTurn() const; 
        Color getPlayerColor() const;
        void setPlayerTurn(Color color); 
        bool getIsEnpassent() const; 
        bool getIsCastle() const; 
        Move getLastMove() const;  
        void setBoard(std::shared_ptr<Board> board);  
        std::shared_ptr<Board> getBoard() const;  
        
        
};

#endif
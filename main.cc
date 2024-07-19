#include "board.h"
#include "controller.h"
#include "mode.h"
#include <iostream>

int main() {

    Board* board; 
    Controller Controller{board}; 
    std::string command;


    while (std::cin >> command) {
        if (command == "game") {
            std::string whitePlayer, blackPlayer; 
            std::cin >> whitePlayer >> blackPlayer; 

            Controller.setPlayers(BLACK, blackPlayer); 
            Controller.setPlayers(WHITE, whitePlayer);
            Controller.setMode(GAME); 
            
        } else if (command == "resign") {
            if (Controller.getIsInGame()) {

            } else {
                
            }
        } else if (command == "move") {
            // If not in game throw error
            if (Controller.getIsInGame()) {

                // If Human then read input and make the move
                if (Controller.getPlayerTurn()->getIsHuman()) {
                    Controller.
                } else {

                }

            }
        } else if (command == "undo") {
        }
    }
}
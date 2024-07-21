#include "board.h"
#include "controller.h"
#include "mode.h"
#include "move.h"
#include <iostream>

int main() {

    Board* board = new Board(); 
    Controller controller{board}; 
    std::string command;


    while (std::cin >> command) {
        if (command == "game") {
            if (controller.getMode() == GAME) {
                std::cout << "Alreading in a game - resign to end the game";
            } else {
                std::string whitePlayer, blackPlayer; 
                std::cin >> whitePlayer >> blackPlayer; 

                controller.setPlayers(BLACK, blackPlayer); 
                controller.setPlayers(WHITE, whitePlayer);
                controller.setMode(GAME); 
            }

            
        } else if (command == "resign") {
            if (controller.getIsInGame()) {

            } else {
                
            }
        } else if (command == "move") {
        
            // If not in game throw error
            if (controller.getMode() == GAME) { 
                Move move; 
                // If Human then read input and make the move
                if (controller.getPlayerTurn()->getIsHuman()) {
                    
                    move = controller.getPlayerTurn()->getNextMove();
                    // If not valid then try again
                    if (!controller.isValidMove(move, controller.getPlayerColor())) {
                        std::cout << "Invalid move re-enter a valid move" << std::endl; 
                        continue; 
                    }

                } else {
                    move = controller.getPlayerTurn()->getNextMove(); 
                }


                controller.makeMove(move, controller.getPlayerColor()); 


            } else {
                std::cout << "Not in Game - Use game [Human/Computer[1-4]] to start one" << std::endl; 
            }
        } else if (command == "undo") {

        } else if (command == "setup") {
            controller.setMode(SETUP); 
        }
    }
}
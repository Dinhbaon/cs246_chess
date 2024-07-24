#include "board.h"
#include "controller.h"
#include "mode.h"
#include "move.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "text.h"
#include "graphic.h"
#include "historyservice.h"
#include <iostream>
#include <string>

int main() {

    Board* board = new Board(); 
    Controller controller{board}; 
    HistoryService* historyService = new HistoryService{&controller, board};
    std::string command;
    std::vector<Observer*> observers;
    observers.emplace_back(new Text{&controller});
    observers.emplace_back(historyService); 
    observers.emplace_back(new Graphic{&controller});
    controller.printInit();


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
            historyService->undo(); 
        } else if (command == "setup") {
            if (controller.getMode() == GAME) {
                std::cout << "Can't enter setup mode when in game mode." << std::endl;
                continue;
            }

            std::cout << "setup command" << std::endl;
            controller.setMode(SETUP); 
            while (std::cin >> command) {
                Color c = BLACK;
                PieceType pt = ROOK;
                std::string s;
                if (command == "done") {
                    if (!(board->oneKing(WHITE) && board->oneKing(BLACK))) {
                        std::cout << "There are two Kings of the same color on the board \
                                      - cannot exit setup mode until one King of each color \
                                      are on the board." << std::endl;
                    } else if (board->isInCheck(WHITE) || board->isInCheck(BLACK)) {
                        std::cout << "A Knight is in check - cannot exit setup \
                                      mode until both Knights are not in check." << std::endl; 
                    } else if (controller.checkPromotion()) {
                        std::cout << "There is a pawn in the first or last rows of the board \
                                      - cannot exit setup mode until there are no pawns in \
                                      either the first or last rows of the board." << std::endl;
                    } else {
                        controller.setMode(START);
                        controller.printInit();
                        break;
                    }
                } else if (command == "+") {
                    if (std::cin >> command) {
                        if (command == "R") {
                            c = WHITE;
                            pt = ROOK;
                        } else if (command == "N") {
                            c = WHITE;
                            pt = KNIGHT;
                        } else if (command == "B") {
                            c = WHITE;
                            pt = BISHOP;
                        } else if (command == "Q") {
                            c = WHITE;
                            pt = QUEEN;
                        } else if (command == "K") {
                            c = WHITE;
                            pt = KING;
                        } else if (command == "P") {
                            c = WHITE;
                            pt = PAWN;
                        } else if (command == "r") {
                            pt = ROOK;
                        } else if (command == "n") {
                            pt = KNIGHT;
                        } else if (command == "b") {
                            pt = BISHOP;
                        } else if (command =="q") {
                            pt = QUEEN;
                        } else if (command == "k") {
                            pt = KING;
                        } else if (command == "p") {
                            pt = PAWN;
                        }
                        std::string src;
                        std::cin >> src; 

                        int xIndex = src[0] - 'a'; 
                        int yIndex = src[1] - '0' - 1; 

                        if (!((board->getSquare(xIndex, yIndex))->isEmpty())) {
                            delete (board->getSquare(xIndex, yIndex))->getPiece();
                            board->getSquare(xIndex, yIndex)->setPiece(nullptr);
                        }
        
                        if (pt == ROOK) {
                            board->setSquare(xIndex, yIndex, new Rook(c));
                        } else if (pt == KNIGHT) {
                            board->setSquare(xIndex, yIndex, new Knight(c));
                        } else if (pt == BISHOP) {
                            board->setSquare(xIndex, yIndex, new Bishop(c));
                        } else if (pt == QUEEN) {
                            board->setSquare(xIndex, yIndex, new Queen(c));
                        } else if (pt == KING) {
                            board->setSquare(xIndex, yIndex, new King(c));
                        } else {
                            board->setSquare(xIndex, yIndex, new Pawn(c));
                        }
                        
                    }
                } else if (command == "-") {
                    std::string src;
                    std::cin >> src; 

                    int xIndex = src[0] - 'a'; 
                    int yIndex = src[1] - '0' - 1; 

                    delete (board->getSquare(xIndex, yIndex))->getPiece();
                    board->getSquare(xIndex, yIndex)->setPiece(nullptr);

                } else { // command == "="
                    std::cin >> s;
                    if (s == "black" || "b" || "B") {
                        c = BLACK;
                    } else {
                        c = WHITE;
                    }
                    controller.setPlayerTurn(c);
                }
                
            }
        } 
    }
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        delete *it;
    }
}
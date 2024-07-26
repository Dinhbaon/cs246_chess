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
#include "endgameservice.h"
#include <memory>

int main() {

    std::shared_ptr<Board> board{new Board}; 
    Controller controller{board}; 
    std::shared_ptr<HistoryService> historyService = std::make_unique<HistoryService>(&controller, board);
    std::string command;
    std::shared_ptr<EndGameService>endGame =  std::make_unique<EndGameService>(&controller, board);
    std::shared_ptr<Text> text = std::make_unique<Text>(&controller); 
    std::shared_ptr<Graphic> graphic = std::make_unique<Graphic>(&controller); 

    bool setUpInGame = true; 
    controller.attach(graphic);
    controller.attach(historyService); 
    controller.attach(text);
    controller.attach(endGame); 

    while (std::cin >> command) {
        bool came_from_setup = false;
        if (command == "game") {
            if (!came_from_setup) {
                controller.printInit();
            }
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
            if (controller.getMode() == GAME) {
                std::shared_ptr<Board> newBoard{new Board()}; 
                std::cout <<  controller.getPlayerColor() +" Resigned - use game command to start a new game" << std::endl << std::flush;
                if (controller.getPlayerColor() == WHITE) {
                    controller.score.at(BLACK) += 1; 
                    std::cout << " Black Wins!" << std::endl;
                } else {
                    controller.score.at(WHITE) += 1; 
                    std::cout << " White Wins!" << std::endl;
                }
                
                endGame->reset(newBoard);
                controller.handleGameEnd(newBoard); 
                historyService->reset(newBoard); 
                
    
                continue; 
            } else {
                std::cout << "" <<std::endl; 
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
                if(endGame->getIsCheckMate()) {
                    std::shared_ptr<Board> newBoard{new Board()}; 
                    controller.score.at(controller.getPlayerColor()) += 1; 
                    std::cout << "Checkmate!" << std::endl << std::flush;
                    if (controller.getPlayerColor() == WHITE) {
                        std::cout << "White Wins!" << std::endl;
                    } else {
                        std::cout << "Black Wins!" << std::endl;
                    }
                    endGame->reset(newBoard);
                    controller.handleGameEnd(newBoard); 
                    historyService->reset(newBoard); 


                    continue;
                } else if(endGame->getIsStaleMate()) {
                    controller.score.at(WHITE) += 0.5; 
                    controller.score.at(BLACK) += 0.5; 
                    std::shared_ptr<Board> newBoard{new Board()};  
                    endGame->reset(newBoard);
                    controller.handleGameEnd(newBoard); 
                    historyService->reset(newBoard);   
                    std::cout << "Stalemate!" << std::endl << std::flush;

                    continue;
                }
                controller.switchTurn(); 
                if (controller.isInCheck(controller.getPlayerColor())) {
                    if (controller.getPlayerColor() == WHITE) {
                        std::cout << "White is in check." << std::endl; 
                    } else {
                        std:: cout << "Black is in check." << std::endl; 
                    }
                }

            } else {
                std::cout << "Not in Game - Use game [Human/Computer[1-4]] to start one" << std::endl; 
            }
        } else if (command == "undo") {
            if (controller.getMode() == GAME) {
                historyService->undo(); 
            } 
        } else if (command == "redo") {
            if (controller.getMode() == GAME) {
                historyService->redo();
            }
             
        } else if (command == "setup") {
            came_from_setup = true;
            controller.emptyBoard();
            controller.printInit();
            if (controller.getMode() == GAME) {
                std::cout << "Can't enter setup mode when in game mode." << std::endl;
                continue;
            }
            controller.setMode(SETUP); 
            while (std::cin >> command) { 
                Color c = BLACK;
                PieceType pt = ROOK;
                std::string s;
                if (command == "done") {
                    if (!(controller.oneKing(WHITE) && controller.oneKing(BLACK))) {
                        std::cout << "There is not one King of each color on the board " \
                                      "- cannot exit setup mode until one King of each color " \
                                      "are on the board." << std::endl;
                    } else if (controller.isInCheck(WHITE) || controller.isInCheck(BLACK)) {
                        std::cout << "A King is in check - cannot exit setup " \
                                      "mode until both Kings are not in check." << std::endl; 
                    } else if (controller.checkPawnEdgeRows()) {
                        std::cout << "There is a pawn in the first or last rows of the board "\
                                      "- cannot exit setup mode until there are no pawns in "\
                                      "either the first or last rows of the board." << std::endl;
                    } else {

                        controller.setMode(START);
                    
                        if (controller.getPlayerColor() == WHITE) {
                            std::cout << "It is now Whites turn to move" << std::endl; 
                        } else {
                            std::cout << "It is now Blacks turn to move" << std::endl; 
                        }
                        historyService->reset(board); 
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

                        if (!((controller.getSquare(xIndex, yIndex))->isEmpty())) {
                            controller.getSquare(xIndex, yIndex)->setPiece(nullptr);
                        }
        
                        if (pt == ROOK) {
                            controller.setSquare(xIndex, yIndex,  std::make_shared<Rook>(c));
                        } else if (pt == KNIGHT) {
                            controller.setSquare(xIndex, yIndex, std::make_shared<Knight>(c));
                        } else if (pt == BISHOP) {
                            controller.setSquare(xIndex, yIndex, std::make_shared<Bishop>(c));
                        } else if (pt == QUEEN) {
                            controller.setSquare(xIndex, yIndex, std::make_shared<Queen>(c));
                        } else if (pt == KING) {
                            controller.setSquare(xIndex, yIndex, std::make_shared<King>(c));
                        } else {
                            controller.setSquare(xIndex, yIndex, std::make_shared<Pawn>(c));
                        }
                        controller.notifyObservers(Move{*(controller.getEmptySquare()), *(controller.getSquare(xIndex ,yIndex))}, true);
                    }
                } else if (command == "-") {
                    std::string src;
                    std::cin >> src; 

                    int xIndex = src[0] - 'a'; 
                    int yIndex = src[1] - '0' - 1; 

                    controller.getSquare(xIndex, yIndex)->setPiece(nullptr);

                    controller.notifyObservers(Move{*(controller.getEmptySquare()), *(controller.getSquare(xIndex ,yIndex))}, true);

                } else if (command == "=") { // command == "="
                    std::cin >> s;
                    if (s == "black" || s == "b" || s == "B") {
                        c = BLACK;
                    } else if (s == "white" || s == "w" || s == "W") {
                        c = WHITE;
                    }
                    controller.setPlayerTurn(c);
                }
                
            }
        } 
    }


    std::cout << "Final Score" << std::endl; 
    std::cout << "White: " << controller.score[WHITE] << std::endl; 
    std::cout << "Black: " << controller.score[BLACK] << std::endl;  
}
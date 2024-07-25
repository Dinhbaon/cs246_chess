#include "human.h"
#include "move.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include <string>    
#include <iostream>

Human::Human(Color color, std::shared_ptr<Board> board): Player{color, board} {}


bool Human::getIsHuman() const {
    return true; 
}

Move Human::getNextMove() const {
    std::string src, dest; 
    std::cin >> src >> dest; 

    int xSrcIndex = src[0] - 'a'; 
    int ySrcIndex = src[1] - '0' - 1;  

    Square srcSquare = Square{xSrcIndex, ySrcIndex}; 

    int xDestIndex = dest[0] - 'a'; 
    int yDestIndex = dest[1] - '0' - 1;  

    Square destSquare = Square{xDestIndex, yDestIndex}; 

    return Move{srcSquare, destSquare}; 
}

void Human::handlePromotion() {
    std::string newPiece; 
    std::cout << "Choose a piece to promote your pawn to (Q(ueen), B(ishop), K(night), R(ook))" <<std::endl;
    std::cin >> newPiece; 
    std::shared_ptr<Piece> piece; 
    while (true) {
        if (newPiece == "Q") {
            piece = std::make_shared<Queen>(color);
            break; 
        } else if (newPiece == "R") {
            piece =  std::make_shared<Rook>(color); 
            break; 
        } else if (newPiece == "B") {
            piece = std::make_shared<Bishop>(color);
            break;  
        } else if (newPiece == "K") {
            piece = std::make_shared<Knight>(color); 
            break; 
        } else {
            std::cout << "Invalid selection" << std::endl; 
            continue; 
        }
    } 
    std::cin >> newPiece; 


    Move lastMove = board->getLastMove(); 

    board->setSquare(lastMove.end.getX(), lastMove.end.getY(), piece); 
}
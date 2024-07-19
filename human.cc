#include "human.h"
#include "move.h"
#include <string>    
#include <iostream>

Human::Human(Color color, Board* board): Player{color, board} {}


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
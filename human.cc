#include "human.h"
#include "move.h"
#include <string>    
#include <iostream>

bool Human::getIsHuman() const {
    return true; 
}

Move Human::getNextMove() const {
    std::string src, dest; 
    std::cin >> src >> dest; 

    int xSrcIndex = src[0] - 'a'; 

    int ySrcIndex = std::stoi(src[1]); 

    Square srcSquare = Square{xSrcIndex, ySrcIndex}; 

    int xDestIndex = dest[0] - 'a'; 

    int yDestIndex = std::stoi(dest[1]); 

    Square destSquare = Square{xDestIndex, yDestIndex}; 

    return Move{srcSquare, destSquare}; 

}
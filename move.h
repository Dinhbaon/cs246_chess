#ifndef MOVE_H
#define MOVE_H

#include "square.h"
#include "piece.h"

struct Move {
    Square start; 
    Square end; 
};

#endif
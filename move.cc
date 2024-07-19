#include "move.h"

Move::Move(Square src, Square dest) : start{src}, end{dest} {}

Move& Move::operator=(const Move& other) {
    if (this == &other) {
        return *this; 
    }
    start = other.start;
    end = other.end;
    return *this;
}
#include "piece.h"
#include <vector>
#include <memory>

class Square {
        const int x;
        const int y;
        Piece piece;
    public:
        Piece &getPiece();
        std::vector<int> getCoords();
};
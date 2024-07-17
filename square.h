#ifndef SQUARE_H
#define SQUARE_H

#include <vector>


class Piece;

class Square {
        const int x;
        const int y;
        Piece* piece;
    public:
        Square(int x, int y, Piece* piece = nullptr); 
        Piece* getPiece();
        void setPiece(Piece* piece); 
        std::vector<int> getCoords();
        int getX() const; 
        int getY() const; 
        bool isEmpty() const; 
};

#endif


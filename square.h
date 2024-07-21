#ifndef SQUARE_H
#define SQUARE_H

#include <vector>


class Piece;

class Square {
    int x;
    int y;
    Piece* piece;
    public:
        char charAt(int row, int col);
        Square(int x = 0, int y = 0, Piece* piece = nullptr); 
        Square& operator=(const Square& other); 
        Piece* getPiece() const;
        void setPiece(Piece* piece); 
        std::vector<int> getCoords();
        int getX() const; 
        int getY() const; 
        bool isEmpty() const; 
};

#endif


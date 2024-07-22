#ifndef SQUARE_H
#define SQUARE_H

#include <vector>


class Piece;

class Square {
    int x;
    int y;
    int const dim = 8;
    bool black;
    Piece* piece;
    public:
        char charAt(int col, int row);
        Square(int x = 0, int y = 0, Piece* piece = nullptr); 
        Square& operator=(const Square& other); 
        Square(const Square& square); 
        Piece* getPiece() const;
        void setPiece(Piece* piece); 
        std::vector<int> getCoords();
        int getX() const; 
        int getY() const; 
        bool isEmpty() const; 
        bool isBlack();
};

#endif


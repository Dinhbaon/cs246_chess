#ifndef SQUARE_H
#define SQUARE_H

#include <vector>
#include <memory>


class Piece;

class Square {
    int x;
    int y;
    int const dim = 8;
    bool black;
    std::shared_ptr<Piece> piece;
    public:
        char charAt(int col, int row);
        Square(int x = 0, int y = 0, std::shared_ptr<Piece> piece = nullptr); 
        Square& operator=(const Square& other); 
        bool operator==(const Square& other); 
        Square(const Square& square); 
        std::shared_ptr<Piece> getPiece() const;
        void setPiece(std::shared_ptr<Piece> piece); 
        std::vector<int> getCoords();
        int getX() const; 
        int getY() const; 
        bool isEmpty() const; 
        bool isBlack();
};

#endif


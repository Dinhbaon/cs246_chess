#include "board.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "move.h"

#include <stdexcept>

Square* Board::getSquare(const int x, const int y) const {
    if (x < 0 || x >= xDimension || y < 0 || y >= yDimension) {
        return nullptr;
    }
    return board[y * xDimension + x];
}

void Board::setSquare(int x, int y, Square* square) {
    if (x >= 0 && x < xDimension && y >= 0 && y < yDimension) {
        board[y * xDimension + x]->setPiece(square->getPiece());
    } else {
        throw std::invalid_argument( "Inputted square not on board" );
    }
}

void Board::movePiece(Move move, Color color) {
    int fromX = move.start.getX();
    int fromY = move.start.getY();

    int toX = move.end.getX();
    int toY = move.end.getY();

    Piece* piece = this->getSquare(fromX, fromY)->getPiece();
    this->getSquare(fromX, fromY)->setPiece(nullptr);
    this->getSquare(toX, toY)->setPiece(piece);
    updateAllPieces();
}

Board::Board() {
    board.resize(xDimension * yDimension, nullptr);  

    for (int i = 0; i < xDimension; i++) {
        for (int j = 0; j < yDimension; j++) {
            board[j * xDimension + i] = new Square(i, j); // Place default Square
        }
    }

    this->setSquare(0, 0, new Square(0, 0, new Rook(WHITE)));
    this->setSquare(1, 0, new Square(1, 0, new Knight(WHITE)));
    this->setSquare(2, 0, new Square(2, 0, new Bishop(WHITE)));
    this->setSquare(3, 0, new Square(3, 0, new Queen(WHITE)));
    this->setSquare(4, 0, new Square(4, 0, new King(WHITE))); 
    this->setSquare(5, 0, new Square(5, 0, new Bishop(WHITE))); 
    this->setSquare(6, 0, new Square(6, 0, new Knight(WHITE))); 
    this->setSquare(7, 0, new Square(7, 0, new Rook(WHITE))); 

    for (int i = 0; i < xDimension; i++) {
        this->setSquare(i, 1, new Square(i, 1, new Pawn(WHITE))); 
    }

    this->setSquare(0, 7, new Square(0, 0, new Rook(BLACK)));
    this->setSquare(1, 7, new Square(1, 0, new Knight(BLACK)));
    this->setSquare(2, 7, new Square(2, 0, new Bishop(BLACK)));
    this->setSquare(3, 7, new Square(3, 0, new Queen(BLACK)));
    this->setSquare(4, 7, new Square(4, 0, new King(BLACK))); 
    this->setSquare(5, 7, new Square(5, 0, new Bishop(BLACK))); 
    this->setSquare(6, 7, new Square(6, 0, new Knight(BLACK))); 
    this->setSquare(7, 7, new Square(7, 0, new Rook(BLACK))); 
    
    for (int i = 0; i < xDimension; i++) {
        this->setSquare(i, 6, new Square(i, 6, new Pawn(BLACK))); 
    }

    updateAllPieces();
}

Board::~Board() {
    for (Square* square : board) {
        delete square->getPiece(); 
        delete square;  
    }
}

void Board::updateAllPieces() {
    std::vector<Piece*> blackPieces;
    std::vector<Piece*> whitePieces;

    for (Square* square : this->board) {
        if (square != nullptr) {
            Piece* piece = square->getPiece();
            if (piece != nullptr) {
                if (piece->getColor() == WHITE) {
                    whitePieces.emplace_back(piece);
                } else {
                    blackPieces.emplace_back(piece);
                }
            }
        }
    }

    allPieces[WHITE] = whitePieces;
    allPieces[BLACK] = blackPieces;
}

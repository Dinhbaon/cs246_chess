#include "board.h"
#include "move.h"
#include "piece.h"
#include "move.h"
#include <vector>

Square* Board::getSquare(const int x, const int y) const {
    if (xDimension * y +x > 63 || xDimension * y +x < 0) {
        return nullptr; 
    }
    return board[xDimension*y + x];
}

void Board::setSquare(int x, int y, Square* square) {
    this->getSquare(x, y)->setPiece(square->getPiece()); 
}

void Board::movePiece(Move move, Color color) {
    int fromX = move.start.getX(); 
    int fromY = move.start.getY();

    int toX = move.start.getX(); 
    int toY = move.start.getY(); 
    Piece* piece = this->getSquare(fromX, fromY)->getPiece(); 
    if (piece->canMove(move, *this)) {
        this->getSquare(fromX, fromY)->setPiece(nullptr);
        this->getSquare(toX, toY)->setPiece(piece);
    } 
    updateAllPieces(); 
}

Board::Board() {
    updateAllPieces(); 
} 


void Board::updateAllPieces() {
    std::vector<Piece*> blackPieces; 
    std::vector<Piece*> whitePieces; 

    for (Square* square: this->board) {
        if (square->getPiece()->getColor() == true) whitePieces.emplace_back(square->getPiece()); 

        if (square->getPiece()->getColor() == false) blackPieces.emplace_back(square->getPiece()); 

        allPieces[WHITE] = whitePieces; 
        allPieces[BLACK] = blackPieces; 

    }
}


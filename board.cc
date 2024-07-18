#include "board.h"
#include "move.h"
#include "piece.h"
#include <vector>

Square* Board::getSquare(const int x, const int y) const {
    if (xDimension * y +x > 63 || xDimension * y +x < 0) {
        return nullptr; 
    }
    return board[xDimension*y + x];
}

void Board::movePiece(const int fromX, const int fromY, const int toX, const int toY) {
    Piece* piece = this->getSquare(fromX, fromY)->getPiece(); 
    Move move{Square{fromX, fromY}, Square{toX, toY}};
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
    std::vector<Piece> blackPieces; 
    std::vector<Piece> whitePieces; 

    for (Square* square: this->board) {
        if (square->getPiece()->getIsWhite() == true) whitePieces.emplace_back(square->getPiece()); 

        if (square->getPiece()->getIsWhite() == false) blackPieces.emplace_back(square->getPiece()); 

        allPieces[WHITE] = whitePieces; 
        allPieces[BLACK] = blackPieces; 

    }
}


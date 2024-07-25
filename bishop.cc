#include "bishop.h"
#include "board.h" 
#include "move.h"
#include "square.h"
#include <stdlib.h> 


Bishop::Bishop(Color color) : Piece(color) {}

char Bishop::name() const {
    if (getColor() == BLACK) {
        return 'b';
    } else {
        return 'B';
    }
}

bool Bishop::canMove(const Move& move, const Board& board) const {
    // If not on diagonal, return false
    int dx = move.end.getX() - move.start.getX();
    int dy = move.end.getY() - move.start.getY(); 
    if (abs(dy) != abs(dx)) return false; 

    // Determine the direction of movement
    int stepX = (dx > 0) ? 1 : -1;
    int stepY = (dy > 0) ? 1 : -1;

    // Check for blocking pieces in the path (excluding the destination square)
    int iterX = move.start.getX() + stepX;
    int iterY = move.start.getY() + stepY;
    while (iterX != move.end.getX() || iterY != move.end.getY()) {
        std::shared_ptr<Square> iterSquare = board.getSquare(iterX, iterY);
        if (iterSquare == nullptr || !iterSquare->isEmpty()) return false;
        iterX += stepX;
        iterY += stepY;
    }

    // Check if the final square is empty or contains an opponent's piece
    std::shared_ptr<Square> endSquare = board.getSquare(move.end.getX(), move.end.getY());
    return endSquare == nullptr || endSquare->isEmpty() || endSquare->getPiece()->getColor() != getColor();
}


bool Bishop::canCapture(const Move& move, const Board& board) const {
    return canMove(move, board); 
}

PieceType Bishop::getPieceType() const {
    return BISHOP; 
}


std::shared_ptr<Piece> Bishop::copy() const {
    return  std::make_shared<Bishop>(*this); 
}
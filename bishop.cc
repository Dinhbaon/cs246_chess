#include "bishop.h"
#include "board.h" 
#include "move.h"
#include "square.h"
#include <stdlib.h> 

Bishop::Bishop(Color color) : Piece(color) {}

bool Bishop::canMove(const Move& move, const Board& board) const {
    // If not on diagonal return false
    int dx = move.end.getX() - move.start.getX();
    int dy = move.end.getY() - move.start.getY(); 
    if (abs(dy / dx) != 1) return false; 

    // Determine the direction of movement
    int stepX = (dx > 0) ? 1 : -1;
    int stepY = (dy > 0) ? 1 : -1;

    // Check for blocking pieces
    int iterX = move.start.getX();
    int iterY = move.start.getY();
    while (iterX != move.end.getX() || iterY != move.end.getY()) {
        iterX += stepX;
        iterY += stepY;

        Square* iterSquare = board.getSquare(iterX, iterY);
        if (iterSquare == nullptr || iterSquare->isEmpty()) return false;
    }

    // Check if final square is friendly piece
    Square* endSquare = board.getSquare(move.end.getX(), move.end.getY());
    return endSquare == nullptr || endSquare->isEmpty() || endSquare->getPiece()->getColor() != getColor();
}

PieceType Bishop::getPieceType() const {
    return BISHOP; 
}

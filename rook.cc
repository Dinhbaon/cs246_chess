#include "rook.h"
#include "board.h" 
#include "move.h"
#include "square.h"
#include <stdlib.h> 

Rook::Rook(bool isWhite) : Piece(isWhite) {}

bool Rook::canMove(const Move& move, const Board& board) const {
    // If not on diagonal return false
    int dx = move.end.getX() - move.start.getX();
    int dy = move.end.getY() - move.start.getY(); 
    if (dy != 0 && dx != 0) return false; 

    // Check if any pieces blocking path
    int iterX = move.start.getX(); 
    int iterY = move.start.getY(); 
    while (iterX != move.end.getX() || iterY != move.end.getY()) {
        iterX += (dx == 0) ? 0 : 1;
        iterY += (dy == 0) ? 0 : 1;
        Square* iterSquare = board.getSquare(iterX, iterY); 
        if (iterSquare == nullptr || !iterSquare->isEmpty()) return false; 
    }

    // Check if final square is friendly piece
    Square* endSquare = board.getSquare(move.end.getX(), move.end.getY());
    return endSquare == nullptr || endSquare->isEmpty() || endSquare->getPiece()->getIsWhite() != getIsWhite();
}

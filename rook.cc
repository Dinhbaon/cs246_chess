#include "rook.h"
#include "move.h"
#include "board.h"

Rook::Rook(Color color) : Piece(color) {}

char Rook::name() const {
    if (getColor() == BLACK) {
        return 'r';
    } else {
        return 'R';
    }
}

bool Rook::canMove(const Move& move, const Board& board) const {
    int dx = move.end.getX() - move.start.getX();
    int dy = move.end.getY() - move.start.getY();

    // If move is not on either horizontal or vertical then not possible move
    if (dx != 0 && dy != 0) return false;

    // Determine the direction of movement
    int stepX = (dx != 0) ? (dx > 0 ? 1 : -1) : 0;
    int stepY = (dy != 0) ? (dy > 0 ? 1 : -1) : 0;

    // Traverse from start to end check for piece
    int iterX = move.start.getX() + stepX;
    int iterY = move.start.getY() + stepY;
    while (iterX != move.end.getX() || iterY != move.end.getY()) {

        Square* iterSquare = board.getSquare(iterX, iterY);
        if (iterSquare == nullptr || !iterSquare->isEmpty()) return false; 

        iterX += stepX;
        iterY += stepY; 
    }

    // Check if the final destination square is empty or has an opponent's piece
    Square* endSquare = board.getSquare(move.end.getX(), move.end.getY());
    return endSquare != nullptr && (endSquare->isEmpty() || endSquare->getPiece()->getColor() != getColor());
}

bool Rook::canCapture(const Move& move, const Board& board) const {
    return canMove(move,board); 
}

PieceType Rook::getPieceType() const {
    return ROOK; 
}

Piece* Rook::copy() const {
    return new Rook(*this); 
}
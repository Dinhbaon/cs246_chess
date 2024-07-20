#include "pawn.h"
#include "board.h" 
#include "move.h"
#include "square.h"
#include <stdlib.h> 

Pawn::Pawn(Color color) : Piece(color) {}

bool Pawn::canMove(const Move& move, const Board& board) const {
    int dx = move.end.getX() - move.start.getX(); 
    int dy = move.end.getY() - move.start.getX(); 
    // Pawns move differently based on their color
    int direction = (getColor() == Color::WHITE) ? 1 : -1;

        // Check if moving straight forward
    if (dx == 0) {
        // Moving one square forward
        if (dy == direction && board.getSquare(move.end.getX(), move.end.getY()) == nullptr) {
            return true;
        }

        // Moving two squares forward from starting position
        if (!getHasMoved() && dy == 2 * direction && board.getSquare(move.end.getX(), move.end.getY()) == nullptr &&
            board.getSquare(move.start.getX(), move.start.getY() + direction) == nullptr) {
            return true;
        }
    }

    // Check for capturing move (diagonal move by one square)
    if (abs(dx) == 1 && dy == direction && board.getSquare(move.end.getX(), move.end.getY()) != nullptr &&
        board.getSquare(move.end.getX(), move.end.getY())->getPiece()->getColor() != getColor()) {
        Piece* target = board.getSquare(move.end.getX(), move.end.getY())->getPiece();
        if (target != nullptr && target->getColor() != getColor()) {
            return true;
        }

        // Check for enpassent
        const Move& lastMove = board.getLastMove();
        if (abs(lastMove.end.getY() - lastMove.start.getY()) == 2 && 
            lastMove.end.getX() == move.end.getX() &&
            lastMove.end.getY() == move.start.getY() + direction) {
            Piece* lastMovedPiece = board.getSquare(lastMove.end.getX(), lastMove.end.getY())->getPiece();
            if (lastMovedPiece != nullptr && lastMovedPiece->getPieceType() == PAWN &&
                lastMovedPiece->getColor() != getColor()) {
                return true;
            }
        }
    }

    return false; 
}

PieceType Pawn::getPieceType() const {
    return PAWN; 
}

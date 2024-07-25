#include "pawn.h"
#include "board.h" 
#include "move.h"
#include "square.h"
#include <stdlib.h> 

Pawn::Pawn(Color color) : Piece(color) {}

char Pawn::name() const {
    if (getColor() == BLACK) {
        return 'p';
    } else {
        return 'P';
    }
}

bool Pawn::canMove(const Move& move, const Board& board) const {
    int dx = move.end.getX() - move.start.getX(); 
    int dy = move.end.getY() - move.start.getY(); 
    int direction = (getColor() == Color::WHITE) ? 1 : -1;

    // Check if moving straight forward
    if (dx == 0) {
        // Moving one square forward
        if (dy == direction && board.getSquare(move.end.getX(), move.end.getY())->getPiece() == nullptr) {
            return true;
        }

        // Moving two squares forward from starting position
        if (!getHasMoved() && dy == 2 * direction && 
            board.getSquare(move.end.getX(), move.end.getY())->getPiece() == nullptr &&
            board.getSquare(move.start.getX(), move.start.getY() + direction)->getPiece() == nullptr
            && (move.start.getY() == 1 || move.start.getY() == 6)) {
            return true;
        }
    }

    // Check for capturing move
    if (abs(dx) == 1 && dy == direction) {
        if (canCapture(move, board)) {
            return true;
        }
    }

    return false; 
}

bool Pawn::canCapture(const Move& move, const Board& board) const {
    int dx = move.end.getX() - move.start.getX(); 
    int dy = move.end.getY() - move.start.getY(); 
    int direction = (getColor() == Color::WHITE) ? 1 : -1;

    // Check for normal capture
    if (abs(dx) == 1 && dy == direction) {
        std::shared_ptr<Piece> target = board.getSquare(move.end.getX(), move.end.getY())->getPiece();
        if (target != nullptr && target->getColor() != getColor()) {
            return true;
        }
    }

    // Check for en passant capture
    if (abs(dx) == 1 && dy == direction) {
        const Move& lastMove = board.getLastMove();
        if (abs(lastMove.end.getY() - lastMove.start.getY()) == 2 &&
            lastMove.end.getX() == move.end.getX() &&
            lastMove.end.getY() == move.start.getY()) {
            std::shared_ptr<Piece> lastMovedPiece = board.getSquare(lastMove.end.getX(), lastMove.end.getY())->getPiece();
            if (lastMovedPiece != nullptr && lastMovedPiece->getPieceType() == PieceType::PAWN &&
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


std::shared_ptr<Piece> Pawn::copy() const {
    return std::make_shared<Pawn>(*this); 
}
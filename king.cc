#include "king.h"
#include "move.h"
#include "board.h"
#include <stdlib.h> 

King::King(Color color): Piece{color} {}

char King::name() const {
    if (getColor() == BLACK) {
        return 'k';
    } else {
        return 'K';
    }
}

bool King::canMove(const Move& move, const Board& board) const {
    return canCapture(move, board) && !(board.isSquareUnderAttack(move.end, getColor()));
}

bool King::canCapture(const Move& move, const Board& board) const {
    int dx = abs(move.end.getX() - move.start.getX());
    int dy = abs(move.end.getY() - move.start.getY());

    // The king can move one square in any direction
    if ((dx <= 1 && dy <= 1) && (dx != 0 || dy != 0)) {
        Piece* target = board.getSquare(move.end.getX(), move.end.getY())->getPiece();
        // Check if the destination square is either empty or contains an opponent's piece
        if (target == nullptr || target->getColor() != getColor()) {
            return true;
        }
    }

    // Castling move
    if (dy == 0 && dx == 2 && !getHasMoved()) {
        int rookX = (dx > 0) ? 7 : 0; // Rook's initial position (kingside or queenside)
        int kingY = move.start.getY(); // The rank of the king
        Piece* rook = board.getSquare(rookX, kingY)->getPiece();

        // Check if the rook is in place and hasn't moved
        if (rook != nullptr && rook->getPieceType() == PieceType::ROOK && !rook->getHasMoved()) {
            int step = (rookX == 7) ? 1 : -1;
            for (int x = move.start.getX() + step; x != rookX; x += step) {
                if (board.getSquare(x, kingY)->getPiece() != nullptr) return false; // Making sure no pieces is in the way

                if (board.isSquareUnderAttack(Square(x, kingY), getColor())) return false; // Can't castle through check
            }
            // Check the destination square and the square before it
            if (board.isSquareUnderAttack(Square(move.start.getX() + step, kingY), getColor()) || 
                board.isSquareUnderAttack(move.end, getColor())) return false;
            return true;
        }
    }

    // Invalid move
    return false;
}


PieceType King::getPieceType() const {
    return KING; 
}

Piece* King::copy() const {
    return new King(*this); 
}
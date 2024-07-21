#include "king.h"
#include "move.h"
#include "board.h"
#include <stdlib.h> 

King::King(Color color): Piece{color} {}

bool King::canMove(const Move& move, const Board& board) const {
    int dx = abs(move.end.getX() - move.start.getX());
    int dy = abs(move.end.getY() - move.start.getY());

    if (board.isSquareUnderAttack(move.end, getColor())) return false;

    // The king can move one square in any direction
    if ((dx <= 1 && dy <= 1) && (dx != 0 || dy != 0)) {
        Piece* target = board.getSquare(move.end.getX(), move.end.getY())->getPiece();
        // Check if the destination square is either empty or contains an opponent's piece
        if (target == nullptr || target->getColor() != getColor()) {
            return true;
        }
    }

        // Castling move
    if (dy == 0 && dx == 2&& !getHasMoved()) {
        int rookX = (dx > 0) ? 7 : 0; // Rook's initial position (kingside or queenside)
        Square rookSquare(rookX, 0);
        Piece* rook = board.getSquare(rookX, 0)->getPiece();

        // Check if the rook is in place and hasn't moved
        if (rook != nullptr && rook->getPieceType() == PieceType::ROOK && !rook->getHasMoved()) {
            int step = (rookX == 7) ? 1 : -1;
            for (int x = move.start.getX() + step; x != rookSquare.getX(); x += step) {
                if (board.getSquare(rookSquare.getX(), 0)->getPiece() != nullptr) return false; // Making sure no pieces is in the way

                if (board.isSquareUnderAttack(Square(x, move.start.getY()), getColor()))  return false; // Can't casle through check
            }
            // Check the destination square
            if (board.isSquareUnderAttack(rookSquare, getColor())) return false;
            return true;
        }
    }

    // Invalid move
    return false;
}

bool King::canCapture(const Move& move, const Board& board) const {
    return canMove(move, board); 
}

PieceType King::getPieceType() const {
    return KING; 
}


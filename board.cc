#include "board.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "move.h"

#include <stdexcept>

char Board::charAt(int row, int col) {
    return (board[row * 8 + col])->charAt(row, col);
}

void Board::movePiece(Move move, Color color) {
    int fromX = move.start.getX();
    int fromY = move.start.getY();

    int toX = move.end.getX();
    int toY = move.end.getY();

    Piece* piece = this->getSquare(fromX, fromY)->getPiece();
    if (isMoveCastle(move)) {
        Castle(move); 
    } else if (isMoveEnpassent(move)) {
        Enpassent(move); 
    } else {
        this->getSquare(fromX, fromY)->setPiece(nullptr);
        this->getSquare(toX, toY)->setPiece(piece);
    }

    updateAllPieces();

    lastMove = move; 

    piece->setHasMoved(true); 


}

Board::Board() {
    board.resize(xDimension * yDimension, nullptr);  

    for (int i = 0; i < xDimension; i++) {
        for (int j = 0; j < yDimension; j++) {
            board[j * xDimension + i] = new Square(i, j); 
        }
    }

    this->setSquare(0, 0, new Rook(WHITE));
    this->setSquare(1, 0, new Knight(WHITE));
    this->setSquare(2, 0, new Bishop(WHITE));
    this->setSquare(3, 0, new Queen(WHITE));
    this->setSquare(4, 0, new King(WHITE)); 
    this->setSquare(5, 0, new Bishop(WHITE)); 
    this->setSquare(6, 0, new Knight(WHITE)); 
    this->setSquare(7, 0, new Rook(WHITE)); 

    for (int i = 0; i < xDimension; i++) {
        this->setSquare(i, 1, new Pawn(WHITE)); 
    }

    this->setSquare(0, 7, new Rook(BLACK));
    this->setSquare(1, 7, new Knight(BLACK));
    this->setSquare(2, 7, new Bishop(BLACK));
    this->setSquare(3, 7, new Queen(BLACK));
    this->setSquare(4, 7, new King(BLACK)); 
    this->setSquare(5, 7, new Bishop(BLACK)); 
    this->setSquare(6, 7, new Knight(BLACK)); 
    this->setSquare(7, 7, new Rook(BLACK)); 
    
    for (int i = 0; i < xDimension; i++) {
        this->setSquare(i, 6, new Pawn(BLACK)); 
    }

    updateAllPieces();
}

Board::~Board() {
    for (Square* square : board) {
        delete square->getPiece(); 
        delete square;  
    }
}

//Helper methods
bool Board::isSquareUnderAttack(const Square& square, Color color) const {
    Color attackingColor; 
    if (color == WHITE) {
        attackingColor = BLACK; 
    } else {
        attackingColor = WHITE; 
    }
    const std::vector<Square*>& squares = allSquaresWithPieces.at(attackingColor);
    for (Square* squareWithPieces : squares) {
        Move move{*squareWithPieces, square}; 
        if (squareWithPieces->getPiece()->canCapture(move, *this)) {
            return true;
        }
    }
    return false;
}

bool Board::isInCheck(Color color) const {
    return isSquareUnderAttack(*getKingSquare(color), color);
}

bool Board::isPiecePinned(const Square& square, Color color) {
    Piece* piece = getSquare(square.getX(), square.getY())->getPiece(); 

    // If we remove the piece, is the king in check
    setSquare(square.getX(), square.getY(), nullptr); 

    if (isInCheck(color)) {
        // Place the piece back to original square 
        setSquare(square.getX(), square.getY(), piece); 
        return true; 
    }
    
    setSquare(square.getX(), square.getY(), piece);
    return false;  

}

void Board::updateAllPieces() {
    allSquaresWithPieces[WHITE].clear(); 
    allSquaresWithPieces[BLACK].clear(); 
    for (Square* square : this->board) {
        if (square != nullptr) {
            Piece* piece = square->getPiece();
            if (piece != nullptr) {
                if (piece->getColor() == WHITE) {
                    allSquaresWithPieces[WHITE].emplace_back(square);
                } else {
                    allSquaresWithPieces[BLACK].emplace_back(square);
                }
            }
        }
    }

}

bool Board::isMoveCastle(const Move& move) const {
    int dx = move.end.getX() - move.start.getX(); 

    int dy = move.end.getY() - move.start.getY(); 

    Piece* piece = this->getSquare(move.start.getX(), move.start.getY())->getPiece();

    if (piece->getPieceType() == KING && (abs(dx) == 2) && (dy == 0) ) {
        return true; 
    }  
    return false; 
}

void Board::Castle(const Move& move) {
    int dx = move.end.getX() - move.start.getX(); 

    Piece* king = move.start.getPiece(); 
    this->setSquare(move.end.getX(), move.end.getY(), king); 
    this->setSquare(move.start.getX(), move.start.getY(), nullptr); 
    // King side castle
    if (dx > 0) {
        Piece* rook = getSquare(7, move.end.getY())->getPiece(); 
        this->setSquare(5, 0, rook); 
        this->setSquare(7, 0, nullptr); 
    } else { //Queen side castle
        Piece* rook = getSquare(0, move.end.getY())->getPiece(); 
        this->setSquare(3, 0, rook); 
        this->setSquare(0, 0, nullptr); 
    }
}

bool Board::isMoveEnpassent(const Move& move) const {
    int dx = move.end.getX() - move.start.getX(); 

    Piece* piece = this->getSquare(move.start.getX(), move.start.getY())->getPiece(); 
    // If Pawn is moving sideways that means its a capture but if the target square is empty
    // That must be enpassent
    if (piece->getPieceType() == PAWN  && abs(dx) == 1 && move.end.isEmpty()) {
        return true; 
    }

    return false; 
}

void Board::Enpassent(const Move& move) {
    int dx = move.end.getX() - move.start.getX(); 
    int dy = move.end.getY() - move.end.getY(); 

    int direction = (dy > 0) ? 1 : -1; 

    Piece* pawn = this->getSquare(move.start.getX(), move.start.getY())->getPiece(); 

    this->setSquare(move.end.getX(), move.end.getY(), pawn); 
    this->setSquare(move.start.getX(), move.start.getY(), nullptr); 

    // the pawn to be captured in enpassent will be the x of the endsquare but the y of the starting square
    // This removes the pawn
    this->setSquare(move.end.getX(), move.start.getY(), nullptr); 

}

//Getters and setters
std::map<Color, std::vector<Square*>> Board::getAllSquaresWithPieces() const {
    return allSquaresWithPieces;
}

Square* Board::getSquare(const int x, const int y) const {
    if (x < 0 || x >= xDimension || y < 0 || y >= yDimension) {
        return nullptr;
    }
    return board[y * xDimension + x];
}

void Board::setSquare(int x, int y, Piece* piece) {
    if (x >= 0 && x < xDimension && y >= 0 && y < yDimension) {
        board[y * xDimension + x]->setPiece(piece);
    } else {
        throw std::invalid_argument( "Inputted square not on board" );
    }
}

Move Board::getLastMove() const {
    return lastMove; 
}

Square* Board::getKingSquare(Color color) const {
    for (Square* square: allSquaresWithPieces.at(color)) {
        if (square->getPiece()->getPieceType() == KING && square->getPiece()->getColor() == color) {
            return square; 
        }
    }
}

bool Board::oneKing(const Color color) const {
    int count = 0;
    for (auto it = board.begin(); it != board.end(); ++it) {
        if ((*it)->getPiece()->getPieceType() == KING && 
            (*it)->getPiece()->getColor() == color) {
            count += 1;
        }
    }
    if (count > 0) {
        return false;
    }
}





#include "board.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "move.h"
#include <iostream>
#include <stdexcept>

char Board::charAt(int col, int row) {
    return (board[(yDimension - 1 - row) * xDimension + col])->charAt(col, row);
}

void Board::movePiece(Move move, Color color) {
    int fromX = move.start.getX();
    int fromY = move.start.getY();

    int toX = move.end.getX();
    int toY = move.end.getY();

    std::shared_ptr<Piece> piece = this->getSquare(fromX, fromY)->getPiece();
    if (isMoveCastle(move)) {
        Castle(move); 
    } else if (isMoveEnpassent(move)) {
        Enpassent(move); 
        
    } else {
        this->getSquare(fromX, fromY)->setPiece(nullptr);
        this->getSquare(toX, toY)->setPiece(piece);
    }

    lastMove = move; 

    piece->setHasMoved(true);


}

Board::Board() {
    board.resize(xDimension * yDimension, nullptr);  

    for (int i = 0; i < xDimension; i++) {
        for (int j = 0; j < yDimension; j++) {
            board[(yDimension - 1 - i) * xDimension + j] = std::make_shared<Square>(j, i); 
        }
    }

    this->setSquare(0, 0, std::make_shared<Rook>(WHITE));
    this->setSquare(1, 0, std::make_shared<Knight>(WHITE));
    this->setSquare(2, 0, std::make_shared<Bishop>(WHITE));
    this->setSquare(3, 0, std::make_shared<Queen>(WHITE));
    this->setSquare(4, 0, std::make_shared<King>(WHITE)); 
    this->setSquare(5, 0, std::make_shared<Bishop>(WHITE)); 
    this->setSquare(6, 0, std::make_shared<Knight>(WHITE)); 
    this->setSquare(7, 0, std::make_shared<Rook>(WHITE)); 

    for (int i = 0; i < xDimension; i++) {
        this->setSquare(i, 1, std::make_shared<Pawn>(WHITE)); 
    }

    this->setSquare(0, 7, std::make_shared<Rook>(BLACK));
    this->setSquare(1, 7, std::make_shared<Knight>(BLACK));
    this->setSquare(2, 7, std::make_shared<Bishop>(BLACK));
    this->setSquare(3, 7, std::make_shared<Queen>(BLACK));
    this->setSquare(4, 7, std::make_shared<King>(BLACK)); 
    this->setSquare(5, 7, std::make_shared<Bishop>(BLACK)); 
    this->setSquare(6, 7, std::make_shared<Knight>(BLACK)); 
    this->setSquare(7, 7, std::make_shared<Rook>(BLACK)); 
    
    for (int i = 0; i < xDimension; i++) {
        this->setSquare(i, 6,  std::make_shared<Pawn>(BLACK)); 
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
    const std::vector<std::shared_ptr<Square>>& squares = getAllSquaresWithPieces().at(attackingColor);
    if (!squares.empty()) {
        for (std::shared_ptr<Square> squareWithPieces : squares) {
            Move move{*squareWithPieces, square}; 
            if (squareWithPieces->getPiece()->canCapture(move, *this)) {
                return true;
            }
        }
    }

    return false;
}

//Helper methods
bool Board::isSquareUnderAttackAfterMove(Move lastMove, Color color) const {
    Color attackingColor; 
    if (color == WHITE) {
        attackingColor = BLACK; 
    } else {
        attackingColor = WHITE; 
    }
    
    Board tmp {*this};
    tmp.movePiece(lastMove, color);
    const std::vector<std::shared_ptr<Square>>& squares = tmp.getAllSquaresWithPieces().at(attackingColor);
    if (!squares.empty()) {
        for (std::shared_ptr<Square> squareWithPieces : squares) {
            Move move{*squareWithPieces, lastMove.end}; 
            if (squareWithPieces->getPiece()->canCapture(move, tmp)
            && !(tmp.isCheckAfterMove(move, attackingColor))) {
                return true;
            }
        }
    }

    return false;
}

bool Board::isInCheck(Color color) const {
    return isSquareUnderAttack(*getKingSquare(color), color);
}

bool Board::isMoveCastle(const Move& move) const {
    int dx = move.end.getX() - move.start.getX(); 

    int dy = move.end.getY() - move.start.getY(); 

    std::shared_ptr<Piece> piece = this->getSquare(move.start.getX(), move.start.getY())->getPiece();

    if (piece->getPieceType() == KING && (abs(dx) == 2) && (dy == 0) ) {
        return true; 
    }  
    return false; 
}

void Board::Castle(const Move& move) {
    int dx = move.end.getX() - move.start.getX(); 

    std::shared_ptr<Piece> king = getSquare(move.start.getX(), move.start.getY())->getPiece(); 
    this->setSquare(move.end.getX(), move.end.getY(), king); 
    this->setSquare(move.start.getX(), move.start.getY(), nullptr); 
    // King side castle
    if (dx > 0) {
        std::shared_ptr<Piece> rook = getSquare(7, move.end.getY())->getPiece(); 
        this->setSquare(5, move.end.getY(), rook); 
        this->setSquare(7, move.end.getY(), nullptr); 
    } else { //Queen side castle
        std::shared_ptr<Piece> rook = getSquare(0, move.end.getY())->getPiece(); 
        this->setSquare(3, move.end.getY(), rook); 
        this->setSquare(0, move.end.getY(), nullptr); 
    }
}

bool Board::isMoveEnpassent(const Move& move) const {
    int dx = move.end.getX() - move.start.getX(); 

    std::shared_ptr<Piece> piece = this->getSquare(move.start.getX(), move.start.getY())->getPiece(); 
    // If Pawn is moving sideways that means its a capture but if the target square is empty
    // That must be enpassent
    if (piece->getPieceType() == PAWN  && abs(dx) == 1 && getSquare(move.end.getX(), move.end.getY())->isEmpty()) {
        return true; 
    }

    return false; 
}

void Board::Enpassent(const Move& move) {
    int dx = move.end.getX() - move.start.getX(); 
    int dy = move.end.getY() - move.end.getY(); 

    int direction = (dy > 0) ? 1 : -1; 

    std::shared_ptr<Piece> pawn = this->getSquare(move.start.getX(), move.start.getY())->getPiece(); 

    this->setSquare(move.end.getX(), move.end.getY(), pawn); 
    this->setSquare(move.start.getX(), move.start.getY(), nullptr); 

    // The pawn to be captured in enpassent will be the x of the endsquare but the y of the starting square
    // This removes the pawn
    this->setSquare(move.end.getX(), move.start.getY(), nullptr); 

}

//Getters and setters
const std::map<Color, std::vector<std::shared_ptr<Square>>>& Board::getAllSquaresWithPieces() const {
    allSquaresWithPieces[WHITE].clear(); // Clear the map before updating it
    allSquaresWithPieces[BLACK].clear(); 

    

    for (std::shared_ptr<Square> square : this->board) {
        if (square != nullptr) {
            std::shared_ptr<Piece> piece = square->getPiece();
            if (piece != nullptr) {
                allSquaresWithPieces[piece->getColor()].emplace_back(square);
            }
        }
    }
    return allSquaresWithPieces;
}


std::shared_ptr<Square> Board::getSquare(const int x, const int y) const {
    if (x < 0 || x >= xDimension || y < 0 || y >= yDimension) {
        return nullptr;
    }
    return board[(yDimension - 1 -y) * xDimension + x];
}

void Board::setSquare(int x, int y, std::shared_ptr<Piece> piece) {
    if (x >= 0 && x < xDimension && y >= 0 && y < yDimension) {
        board[(yDimension - 1 - y) * xDimension + x]->setPiece(piece);
    } else {
        throw std::invalid_argument( "Inputted square not on board" );
    }
}

Move Board::getLastMove() const {
    return lastMove; 
}

std::shared_ptr<Square> Board::getKingSquare(Color color) const {
    for (std::shared_ptr<Square> square: getAllSquaresWithPieces().at(color)) {
        if (square->getPiece()->getPieceType() == KING && square->getPiece()->getColor() == color) {
            return square; 
        }
    }
}

Board::Board(const Board& other) {

    // Clear the existing board data
    clearBoard();

    // Copy xDimension and yDimension
    xDimension = other.xDimension;
    yDimension = other.yDimension;
        // Deep copy the board squares
    for (const auto& square : other.board) {
        if (square != nullptr) {
            board.push_back(std::make_shared<Square>(*square)); // Create a new Square and copy the contents
        } else {
            board.push_back(nullptr);
        }
    }


    // Copy the last move
    lastMove = other.lastMove;
}

bool Board::oneKing(const Color color) const {
    int count = 0;
    for (const auto& square : board) {
        if (!(square->isEmpty())) {
            if (square->getPiece()->getPieceType() == KING &&
                square->getPiece()->getColor() == color) {
                count += 1;
            }
        }
    }
    if (count == 1) {
        return true;
    }
    return false;
    
}

Board& Board::operator=(const Board &other) {
    allSquaresWithPieces = other.allSquaresWithPieces;
    board = other.board;
    xDimension = other.xDimension;
    yDimension = other.yDimension;
    lastMove = other.lastMove;
    return *this;

}

bool Board::operator==(const Board& other) {
    if (other.board.size() != board.size()) return false; 

    for (int i = 0; i < other.board.size(); i++) {
        if (*board[i] != *other.board[i]) return false; 
    }

    return 
    lastMove.end.getX() == other.lastMove.end.getX() && 
    lastMove.start.getX() == other.lastMove.start.getX() &&
    lastMove.end.getY() == other.lastMove.start.getY() &&
    lastMove.start.getY() == other.lastMove.start.getY(); 
}

bool Board::isCheckAfterMove(Move move, Color color){
    Board tmpBoard{*this};
    if(getSquare(move.start.getX(), move.start.getY())->getPiece()->canMove(move, *this)) {
        tmpBoard.movePiece(move, color);
        if(tmpBoard.isSquareUnderAttack(*tmpBoard.getKingSquare(color), color)){
            return true;
        };
    }
    return false;
}


void Board::clearBoard() {
    // Delete dynamically allocated squares
    board.clear();

}

void Board::emptyBoard() {
    // clears the board of all pieces
    for (auto& square : board) {
        square->setPiece(nullptr);
    }
}

bool Board::checkPawnEdgeRows() const {
    int lastRow = 0;
    int firstRow = 7;
    std::shared_ptr<Square> sqlast;
    std::shared_ptr<Square> sqfirst;
    for (int i = 0; i < xDimension; ++i) {
        sqlast = getSquare(i, lastRow);
        sqfirst = getSquare(i, firstRow);
        if (!(sqlast->isEmpty())) {
            if (sqlast->getPiece()->getPieceType() == PAWN) {
                return true;
            }
        } else if (!(sqfirst->isEmpty())) {
            if (sqfirst->getPiece()->getPieceType() == PAWN) {
                return true;
            }
        }
    }
    return false;
}

std::shared_ptr<Square> Board::getEmptySquare() const {
    for (auto square : board) {
        if (square->isEmpty()) {
            return square;
        }
    }
}

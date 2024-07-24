#include "bot.h"
#include "queen.h"
#include <random>

template <typename T> T getRandom(std::vector<T> vector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrMoves(0, vector.size()-1);
    int ithElement = distrMoves(gen);
    return vector[ithElement];
}

Bot::Bot(Color color, Board* board): Player{color, board}{};

bool Bot::getIsHuman() const{
    return false;
}

void Bot::handlePromotion() {
    Piece* piece; 
    Move lastMove = board->getLastMove(); 
    piece = new Queen{color};
    board->setSquare(lastMove.end.getX(), lastMove.end.getY(), piece); 
}

std::vector<Move> Bot::findGetCaptureMoves(const std::vector<Square*> &squares, Color color) const {
    std::vector<Move> moves;

    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && !(board->isSquareUnderAttack(Square(x, y), color))
                && !(board->isCheckAfterMove(move, color))){
                    moves.emplace_back(move);
                }
            }
        }
    }
    return moves;    
}

std::vector<Move> Bot::findCaptureMoves(const std::vector<Square*> &squares, Color color) const {
    std::vector<Move> moves;
    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && board->getSquare(x, y)->getPiece() != nullptr
                && !(board->isCheckAfterMove(move, color))){
                    moves.emplace_back(move);
                } else if ((*it)->getPiece()->getPieceType() == PAWN
                && (*it)->getPiece()->canMove(move, *board)
                && (*it)->getPiece()->canCapture(move, *board)
                && !(board->isCheckAfterMove(move, color))){
                    moves.emplace_back(move);
                }
            }
        }
    }
    return moves;
}

std::vector<Move> Bot::findCheckMoves(const std::vector<Square*> &squares, Color color) const {
    Color attackingColor;
    if(color==WHITE){
        attackingColor = BLACK;
    } else {
        attackingColor = WHITE;
    }
    std::vector<Move> moves;
    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Board tmpBoard = *board;
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)){
                    tmpBoard.movePiece(move, color);
                    if(tmpBoard.isSquareUnderAttack(*tmpBoard.getKingSquare(attackingColor), attackingColor)
                    && !(board->isCheckAfterMove(move, color))){
                        moves.emplace_back(move);
                    };
                }
            }
        }
    }
    return moves;
}

std::vector<Move> Bot::findRandomMoves(const std::vector<Square*> &squares, Color color) const {
    std::vector<Move> moves;

    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, *board->getSquare(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && !(board->isCheckAfterMove(move, color))){
                    moves.emplace_back(move);
                }
            }
        }
    }

    return moves;
}

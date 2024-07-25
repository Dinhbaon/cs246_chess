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

Bot::Bot(Color color, std::shared_ptr<Board> board): Player{color, board}{};

bool Bot::getIsHuman() const{
    return false;
}

void Bot::handlePromotion() {
    std::shared_ptr<Piece> piece; 
    Move lastMove = board->getLastMove(); 
    piece = std::make_shared<Queen>(color);
    board->setSquare(lastMove.end.getX(), lastMove.end.getY(), piece); 
}

std::vector<Move> Bot::findAvoidCaptureMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const {
    std::vector<Move> moves;
    for(auto it = squares.begin(); it != squares.end(); ++it){
        if(board->isSquareUnderAttack(**it, color)){
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
    }
    return moves;  
}

std::vector<Move> Bot::findRandomAvoidCaptureMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const {
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

std::vector<Move> Bot::findCaptureMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const {
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

std::vector<Move> Bot::findCheckMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const {
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
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && board->isCheckAfterMove(move, attackingColor)
                && !(board->isCheckAfterMove(move, color))) {
                    moves.emplace_back(move);
                }
            }
        }
    }
    return moves;
}

std::vector<Move> Bot::findRandomMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const {
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

Move Bot::findBetterCaptureMoves(const std::vector<std::shared_ptr<Square>> &squares, Color color) const {
    Move bestMove;
    int maxPoint = 0;
    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && board->getSquare(x, y)->getPiece() != nullptr
                && !(board->isCheckAfterMove(move, color))
                && (board->isSquareUnderAttack(Square(x, y), color) 
                && piecesPoints.at((*it)->getPiece()->getPieceType()) > piecesPoints.at(board->getSquare(x, y)->getPiece()->getPieceType()))){
                    if(piecesPoints.at(board->getSquare(x, y)->getPiece()->getPieceType()) > maxPoint){
                        bestMove = move;
                        maxPoint = piecesPoints.at((*it)->getPiece()->getPieceType()) - piecesPoints.at(board->getSquare(x, y)->getPiece()->getPieceType());
                    }
                } else if ((*it)->getPiece()->canMove(move, *board)
                && board->getSquare(x, y)->getPiece() != nullptr
                && !(board->isCheckAfterMove(move, color))
                && !(board->isSquareUnderAttack(Square(x, y), color))){
                    if(piecesPoints.at(board->getSquare(x, y)->getPiece()->getPieceType()) > maxPoint){
                        bestMove = move;
                        maxPoint = piecesPoints.at(board->getSquare(x, y)->getPiece()->getPieceType());
                    }
                } else if ((*it)->getPiece()->getPieceType() == PAWN
                && (*it)->getPiece()->canMove(move, *board)
                && (*it)->getPiece()->canCapture(move, *board)
                && !(board->isCheckAfterMove(move, color))){
                    if(maxPoint == 0){
                        bestMove = move;
                    }
                }
            }
        }
    }
    return bestMove;
}

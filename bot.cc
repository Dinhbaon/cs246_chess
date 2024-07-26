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
                    && board->isSquareUnderAttack(**it, color)
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
                && !(board->isSquareUnderAttackAfterMove(move, color))
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
    Color oppositionColor;
    if(color==WHITE){
        oppositionColor = BLACK;
    } else {
        oppositionColor = WHITE;
    }
    std::vector<Move> moves;
    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && board->isCheckAfterMove(move, oppositionColor)
                && !(board->isSquareUnderAttackAfterMove(move, color))
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
                if((*it)->getPiece()->canMove(move, *board) // check can move
                && board->getSquare(x, y)->getPiece() != nullptr // check if piece exist at square
                && !(board->isCheckAfterMove(move, color)) // check if check after move
                && (board->isSquareUnderAttackAfterMove(move, color) // check if square moving in is under attack
                && piecesPoints.at((*it)->getPiece()->getPieceType()) < piecesPoints.at(board->getSquare(x, y)->getPiece()->getPieceType()))){
                    if(piecesPoints.at(board->getSquare(x, y)->getPiece()->getPieceType()) > maxPoint){
                        bestMove = move;
                        maxPoint = piecesPoints.at((*it)->getPiece()->getPieceType()) - piecesPoints.at(board->getSquare(x, y)->getPiece()->getPieceType());
                    }
                } else if ((*it)->getPiece()->canMove(move, *board)
                && board->getSquare(x, y)->getPiece() != nullptr
                && !(board->isCheckAfterMove(move, color))
                && !(board->isSquareUnderAttackAfterMove(move, color))){
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

bool checkCanMove(std::shared_ptr<Board> board, Color oppositionColor){
    
    const std::vector<std::shared_ptr<Square>> &squares = board->getAllSquaresWithPieces().at(oppositionColor);
    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, Square(x, y)};
                if((*it)->getPiece()->canMove(move, *board)
                && !(board->isCheckAfterMove(move, oppositionColor))){
                    return true;
                }
            }
        }
    }
    return false;
}

Move Bot::findCheckMate(const std::vector<std::shared_ptr<Square>> &squares, Color color) const {
    Move bestMove;
    Color oppositionColor;
    if(color==WHITE){
        oppositionColor = BLACK;
    } else {
        oppositionColor = WHITE;
    }
    for(auto it = squares.begin(); it != squares.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {**it, Square(x, y)};
                Board tmp = *board;
                tmp.movePiece(move, color);
                if((*it)->getPiece()->canMove(move, *board)
                && board->isCheckAfterMove(move, oppositionColor)
                && !(board->isCheckAfterMove(move, color))
                && !(checkCanMove(std::make_shared<Board>(tmp), oppositionColor))) {
                    bestMove = move;
                    return bestMove;
                }
            }
        }
    }
    return bestMove;
}

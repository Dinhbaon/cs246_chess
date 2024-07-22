#include "botLevel2.h"
#include "king.h"
#include <random>
#include 

BotLevel2::BotLevel2(Color color, Board* board): Bot{color, board}{}

std::vector<Move> findCaptureMoves(std::vector<Piece*> pieces, Board *board, Color color){
    std::vector<Move> moves;
    for(auto it = pieces.begin(); it != pieces.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {x, y};
                Color opposition = color == WHITE? BLACK: WHITE;
                if((*it)->canMove(move, *board)
                 && board->getSquare(x, y)->getPiece() != nullptr
                 && board->getSquare(x, y)->getPiece()->getColor() == opposition){
                    moves.emplace_back(move);
                }
            }
        }
    }
    return moves;
}

std::vector<Move> findCheckMoves(std::vector<Piece*> pieces, Board *board, Color color){
    std::vector<Move> moves;
    for(auto it = pieces.begin(); it != pieces.end(); ++it){
        for(int x = 0; x < 8; ++x){
            for(int y = 0; y < 8; ++y){
                Move move {x, y};
                Color opposition = color == WHITE? BLACK: WHITE;
                
            }
        }
    }
    return moves;
}

template <typename T> T getRandom(std::vector<T> vector){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrMoves(0, vector.size());
    int ithElement = distrMoves(gen);
    return vector[ithElement];
}

Move BotLevel2::getNextMove() const {
    std::vector<Piece*> pieces = board->getPieces()[color];
    std::vector<Move> captureMoves = findCaptureMoves(pieces, board, color);
    std::vector<Move> checkMoves = findCheckMoves(pieces, board, color);

    if(captureMoves.size() > 0){
        return getRandom<Move>(captureMoves);
    } else if(checkMoves.size() > 0){
        return getRandom<Move>(checkMoves);
    }

    Piece* selectedPiece = getRandom<Piece*>(pieces);
    std::vector<Move> moves;

    for(int x = 0; x < 8; ++x){
        for(int y = 0; y < 8; ++y){
            Move move {x, y};
            if(selectedPiece->canMove(move, *board)){
                moves.emplace_back(move);
            }
        }
    }

    return getRandom<Move>(moves);
}

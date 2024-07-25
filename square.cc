#include "square.h"
#include "move.h"

Square::Square(int x, int y, std::shared_ptr<Piece> piece): x{x}, y{y}, piece{piece} {
    if (y == 7 || y == 5 || y == 3 || y == 1) {
        for (int i = 1; i < dim; i += 2) {
            if (x == i) {
                black = true;
                return;
            }
        }
    } else {
        for (int i = 0; i < dim; i += 2) {
            if (x == i) {
                black = true;
                return;
            }
        }
    }
    black = false;
}

Square::Square(const Square& other) {
        if (other.piece) {
            piece = other.piece->copy(); 
        } else {
            piece = nullptr;
        }
        x = other.x; 
        y = other.y; 
        black = other.black; 
}

char Square::charAt(int col, int row) {
    if (isEmpty()) {
        if (isBlack()) {
            return '_';
        } else {
            return ' ';
        }
    }
    return piece->name();
}

std::shared_ptr<Piece> Square::getPiece() const {
    return piece;
}

void Square::setPiece(std::shared_ptr<Piece> piece) {
    this->piece = piece; 
}

std::vector<int> Square::getCoords() {
    std::vector<int> v = {x, y};
    return v;
}

int Square::getX() const {
    return x; 
}

int Square::getY() const {
    return y; 
}

bool Square::isEmpty() const {
    return piece == nullptr; 
}

Square& Square::operator=(const Square& other) {
    if (this == &other) {
        return *this; 
    }
    
    x = other.x; 
    y = other.y; 
    piece = other.piece;
    return *this;
}

bool Square::operator==(const Square& other) {

    if (piece != nullptr && other.piece != nullptr) {
        if (!(piece->getPieceType() == other.piece->getPieceType() && piece->getHasMoved() && other.piece->getHasMoved())) {
            return false; 
        }
    } 

    return x == other.x && y == other.y; 
}

bool Square::isBlack() {
    return black;
}

#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__
#include "observer.h"
#include "controller.h"
#include "window.h"
#include "piece.h"

class Graphic: public Observer {
    Controller *subject;
    int bottom = 8;
    int right = 8;
    int squareDim = 50; // each square is 10 by 10, must be multiples of 10
    int pieceDim = 10;
    Xwindow window;
    
    // assuming a width and hight of 10 for these methods
    void printRook(int c_background, int color, int x, int y); 
    void printKnight(int c_background, int color, int x, int y);
    void printBishop(int c_background, int color, int x, int y);
    void printQueen(int c_background, int color, int x, int y);
    void printKing(int c_background, int color, int x, int y);
    void printPawn(int c_background, int color, int x, int y);
    void printSquare(int c_background, int x, int y);

    public:
        Graphic(Controller *s);
        void notify(Move move) override;
        void initNotify() override;
        ~Graphic();
        int getPieceColor(int x, int y);
        int getBackgroundColor(int x, int y);
        void printPiece(int x, int y);
};

#endif
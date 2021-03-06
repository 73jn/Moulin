#ifndef GAMEOUTPUT_H
#define GAMEOUTPUT_H
#include "point.h"
#include <QWidget>
#include <QVector>
#include <QLabel>
#include "view.h"

#define PAWNSIZE 20

class GameOutput : public View
{
    Q_OBJECT
public:
    QPainter* painter;
    QLabel * lblInfo;
    GameOutput(int x, int y, int width, int heigth, QString title);
    void paintEvent(QPaintEvent* event);

    //====================================================
    // Function name : drawBoard
    // draw the grid
    //====================================================
    // Input : QPainter *p
    // Output : void
    //====================================================
    void drawBoard(QPainter *p);

    //====================================================
    // Function name : drawNumber
    // draw position number near each points
    //====================================================
    // Input : QPainter *p
    // Output : void
    //====================================================
    void drawNumber(QPainter *p);

    //====================================================
    // Function name : drawLblInfos
    // update the label infos
    //====================================================
    // Input : void
    // Output : void
    //====================================================
    void drawLblInfos();

    //====================================================
    // Function name : drawPawn
    // draw all pawn
    //====================================================
    // Input : QPainter *p
    // Output : void
    //====================================================
    void drawPawn(QPainter *p);
protected:
    void changed();

};

#endif // GAMEOUTPUT_H

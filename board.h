#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include "point.h"
class Board
{

public:
    Board();
    QVector<Point*> vectPoint;
    QVector<int> vectMillOnBoardPos;
    void setRelation(int relation[][2], int pointNeigh[][4]);
};

#endif // BOARD_H

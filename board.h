#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include "point.h"
class Board
{

public:
    Board();
    QVector<Point*> vectPoint;
    void setRelation(int relation[][2]);
};

#endif // BOARD_H

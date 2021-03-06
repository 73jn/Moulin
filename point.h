#ifndef POINT_H
#define POINT_H
#include "pawn.h"
#include <QVector>
class Point
{
public:
    Point(int number, int posX, int posY);
    int number;
    int posX;
    int posY;
    Pawn* pPawn=nullptr;
    bool isEdge;
    QVector<Point*> vectHisNeighbour;

    bool isEmpty();
    void setNeighbour(Point* p1, Point* p2, Point* p3, Point* p4);

};

#endif // POINT_H

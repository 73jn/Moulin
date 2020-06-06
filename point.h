#ifndef POINT_H
#define POINT_H
#include "pawn.h"

class Point
{
public:
    Point(int number, int posX, int posY);
    int number;
    int posX;
    int posY;
    Pawn* pPawn=nullptr;
    bool isEdge;
    Point** hisNeighbour=nullptr;

    bool isEmpty();
    void setNeighbour(Point* p1, Point* p2, Point* p3, Point* p4);
    void setNeighbour(Point* p1, Point* p2, Point* p3);
    void setNeighbour(Point* p1, Point* p2);

};

#endif // POINT_H

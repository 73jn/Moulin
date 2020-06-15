#include "point.h"


Point::Point(int number, int posX, int posY)
{
    this->number = number;
    this->posX = posX;
    this->posY = posY;
}

bool Point::isEmpty()
{
    if (pPawn == nullptr){
        return true;
    }
    else {
        return false;
    }
}

void Point::setNeighbour(Point *p1, Point *p2, Point *p3, Point *p4)
{
    vectHisNeighbour.append(p1);
    vectHisNeighbour.append(p2);
    if(p3!=nullptr){
       vectHisNeighbour.append(p3);
    }
    if (p4!=nullptr){
       vectHisNeighbour.append(p4);
    }
}

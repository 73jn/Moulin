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
    hisNeighbour = new Point*[4];
    hisNeighbour[0]=p1;
    hisNeighbour[1]=p2;
    hisNeighbour[2]=p3;
    hisNeighbour[3]=p4;
}

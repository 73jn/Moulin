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

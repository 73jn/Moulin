#include "board.h"

Board::Board()
{

}

void Board::setRelation(int pointsPos[][2])
{
    for (int i = 0; i < 2; i++){
        vectPoint.append(new Point(i, pointsPos[0][i], pointsPos[1][i]));
    }


}

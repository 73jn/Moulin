#include "board.h"

Board::Board()
{

}

void Board::setRelation(int pointsPos[][2])
{
    for (int i = 0; i < 26; i++){
        vectPoint.append(new Point(i, pointsPos[i][0], pointsPos[i][1]));
    }


}

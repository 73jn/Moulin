#include "board.h"
#include "config.h"
Board::Board()
{

}

void Board::setRelation(int pointsPos[][2], int pointNeigh[][4])
{

    for (int i = 0; i < MAXPOINTS; i++){ //Create 24 Points in vectPoint QVector with the correct coordonate
        vectPoint.append(new Point(i, pointsPos[i][0], pointsPos[i][1]));
    }

    for (int j = 0; j < MAXPOINTS; j++){ //Set each point neighbour
        if (pointNeigh[j][2]==-1 && pointNeigh[j][3]==-1){
            vectPoint.at(j)->setNeighbour(vectPoint.at(pointNeigh[j][0]), vectPoint.at(pointNeigh[j][1]), nullptr, nullptr);
        }
        else if (pointNeigh[j][3]==-1) {
            vectPoint.at(j)->setNeighbour(vectPoint.at(pointNeigh[j][0]), vectPoint.at(pointNeigh[j][1]), vectPoint.at(pointNeigh[j][2]), nullptr);
        }
        else {
            vectPoint.at(j)->setNeighbour(vectPoint.at(pointNeigh[j][0]), vectPoint.at(pointNeigh[j][1]), vectPoint.at(pointNeigh[j][2]), vectPoint.at(pointNeigh[j][3]));
        }

    }

}

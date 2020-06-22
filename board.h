#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include "point.h"
class Board
{

public:
    Board(); //Constructor
    QVector<Point*> vectPoint; //Contains all points
    QVector<int> vectMillOnBoardPos; //Contains the current mill on the board

    //================================================================
    // This function create in the QVector vectPoint 24 Points with
    // the her coordonate.
    // This function set for each point his neighbour
    //================================================================
    // Input : int pointPos[][], the points coordonate
    //         int pointNeigh[][], the neighbour of each point
    // Output : void
    //================================================================
    void setRelation(int relation[][2], int pointNeigh[][4]);
};

#endif // BOARD_H

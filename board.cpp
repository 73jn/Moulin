#include "board.h"

Board::Board()
{

}

void Board::setRelation(int **pointsPos)
{
    for (int i = 0; i < 24; i++){
        vectPoint().append(*new Point(i, pointsPos[0][i], pointsPos[1][i]));
    }
    /*
        int position, p1, p2, p3, p4;
    for (int i = 0; i < 24; i++){
        vector().append(*new Point());
    }

    for (int i = 0; i < vector().size(); i++){
        position = relation[0][i];
        p1 = relation[1][i];
        p2 = relation[2][i];
        p3 = relation[3][i];
        p4 = relation[4][i];
        if (p3 >= 0 && p4 >= 0){
            position = vector().value(i).position;
        }
    }
    */
}

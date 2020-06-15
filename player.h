#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"

class Player
{
public:
    Player(Color colorTeam);
    void removeAPawn();
    int getPawnNumber();
    Color getColorTeam();
private:
    int numberOfPawn = 8;
    Color colorTeam;
};

#endif // PLAYER_H

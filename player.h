#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"
#define NUMBERPAWN 8
class Player
{
public:
    Player(Color colorTeam);
    void removeAPawn();
    int getPawnNumber();
    Color getColorTeam();
    void resetPlayer();
private:
    int numberOfPawn = NUMBERPAWN;
    Color colorTeam;
};

#endif // PLAYER_H

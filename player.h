#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"
#define NUMBERPAWN 8
class Player
{
public:
    Player(Color colorTeam);

    //====================================================
    // Function name : removeAPawn
    // remove a pawn in the hand of the player
    //====================================================
    // Input : void
    // Output : void
    //====================================================
    void removeAPawn();

    //====================================================
    // Function name : getPawnNumber
    // return the number of pawn in hand
    //====================================================
    // Input : void
    // Output : int
    //====================================================
    int getPawnNumber();
    Color getColorTeam();
    void resetPlayer();
private:
    int numberOfPawn = NUMBERPAWN;
    Color colorTeam;
};

#endif // PLAYER_H

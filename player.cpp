#include "player.h"



Player::Player(Color colorTeam)
{
    this->colorTeam = colorTeam;
}

void Player::removeAPawn()
{
    numberOfPawn--;
}

int Player::getPawnNumber()
{
    return numberOfPawn;
}

Color Player::getColorTeam()
{
    return colorTeam;
}

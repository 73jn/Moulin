#ifndef FACTORY_H
#define FACTORY_H

#include "gamedata.h"
#include "gamecontroller.h"
#include "gameinput.h"
#include "gameoutput.h"

#define NBROV 1

class Factory
{
public:
    Factory();
    ~Factory();
    void build();
private:
    GameData* data;
    GameController* logic;
    GameOutput** v1;
    GameInput* v2;
};

#endif // FACTORY_H

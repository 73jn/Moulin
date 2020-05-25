#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gamedata.h"
#include <QString>

class GameController
{
public:
    GameController();
    void initRelations(GameData* d);
    void onInput(QString data);
    void onMove(QString source, QString destination);
    void onEat(QString target);
    void onPlace(QString target);
private:
    GameData* pData;
};

#endif // GAMECONTROLLER_H

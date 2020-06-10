#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gamedata.h"
#include <QString>

class GameController
{
public:
    enum SigIdentifier {PLACESIG, MOVESIG, EATSIG};
    enum State {PLACING, EATING, MOVING, END};
    GameController();
    void initRelations(GameData* d);
    void onMove(QString source, QString destination);
    void onEat(QString target);
    void onPlace(QString target);
    State getState();
private:
    GameData* pData;
    State state = PLACING;
    void onAction(SigIdentifier SI, int target, int destination);
};

#endif // GAMECONTROLLER_H

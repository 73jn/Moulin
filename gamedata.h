#ifndef GAMEDATA_H
#define GAMEDATA_H
#include "rules.h"
#include "board.h"
#include "player.h"
#include "observer.h"
#include "humanplayer.h"
#include <QPainter>
#include <QWidget>
class GameData
{
public:
    GameData();
    void subscribe(Observer* obs);
    void notifyAll();
    bool placePawn(int pos);
    bool removePawn(int pos);
    bool movePawn(int src, int dest);
    void changeActualPlayer();
    bool checkNewMill();
    bool noMorePawnToPlace();
    HumanPlayer* pHuman1;
    HumanPlayer* pHuman2;
    Player* pActualPlayer = pHuman1;
    Player* pWaitingPlayer;
    Board* pBoard;
    Rules* pRules;
private:
    Observer** observers;
    int obsCnt;
    bool isAMill(int target);
};
#endif // GAMEDATA_H

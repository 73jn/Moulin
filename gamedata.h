#ifndef GAMEDATA_H
#define GAMEDATA_H
#include "rules.h"
#include "board.h"
#include "player.h"
#include "observer.h"
#include <QPainter>
#include <QWidget>
class GameData
{
public:
    GameData();
    void subscribe(Observer* obs);
    void notifyAll();
    void placePawn(int pos);
    void removePawn(int pos);
    void movePawn(int src, int dest);
    Board* pBoard;
    Rules* pRules;
private:
    Observer** observers;
    int obsCnt;
};
#endif // GAMEDATA_H

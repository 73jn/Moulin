#ifndef GAMEDATA_H
#define GAMEDATA_H
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
    Board* pBoard;
private:
    Observer** observers;
    int obsCnt;
};
#endif // GAMEDATA_H

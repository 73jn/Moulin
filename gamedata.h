#ifndef GAMEDATA_H
#define GAMEDATA_H
#include "rules.h"
#include "board.h"
#include "player.h"
#include "observer.h"
#include "humanplayer.h"
#include <QPainter>
#include <QWidget>
#include <QObject>
class GameData : public QObject
{
    Q_OBJECT
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
    bool isFlyingMode(Player* pPlayer);
    Color actualPlayerColor();
    bool checkEndGame();
    bool isStuck(Player* pPlayer);
    int getRemainPawnToPlace(Color color);
    void resetGame();
    HumanPlayer* pHuman1;
    HumanPlayer* pHuman2;
    Player* pActualPlayer = pHuman1;
    Player* pWaitingPlayer;
    Player* pWinner;
    Board* pBoard;
    Rules* pRules;
signals:
    void sigResetGame();
    void sigEndGame();
private:
    int numberPlayerPawnOnBoard(Player * pPlayer);
    Observer** observers;
    int obsCnt;
    bool isAMill(int target);
    void delMill(int target);
};
#endif // GAMEDATA_H

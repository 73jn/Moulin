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

    //====================================================
    // Function name : subscribe
    // subscribe to an observer
    //====================================================
    // Input : Observer* obs
    // Output : void
    //====================================================
    void subscribe(Observer* obs);

    //====================================================
    // Function name : notifyAll
    // update all observers
    //====================================================
    // Input : void
    // Output : void
    //====================================================
    void notifyAll();

    //====================================================
    // Function name : placePawn
    // try to place a pawn at the selected position on the
    // grid, return true if has been placed
    //====================================================
    // Input : int pos, point position
    // Output : bool, return true if succeded
    //====================================================
    bool placePawn(int pos);

    //====================================================
    // Function name : removePawn
    // try to del a pawn at the selected position on the
    // grid, return true if has been deleted
    //====================================================
    // Input : int pos, point position
    // Output : bool, return true if succeded
    //====================================================
    bool removePawn(int pos);

    //====================================================
    // Function name : movePawn
    // try to move a pawn at the selected position on the
    // grid, return true if has been moved
    //====================================================
    // Input : int src, point source position
    //         int dest, point destination position
    // Output : bool, return true if succeded
    //====================================================
    bool movePawn(int src, int dest);

    //====================================================
    // Function name : changeActualPlayer
    // switch player
    //====================================================
    // Input : void
    // Output : void
    //====================================================
    void changeActualPlayer();

    //====================================================
    // Function name : checkNewMill
    // check for a new Mill that is not in vectMillOnBoard
    //====================================================
    // Input : void
    // Output : bool, return true if there is a new mill
    //====================================================
    bool checkNewMill();

    //====================================================
    // Function name : noMorePawnToPlace
    // check if there is any pawn to be place
    //====================================================
    // Input : void
    // Output : bool, return true if there is a no more
    // pawn to place
    //====================================================
    bool noMorePawnToPlace();

    //====================================================
    // Function name : isFlyingMode
    // check if the player has 3 pawn on the board
    //====================================================
    // Input : Player* pPlayer, pointer of the selected player
    // Output : bool, return true if the player has 3 pawn on board
    //====================================================
    bool isFlyingMode(Player* pPlayer);

    //====================================================
    // Function name : actualPlayerColor
    // get the actual player color
    //====================================================
    // Input : void
    // Output : Color, see color.h
    //====================================================
    Color actualPlayerColor();

    //====================================================
    // Function name : checkEndGame
    // check if the game is ended
    //====================================================
    // Input : void
    // Output : bool, return true game is ended
    //====================================================
    bool checkEndGame();

    //====================================================
    // Function name : isStuck
    // check if the player has been stuck by the other player
    //====================================================
    // Input : Player* pPlayer, pointer of the selected player
    // Output : bool, return true if the player is stuck
    //====================================================
    bool isStuck(Player* pPlayer);

    //====================================================
    // Function name : getRemainPawnToPlace
    // get how many pawn has to be place
    //====================================================
    // Input : Color color, team color
    // Output : int, return the number of remain pawn to place
    //====================================================
    int getRemainPawnToPlace(Color color);

    //====================================================
    // Function name : resetGame
    // call when we want reset the game, clear the board
    //====================================================
    // Input : void
    // Output : void
    //====================================================
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

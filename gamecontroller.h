#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gamedata.h"
#include <QString>
#include <QObject>
class GameController : public QObject
{
    Q_OBJECT
public:
    enum SigIdentifier {PLACESIG, MOVESIG, EATSIG, PLAYSIG};
    enum State {PLACING, EATING, MOVING, END, MENUPLAY};

    //===================================
    // Constructor of GameController
    //===================================
    GameController();

    //=====================================================
    // Function name : initRelations
    // This function connect pData to a pointer GameData
    //=====================================================
    // Input : GameData* d, GameData pointer
    //=====================================================
    void initRelations(GameData* d);

    //====================================================
    // Function name : onMove
    // This function is call by the gameinput when lineEdit
    // moveDest or moveSrc has been changed with his infos,
    // source and destination
    //====================================================
    // Input : QString source, source points number
    //         QString destination, destination point number
    //====================================================
    void onMove(QString source, QString destination);

    //====================================================
    // Function name : onEat
    // This function is call by the gameinput when lineEdit
    // eat has been changed with his info,
    // target
    //====================================================
    // Input : QString target, target points to eat
    //====================================================
    void onEat(QString target);

    //====================================================
    // Function name : onPlace
    // This function is call by the gameinput when lineEdit
    // place has been changed with his info,
    // target
    //====================================================
    // Input : QString target, target points to place
    //====================================================
    void onPlace(QString target);

    //====================================================
    // Function name : onBtnPlay
    // This function is call by the gameinput
    // when the BtnPlay is clicked
    //====================================================
    // Input : void
    //====================================================
    void onBtnPlay();

    //====================================================
    // Function name : getState
    // return the current state of controller
    //====================================================
    // Input : void
    // Output : State, current state
    //====================================================
    State getState();

    //====================================================
    // Function name : getData
    // return GameData pointer
    //====================================================
    // Input : void
    // Output : GameData*, return GameData pointer
    //====================================================
    GameData *getData();
private slots:

    //====================================================
    // Function name : onResetGame
    // slots call when the game is reset
    //====================================================
    // Input : void
    //====================================================
    void onResetGame();

private:
    GameData* pData;
    State state = MENUPLAY;
    void onAction(SigIdentifier SI, int target, int destination);
};

#endif // GAMECONTROLLER_H

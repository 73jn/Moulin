#include "gamecontroller.h"
#include <QString>
#include <QDebug>
#include <QApplication>
#include "config.h"
#include <QObject>


GameController::GameController() : QObject()
{
    pData = 0;
}

void GameController::initRelations(GameData *d)
{
    pData = d;
    connect(pData, SIGNAL(sigResetGame()), this, SLOT(onResetGame()));
}
void GameController::onMove(QString source, QString destination)
{
    onAction(MOVESIG, source.toInt(), destination.toInt());
}

void GameController::onEat(QString target)
{
    onAction(EATSIG, target.toInt(), UNUSED);
}

void GameController::onPlace(QString target)
{
    onAction(PLACESIG, target.toInt(), UNUSED);
}

void GameController::onBtnPlay()
{
    pData->resetGame();
    onAction(PLAYSIG, UNUSED, UNUSED);
}

GameController::State GameController::getState()
{
    return state;
}


GameData *GameController::getData()
{
    return pData;
}

void GameController::onResetGame()
{
    state = MENUPLAY;
}

void GameController::onAction(SigIdentifier SI, int target, int destination)
{
    switch (state){
    case PLACING:
        if (SI == PLACESIG){
            if(pData->placePawn(target)){
                if(pData->checkNewMill()){
                    state = EATING;
                    qDebug() << "ENTER IN EATING MODE";
                }
                else {
                    pData->changeActualPlayer();
                    if (pData->noMorePawnToPlace()){
                        if (pData->checkEndGame()){
                            state = END;
                            break;
                        }
                        state = MOVING;
                        qDebug() << "ENTER IN MOVING MODE";
                    }
                    else {
                        state = PLACING;
                    qDebug() << "ENTER IN PLACING MODE";
                    }
                }
            }
        }
        break;
    case EATING:
        if (SI == EATSIG){
            if (pData->removePawn(target)){
                if (pData->checkEndGame()){
                    state = END;
                    break;
                }
                pData->changeActualPlayer();
                if (pData->noMorePawnToPlace()){
                    state = MOVING;
                    qDebug() << "ENTER IN MOVING MODE";
                }
                else {
                    state = PLACING;
                    qDebug() << "ENTER IN PLACING MODE";
                }
            }
        }
        break;
    case MOVING:
        if (SI == MOVESIG){
            if (pData->checkEndGame()){
                state = END;
                break;
            }
            if(pData->movePawn(target, destination)){
                if(pData->checkNewMill()){
                    state = EATING;
                    qDebug() << "ENTER IN EATING MODE";
                }
                else {
                    state = MOVING;
                    pData->changeActualPlayer();
                    qDebug() << "ENTER IN MOVING MODE";
                }
            }
        }
        break;
    case END:
        break;
    case MENUPLAY:
        if (SI == PLAYSIG){
            state = PLACING;
            pData->notifyAll();
        }
        break;
    }
}

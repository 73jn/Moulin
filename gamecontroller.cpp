#include "gamecontroller.h"
#include <QString>
#include <QDebug>
#include <QApplication>
#include "config.h"

GameController::GameController()
{
    pData = 0;
}

void GameController::initRelations(GameData *d)
{
    pData = d;
}


void GameController::onMove(QString source, QString destination)
{
    /*
    qDebug() << "[onMove] Source : " <<source.toInt()<< " , Destination : " << destination.toInt() << endl;
    pData->movePawn(source.toInt(),destination.toInt());
    */
    onAction(MOVESIG, source.toInt(), destination.toInt());
}

void GameController::onEat(QString target)
{
/*
    qDebug() << "[onEat] Target : " <<target<< endl;
    pData->removePawn(target.toInt());
*/
    onAction(EATSIG, target.toInt(), UNUSED);
}

void GameController::onPlace(QString target)
{
    /*
    pData->placePawn(target.toInt());
    qDebug() << "[onPlace] Target : " <<target<< endl;
    */
    onAction(PLACESIG, target.toInt(), UNUSED);
}

GameController::State GameController::getState()
{
    return state;
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
    }
}

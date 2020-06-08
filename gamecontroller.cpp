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

    qDebug() << "[onEat] Target : " <<target<< endl;
    pData->removePawn(target.toInt());

    //onAction(EATSIG, target.toInt(), UNUSED);
}

void GameController::onPlace(QString target)
{
    /*
    pData->placePawn(target.toInt());
    qDebug() << "[onPlace] Target : " <<target<< endl;
    */
    onAction(PLACESIG, target.toInt(), UNUSED);
}

void GameController::onAction(SigIdentifier SI, int target, int destination)
{
    switch (state){
    case PLACING:
        if (SI == PLACESIG){
            if(pData->placePawn(target)){
                qDebug() << "SWITCH PASSED";
            }
        }
        break;
    }
}

#include "gamecontroller.h"
#include <QString>
#include <QDebug>
#include <QApplication>

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
    qDebug() << "[onMove] Source : " <<source.toInt()<< " , Destination : " << destination.toInt() << endl;
    pData->movePawn(source.toInt(),destination.toInt());
}

void GameController::onEat(QString target)
{
    qDebug() << "[onEat] Target : " <<target<< endl;
    pData->removePawn(target.toInt());
}

void GameController::onPlace(QString target)
{
    pData->placePawn(target.toInt());
    qDebug() << "[onPlace] Target : " <<target<< endl;
}

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
    int src = source.toInt();
    int dest = destination.toInt();
    qDebug() << "[onMove] Source : " <<src<< " , Destination : " << dest << endl;

}

void GameController::onEat(QString target)
{
    qDebug() << "[onEat] Target : " <<target<< endl;
}

void GameController::onPlace(QString target)
{
    pData->placePawn(target.toInt());
    qDebug() << "[onPlace] Target : " <<target<< endl;
}

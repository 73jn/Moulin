#include "gamedata.h"
#include "observer.h"
#include "QDebug"
#define MAXOBSERVERS 1

GameData::GameData()
{
    observers = new Observer*[MAXOBSERVERS];

    for (int cnt=0; cnt<MAXOBSERVERS; cnt++)
    {
        observers[cnt] = 0;
    }
    obsCnt=0;
    pBoard = new Board();
    pRules = new Rules();
    pBoard->setRelation(pRules->pointTab);
}

void GameData::subscribe(Observer *obs)
{
    if (obsCnt < MAXOBSERVERS)
    {
        observers[obsCnt] = obs;
    }
    obsCnt++;
}

void GameData::notifyAll()
{
    for (int cnt=0; cnt<MAXOBSERVERS; cnt++)
    {
        if (observers[cnt])
        {
            observers[cnt]->changed();
        }

    }
}

void GameData::placePawn(int pos)
{

    for (int i = 0; i < pBoard->vectPoint.size(); i++){
        qDebug() << "i : " << i << ", number : " << pBoard->vectPoint.value(i)->number << " , isEmpty : " << pBoard->vectPoint.value(i)->isEmpty() << endl;
        if (pBoard->vectPoint.value(i)->number == pos && pBoard->vectPoint.value(i)->isEmpty()==true){
            qDebug() << "Create A Pawn" << endl;
            (pBoard->vectPoint.value(i)->pPawn) = new Pawn();
            notifyAll();
        }

    }


}

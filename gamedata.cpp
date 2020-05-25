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

    for (int i = 0; i < pBoard->vectPoint().size(); i++){
        if (pBoard->vectPoint().value(i).number == pos && pBoard->vectPoint().value(i).isEmpty()!=0){
            *(pBoard->vectPoint().value(i).pPawn) = *new Pawn();
            notifyAll();
        }

    }

}

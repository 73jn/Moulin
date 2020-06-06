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
    pBoard->setRelation(pRules->pointTab, pRules->pointNeigh);
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

void GameData::removePawn(int pos)
{
    for (int i = 0; i < pBoard->vectPoint.size(); i++){
        if (pBoard->vectPoint.value(i)->number == pos && pBoard->vectPoint.value(i)->isEmpty()==false){
            qDebug() << "Del Pawn" << endl;
            delete((pBoard->vectPoint.value(i)->pPawn));
            (pBoard->vectPoint.value(i)->pPawn)=nullptr;
            notifyAll();
        }
    }
}

void GameData::movePawn(int src, int dest)
{
    bool isNeighbour = false;
    for (int i = 0; i < pBoard->vectPoint.size(); i++){
        if (pBoard->vectPoint.value(i)->number == src && pBoard->vectPoint.value(i)->isEmpty()==false){
            qDebug() << "Move Pawn" << endl;
            for (int j = 0; j < pBoard->vectPoint.size(); j++){
                if (pBoard->vectPoint.value(j)->number == dest && pBoard->vectPoint.value(j)->isEmpty()==true){


                    //This part check if the dest is a neighbour of the source
                    //If not, isNeighbour will be false and we would'nt change the pawn position
                    for (int k = 0; k < 4; k++){
                        if((pBoard->vectPoint.at(i)->hisNeighbour[k]==pBoard->vectPoint.at(j))&&pBoard->vectPoint.at(i)->hisNeighbour[k]!=nullptr){
                            isNeighbour = true;
                            break;
                        }
                    }
                    if (isNeighbour){
                        qDebug() << "Del Pawn" << endl;
                        pBoard->vectPoint.value(j)->pPawn=pBoard->vectPoint.value(i)->pPawn;
                        pBoard->vectPoint.value(i)->pPawn = nullptr;
                        notifyAll();
                    }

                }
            }
        }
    }
}

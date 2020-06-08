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
    pHuman1 = new HumanPlayer(RED);
    pHuman2 = new HumanPlayer(BLUE);
    pActualPlayer = pHuman1;
    pWaitingPlayer = pHuman2;
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

bool GameData::placePawn(int pos)
{
    for (int i = 0; i < pBoard->vectPoint.size(); i++){
        //qDebug() << "i : " << i << ", number : " << pBoard->vectPoint.value(i)->number << " , isEmpty : " << pBoard->vectPoint.value(i)->isEmpty() << endl;
        if (pBoard->vectPoint.value(i)->number == pos && pBoard->vectPoint.value(i)->isEmpty()==true){
            qDebug() << "Create A Pawn" << endl;
            (pBoard->vectPoint.value(i)->pPawn) = new Pawn(pActualPlayer->getColorTeam());
            pActualPlayer->removeAPawn();
            notifyAll();
            return true;
        }
    }
    return false;
}

bool GameData::removePawn(int pos)
{
    for (int i = 0; i < pBoard->vectPoint.size(); i++){
        if (pBoard->vectPoint.value(i)->number == pos && pBoard->vectPoint.value(i)->isEmpty()==false && !isAMill(pos)){
            qDebug() << "Del Pawn" << endl;
            delete((pBoard->vectPoint.value(i)->pPawn));
            (pBoard->vectPoint.value(i)->pPawn)=nullptr;
            notifyAll();
            return true;
        }
    }
    return false;
}

bool GameData::movePawn(int src, int dest)
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
                        return true;
                    }

                }
            }
        }
    }
    return false;
}

void GameData::changeActualPlayer()
{
    if (pActualPlayer == pHuman1){
        pActualPlayer = pHuman2;
        pWaitingPlayer = pHuman1;
    }
    else if (pActualPlayer == pHuman2){
        pActualPlayer = pHuman1;
        pWaitingPlayer = pHuman2;
    }
}

bool GameData::checkNewMill()
{
    bool alreadyAMill = false;
    for (int i = 0; i < pBoard->vectPoint.size(); i++){
        for (int j = 0; j < pBoard->vectPoint.size(); j++){
            for (int k = 0; k < pBoard->vectPoint.size(); k++){
                for (int l = 0; l < MAXMILL; l++){
                    alreadyAMill = false;
                    for (int m = 0; m < pBoard->vectMillOnBoardPos.size(); m++){
                        if (pBoard->vectMillOnBoardPos.at(m)==l){
                            alreadyAMill = true;
                        }
                    }
                            if (!pBoard->vectPoint.at(i)->isEmpty() && !pBoard->vectPoint.at(j)->isEmpty() &&
                                    !pBoard->vectPoint.at(k)->isEmpty() && !alreadyAMill){
                                if (((pBoard->vectPoint.at(i)->pPawn->colorPawn==pActualPlayer->getColorTeam() &&
                                        pBoard->vectPoint.at(j)->pPawn->colorPawn==pActualPlayer->getColorTeam() &&
                                        pBoard->vectPoint.at(k)->pPawn->colorPawn==pActualPlayer->getColorTeam()) ||
                                        (pBoard->vectPoint.at(i)->pPawn->colorPawn==pWaitingPlayer->getColorTeam() &&
                                         pBoard->vectPoint.at(j)->pPawn->colorPawn==pWaitingPlayer->getColorTeam() &&
                                         pBoard->vectPoint.at(k)->pPawn->colorPawn==pWaitingPlayer->getColorTeam()))
                                        &&
                                        pBoard->vectPoint.at(i)->number == pRules->mill[l][0] &&
                                        pBoard->vectPoint.at(j)->number == pRules->mill[l][1] &&
                                        pBoard->vectPoint.at(k)->number == pRules->mill[l][2])
                                {
                                    qDebug() << "MILL DETECTED !!!!!!!!!!!!!!!!!!!!";
                                    pBoard->vectMillOnBoardPos.append(l);
                                    return true;
                                }
                            }
                }
            }
        }
    }
}

bool GameData::noMorePawnToPlace()
{
    if (pActualPlayer->getPawnNumber() == 0 && pWaitingPlayer->getPawnNumber() == 0){
        return true;
    }
    return false;
}

bool GameData::isAMill(int target)
{
    for (int i = 0; i < pBoard->vectMillOnBoardPos.size(); i++){
        if (pRules->mill[pBoard->vectMillOnBoardPos.at(i)][0] == target ||
                pRules->mill[pBoard->vectMillOnBoardPos.at(i)][1] == target ||
                pRules->mill[pBoard->vectMillOnBoardPos.at(i)][2] == target)
        {
            return true;
        }
    }
    return false;
}

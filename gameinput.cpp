#include "gameinput.h"

GameInput::GameInput(int x, int y, int width, int heigth, QString title) :
                     View(x, y, width, heigth, title)
{
    setupUI();
    connect(lePlace,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
    connect(leMoveDest,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
    connect(leMoveSource,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
    connect(leEat,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
}

void GameInput::setupUI()
{
    lePlace = new QLineEdit("Coordonate Place", this);
    lePlace->setGeometry(10,10,300,20);
    lePlace->selectAll();
    lePlace->setVisible(true);

    leMoveSource = new QLineEdit("Coordonate Source", this);
    leMoveSource->setGeometry(10,50,300,20);
    leMoveSource->selectAll();
    leMoveSource->setVisible(true);

    leMoveSource = new QLineEdit("Coordonate Destination", this);
    leMoveSource->setGeometry(10,90,300,20);
    leMoveSource->selectAll();
    leMoveSource->setVisible(true);

    leEat = new QLineEdit("Coordonate Eat", this);
    leEat->setGeometry(10,130,300,20);
    leEat->selectAll();
    leEat->setVisible(true);
}

void GameInput::onCommandEntered()
{
    QObject* obj = sender();

    if(obj == lePlace){
        pController->onPlace(lePlace->text());
        lePlace->selectAll();
    }
    if(obj == leMoveDest){
        if (leMoveSource->text() != ""){
            pController->onMove(leMoveSource->text(), leMoveDest->text());
        }
        leMoveDest->selectAll();
    }
    if(obj == leMoveSource){
        if (leMoveDest->text() != ""){
            pController->onMove(leMoveSource->text(), leMoveDest->text());
        }
        leMoveSource->selectAll();
    }
    if(obj == leEat){
        pController->onEat(leEat->text());
        leEat->selectAll();
    }

}

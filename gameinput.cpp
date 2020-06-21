#include "gameinput.h"

GameInput::GameInput(int x, int y, int width, int heigth, QString title) :
                     View(x, y, width, heigth, title)
{
    setupUI();
    connect(lePlace,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
    connect(leMoveDest,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
    connect(leMoveSource,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
    connect(leEat,SIGNAL(returnPressed()),this,SLOT(onCommandEntered()));
    connect(btnPlay, SIGNAL (released()),this, SLOT (onCommandEntered()));
}

void GameInput::setupUI()
{
    btnPlay = new QPushButton("PLAY", this);
    btnPlay->setGeometry(100,100,200,100);
    btnPlay->setVisible(true);

    lePlace = new QLineEdit("Coordonate Place", this);
    lePlace->setGeometry(110,10,100,20);
    lePlace->selectAll();

    leMoveSource = new QLineEdit("Coordonate Source", this);
    leMoveSource->setGeometry(110,50,100,20);


    leMoveDest = new QLineEdit("Coordonate Destination", this);
    leMoveDest->setGeometry(110,90,100,20);


    leEat = new QLineEdit("Coordonate Eat", this);
    leEat->setGeometry(110,130,100,20);


    lblPlace = new QLabel("Coordonate Place :", this);
    lblPlace->setGeometry(10,10,100,20);


    lblMoveSource = new QLabel("Coordonate Source :", this);
    lblMoveSource->setGeometry(10,50,100,20);


    lblMoveDest = new QLabel("Coordonate Dest :", this);
    lblMoveDest->setGeometry(10,90,100,20);


    lblEat = new QLabel("Coordonate Eat :", this);
    lblEat->setGeometry(10,130,100,20);

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
    if(obj == btnPlay){
        pController->onBtnPlay();

        btnPlay->setVisible(false);

        lePlace->setVisible(true);
        leMoveSource->setVisible(true);
        leMoveDest->setVisible(true);
        leEat->setVisible(true);
        lblPlace->setVisible(true);
        lblMoveSource->setVisible(true);
        lblMoveDest->setVisible(true);
        lblEat->setVisible(true);
        connect(pController->getData(), SIGNAL(sigEndGame()), this, SLOT(onEndGame()));
    }

}

void GameInput::onEndGame()
{
    btnPlay->setVisible(true);

    lePlace->setVisible(false);
    leMoveSource->setVisible(false);
    leMoveDest->setVisible(false);
    leEat->setVisible(false);
    lblPlace->setVisible(false);
    lblMoveSource->setVisible(false);
    lblMoveDest->setVisible(false);
    lblEat->setVisible(false);
    update();
}

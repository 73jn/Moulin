#include "gameoutput.h"
#include <QDebug>
#include "config.h"
#include "color.h"
#include "gamecontroller.h"
GameOutput::GameOutput(int x, int y, int width, int heigth, QString title)
 : View(x, y, width, heigth, title)
{
    lblInfo = new QLabel(this);
    lblInfo->show();
    lblInfo->setGeometry(200,400,250,100);
    lblInfo->setText("Press Play");
}

void GameOutput::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    drawBoard(&p);
    drawLblInfos();
    drawPawn(&p);
    drawNumber(&p);
}

void GameOutput::drawBoard(QPainter* p)
{
       for (int i = 0; i < MAXPOINTS; i++){
           for (int j = 0; j < 4; j++){
               if (pData->pRules->pointNeigh[i][j]!=-1){
                   p->drawLine(pData->pRules->pointTab[i][0],pData->pRules->pointTab[i][1],pData->pRules->pointTab[pData->pRules->pointNeigh[i][j]][0],pData->pRules->pointTab[pData->pRules->pointNeigh[i][j]][1]);
               }
           }
       }
}

void GameOutput::drawNumber(QPainter *p)
{
    for (int i = 0; i < MAXPOINTS; i++){
        p->drawText(pData->pRules->pointTab[i][0], pData->pRules->pointTab[i][1], QString::number(i));
    }
}

void GameOutput::drawLblInfos()
{
    switch (pController->getState()) {
    case GameController::PLACING:
        if (pData->actualPlayerColor()==RED){
            lblInfo->setText("Red has to place a pawn");
        } else {
            lblInfo->setText("Blue has to place a pawn");
        }
        break;
    case GameController::EATING:
        if (pData->actualPlayerColor()==RED){
            lblInfo->setText("Red has to eat blue's pawn !");
        } else {
            lblInfo->setText("Blue has to eat red's pawn !");
        }
        break;
    case GameController::MOVING:
        if (pData->actualPlayerColor()==RED){
            if (!pData->isFlyingMode(pData->pActualPlayer)) {
                lblInfo->setText("Red has to move a pawn");
            }
            else{
                lblInfo->setText("Red has to move a pawn. You can FLY !");
            }

        } else {
            if (!pData->isFlyingMode(pData->pActualPlayer)) {
                lblInfo->setText("Blue has to move a pawn");
            }
            else{
                lblInfo->setText("Blue has to move a pawn. You can FLY !");
            }
        }
        break;
    case GameController::END:
        if(pData->pWinner->getColorTeam()==RED){
            lblInfo->setText("RED WIN");
        } else {
            lblInfo->setText("BLUE WIN");
        }
        break;
    }

}

void GameOutput::drawPawn(QPainter *p)
{
    for (int i = 0; i < pData->pBoard->vectPoint.size(); i++){
        if (pData->pBoard->vectPoint.value(i)->isEmpty()==false){
            //qDebug() << "[GameOutput::paintEvent] The " << pData->pBoard->vectPoint.value(i) << " is not empty !" << endl;
            if (pData->pBoard->vectPoint.value(i)->pPawn->colorPawn==RED){
                p->setBrush(Qt::red);
            }
            else {
                p->setBrush(Qt::blue);
            }
            p->drawEllipse(pData->pBoard->vectPoint.value(i)->posX-(PAWNSIZE/2), pData->pBoard->vectPoint.value(i)->posY-(PAWNSIZE/2), PAWNSIZE, PAWNSIZE);
        }
    }

    for (int j = 0; j < pData->getRemainPawnToPlace(Color::RED); ++j) {
        p->setBrush(Qt::red);
        p->drawEllipse(j*20+20,430,PAWNSIZE,PAWNSIZE);
    }
    for (int k = 0; k < pData->getRemainPawnToPlace(Color::BLUE); ++k) {
        p->setBrush(Qt::blue);
        p->drawEllipse(k*20+20,460,PAWNSIZE,PAWNSIZE);
    }
}

void GameOutput::changed()
{
    update();
}

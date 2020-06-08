#include "gameoutput.h"
#include <QDebug>
#include "config.h"
GameOutput::GameOutput(int x, int y, int width, int heigth, QString title)
 : View(x, y, width, heigth, title)
{


}

void GameOutput::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    drawBoard(&p);
    for (int i = 0; i < pData->pBoard->vectPoint.size(); i++){
        if (pData->pBoard->vectPoint.value(i)->isEmpty()==false){
            //qDebug() << "[GameOutput::paintEvent] The " << pData->pBoard->vectPoint.value(i) << " is not empty !" << endl;
            if (pData->pBoard->vectPoint.value(i)->pPawn->colorPawn==RED){
                p.setBrush(Qt::red);
            }
            else {
                p.setBrush(Qt::blue);
            }
            p.drawEllipse(pData->pBoard->vectPoint.value(i)->posX-(PAWNSIZE/2), pData->pBoard->vectPoint.value(i)->posY-(PAWNSIZE/2), PAWNSIZE, PAWNSIZE);
        }
    }
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

void GameOutput::changed()
{
    update();
}

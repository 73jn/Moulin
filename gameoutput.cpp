#include "gameoutput.h"

GameOutput::GameOutput(int x, int y, int width, int heigth, QString title)
 : View(x, y, width, heigth, title)
{
}

void GameOutput::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    for (int i = 0; i < pData->pBoard->vectPoint().size(); i++){
        if (pData->pBoard->vectPoint().value(i).isEmpty()==0){
            p.drawEllipse(pData->pBoard->vectPoint().value(i).posX, pData->pBoard->vectPoint().value(i).posY, 20, 20);
        }
    }
}

void GameOutput::changed()
{
    update();
}

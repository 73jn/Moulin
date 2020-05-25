#include "view.h"

#include <QDebug>

View::View(int x, int y, int width, int height, QString title)
{
    pData = 0;
    pController = 0;

    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->title = title;
    setupUI();
}

void View::initRelations(GameData *d, GameController *c)
{
    pData = d;
    pController = c;
}

void View::changed()
{
    //the view does not do anything;
}

void View::stop()
{
    this->close();
    qDebug() << "closing";
}

void View::setupUI()
{
    this->setGeometry(x,y,width,height);
    this->setWindowTitle(title);
    this->setVisible(true);
}


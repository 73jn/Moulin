#ifndef GAMEOUTPUT_H
#define GAMEOUTPUT_H
#include "point.h"
#include <QWidget>
#include <QVector>
#include "view.h"

class GameOutput : public View
{
    Q_OBJECT
public:
    QPainter* painter;
    GameOutput(int x, int y, int width, int heigth, QString title);
    void paintEvent(QPaintEvent* event);
    void drawBoard(QPainter *p);
protected:
    void changed();

};

#endif // GAMEOUTPUT_H

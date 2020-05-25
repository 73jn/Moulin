#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include "observer.h"
#include "gamedata.h"
#include "gamecontroller.h"

class View : public QWidget, public Observer
{
    Q_OBJECT
public:
    View(int x, int y, int width, int heigth, QString title);
    void initRelations(GameData* d, GameController* c);

protected:
    GameData* pData;
    GameController* pController;
    void changed();
    void stop();

private:

    int x;
    int y;
    int height;
    int width;
    QString title;

private:
    void setupUI();
};

#endif // VIEW_H

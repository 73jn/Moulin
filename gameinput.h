#ifndef GAMEINPUT_H
#define GAMEINPUT_H

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "view.h"
class GameInput : public View
{
    Q_OBJECT
public:
    GameInput(int x, int y, int width, int heigth, QString title);


private:
    void setupUI();

private:
    QLineEdit* lePlace;
    QLineEdit* leMoveSource;
    QLineEdit* leMoveDest;
    QLineEdit* leEat;

    QLabel* lblPlace;
    QLabel* lblMoveSource;
    QLabel* lblMoveDest;
    QLabel* lblEat;

    QPushButton* btnPlay;
    QPushButton* btnTwoHumanPlayer;

private slots:
    void onCommandEntered();

};

#endif // GAMEINPUT_H

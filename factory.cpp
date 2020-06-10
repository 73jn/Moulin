#include "factory.h"

Factory::Factory()
{
    data = new GameData();
    logic = new GameController();

    v1 = new GameOutput*[NBROV];
    for (int i=0; i<NBROV; i++)
    {
        QString t;
        t.sprintf("Outputview #%d",i);
        v1[i] = new GameOutput(100+i*50,100+i*50,500,500,t);
    }
    v2 = new GameInput(100,450,400,300,"Command Window");
}

Factory::~Factory()
{
    delete data;
    delete logic;
    for (int i=0; i<NBROV; i++)
    {
        delete v1[i];
    }
    delete[] v1;
    delete v2;
}

void Factory::build()
{
    logic->initRelations(data);
    for (int i=0; i<NBROV; i++)
    {
        v1[i]->initRelations(data, logic);
    }
    v2->initRelations(data, logic);

    for (int i=0; i<NBROV; i++)
    {
        data->subscribe(v1[i]);
    }
}

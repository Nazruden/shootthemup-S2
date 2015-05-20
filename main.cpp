// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// main.cpp

#include <iostream>
#include "GameModel.h"
#include "GameView.h"

using namespace std;

int main()
{
    /*** Launching ***/
    GameModel* model = new GameModel();
    GameView* view = new GameView(model);
    model->setGameView(view);

    model->runGame();

    delete model;
    delete view;

    return 0;
}

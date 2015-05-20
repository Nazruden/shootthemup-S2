// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameEnd.cc

#include "GameEnd.h"
#include <iostream>

using namespace std;

/*** Ctors / Dtors ***/
GameEnd::GameEnd(string title, GameModel* model) : GameState(title, model), _won(false)
{
    _endMessage = "";
}

/*** Accessors ***/
void GameEnd::setWinState(bool winState)
{
    _won = winState;
}

/*** Methods ***/
void GameEnd::update()
{
    if(_won)
        _endMessage = "You won ! Congratulations !";
    else
        _endMessage = "You lose... Try again";
    _model->quitGame();
}

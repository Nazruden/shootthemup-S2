// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameMenu.cc

#include "GameMenu.h"

using namespace std;

/*** Ctors / Dtors ***/
GameMenu::GameMenu(string title, GameModel* model) : GameState(title, model)
{
}

/*** Methods ***/

void GameMenu::enter()
{
    GameState::enter();
}

void GameMenu::update()
{}

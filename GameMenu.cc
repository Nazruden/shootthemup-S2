// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameMenu.cc

#include "GameMenu.h"

using namespace std;

/*** Ctors / Dtors ***/
GameMenu::GameMenu(string title, GameModel* model) : GameState(title, model)
{
    _items.push_back("Play");
    _items.push_back("Quit");
}

/*** Methods ***/

void GameMenu::enter()
{
    GameState::enter();
}

void GameMenu::update()
{}

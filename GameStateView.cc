// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameStateView.cc

#include "GameStateView.h"
#include <string>

using namespace std;

/*** Constructors / Destructors ***/
GameStateView::GameStateView(std::string title, sf::RenderWindow* window, sf::Font* font) : _title(title), _window(window), _font(font), _state(nullptr)
{}

GameStateView::~GameStateView()
{

}

/*** Accessors ***/

void GameStateView::setState(GameState* state)
{
    _state = state;
}

string GameStateView::getTitle()
{
    return _title;
}

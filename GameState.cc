// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameState.cc
#include "GameState.h"
#include "GameView.h"
#include <iostream>
using namespace std;

/*** Constructors / Destructors ***/
GameState::GameState(std::string title, GameModel* model) : _title(title), _model(model), _enabled(false) {}

GameState::~GameState()
{
    cout << "appel destructeur etat" << _title << endl;
}

/*** Accessors ***/
string GameState::getTitle()
{
    return _title;
}

bool GameState::isEnabled()
{
    return _enabled;
}

StateView* GameState::getStateView()
{
    return _stateView;
}

void GameState::setStateView(StateView* stateView)
{
    _stateView = stateView;
}

GameModel* GameState::getModel()
{
    return _model;
}


/*** Methods ***/
void GameState::enter()
{
    _enabled = true;
    setStateView(_model->getGameView()->getStateView(_title));
}

void GameState::leave()
{
    _enabled = false;
}

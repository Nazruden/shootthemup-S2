// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameModel.cc

#include "GameModel.h"
#include "GameMenu.h"
#include "GamePlay.h"
#include "GameEnd.h"
#include "StateView.h"
#include <iostream>
using namespace std;

/*** Ctors / Dtors ***/
GameModel::GameModel()
{
    // Creation of game states
    GameEnd* gameEnd = new GameEnd("gameEnd", this);
    _states.push_back(gameEnd);

    GamePlay* gamePlay = new GamePlay("gamePlay", this);
    _states.push_back(gamePlay);

    GameMenu* gameMenu = new GameMenu("gameMenu", this);
    _states.push_back(gameMenu);
}

/*** Accessors ***/
// Finds the state corresponding to the given title
GameState* GameModel::getState(std::string title)
{
    GameState* state = nullptr;

    bool found = false;
    unsigned int i = 0;

    while (!found && i<_states.size())
    {
        if (_states[i]->getTitle() == title)
        {
            state = _states[i];
            found = true;
        }
        else
            i++;
    }

    return state;
}

GameState* GameModel::getCurrentState()
{
    return _currentState;
}

GameView* GameModel::getGameView()
{
    return _gameView;
}

// Changes the current state
void GameModel::setState(GameState* s)
{
    _currentState->leave();
    _currentState = s;
    _currentState->enter();
}

void GameModel::setGameView(GameView* view)
{
    _gameView = view;
}

/*** Methods ***/
void GameModel::runGame()
{
    _currentState = getState("gameMenu");
    _currentState->enter();
    while(_currentState->isEnabled())
    {
        _currentState->getStateView()->draw();
        _currentState->getStateView()->treatEvents();
        _currentState->getStateView()->update();
        _currentState->update();
    }
}

void GameModel::quitGame()
{
    _currentState->leave();
}

GameModel::~GameModel()
{
    for (auto s: _states)
       if (s != nullptr)
            delete s;
}

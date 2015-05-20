//// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameView.cc

#include "GameView.h"
#include "GameModel.h"
#include "GameState.h"
#include "GamePlay.h"
#include "StateView.h"
#include "StateViewMenu.h"
#include "StateViewPlay.h"

#include <iostream>

using namespace std;
using namespace sf;

GameView::GameView(GameModel* model) : _model(model), _w(VIEW_WIDTH), _h(VIEW_HEIGHT)
{
    _window = new RenderWindow(sf::VideoMode(_w, _h, VIEW_BPP), "Shoot Them Up", sf::Style::Close);
    _window->SetFramerateLimit(60);

    // Creation of state view menu
    StateViewMenu* stateViewMenu = new StateViewMenu("gameMenu", _window, &_font);
    stateViewMenu->setState(_model->getState("gameMenu"));
    _stateViews.push_back(stateViewMenu);

    // Creation of state view play
    StateViewPlay* stateViewPlay = new StateViewPlay("gamePlay", _window, &_font);
    stateViewPlay->setState(_model->getState("gamePlay"));
    _stateViews.push_back(stateViewPlay);

    _font.LoadFromFile("Antique Olive.ttf");
}

GameView::~GameView()
{
    if (_window != nullptr)
        delete _window;

    for (auto s: _stateViews)
        if (s != nullptr)
            delete s;
}

// Finds the state corresponding to the given title
StateView* GameView::getStateView(string title)
{
    StateView* stateView = nullptr;

    bool found = false;
    unsigned int i = 0;

    while (!found && i<_stateViews.size())
    {
        if (_stateViews[i]->getTitle() == title)
        {
            stateView = _stateViews[i];
            found = true;
        }
        else
            i++;
    }

    return stateView;
}

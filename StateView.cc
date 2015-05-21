// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// StateView.cc

#include "StateView.h"
#include <string>
#include <iostream>

using namespace std;

/*** Constructors / Destructors ***/
StateView::StateView(std::string title, sf::RenderWindow* window, sf::Font* font) : _title(title), _window(window), _font(font), _state(nullptr)
{}

StateView::~StateView()
{}

/*** Accessors ***/

void StateView::setState(GameState* state)
{
    _state = state;
}

string StateView::getTitle()
{
    return _title;
}

/*** Methods ***/
void StateView::update()
{}

void StateView::displayTransition(string text)
{
    _transitionText.SetColor(sf::Color::White);
    _transitionText.SetFont(*_font);
    _transitionText.SetSize(50.f);
    _transitionText.SetPosition(TRANSITION_TEXT_X, TRANSITION_TEXT_Y);
    _transitionText.SetText(text);

    sf::Clock clock;
    clock.Reset();

    while (clock.GetElapsedTime() <= 1.5 )
    {
        _window->Clear(sf::Color::Black);
        _window->Draw(_transitionText);
        _window->Display();
    }
}

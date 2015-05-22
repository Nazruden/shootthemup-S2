// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// StateView.h

#ifndef GAME_STATE_VIEW_H
#define GAME_STATE_VIEW_H

#include <SFML/Graphics.hpp>

const int TRANSITION_TEXT_X = 420;
const int TRANSITION_TEXT_Y = 260;

class GameModel;
class GameView;
class GameState;

class StateView
{
protected :
    std::string _title;
    sf::RenderWindow* _window;
    sf::Font* _font;
    sf::String _transitionText;
    GameState* _state;

public:
    StateView(std::string title, sf::RenderWindow* window, sf::Font *font);
    virtual ~StateView();

    virtual void setState(GameState* state);
    std::string getTitle();

    virtual void update();
    virtual void draw() = 0;
    virtual void treatEvents() = 0;
    void displayTransition(std::string text);
};

#endif

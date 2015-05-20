// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameStateView.h

#ifndef GAME_STATE_VIEW_H
#define GAME_STATE_VIEW_H

#include <SFML/Graphics.hpp>

class GameModel;
class GameView;
class GameState;

class GameStateView
{
protected :
    std::string _title;
    sf::RenderWindow* _window;
    sf::Font* _font;
    GameState* _state;
    //std::map<MovableElement *, GraphicElement *> _movableGraphicElements;


public:
    GameStateView(std::string title, sf::RenderWindow* window, sf::Font *font);
    virtual ~GameStateView();

    virtual void setState(GameState* state);
    std::string getTitle();

    //void clearMovableGraphicElements();
    //void addMovableGraphicElement(MovableElement* elem);
    //virtual void synchronize();
    virtual void draw() = 0;
    virtual void treatEvents() = 0;
};

#endif

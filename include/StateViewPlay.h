// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// StateViewPlay.h

#ifndef STATE_VIEW_PLAY_H
#define STATE_VIEW_PLAY_H

#include <SFML/Graphics.hpp>

#include "../include/StateView.h"

const int SCORE_X = 550;
const int SCORE_Y = 15;
const int LIFEPOINTS_X = 260;
const int LIFEPOINTS_Y = 15;
const int LEVEL_X = 15;
const int LEVEL_Y = 15;
const int NBLIVES_X = 755;
const int NBLIVES_Y = 15;
const int BACKGROUND_W = 2340;

class MovableElement;
class GraphicElement;
class GamePlay;
class StateViewPlay : public StateView
{
private:
    std::vector<GraphicElement*> _graphicElements;
    std::map<GraphicElement*, MovableElement*> _graphicToMovable;
    sf::Image _playerImg;
    sf::Image _backgroundImg;
    sf::Image _backgroundTopBar;
    sf::Image _backgroundHealthBar;
    sf::Image _healthBar;

    sf::Image _ennemy0Img;
    sf::Image _shotImg;
    std::map<std::string, sf::Image> _images;

    sf::String _score;
    sf::String _lifepoints;
    sf::String _nbLives;
    sf::String _level;
    sf::String _eventToNotice;

public:
    // Constructors / Destructors
    StateViewPlay(std::string title, sf::RenderWindow* window, sf::Font* font);

    // Accessors
    GraphicElement* getElement(int id);
    void setGraphicToMovableElem(GraphicElement* graphicElem, MovableElement* movableElem);
    sf::Image* getImg(std::string imgName);

    // Methods
    void update() override;
    void draw() override;
    void treatEvents() override;

    void deleteGraphicToMovableElem(int id);
};

#endif

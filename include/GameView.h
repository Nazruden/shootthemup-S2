// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameView.h

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <SFML/Graphics.hpp>
#include <vector>

const int VIEW_WIDTH = 1000;
const int VIEW_HEIGHT = 600;
const int VIEW_BPP = 32;

class GameModel;
class StateView;

class GameView
{
private :
    GameModel* _model;
    int _w, _h;
    sf::RenderWindow* _window;
    sf::Font _font;
    std::vector<StateView*> _stateViews;

public:
    GameView(GameModel* model);
    ~GameView();

    StateView* getStateView(std::string title);

};

#endif

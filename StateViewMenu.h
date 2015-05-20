// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// StateViewMenu.h

#ifndef STATE_VIEW_MENU_H
#define STATE_VIEW_MENU_H

#include <SFML/Graphics.hpp>

#include "StateView.h"

const int BUTTONPLAY_X = 600;
const int BUTTONPLAY_Y = 350;

const int BUTTONQUIT_X = 600;
const int BUTTONQUIT_Y = 460;


/** Nouveau menu **/
const int BUTTON_W = 270;
const int BUTTON_H = 40;
const int BUTTON_X = 1000 - BUTTON_W;
/**/

//const int BUTTON_W = 150;
//const int BUTTON_H = 80;

class GraphicElement;
class StateViewMenu : public StateView
{
private:
    std::vector<GraphicElement*> _graphicElements;
    sf::Image _logoImg;
    sf::Image _buttonsImg;
    sf::Image _reviveImg;
    sf::Image _logoSpaceship;
    sf::Image _backgroundFooter;
    sf::Image _backgroundMenu;
    sf::Image _background;
    std::vector<GraphicElement*> _menuButtons;
    std::vector<sf::String*> _menuItems;

    sf::String _title;
    sf::String _play;
    sf::String _quit;
    sf::String _options;
    sf::String _scores;

    sf::Font _font_WalkwayBold;
    sf::Font _font_WalkwaySemiBold;
    sf::Font _font_WalkwayBlack;

public:
   // Constructors / Destructors
    StateViewMenu(std::string title, sf::RenderWindow* window, sf::Font* font);
    ~StateViewMenu();

    // Methods
    void draw() override;
    void treatEvents() override;

};

#endif


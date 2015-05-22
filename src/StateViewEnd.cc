// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// StateViewMenu.cc

#include "../include/StateViewMenu.h"
#include "../include/GraphicElement.h"
#include "../include/GameState.h"
#include <iostream>
using namespace std;

const int VIEW_WIDTH = 1000;
const int VIEW_HEIGHT = 600;

const int MENU_WIDTH = 330;
const int MENU_HEIGHT = 400;

const int FIRSTBUTTON_Y = VIEW_HEIGHT/2 - MENU_HEIGHT/2 + 140 - BUTTON_H;

/*** Ctors / Dtors ***/
StateViewMenu::StateViewEnd(std::string title, sf::RenderWindow* window, sf::Font* font) : StateView(title, window, font)
{
    // Loading fonts
    _font_WalkwayBold.LoadFromFile("polices/Walkway Bold.ttf");
    _font_WalkwayBlack.LoadFromFile("polices/Walkway Black.ttf");
    _font_WalkwaySemiBold.LoadFromFile("polices/Walkway SemiBold.ttf");

    // Creation of state's background
    if(_background.LoadFromFile("img/new/bg_home.jpg"))
    {
        GraphicElement* bg_home = new GraphicElement(&_background);
        bg_home->setPosition(0,0);
        bg_home->Resize(VIEW_WIDTH, VIEW_HEIGHT);
        _graphicElements.push_back(bg_home);
    }

    // Creation of bottom border
    if (_backgroundFooter.LoadFromFile("img/new/bg_footer.png"))
    {
        GraphicElement* bg_footer = new GraphicElement(&_backgroundFooter);
        bg_footer->setPosition(0, VIEW_HEIGHT - 100);
        _graphicElements.push_back(bg_footer);
    }

    // Creation of text elements
    _title.SetText("Shoot Them Up");
    _title.SetPosition(10, VIEW_HEIGHT - 75);
    _title.SetFont(_font_WalkwayBlack);
    _title.SetSize(64.f);

    _play.SetText("Play");
    _quit.SetText("Quit");
    _scores.SetText("Scores");
    _options.SetText("Options");
    _menuItems.push_back(&_play);
    _menuItems.push_back(&_scores);
    _menuItems.push_back(&_options);
    _menuItems.push_back(&_quit);

    int cpt = 0;
    for(auto item : _menuItems)
    {
        item->SetColor(sf::Color::White);
        item->SetFont(_font_WalkwayBold);
        item->SetSize(40.f);
        // Placing text menu's items
        item->SetPosition(BUTTON_X + 20, FIRSTBUTTON_Y + (cpt * BUTTON_H) + 4);
        ++cpt;
    }
}

StateViewEnd::~StateViewEnd()
{
    for (auto elem : _graphicElements)
        if (elem != nullptr)
            delete elem;
    for (auto item : _menuItems)
        if (item != nullptr)
            delete item;
    for (auto button : _menuButtons)
        if (button != nullptr)
            delete button;

}

/*** Methods ***/
void StateViewEnd::draw()
{
    _window->Clear(sf::Color::White);

    for (auto elem: _graphicElements)
      _window->Draw(*elem);

    for(auto item: _menuItems)
        _window->Draw(*item);
    _window->Draw(_title);

    _window->Display();
}

void StateViewEnd::treatEvents()
{
    if (_window->IsOpened())
    {
        sf::Event event;
        // While getting an event in the queue of events
        while (_window->GetEvent(event))
        {
            // Closing the game
            if ((event.Type == sf::Event::Closed) || ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape)))
                _window->Close();
            if(event.Key.Code == sf::Key::Space)
            {
                GameModel* model = _state->getModel();
                model->setState(model->getState("gameMenu"));
                cout << "Going back to the menu." << endl;
                _window->Clear();
            }

            // Input events
            const sf::Input& Input = _window->GetInput();

        }
    }
}



// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// StateViewMenu.cc

#include "StateViewMenu.h"
#include "GraphicElement.h"
#include "GameState.h"
#include <iostream>
using namespace std;

const int VIEW_WIDTH = 1000;
const int VIEW_HEIGHT = 600;

const int MENU_WIDTH = 330;
const int MENU_HEIGHT = 400;

const int FIRSTBUTTON_Y = VIEW_HEIGHT/2 - MENU_HEIGHT/2 + 140 - BUTTON_H;

/*** Ctors / Dtors ***/
StateViewMenu::StateViewMenu(std::string title, sf::RenderWindow* window, sf::Font* font) : StateView(title, window, font)
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

    // Creation of menu's background
    if(_backgroundMenu.LoadFromFile("img/new/bg_menu_v2.png"))
    {
        GraphicElement* bg_menu = new GraphicElement(&_backgroundMenu);
        bg_menu->setPosition(VIEW_WIDTH - MENU_WIDTH, VIEW_HEIGHT/2 - MENU_HEIGHT/2);
        _graphicElements.push_back(bg_menu);
    }

    // Creation of bottom border
    if (_backgroundFooter.LoadFromFile("img/new/bg_footer.png"))
    {
        GraphicElement* bg_footer = new GraphicElement(&_backgroundFooter);
        bg_footer->setPosition(0, VIEW_HEIGHT - 100);
        _graphicElements.push_back(bg_footer);
    }

    // Creation of the logo
    if (_logoSpaceship.LoadFromFile("img/new/logo.png"))
    {
        GraphicElement* spaceship = new GraphicElement(&_logoSpaceship);
        spaceship->setPosition((VIEW_WIDTH - MENU_WIDTH)/2 - 200, (VIEW_HEIGHT-100)/2 - 210);
        _graphicElements.push_back(spaceship);
    }

    // Creation of buttons
    if (_buttonsImg.LoadFromFile("img/new/bg_buttons.jpg"))
    {
        GraphicElement* buttonPlay = new GraphicElement(&_buttonsImg);
        GraphicElement* buttonQuit = new GraphicElement(&_buttonsImg);
        GraphicElement* buttonScores = new GraphicElement(&_buttonsImg);
        GraphicElement* buttonOptions = new GraphicElement(&_buttonsImg);

        _menuButtons.push_back(buttonPlay);
        _menuButtons.push_back(buttonQuit);
        _menuButtons.push_back(buttonScores);
        _menuButtons.push_back(buttonOptions);

        int cpt =0;
        for(auto button : _menuButtons)
        {
            button->SetSubRect(sf::IntRect(BUTTON_W, 0, BUTTON_W*2, BUTTON_H));
            button->Resize(BUTTON_W, BUTTON_H);
            // Placing buttons background
            button->SetPosition(BUTTON_X, FIRSTBUTTON_Y + (cpt * BUTTON_H) + 10);
            ++cpt;
        }
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

StateViewMenu::~StateViewMenu()
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
void StateViewMenu::draw()
{
    _window->Clear(sf::Color::White);

    for (auto elem: _graphicElements)
      _window->Draw(*elem);

    for (auto button: _menuButtons)
      _window->Draw(*button);

    for(auto item: _menuItems)
        _window->Draw(*item);
    _window->Draw(_title);

    _window->Display();
}

void StateViewMenu::treatEvents()
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

            // Clicking events
            if (event.Type == sf::Event::MouseButtonPressed)
            {
                // Clicking on the menu
                if ((event.MouseButton.X >= VIEW_WIDTH - MENU_WIDTH) && (event.MouseButton.X < VIEW_WIDTH)
                    && (event.MouseButton.Y >= FIRSTBUTTON_Y - 20) && (event.MouseButton.Y < VIEW_HEIGHT/2 + MENU_HEIGHT/2))
                {
                    unsigned int y = event.MouseButton.Y - FIRSTBUTTON_Y;
                    if(y > 0 && y < _menuItems.size() * BUTTON_H)
                    {
                        int indice = (y - (y%BUTTON_H))  / BUTTON_H;
                        if (indice == 0)
                        {
                            GameModel* model = _state->getModel();
                            model->setState(model->getState("gamePlay"));
                            cout << "Launching the game." << endl;
                            _window->Clear();
                        }
                        /** Scores **/
                        else if (indice == 1)
                        {
                        // A REMPLIR
                        }
                        /** Options **/
                        else if (indice == 2)
                        {
                        // A REMPLIR
                        }
                        /** Quit **/
                        else if (indice == 3)
                        {
                                cout << "Leaving the game." << endl;
                                _window->Clear();
                                _state->getModel()->quitGame();
                        }
                    }
                }
            }

            // Input events
            const sf::Input& Input = _window->GetInput();

            // Hovering the menu
            if ((Input.GetMouseX() >= VIEW_WIDTH - MENU_WIDTH) && (Input.GetMouseX() < VIEW_WIDTH)
                && (Input.GetMouseY() >= FIRSTBUTTON_Y) && (Input.GetMouseY() < FIRSTBUTTON_Y + _menuButtons.size() * BUTTON_H))
            {
                unsigned int y = Input.GetMouseY() - FIRSTBUTTON_Y;
                if(y > 0 && y < _menuButtons.size() * BUTTON_H)
                {
                    // Resetting menu
                    for (auto button : _menuButtons)
                        button->SetSubRect(sf::IntRect(BUTTON_W, 0, BUTTON_W*2, BUTTON_H));

                    // Getting hovered item id
                    int indice = (y - (y%BUTTON_H))  / BUTTON_H;
                    // Applying hover effect
                    if (indice >= 0)
                    {
                        _menuButtons[indice]->SetSubRect(sf::IntRect(0, 0, BUTTON_W, BUTTON_H));
                    }
                }
            }

            else
            {
                // Resetting menu
                for (auto button : _menuButtons)
                    button->SetSubRect(sf::IntRect(BUTTON_W, 0, BUTTON_W*2, BUTTON_H));
            }

            _window->Display();
        }
    }
}

// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// StateViewPlay.cc

#include "StateViewPlay.h"
#include "GamePlay.h"
#include "GameState.h"
#include "Player.h"
#include "GraphicElement.h"

#include <iostream>
using namespace std;

StateViewPlay::StateViewPlay(std::string title, sf::RenderWindow* window, sf::Font* font) : StateView(title, window, font)
{
    // Creation the background graphic element
    if (_backgroundImg.LoadFromFile("img/new/background_1.jpg"))
    {
        GraphicElement* background = new GraphicElement(&_backgroundImg);
        background->Resize(2340, GAMEPLAY_HEIGHT);
        //background->SetSubRect(sf::IntRect(0, 0, GAMEPLAY_WIDTH, GAMEPLAY_HEIGHT));
        background->setPosition(0, 0);
        _graphicElements.push_back(background);
    }

    // Creation the player graphic element
    if (_playerImg.LoadFromFile("img/new/playership.png"))
    {
        GraphicElement* player = new GraphicElement(&_playerImg);
        player->setPosition(PLAYER_X_INIT, PLAYER_Y_INIT);
        player->SetSubRect(sf::IntRect(0, 0, 300, 200));
        player->Resize(PLAYER_WIDTH, PLAYER_HEIGHT);
        player->setId(0);
        // Will be linked to the player after
        _graphicToMovable[player] = nullptr;
    }

    // Loading the other images
    sf::Image img;
    img.LoadFromFile("img/new/blue_projectiles.png");
    _images["shot"] = img;
    img.LoadFromFile("img/new/yellow_projectiles.png");
    img.LoadFromFile("img/new/purple_projectiles.png");
    img.LoadFromFile("img/new/red_projectiles.png");
    img.LoadFromFile("img/ennemy_0.png");
    _images["ennemy0"] = img;

    img.LoadFromFile("img/ennemy_1.png");
    _images["ennemy1"] = img;

    img.LoadFromFile("img/ennemy_2.png");
    _images["ennemy2"] = img;

    // Initialization of text elements
    _score.SetColor(sf::Color::White);
    _score.SetFont(*_font);
    _score.SetSize(20.f);
    _score.SetPosition(SCORE_X, SCORE_Y);

    _lifepoints.SetColor(sf::Color::White);
    _lifepoints.SetFont(*_font);
    _lifepoints.SetSize(20.f);
    _lifepoints.SetPosition(LIFEPOINTS_X, LIFEPOINTS_Y);

    _level.SetColor(sf::Color::White);
    _level.SetFont(*_font);
    _level.SetSize(20.f);
    _level.SetPosition(LEVEL_X, LEVEL_Y);


    _nbLives.SetColor(sf::Color::White);
    _nbLives.SetFont(*_font);
    _nbLives.SetSize(20.f);
    _nbLives.SetPosition(NBLIVES_X, NBLIVES_Y);

}

GraphicElement* StateViewPlay::getElement(int id)
{
    auto it = _graphicToMovable.begin();
    bool found = false;
    GraphicElement* elem = nullptr;

    while ( it != _graphicToMovable.end() && !found)
    {
        if ( it->first->getId() == id)
        {
            elem = it->first;
            found = true;
        }

        else
            it++;
    }

    return elem;
}

void StateViewPlay::setGraphicToMovableElem(GraphicElement* graphicElem, MovableElement* movableElem)
{
   _graphicToMovable[graphicElem] = movableElem;
}

sf::Image* StateViewPlay::getImg(std::string imgName)
{
    auto it = _images.find(imgName);

    if (it != _images.end())
        return &(it->second);
    return nullptr;
}

void StateViewPlay::update()
{
    // Updating text elements
    GamePlay* statePlay = dynamic_cast<GamePlay*>(_state);
    _score.SetText("Score : " + to_string(statePlay->getPlayer()->getScore()) );
    _lifepoints.SetText(statePlay->getPlayer()->getName() + "'s lifepoints : " + to_string(statePlay->getPlayer()->getLifePoints()) );
    _level.SetText("Level : " + to_string(statePlay->getLevel()) );
    _nbLives.SetText( "Lives : " + to_string(statePlay->getPlayer()->getLives()) );

    for (auto it = _graphicToMovable.begin(); it != _graphicToMovable.end(); it++)
    {
        if (it->second != nullptr)
        {
            // Updating the position of each sprite
            int x = it->second->getX();
            int y = it->second->getY();
            it->first->nextFrame();
            it->first->setPosition(x, y);
        }
    }

    // Reinitializing the background
    if (_graphicElements[0]->GetPosition().x - GAMEPLAY_WIDTH == - BACKGROUND_W )
        _graphicElements[0]->SetX(0);

    // Scrolling the background
    _graphicElements[0]->Move(-1, 0);
}

// Methods
void StateViewPlay::draw()
{
    for (auto elem: _graphicElements)
        _window->Draw(*elem);

    for (auto it = _graphicToMovable.begin(); it != _graphicToMovable.end(); it++)
        _window->Draw( *(it->first) );

    _window->Draw(_score);
    _window->Draw(_lifepoints);
    _window->Draw(_nbLives);
    _window->Draw(_level);

    _window->Display();
}

void StateViewPlay::treatEvents()
{
    sf::Event event;
    GamePlay* statePlay = dynamic_cast<GamePlay*>(_state);

    // While getting an event in the queue of events
    while (_window->GetEvent(event))
    {
        // Closing the game
        if ((event.Type == sf::Event::Closed) || ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape)))
            _window->Close();

        if (statePlay != nullptr)
        {
            if (event.Type == sf::Event::KeyPressed)
            {
                if (event.Key.Code == sf::Key::Space)
                    statePlay->getPlayer()->shoot();

                else if (event.Key.Code == sf::Key::Up)
                    statePlay->getPlayer()->moveUp();

                else if (event.Key.Code == sf::Key::Down)
                    statePlay->getPlayer()->moveDown();

                else if (event.Key.Code == sf::Key::Left)
                    statePlay->getPlayer()->moveLeft();

                else if (event.Key.Code == sf::Key::Right)
                    statePlay->getPlayer()->moveRight();
            }
        }
    }
    if (statePlay != nullptr)
        {
            // Getting an input linked to the opened window
            const sf::Input& Input = _window->GetInput();

            if (Input.IsKeyDown(sf::Key::Up))
                statePlay->getPlayer()->moveUp();

            else if (Input.IsKeyDown(sf::Key::Down))
                statePlay->getPlayer()->moveDown();

            else if (Input.IsKeyDown(sf::Key::Left))
                statePlay->getPlayer()->moveLeft();

            else if (Input.IsKeyDown(sf::Key::Right))
                statePlay->getPlayer()->moveRight();

            // Changing weapon
            else if (Input.IsKeyDown(sf::Key::N)) // Incrementing weapon id
                cout << "Changing weapon : ++" << endl;
                // A REMPLIR
            else if (Input.IsKeyDown(sf::Key::B)) // Decrementing weapon id
                cout << "Changing weapon : --" << endl;
                // A REMPLIR

        }
}

// Deletes a graphic element of the map, and erases the matching pair in the map corresponding to the given id
void StateViewPlay::deleteGraphicToMovableElem(int id)
{
    bool found = false;
    auto it = _graphicToMovable.begin();

    while (it != _graphicToMovable.end() && !found)
    {
        if (it->second->getId() == id)
        {
            cout << "in StateViewPlay, deleting " << it->second->getName() << " of id " << id << " from the map" << endl;
            if (it->first != nullptr)
                delete it->first;
            _graphicToMovable.erase(it);
            found = true;
        }
        else
            it++;
    }
}

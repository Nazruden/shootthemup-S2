// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GamePlay.cc
#include "../include/GamePlay.h"
#include "../include/Player.h"
#include "../include/Ennemy.h"
#include "../include/StateView.h"
#include "../include/StateViewPlay.h"
#include "../include/GraphicElement.h"
#include "../include/Projectile.h"
#include "../include/Weapon.h"

#include "time.h"
#include <map>
#include <vector>

using namespace std;

/*** Ctors / Dtors ***/
GamePlay::GamePlay(string title, GameModel* model) : GameState(title, model), _w(GAMEPLAY_WIDTH), _h(GAMEPLAY_HEIGHT), _phase(5), _level(1), _player(nullptr)
{
}

GamePlay::~GamePlay()
{
    for (auto e : _elements)
        if (e != nullptr)
            this->deleteMovableElement(e->getId());

    _elements.clear();
}

/*** Accessors ***/
vector<MovableElement*> GamePlay::getElements()
{
    return _elements;
}

vector<Spaceship*> GamePlay::getSpaceships()
{
    vector<Spaceship*> spaceships;
    for(auto e: _elements)
    {
        Spaceship* ship = dynamic_cast<Spaceship*> (e);
        if(ship!=nullptr)
            spaceships.push_back(ship);
    }
    return spaceships;
}

int GamePlay::getPhase() const
{
    return _phase;
}

void GamePlay::setPhase(int p)
{
    _phase = p;
}

int GamePlay::getLevel() const
{
    return _level;
}

void GamePlay::setLevel(int l)
{
    _level = l;
}

Player* GamePlay::getPlayer() const
{
    return _player;
}

MovableElement* GamePlay::getElement(int id)
{
    unsigned int i = 0;
    bool found = false;
    MovableElement* elem = nullptr;

    while ( i<_elements.size() && !found)
    {
        if (_elements[i]->getId() == id)
        {
            elem = _elements[i];
            found = true;
        }

        else
            ++i;
    }
    return elem;
}

/*** Methods ***/

string GamePlay::displayControls() const
{
    string controls = "----CONTROLS----\n";
    controls += "Shoot/Fire : SPACE \n";
    controls += "Move up : UP\n";
    controls += "Move down : DOWN\n";
    controls += "Move left : LEFT\n";
    controls += "Move right : RIGHT\n";
    controls += "----------------";
    return controls;
}

void GamePlay::enter()
{
    GameState::enter();
    cout << "You've entered the game." << endl;
    cout << "Temporary nickname :  Player";
    string nickname = "Player";
    /*
    cin >>  nickname;
    */
    initPlayer(nickname);

    cout << endl;
    cout << displayControls() << endl;

    _stateView->displayTransition("Level " + to_string(_level));
}

void GamePlay::initPlayer(string name)
{
    _player = new Player(this, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, name);
    addElement(_player);
    // Linking the player to the player graphic element
    StateViewPlay* stateViewPlay = dynamic_cast<StateViewPlay*>(_stateView);
    stateViewPlay->setGraphicToMovableElem(stateViewPlay->getElement(0), this->getElement(0));
}

void GamePlay::addElement(MovableElement* e)
{
    _elements.push_back(e);
}

// Finds and delete a movable element corresponding to the given id
void GamePlay::deleteElement(int id)
{
    bool found = false;
    unsigned int i = 0;

    while (!found && i < _elements.size())
    {
        if (_elements[i]->getId() == id)
        {
            // If it's a spaceship, the link between him and his projectiles must be erased
            Spaceship* spaceship = dynamic_cast<Spaceship*>(_elements[i]);
            if (spaceship != nullptr)
                spaceship->freeProjectiles();

            // Deallocation
            delete _elements[i];
            // Erasing the element from the vector
            _elements.erase(_elements.begin() + i);
            found = true;
        }
        else
            i++;
    }
}


void GamePlay::deleteMovableElement(int id)
{
    // Deleting the graphic element
    StateViewPlay* stateViewPlay = dynamic_cast<StateViewPlay*>(this->getStateView());
    stateViewPlay->deleteGraphicToMovableElem(id);
    // Deleting the element from GamePlay
    this->deleteElement(id);
}


void GamePlay::update()
{
    // Updating all movable elements
    unsigned int i = 0;
    while (i < _elements.size())
    {
        if (!_elements[i]->update())
        {
            this->deleteMovableElement(_elements[i]->getId());
            // Restarting from 0 because size of the vector has changed
            i = 0;
        }
        else
            i++;
    }

    // If the level must increase or restart
    if ( (_player->getDistanceTraveled() == _level*LEVEL_FACTOR) || (_player->isKilled() && _player->getLives() > 0) )
    {
        // If the player has ended the level
        if (_player->getDistanceTraveled() == _level*LEVEL_FACTOR)
        {
            _level++;
            // Player's lifepoints restart from 100
            _player->setLifePoints(100);
            // Player improves his shots level by level
            _player->getCurrentWeapon()->setProjectilesDamages(PROJECTILE_DAMAGES_INIT_PLAYER + LEVEL_PLAYER_DAMAGES_FACTOR * _level);
            _stateView->displayTransition("Level " + to_string(_level));
        }
        // If the player has been killed
        else if(_player->isKilled() && _player->getLives() > 0)
            _player->dies();

        _player->setX(PLAYER_X_INIT);
        _player->setY(PLAYER_Y_INIT);
        // Player restarts the level (or the new level)
        _player->setDistanceTraveled(0);
        // Clearing the elements from the screen
        this->clearElements();
    }


    else if(_player->getLives() == 0)
    {
        this->clearElements();
        _model->setState(_model->getState("gameEnd")); /** SEG FAULT **/
    }

    // Incrementing phase
    _phase++;

    // The value of an ennemy and its damages both increase with the level, thanks to factors
    if(_phase%150 == 0 || _phase%200 == 0 || _phase%350 == 0)
        // Creating an ennemy of type 0
        this->createEnnemy("ennemy0", ENNEMY0_W, ENNEMY0_H, ENNEMY0_SPEED,
                           ENNEMY0_VALUE + _level * LEVEL_ENNEMY_VALUE_FACTOR, PROJECTILE_DAMAGES_ENNEMY0 + _level * LEVEL_ENNEMY_DAMAGES_FACTOR);

    else if (_phase%500 == 0 || _phase%999 == 0)
        // Creating an ennemy of type 1
        this->createEnnemy("ennemy1", ENNEMY1_W, ENNEMY1_H, ENNEMY1_SPEED,
                           ENNEMY1_VALUE + _level * LEVEL_ENNEMY_VALUE_FACTOR, PROJECTILE_DAMAGES_ENNEMY1 + _level * LEVEL_ENNEMY_DAMAGES_FACTOR);

    else if (_phase%650 == 0)
    {
        // Creating an ennemy of type 2
        this->createEnnemy("ennemy2", ENNEMY2_W, ENNEMY2_H, ENNEMY2_SPEED,
                           ENNEMY2_VALUE + _level * LEVEL_ENNEMY_VALUE_FACTOR, PROJECTILE_DAMAGES_ENNEMY2 + _level * LEVEL_ENNEMY_DAMAGES_FACTOR);
        _phase = 0;
    }
}

void GamePlay::createEnnemy(string name, int w, int h, int speed, int value, int damages)
{
    // Generating a random y-coordinate, ENNEMY2 being the biggest ennemy in height
    srand(time(NULL));
    int y = rand()%(GAMEPLAY_HEIGHT - ENNEMY2_H) + 0;
    int shotFrequency = rand()%200 + 1;

    Ennemy* ennemy = new Ennemy(this, GAMEPLAY_WIDTH, y, w, h, speed, name, value, shotFrequency, damages);
    StateViewPlay* stateViewPlay = dynamic_cast<StateViewPlay*>(_stateView);
    // Creating the graphic ennemy element
    GraphicElement* ennemyGraphic = new GraphicElement(stateViewPlay->getImg(name));
    ennemyGraphic->setPosition(ennemy->getX(), ennemy->getY());
    ennemyGraphic->Resize(w, h);
    ennemyGraphic->setId(ennemy->getId());

    stateViewPlay->setGraphicToMovableElem(ennemyGraphic, ennemy);
    this->addElement(ennemy);
}

// Deleting all the elements from the vector, except the player
void GamePlay::clearElements()
{
    unsigned int i = 1;
    // Deleting all the elements except the player of id 0
    while (i < _elements.size())
    {
        this->deleteMovableElement(_elements[i]->getId());
        // Restarting from 1 because the size of the vector has changed
        i = 1;
    }
}

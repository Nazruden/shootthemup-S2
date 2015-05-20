// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// MovableElement.cc

#include "MovableElement.h"
#include "Player.h"
#include "GamePlay.h"
#include "StateViewPlay.h"

#include <iostream>
using namespace std;
int MovableElement::_nextId = 0;

/*** Ctors / Dtors ***/
MovableElement::MovableElement(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, string name)
    : _gamePlay(gamePlay), _x(x), _y(y), _w(w), _h(h), _dx(dx), _dy(dy), _name(name)
{
    _id = _nextId;
    _nextId++;
}

MovableElement::~MovableElement(){
    cout << "destructor movable element " << _name << " of id " << _id << endl;
}

/*** Accessors ***/
void MovableElement::setName(string newName)
{
    _name = newName;
}

GamePlay* MovableElement::getGamePlay()
{
    return _gamePlay;
}

string MovableElement::getName()
{
    return _name;
}

int MovableElement::getId()
{
    return _id;
}

int MovableElement::getX()
{
    return _x;
}

int MovableElement::getY()
{
    return _y;
}

int MovableElement::getDX()
{
    return _dx;
}

int MovableElement::getDY()
{
    return _dy;
}

int MovableElement::getW()
{
    return _w;
}

int MovableElement::getH()
{
    return _h;
}

void MovableElement::setX(int x)
{
    _x = x;
}

void MovableElement::setY(int y)
{
    _y = y;
}

/*** Methods ***/
// Returns the name and the position of a movableElement
string MovableElement::toString()
{
    string line = "*************\n";
    return line + _name + " (" + to_string(_x) + "," + to_string(_y) + ")";
}

void MovableElement::displayPosition()
{
    cout << this->toString() << endl;
}

void MovableElement::moveUp()
{
    if (_y > 0)
        _y -= _dy;
}
void MovableElement::moveDown()
{
    if (_y + _h < GAMEPLAY_HEIGHT)
        _y += _dy;
}
void MovableElement::moveLeft()
{
    // Only the player cannot get out of the screen
    if(_x > 0 || _gamePlay->getPlayer()->getName() != _name)
        _x -= _dx;
}
void MovableElement::moveRight()
{
    // Only the player cannot get out of the screen
    if (_x + _w < GAMEPLAY_WIDTH || _gamePlay->getPlayer()->getName() != _name)
        _x += _dx;
}

void MovableElement::update()
{

}

bool MovableElement::collideLeft(Spaceship* s)
{
    if ( (_x <= s->getX())  &&  (_x + _w >= s->getX())
        && (_y >= s->getY()) && (_y <= s->getY() + s->getH()) )
    {
        return true;
    }

    return false;
}


bool MovableElement::collideRight(Spaceship* s)
{
    if ( (_x <= s->getX() + s->getW())  &&  (_x + _w >= s->getX() + s->getW())
        && (_y >= s->getY()) && (_y <= s->getY() + s->getH()) )
    {
        return true;
    }

    return false;
}

bool MovableElement::collideBottom(Spaceship* s)
{
    if ( (_y <= s->getY() + s->getH())  &&  (_y + _h >= s->getY() + s->getH())
        && (_x >= s->getX()) && (_x <= s->getX() + s->getW()) )
    {
        return true;
    }
    return false;
}

bool MovableElement::collideTop(Spaceship* s)
{
    if ( (_y + _h >= s->getY()) &&  (_y <= s->getY())
         && (_x >= s->getX()) && (_x <= s->getX() + s->getW()) )
    {
        return true;
    }
    return false;
}

bool MovableElement::collision(Spaceship* s)
{
    if (this->collideLeft(s) || this->collideRight(s) || this->collideTop(s) || this->collideBottom(s))
        return true;
    return false;
}

void MovableElement::deleteMovableElement()
{
    StateViewPlay* stateViewPlay = dynamic_cast<StateViewPlay*>(_gamePlay->getStateView());
    stateViewPlay->deleteGraphicToMovableElem(_id);
    _gamePlay->deleteElement(_id);
}

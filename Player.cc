// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Player.cc

#include "Player.h"
#include "Projectile.h"
#include "Weapon.h"
#include "Ennemy.h"
#include "StateView.h"

#include <iostream>

using namespace std;

/*** Ctors / Dtors ***/
Player::Player(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, int lifePoints, string name) : Spaceship(gamePlay, x, y, w, h, dx, dy, lifePoints, name),
    _nbLives(3), _score(0), _distanceTraveled(0)
{

    // Adding a basic weapon composed of a basic projectile
    Projectile* basicProjectile = new Projectile
        (gamePlay, _x + _w + 1, _y, BASIC_PROJECTILE_WIDTH, BASIC_PROJECTILE_HEIGHT, PROJECTILE_SPEED_INIT_PLAYER, 0,
         PROJECTILE_NAME_INIT_PLAYER, PROJECTILE_DAMAGES_INIT_PLAYER,
         PROJECTILE_SUPPLY_INIT_PLAYER, PROJECTILE_RANGE_INIT_PLAYER, this);
    Weapon* basicWeapon = new Weapon("basicPlayerWeapon", -1, basicProjectile, this);
    this->addWeapon(basicWeapon);
    _currentWeapon = basicWeapon;
}

/*** Accessors ***/
int Player::getScore()
{
    return _score;
}

int Player::getLives()
{
    return _nbLives;
}

int Player::getDistanceTraveled()
{
    return _distanceTraveled;
}

void Player::setDistanceTraveled(int d)
{
    _distanceTraveled = d;
}

/*** Methods ***/
void Player::moveUp()
{
    this->MovableElement::moveUp();
}

void Player::moveDown()
{
    this->MovableElement::moveDown();
}

void Player::moveLeft()
{
    this->MovableElement::moveLeft();
}

void Player::moveRight()
{
    this->MovableElement::moveRight();
}

bool Player::hasLost()
{
    if (_nbLives == 0)
        return true;

    return false;
}

void Player::dies()
{
    if(_nbLives>0)
        _nbLives--;
    setLifePoints(100);

    if (_nbLives != 0)
        _gamePlay->getStateView()->displayTransition("You died");

    else if (_nbLives == 0)
        _gamePlay->getStateView()->displayTransition("Game\n Over");
}

void Player::computeScore(int value)
{
    _score += value;
}

void Player::shoot()
{
    if(_currentWeapon->hasSupply())
        _currentWeapon->shoot();
}

bool Player::update()
{
    _currentWeapon->updateProjectile();
    _distanceTraveled += PLAYER_DISTANCE_PER_FRAME;

    for(auto s: _gamePlay->getSpaceships())
        if (this->collision(s))
            this->collide(s);

    return true;
}

void Player::collide(Spaceship* s)
{
    // Player loses damages if hit by an ennemy
    Ennemy* ennemy = dynamic_cast<Ennemy*> (s);
    if(ennemy != nullptr)
        _lifePoints -= 1;
}

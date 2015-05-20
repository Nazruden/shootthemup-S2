// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Ennemy.cc

#include "Ennemy.h"
#include "Projectile.h"
#include "Weapon.h"
#include <iostream>

using namespace std;

/*** Ctors / Dtors ***/
Ennemy::Ennemy(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, int lifePoints, string name, int value, int shotFrequency, Weapon* weapon)
    : Spaceship(gamePlay, x, y, w, h, dx, dy, lifePoints, name, weapon), _value(value), _shotFrequency(shotFrequency)
{}

// Basic ennemy
Ennemy::Ennemy(GamePlay* gamePlay, int x, int y, int w, int h, int speed, string name, int value, int shotFrequency)
    : Spaceship(gamePlay, x, y, w, h, speed, speed, 10, name), _value(value), _shotFrequency(shotFrequency)
{
    Projectile* projectile = new Projectile(gamePlay, _x, _y, _w, _h, 10, 0, "ennemy_projectile", 10,-1, 800, this);
    Weapon* ennemyWeapon = new Weapon("ennemy_weapon", -1, projectile, this);
    _currentWeapon = ennemyWeapon;
}

/*** Accessors ***/
int Ennemy::getValue()
{
    return _value;
}

/*** Methods ***/
void Ennemy::shoot()
{
    _currentWeapon->shoot();
}

void Ennemy::update()
{
    _currentWeapon->updateProjectile();

    MovableElement::moveLeft();

    // If the ennemy gets out of the screen
    if (_x + _w <= 0)
        this->deleteMovableElement();

    else if (_gamePlay->getPhase()% _shotFrequency == 0)
        this->shoot();
}

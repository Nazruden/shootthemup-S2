// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Ennemy.cc

#include "../include/Ennemy.h"
#include "../include/Projectile.h"
#include "../include/Weapon.h"
#include <iostream>

using namespace std;

/*** Ctors / Dtors ***/

// Basic ennemy
Ennemy::Ennemy(GamePlay* gamePlay, int x, int y, int w, int h, int speed, string name, int value, int shotFrequency, int damages)
    : Spaceship(gamePlay, x, y, w, h, speed, speed, 10, name), _value(value), _shotFrequency(shotFrequency)
{
    Projectile* projectile = new Projectile(gamePlay, _x, _y, _w, _h, PROJECTILE_SPEED_ENNEMY, 0, "ennemy_projectile", damages, this);
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

bool Ennemy::update()
{
    // If the ennemy was killed or gets out of the screen
    if (this->isKilled() || _x + _w <= 0 )
        return false;

    else
    {
        _currentWeapon->updateProjectile();

        MovableElement::moveLeft();

        if (_gamePlay->getPhase()% _shotFrequency == 0)
            this->shoot();

        return true;
    }
}

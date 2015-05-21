// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Spaceship.cc
#include "Spaceship.h"
#include "GamePlay.h"
#include "Weapon.h"
#include "Projectile.h"
#include <iostream>

using namespace std;

/*** Ctors / Dtors ***/
Spaceship::Spaceship(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, int lifePoints, string name, Weapon* weapon) :
                    MovableElement(gamePlay, x, y, w, h, dx, dy, name), _lifePoints(lifePoints)
{
    this->addWeapon(weapon);
    _currentWeapon = weapon;
}

Spaceship::Spaceship(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, int lifePoints, string name) :
                    MovableElement(gamePlay, x, y, w, h, dx, dy, name), _lifePoints(lifePoints)
{}

Spaceship::~Spaceship()
{
   cout << "destructor spaceship " << _name << " of id " << _id << endl;
   for (auto p: _weapons)
       delete p;

   _weapons.clear();
}

/*** Accessors ***/
int Spaceship::getLifePoints()
{
    return _lifePoints;
}
Weapon* Spaceship::getCurrentWeapon()
{
    return _currentWeapon;
}
int Spaceship::getNumberWeapons()
{
    return _weapons.size();
}
void Spaceship::setLifePoints(int newLP)
{
    _lifePoints = newLP;
}

vector<Projectile*> Spaceship::getProjectiles()
{
    vector<Projectile*> projectiles;
    for(auto e: _gamePlay->getElements())
    {
        Projectile* p = dynamic_cast<Projectile*>(e);
        // If the element is a projectile
        if( p != nullptr)
            // If the projectile was shot by this
            if (p->getShooter() != nullptr)
                if (p->getShooter()->getId() == _id)
                    projectiles.push_back(p);
    }
    return projectiles;
}

/*** Methods ***/
bool Spaceship::update()
{
    _currentWeapon->updateProjectile();
    return MovableElement::update();

}

string Spaceship::toString()
{
    string description = "\n";
    description += "Current lifepoints: ";
    description += to_string(_lifePoints);
    return MovableElement::toString() + description;
}

void Spaceship::addWeapon(Weapon* weapon)
{
    _weapons.insert(weapon);
}

bool Spaceship::isKilled()
{
    if (_lifePoints <= 0)
        return true;
    else
        return false;
}

// The projectiles shot by the spaceship no longer belong to him if he is dead
void Spaceship::freeProjectiles()
{
    for (auto p : getProjectiles())
        p->setShooter(nullptr);
}

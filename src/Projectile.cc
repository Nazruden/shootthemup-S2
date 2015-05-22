// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Projectile.cc

#include "../include/Projectile.h"
#include "../include/StateViewPlay.h"
#include "../include/Ennemy.h"
#include <iostream>

using namespace std;

/*** Ctors / Dtors ***/
Projectile::Projectile(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, string name, int damages, int supply, int range, Spaceship* shooter)
    : MovableElement(gamePlay, x, y, w, h, dx, dy, name), _damages(damages), _supply(supply), _range(range), _shooter(shooter) {}

Projectile::Projectile(Projectile* autre) : MovableElement(autre->_gamePlay, autre->_x, autre->_y, autre->_w, autre->_h, autre->_dx, autre->_dy,
            autre->_name), _damages(autre->_damages), _supply(autre->_supply), _range(autre->_range), _shooter(autre->_shooter) {}

Projectile::~Projectile()
{

}

/*** Accessors ***/
int Projectile::getDamages()
{
    return _damages;
}

void Projectile::setDamages(int damages)
{
    _damages = damages;
}

Spaceship* Projectile::getShooter()
{
    return _shooter;
}

void Projectile::setShooter(Spaceship* shooter)
{
    _shooter = shooter;
}

/*** Methods ***/

// Collision between a projectile and a spaceship. Returns true if the projectile's shooter and the other ship have different types
bool Projectile::collide(Spaceship* ship)
{
    bool effective = false;

    // If the shooter is already dead (it means it was an ennemy), and if the projectile hits the player
    if (_shooter == nullptr && ship->getId() == 0)
    {
        effective = true;
        // Player loses points of life
        ship->setLifePoints(ship->getLifePoints() - _damages);
    }

    // Else if the shooter is still alive
    else
    {
        Player* player = dynamic_cast<Player*>(_shooter);
        Ennemy* ennemy = dynamic_cast<Ennemy*>(ship);

        // If the projectile was shot by the player and hits an ennemy
        if (player != nullptr && ennemy != nullptr)
        {
            effective = true;
            ennemy->setLifePoints(ennemy->getLifePoints() - _damages);
            // Updating player score
            player->computeScore(ennemy->getValue());
        }
        // Else if the projectile was shot by an ennemy still alive and hits the player
        else if (player == nullptr && ennemy == nullptr)
        {
            effective = true;
            ship->setLifePoints(ship->getLifePoints() - _damages);
        }
    }

    return effective;
}

bool Projectile::update()
{
    // Projectiles have a negative speed so that they'll move left
    moveRight();
    // and specific y-axis speed
    moveUp();

    // If the projectile entirely gets out of the screen
    if (_x >= GAMEPLAY_WIDTH || _x +_w <= 0)
        return false;

    else
    {
        bool reached = false;
        int unsigned i = 0;
        vector<Spaceship*> spaceships = _gamePlay->getSpaceships();

        // Searching a collision with a ship
        while (i < spaceships.size() && !reached)
        {
            // If there is a collision
            if (this->collision(spaceships[i]))
                reached = this->collide(spaceships[i]);
            i++;
        }

        if (reached)
            return false;
    }

    return true;
}

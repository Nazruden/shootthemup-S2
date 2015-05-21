// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Projectile.cc

#include "Projectile.h"
#include "StateViewPlay.h"
#include "Ennemy.h"
#include <iostream>

using namespace std;

/*** Ctors / Dtors ***/
Projectile::Projectile(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, string name, int damages, int supply, int range, Spaceship* shooter)
    : MovableElement(gamePlay, x, y, w, h, dx, dy, name), _damages(damages), _supply(supply), _range(range), _shooter(shooter) {}

Projectile::Projectile(Projectile* autre) : MovableElement(autre->_gamePlay, autre->_x, autre->_y, autre->_w, autre->_h, autre->_dx, autre->_dy,
            autre->_name), _damages(autre->_damages), _supply(autre->_supply), _range(autre->_range), _shooter(autre->_shooter) {}

Projectile::~Projectile()
{
    cout << "destructor projectile " << _name << "of id " << _id << endl;
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

/*** Methods ***/

// Collision between a projectile and a spaceship. Returns true if the projectile's shooter and the other ship have different types
bool Projectile::collide(Spaceship* ship)
{
    bool effective = false;

    Player* player = dynamic_cast<Player*>(_shooter);
    Ennemy* ennemy = dynamic_cast<Ennemy*> (ship);

    // If the projectile was shot by the player and hit an ennemy
    if (player != nullptr && ennemy != nullptr)
    {
        cout << "ship was hit by " << _name << " of id " << _id << endl;
        effective = true;
        ennemy->setLifePoints(ennemy->getLifePoints() - _damages);
        // Updating player score
        player->computeScore(ennemy->getValue());
    }
    // Else if the projectile was shot by an ennemy and hit the player
    else if (player == nullptr && ennemy == nullptr)
    {
        cout << "player was hit by " << _name << " of id " << _id << endl;
        effective = true;
        ship->setLifePoints(ship->getLifePoints() - _damages);
    }
    return effective;
}

bool Projectile::update()
{
    // Projectiles have a negative speed so that they'll move left
    moveRight();

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

// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Projectile.h

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../include/GamePlay.h"
#include "../include/MovableElement.h"
#include "../include/Player.h"
#include <string>

const int PROJECTILE_SPEED_INIT_PLAYER = 10;
const std::string PROJECTILE_NAME_INIT_PLAYER = "basicPlayerProjectile";
const int PROJECTILE_DAMAGES_INIT_PLAYER = 10;
const int PROJECTILE_SUPPLY_INIT_PLAYER = -1;
const int PROJECTILE_RANGE_INIT_PLAYER = GAMEPLAY_WIDTH - 0;

const int BASIC_PROJECTILE_WIDTH = 42;
const int BASIC_PROJECTILE_HEIGHT = 20;

const int PROJECTILE_DAMAGES_ENNEMY0 = 10;
const int PROJECTILE_DAMAGES_ENNEMY1 = 12;
const int PROJECTILE_DAMAGES_ENNEMY2 = 15;

const int PROJECTILE_SPEED_ENNEMY = -10;

class Spaceship;
class Projectile : public MovableElement
{
    private:
        int _damages;
        int _supply; // -1 if infinite
        int _range;
        Spaceship* _shooter;

    public:
    // Constructors
        Projectile(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, std::string name, int damages, int supply, int range, Spaceship* shooter);
        Projectile(Projectile* autre);
        Projectile(int x, int y, int w, int h, int dx, int dy, std::string name, int damages, int supply, int range, Spaceship* shooter);
        ~Projectile();
    // Accessors
        int getDamages();
        void setDamages(int damages);
        Spaceship* getShooter();
        void setShooter(Spaceship* shooter);

    // Methods
        bool update() override;

        bool collide(Spaceship* s);
};

#endif

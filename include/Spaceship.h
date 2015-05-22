// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Spaceship.h

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "../include/MovableElement.h"
#include <set>
#include <vector>

class Projectile;
class Weapon;
class Spaceship : public MovableElement
{
    protected:
        int _lifePoints;
        std::set<Weapon*> _weapons;
        Weapon* _currentWeapon;

    public:
    // Constructors / Destructors
        Spaceship(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, int lifePoints, std::string name, Weapon* weapon);
        Spaceship(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, int lifePoints, std::string name);
        virtual ~Spaceship();
    // Gets/Sets
        int getLifePoints();
        Weapon* getCurrentWeapon();
        int getNumberWeapons();
        void setLifePoints(int newLP);
        std::vector<Projectile*> getProjectiles();

    // Methods
        std::string toString() override;
        void addWeapon(Weapon* weapon);
        bool isKilled();
        virtual void shoot() = 0;
        virtual bool update();
        void freeProjectiles();
};

#endif // SPACESHIP_H

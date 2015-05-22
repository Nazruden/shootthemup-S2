#ifndef WEAPON_H
#define WEAPON_H

#include "../include/Player.h"

class Projectile;
class Weapon
{
    private :
        std::string _name;
        int _supply;
        int _shotState;
        Projectile* _projectile;
        Spaceship* _holder;
        bool _infinite;

    public :
    // Constructors / Destructors
        Weapon(std::string name, int supply, Projectile* projectile, Spaceship* holder);
        ~Weapon();

    // Accessors
        void nextShotState();
        void lastShotState();
        int getShotState();
        int getProjectileDamages();
        void setProjectilesDamages(int damages);

    // Methods
        void updateProjectile();
        bool hasSupply();
        void shoot();
        void primaryShoot();
        void secondaryShoot();
        void thirdShoot();
};

#endif // WEAPON_H

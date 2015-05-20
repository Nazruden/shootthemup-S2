#ifndef WEAPON_H
#define WEAPON_H

#include "Player.h"

class Projectile;
class Weapon
{
    private :
        std::string _name;
        int _supply;
        Projectile* _projectile;
        Spaceship* _holder;
        bool _infinite;

    public :
    // Constructors / Destructors
        Weapon(std::string name, int supply, Projectile* projectile, Spaceship* holder);
        ~Weapon();

    // Accessors
        int getProjectileDamages();

    // Methods
        void updateProjectile();
        bool hasSupply();
        void shoot();
};

#endif // WEAPON_H

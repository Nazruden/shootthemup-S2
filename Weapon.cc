// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Weapon.cc
#include "Weapon.h"
#include "Projectile.h"
#include "GraphicElement.h"
#include "StateViewPlay.h"

using namespace std;

/*** Ctors / Dtors ***/
Weapon::Weapon(string name, int supply, Projectile* projectile, Spaceship* holder) : _name(name), _supply(supply), _projectile(projectile), _holder(holder)
{
    if(_supply!=-1)
        _infinite = false;
    else
        _infinite = true;
}

Weapon::~Weapon()
{
    cout << "destructor weapon " << _holder->getName() << " of id " << _holder->getId() << endl;
    if(_projectile != nullptr)
        delete _projectile;
}

int Weapon::getProjectileDamages()
{
    return _projectile->getDamages();
}

void Weapon::setProjectilesDamages(int damages)
{
    _projectile->setDamages(damages);
}

/*** Methods ***/
bool Weapon::hasSupply()
{
    if(_infinite || _supply>0)
        return true;
    else
        return false;
}

void Weapon::shoot()
{
    if(hasSupply())
    {
        Projectile* p = new Projectile(_projectile);
        cout << "new projectile of id " << p->getId()<< endl;

        StateViewPlay* stateViewPlay = dynamic_cast<StateViewPlay*>(p->getGamePlay()->getStateView());

        GraphicElement* projectileGraphic = new GraphicElement(stateViewPlay->getImg("shot"));
        projectileGraphic->setPosition(p->getX(), p->getY());
        projectileGraphic->SetSubRect(sf::IntRect(0, 0, 46, 20));
        projectileGraphic->setId(p->getId());

        stateViewPlay->setGraphicToMovableElem(projectileGraphic, p);
        p->getGamePlay()->addElement(p);

        if (!_infinite)
            _supply--;
    }
}

void Weapon::updateProjectile()
{
    Player* player = dynamic_cast<Player*>(_holder);

    // If the holder is the player, the projectiles start moving from his right
    if (player != nullptr)
        _projectile->setX( _holder->getX() + _holder->getW() );

    // If the holder is an ennemy, it starts moving from his left
    else
        _projectile->setX( _holder->getX() );

    _projectile->setY( _holder->getY() + _holder->getH()/3 );
}

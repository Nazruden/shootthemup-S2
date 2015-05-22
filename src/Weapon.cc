// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Weapon.cc
#include "../include/Weapon.h"
#include "../include/Projectile.h"
#include "../include/GraphicElement.h"
#include "../include/StateViewPlay.h"

using namespace std;

/*** Ctors / Dtors ***/
Weapon::Weapon(string name, int supply, Projectile* projectile, Spaceship* holder) : _name(name), _supply(supply), _shotState(0), _projectile(projectile), _holder(holder)
{
    if(_supply!=-1)
        _infinite = false;
    else
        _infinite = true;
}

Weapon::~Weapon()
{
    if(_projectile != nullptr)
        delete _projectile;
}

/*** Accessors ***/
void Weapon::nextShotState(){
    if(_shotState<2)
        _shotState++;
}
void Weapon::lastShotState(){
    if(_shotState>0)
        _shotState--;
}
int Weapon::getShotState(){
    return _shotState;
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
    switch(_shotState)
    {
        case (0):
            primaryShoot();
            break;
        case (1):
            secondaryShoot();
            break;
        case (2):
            thirdShoot();
            break;
        default:
            break;
    }
}

void Weapon::primaryShoot()
{
    if(hasSupply())
    {
        Projectile* p = new Projectile(_projectile);

        StateViewPlay* stateViewPlay = dynamic_cast<StateViewPlay*>(p->getGamePlay()->getStateView());

        GraphicElement* projectileGraphic = new GraphicElement(stateViewPlay->getImg("blue_shot"));
        projectileGraphic->setPosition(p->getX(), p->getY());
        projectileGraphic->SetSubRect(sf::IntRect(0, 0, 46, 20));
        projectileGraphic->setId(p->getId());

        stateViewPlay->setGraphicToMovableElem(projectileGraphic, p);
        p->getGamePlay()->addElement(p);

        if (!_infinite)
            _supply--;
    }
}

void Weapon::secondaryShoot()
{
    Player* player = dynamic_cast<Player*>(_holder);
    if (player != nullptr)
    {
        if(hasSupply())
        {
            Projectile* p1 = new Projectile(_projectile);
            Projectile* p2 = new Projectile(_projectile);
            Projectile* p3 = new Projectile(_projectile);

            p1->setDY(-8);
            p3->setDY(8);

            StateViewPlay* stateViewPlay = dynamic_cast<StateViewPlay*>(p1->getGamePlay()->getStateView());

            GraphicElement* projectileGraphic1 = new GraphicElement(stateViewPlay->getImg("red_shot"));
            projectileGraphic1->setPosition(p1->getX(), p1->getY());
            projectileGraphic1->SetSubRect(sf::IntRect(0, 0, 46, 20));
            projectileGraphic1->setId(p1->getId());

            GraphicElement* projectileGraphic2 = new GraphicElement(stateViewPlay->getImg("red_shot"));
            projectileGraphic2->setPosition(p2->getX(), p2->getY());
            projectileGraphic2->SetSubRect(sf::IntRect(0, 0, 46, 20));
            projectileGraphic2->setId(p2->getId());

            GraphicElement* projectileGraphic3 = new GraphicElement(stateViewPlay->getImg("red_shot"));
            projectileGraphic3->setPosition(p3->getX(), p3->getY());
            projectileGraphic3->SetSubRect(sf::IntRect(0, 0, 46, 20));
            projectileGraphic3->setId(p3->getId());

            stateViewPlay->setGraphicToMovableElem(projectileGraphic1, p1);
            stateViewPlay->setGraphicToMovableElem(projectileGraphic2, p2);
            stateViewPlay->setGraphicToMovableElem(projectileGraphic3, p3);
            p1->getGamePlay()->addElement(p1);
            p2->getGamePlay()->addElement(p2);
            p3->getGamePlay()->addElement(p3);

            if (!_infinite)
                _supply--;
        }
    }
}

void Weapon::thirdShoot()
{
    if(hasSupply())
    {
        Projectile* p = new Projectile(_projectile);
        p->setDamages(this->getProjectileDamages() * 3);
        p->setW(p->getW() * 8);
        p->setH(p->getH() * 2);

        StateViewPlay* stateViewPlay = dynamic_cast<StateViewPlay*>(p->getGamePlay()->getStateView());

        GraphicElement* projectileGraphic = new GraphicElement(stateViewPlay->getImg("purple_shot"));
        projectileGraphic->setPosition(p->getX(), p->getY());
        projectileGraphic->Resize(p->getW(), p->getH());
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

// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Spaceship_UT.cc

#include <boost/test/unit_test.hpp>

#include "../include/Spaceship.h"
#include "../include/Player.h"
#include "../include/Weapon.h"
#include "../include/Projectile.h"

BOOST_AUTO_TEST_CASE(isKilled)
{
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");
    BOOST_CHECK(player->isKilled() == false);

    player->setLifePoints(0);
    BOOST_CHECK(player->isKilled() == true);

    delete player;
}

BOOST_AUTO_TEST_CASE(addWeapon)
{
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");

    Projectile* newProjectile = new Projectile
        (nullptr, player->getX(), player->getY(), BASIC_PROJECTILE_WIDTH, BASIC_PROJECTILE_HEIGHT, PROJECTILE_SPEED_INIT_PLAYER, 0,
         PROJECTILE_NAME_INIT_PLAYER, PROJECTILE_DAMAGES_INIT_PLAYER);
    Weapon* newWeapon = new Weapon("NewWeapon", -1, newProjectile, player);

    BOOST_CHECK(player->getNumberWeapons() == 1);
    player->addWeapon(newWeapon);
    BOOST_CHECK(player->getNumberWeapons() == 2);
}

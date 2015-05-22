// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Projectile_UT.cc

#include <boost/test/unit_test.hpp>

#include "../include/Projectile.h"

BOOST_AUTO_TEST_CASE(collide)
{
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");

    Projectile* newProjectile = new Projectile
        (nullptr, player->getX() + player->getW(), player->getY(), BASIC_PROJECTILE_WIDTH, BASIC_PROJECTILE_HEIGHT, PROJECTILE_SPEED_INIT_PLAYER, 0,
         PROJECTILE_NAME_INIT_PLAYER, PROJECTILE_DAMAGES_INIT_PLAYER);

    BOOST_CHECK(!newProjectile->collideLeft(player));
    BOOST_CHECK(!newProjectile->collideBottom(player));
    BOOST_CHECK(newProjectile->collideTop(player));
    BOOST_CHECK(newProjectile->collideRight(player));
}

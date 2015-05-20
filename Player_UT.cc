// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Player_UT.cc

#include <boost/test/unit_test.hpp>

#include "Player.h"

BOOST_AUTO_TEST_CASE(computeScore)
{
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");
    BOOST_CHECK(player->getScore() == 0);

    player->computeScore(5);
    BOOST_CHECK(player->getScore() == 5);
}

BOOST_AUTO_TEST_CASE(dies)
{
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");
    BOOST_CHECK(player->getLifePoints() == 100);
    BOOST_CHECK(player->getLives() == 3);

    player->setLifePoints(0);
    player->dies();
    BOOST_CHECK(player->getLives() == 2);
    BOOST_CHECK(player->getLifePoints() == 100);
}


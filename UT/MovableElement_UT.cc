// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// MovableElement_UT.cc

#include <boost/test/unit_test.hpp>

#include "../include/Player.h"

#include <string>

using namespace std;

BOOST_AUTO_TEST_CASE(toString)
{
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");

    BOOST_CHECK(player->toString() == "*************\nPlayer (0,300)\nCurrent lifepoints: 100");
    delete player;
}

BOOST_AUTO_TEST_CASE(movements)
{
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");

    player->moveUp();
    BOOST_CHECK(player->getY() == 290);

    player->moveDown();
    BOOST_CHECK(player->getY() == 300);

    player->moveLeft();
    BOOST_CHECK(player->getX() == 0); // Player cannot be outside of the screen

    player->moveRight();
    BOOST_CHECK(player->getX() == 10);

    delete player;
}

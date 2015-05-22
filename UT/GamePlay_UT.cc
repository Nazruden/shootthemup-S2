// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GamePlay_UT.cc

#include <boost/test/unit_test.hpp>

#include "../include/Player.h"
#include "../include/GamePlay.h"

BOOST_AUTO_TEST_CASE(addElement)
{
    GamePlay* gamePlay = new GamePlay("gamePlay", nullptr);
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");

    BOOST_CHECK(gamePlay->getElements().size() == 0);
    gamePlay->addElement(player);
    BOOST_CHECK(gamePlay->getElements().size() == 1);
}


BOOST_AUTO_TEST_CASE(deleteElement)
{
    GamePlay* gamePlay = new GamePlay("gamePlay", nullptr);
    Player* player = new Player(nullptr, PLAYER_X_INIT, PLAYER_Y_INIT, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_SPEED_X, PLAYER_SPEED_Y, PLAYER_LIFEPOINTS_INIT, "Player");
    gamePlay->addElement(player);

    BOOST_CHECK(gamePlay->getElements().size() == 1);
    gamePlay->deleteElement(player);
    BOOST_CHECK(gamePlay->getElements().size() == 0);
}

BOOST_AUTO_TEST_CASE(displayConsole)
{
    GamePlay* gamePlay = new GamePlay("gamePlay", nullptr);
    BOOST_CHECK(gamePlay->displayControls() == "----CONTROLS----\nShoot/Fire : shoot\nMove up : up\nMove down : down\nMove left : left\nMove right : right\nDo nothing : pass\nReturn to menu : stop\n----------------");
}

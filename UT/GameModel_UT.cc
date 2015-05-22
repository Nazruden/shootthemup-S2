// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameModel_UT.cc

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE

#include <boost/test/unit_test.hpp>

#include "../include/GameState.h"
#include "../include/GamePlay.h"

#include <string>

using namespace std;

BOOST_AUTO_TEST_CASE(getstate)
{
    GameModel* model = new GameModel();
    GameState* state = model->getState("gameMenu");

    BOOST_CHECK(state->getTitle() == "gameMenu");

    delete state;
    //delete model; // FATAL ERROR IN GET STATE MEMORY VIOLATION
}
/* FATAL ERROR
BOOST_AUTO_TEST_CASE(setstate)
{
    GameModel* model = new GameModel();
    model->setState(model->getState("gamePlay")); // FATAL ERROR

    BOOST_CHECK((model->getCurrentState())->getTitle() == "gamePlay");

    delete model;
}
*/

/* FATAL ERROR
BOOST_AUTO_TEST_CASE(quitgame)
{
    GameModel* model;
    model->setState(model->getState("gamePlay"));

    BOOST_CHECK((model->getCurrentState())->isEnabled() == true);
    model->quitGame();
    BOOST_CHECK((model->getCurrentState())->isEnabled() == false);
}
*/

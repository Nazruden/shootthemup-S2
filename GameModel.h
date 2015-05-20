// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameModel.h

#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <string>
#include <vector>

class GameView;
class GameState;
class GameModel
{
    private:
        GameState* _currentState;
        GameView* _gameView;
        std::vector<GameState*> _states;

    public:
    // Constructors / Destructors
        GameModel();
        ~GameModel();
    // Accessors
        GameState* getState(std::string title);
        GameState* getCurrentState();
        GameView* getGameView();

        void setState(GameState* s);
        void setGameView(GameView* view);
    // Methods
        void runGame();
        void quitGame();
};

#endif

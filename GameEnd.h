// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameEnd.h

#ifndef GAME_END_H
#define GAME_END_H

#include "GameState.h"

class GameEnd : public GameState
{
    private:
        std::string _endMessage;
        bool _won;
    public:
        // Constructors / Destructors
        GameEnd(std::string title, GameModel* model);
        // Accessors
        void setWinState(bool winState);
        bool getWinState();
        void setEndMessage(std::string endMessage);
        std::string getEndMessage();
        // Methods
        void update() override;
};

#endif // GAME_END_H

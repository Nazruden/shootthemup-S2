// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameState.h
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include "GameModel.h"

class StateView;
class GameState
{
protected:
    std::string _title;
    GameModel* _model;
    bool _enabled;
    StateView* _stateView;

public:
    // Constructors / Destructors
    GameState(std::string title, GameModel* model);
    virtual ~GameState();
    // Accessors
    std::string getTitle();
    bool isEnabled();
    StateView* getStateView();
    void setStateView(StateView* stateView);
    GameModel* getModel();
    // Methods
    //virtual void displayConsole() = 0;
    //virtual bool treatEvents() = 0;
    virtual void update() = 0;
    virtual void enter();
    virtual void leave();
};

#endif // GAME_STATE_H

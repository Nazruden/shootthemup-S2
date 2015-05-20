// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GameMenu.h
#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "GameState.h"
#include <iostream>
#include <vector>

class GameMenu : public GameState
{
private:
    std::vector<std::string> _items;

public:
    // Constructors / Destructors
    GameMenu(std::string title, GameModel* model);
    // Methods
    void enter() override;
    void update() override;
};

#endif

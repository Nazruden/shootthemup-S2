// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GamePlay.h
#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include "GameState.h"
#include <iostream>
#include <vector>

const int GAMEPLAY_WIDTH = 1000;
const int GAMEPLAY_HEIGHT = 600;
const int LEVEL_FACTOR = 1000;

class Player;
class MovableElement;
class Spaceship;
class GamePlay : public GameState
{
    private:
        int _w, _h;
        int _phase;
        int _level;
        Player* _player;
        std::vector<MovableElement*> _elements;

    public:
    // Constructors / Destructors
        GamePlay(std::string title, GameModel* model);
        ~GamePlay();
    // Accessors
        std::vector<MovableElement*> getElements();
        std::vector<Spaceship*> getSpaceships();
        int getPhase() const;
        void setPhase(int p);
        int getLevel() const;
        void setLevel(int l);
        Player* getPlayer() const;
        MovableElement* getElement(int id);

    // Methods
        void addElement(MovableElement* e);
        //void deleteElement(MovableElement* e);
        void deleteElement(int id);
        void initPlayer(std::string name);
        void enter() override;
        //void displayConsole() override;
        void update() override;
        std::string displayControls() const;
        void createEnnemy(std::string name, int w, int h, int speed, int value);
        void clearElements();
        void deleteMovableElement(int id);

};

#endif


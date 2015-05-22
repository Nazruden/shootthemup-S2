// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "../include/Spaceship.h"
#include <string>
#include <set>

const int PLAYER_X_INIT = 10;
const int PLAYER_Y_INIT = 300;
const int PLAYER_SPEED_X = 7;
const int PLAYER_SPEED_Y = 7;
const int PLAYER_WIDTH = 70;
const int PLAYER_HEIGHT = 60;
const int PLAYER_LIFEPOINTS_INIT = 100;
const int PLAYER_DISTANCE_PER_FRAME = 1;

class Player : public Spaceship
{
    private:
        int _nbLives;
        int _score;
        int _distanceTraveled;

    public:
    // Constructors
        Player(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, int lifePoints, std::string name);
        Player(int x, int y, int w, int h, int dx, int dy, int lifePoints, std::string name);

   // Accessors
        int getScore();
        int getLives();
        void setGamePlay(GamePlay* gamePlay);
        int getDistanceTraveled();
        void setDistanceTraveled(int d);

    // Methods
        void moveUp() override;
        void moveDown() override;
        void moveLeft() override;
        void moveRight() override;
        void changeWeaponState(bool moreOrLess);
        void dies();
        bool hasLost();
        void computeScore(int value);
        bool update() override;
        void collide(Spaceship* s);
        void shoot() override;

};

#endif // PLAYER_H

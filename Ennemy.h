// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Ennemy.h

#ifndef ENNEMY_H
#define ENNEMY_H

#include "Spaceship.h"
#include <string>

const int ENNEMY0_W = 50;
const int ENNEMY0_H = 50;
const int ENNEMY0_SPEED = 2;
const int ENNEMY0_VALUE = 5;

const int ENNEMY1_W = 70;
const int ENNEMY1_H = 70;
const int ENNEMY1_SPEED = 3;
const int ENNEMY1_VALUE = 10;

const int ENNEMY2_W = 90;
const int ENNEMY2_H = 90;
const int ENNEMY2_SPEED = 4;
const int ENNEMY2_VALUE = 20;

class Ennemy : public Spaceship
{
    private:
        int _value; // given to the player's score if the ennemy is killed
        int _shotFrequency;

    public:
        // Constructors / Destructors
        Ennemy(GamePlay* gamePlay, int x, int y, int w, int h, int speed, std::string name, int value, int shotFrequency, int damages);

        // Accessors
        int getValue();
        // Methods
        void shoot() override;
        bool update() override;
};

#endif // ENNEMY_H

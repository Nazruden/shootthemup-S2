// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// MovableElement.h

#ifndef MOVABLE_ELEMENT_H
#define MOVABLE_ELEMENT_H
#include <string>

class Spaceship;
class GamePlay;
class MovableElement
{
protected:
    GamePlay* _gamePlay;
    int _id;
    static int _nextId;
    int _x, _y;
    int _w, _h;
    int _dx, _dy;
    std::string _name;

public:
    // Constructors / Destructors
    MovableElement(GamePlay* gamePlay, int x, int y, int w, int h, int dx, int dy, std::string name);
    virtual ~MovableElement();

    // Accessors
    void setName(std::string newName);
    GamePlay* getGamePlay();
    void setGamePlay(GamePlay* gamePlay);
    std::string getName();
    int getId();
    int getX();
    int getY();
    int getDX();
    int getDY();
    int getW();
    int getH();
    void setX(int x);
    void setY(int y);

    // Methods
    virtual std::string toString();
    void displayPosition();
    virtual void moveUp();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void update() = 0;

    bool collideLeft(Spaceship* s);
    bool collideRight(Spaceship* s);
    bool collideBottom(Spaceship* s);
    bool collideTop(Spaceship* s);
    bool collision(Spaceship* s);

    void deleteMovableElement();

};

#endif

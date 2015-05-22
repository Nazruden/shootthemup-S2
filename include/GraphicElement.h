// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GraphicElement.h

#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <SFML/Graphics.hpp>

class GraphicElement : public sf::Sprite
{
private:
    int _id;
    int _w, _h;
    int _nbFrames;
    float _currentFrame;
    bool _perpetual;

public:
// Constructors / Destructors
    GraphicElement();
    // Constructor with image
    GraphicElement(sf::Image * image);
    // Constructor with image and number of frames
    GraphicElement(sf::Image * image, int nbFrames);
    // Constructor with image, number of frames and starting frame
    GraphicElement(sf::Image * image, int nbFrames, int firstFrame);

    virtual ~GraphicElement();

// Accessors
    int getId();
    void setId(int id);
    bool isPerpetual();
    void setNumberFrames(int nbFrames);
    void setPerpetual(bool perpetuality);
    void nextFrame();
    void setPosition(const sf::Vector2f & pos);
    void setPosition(int x, int y);

// Methods
    void resize(int w, int h);
    virtual void draw(sf::RenderWindow * _window);
};
#endif

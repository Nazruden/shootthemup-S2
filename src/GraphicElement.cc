// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GraphicElement.cc

#include "../include/GraphicElement.h"
#include <iostream>


using namespace std;
using namespace sf;

/*** Constructors / Destructors ***/
GraphicElement::GraphicElement():  Sprite(), _w(0), _h(0), _nbFrames(-1), _currentFrame(0), _perpetual(false)
{}
// Constructor with image
GraphicElement::GraphicElement(Image *image) : Sprite(*image), _nbFrames(-1), _currentFrame(0), _perpetual(false)
{}
// Constructor with image and number of frames
GraphicElement::GraphicElement(Image * image, int nbFrames) : Sprite(*image), _nbFrames(nbFrames), _currentFrame(1), _perpetual(false)
{}
// Constructor with image, number of frames and starting frame
GraphicElement::GraphicElement(Image * image, int nbFrames, int firstFrame) : Sprite(*image), _nbFrames(nbFrames), _currentFrame(firstFrame), _perpetual(false)
{}

GraphicElement::~GraphicElement()
{}

/*** Accessors ***/
int GraphicElement::GraphicElement::getId()
{
    return _id;
}
void GraphicElement::GraphicElement::setId(int id){
  _id = id;
}
bool GraphicElement::isPerpetual(){
    return _perpetual;
}
void GraphicElement::setPerpetual(bool perpetuality){
    _perpetual = perpetuality;
}

// nextFrame :
//      - the graphicElement will reach his nextFrame of animation
//      - does nothing if he has no animation or if its animation ended
void GraphicElement::nextFrame(){
    // If the graphicElement's animation didn't end
    if((int)_currentFrame <= _nbFrames && (int)_currentFrame != -1)
    {
        SetSubRect(sf::IntRect(
                (((int)_currentFrame)-1) * this->GetSubRect().GetWidth() ,
                0 ,
                ((int)_currentFrame) * this->GetSubRect().GetWidth() ,
                this->GetSubRect().GetHeight()
            ));
        // Resetting the frame of a perpetual animation ending
        if(_perpetual && (int)_currentFrame == _nbFrames)
            _currentFrame = 1;

        _currentFrame += 0.1;
    }
}
void GraphicElement::setNumberFrames(int nbFrames){
    _nbFrames = nbFrames;
}
void GraphicElement::setPosition(int x, int y){
  SetPosition(x, y);
}

void GraphicElement::setPosition(const Vector2f & pos){
  SetPosition(pos.x, pos.y);
}

/*** Methods ***/
void GraphicElement::resize(int w, int h){
  _w = w;
  _h = h;
  Resize(_w, _h);
}

void GraphicElement::draw(RenderWindow * window){
  window->Draw(*this);
}

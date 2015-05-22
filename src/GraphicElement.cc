// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GraphicElement.cc

#include "../include/GraphicElement.h"
#include <iostream>


using namespace std;
using namespace sf;

GraphicElement::GraphicElement():  Sprite(), _w(0), _h(0), _nbFrames(0), _currentFrame(0), _perpetual(false)
{}

GraphicElement::GraphicElement(Image *image) : Sprite(*image), _nbFrames(0), _currentFrame(0), _perpetual(false)
{}

GraphicElement::GraphicElement(Image * image, int nbFrames) : Sprite(*image), _nbFrames(nbFrames), _currentFrame(0), _perpetual(false)
{}

GraphicElement::GraphicElement(Image * image, int nbFrames, int firstFrame) : Sprite(*image), _nbFrames(nbFrames), _currentFrame(firstFrame), _perpetual(false)
{}

GraphicElement::~GraphicElement()
{}

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
void GraphicElement::nextFrame(){
    if(_perpetual || _currentFrame < _nbFrames)
    {
//        this->SetSubRect()
    }
}
void GraphicElement::setPosition(int x, int y){
  SetPosition(x, y);
}

void GraphicElement::setPosition(const Vector2f & pos){
  SetPosition(pos.x, pos.y);
}

void GraphicElement::resize(int w, int h){
  _w = w;
  _h = h;
  Resize(_w, _h);
}

void GraphicElement::draw(RenderWindow * window){
  window->Draw(*this);
}

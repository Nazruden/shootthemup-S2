// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// GraphicElement.cc

#include "../include/GraphicElement.h"
#include <iostream>


using namespace std;
using namespace sf;

/*** Constructors / Destructors ***/
GraphicElement::GraphicElement():  Sprite(), _w(0), _h(0), _nbFrames(0), _currentFrame(0), _perpetual(false)
{}

GraphicElement::GraphicElement(Image *image) : Sprite(*image), _nbFrames(0), _currentFrame(0), _perpetual(false)
{}

GraphicElement::GraphicElement(Image * image, int nbFrames) : Sprite(*image), _nbFrames(nbFrames), _currentFrame(1), _perpetual(false)
{}

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
void GraphicElement::nextFrame(){
    // If the graphicElement's animation didn't end
    if(_perpetual || _currentFrame < _nbFrames)
    {
        SetSubRect(sf::IntRect(
                (_currentFrame-1) * this->GetSubRect().GetWidth() ,
                0 ,
                (_currentFrame) * this->GetSubRect().GetWidth() ,
                this->GetSubRect().GetHeight()
            ));
        cout << " Setting the nextFrame of element " << this->getId() << endl;
        cout << " Next frame : " << endl
            <<  "\t  new X :  " <<  (_currentFrame) * this->GetSubRect().GetWidth() << endl
            << " \t last X : " << (_currentFrame-1) * this->GetSubRect().GetWidth() << endl;
        // Resetting the frame of a perpetual animation ending
        if(_perpetual && _currentFrame == _nbFrames)
            _currentFrame = 1;

        _currentFrame++;
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

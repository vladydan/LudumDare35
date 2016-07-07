#include "Duck.hpp"
#include "data.hpp"

Duck::Duck() : ACharacter()
{
  this->_texture = new sf::Texture();
  this->_texture->loadFromFile("ressources//Petit2.png");
  this->_texture->setSmooth(true);
  //sf::Vector2i screenDimensions(200, HEIGHT - 100);
  sf::Vector2i screenDimensions(300, HEIGHT - 125);

  this->_animate = new AnimatedSprite(sf::seconds(0.1), true, false);
  (*this->_animations)[RIGHT].setSpriteSheet(*this->_texture);
  this->setFrames(RIGHT, 44.99999, 49, 0, 4, 0);
  this->_x = 0;
  this->_y = 0;
  this->_speed = 800;
  this->_jumpHeight = 500;
  this->_strengh = false;
  this->_current = &((*this->_animations)[RIGHT]);
  this->_animate->setPosition(sf::Vector2f(screenDimensions));
  this->_animate->play(*this->_current);
  this->_animate->setOrigin(48, 39);
}

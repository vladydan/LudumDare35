#include "Rabbit.hpp"
#include "data.hpp"

Rabbit::Rabbit() : ACharacter()
{
  this->_texture = new sf::Texture();
  this->_texture->loadFromFile("ressources/bird.png");
  this->_texture->setSmooth(true);
  sf::Vector2i screenDimensions(300, 100);
  this->_animate = new AnimatedSprite(sf::seconds(0.1), true, false);
  (*this->_animations)[RIGHT].setSpriteSheet(*this->_texture);
  this->setFrames(RIGHT,120, 94, 0, 5, 0);
  this->_x = 0;
  this->_y = 0;
  this->_speed = 2300;
  this->_jumpHeight = 2500;
  this->_strengh = false;
  this->_current = &((*this->_animations)[RIGHT]);
  this->_animate->setPosition(sf::Vector2f(screenDimensions));
  this->_animate->play(*this->_current);
  this->_animate->setOrigin(48, 39);
  this->_bird = true;
}

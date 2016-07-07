#include "Humain.hpp"
#include "data.hpp"

Humain::Humain() : ACharacter()
{
  this->_texture = new sf::Texture();
  this->_texture->loadFromFile("ressources/lol.png");
  this->_texture->setSmooth(true);
  sf::Vector2i screenDimensions(300, HEIGHT - 300);
  this->_animate = new AnimatedSprite(sf::seconds(0.1), true, false);
  (*this->_animations)[RIGHT].setSpriteSheet(*this->_texture);
  //this->setFrames(RIGHT, 70, 90, 0, 6, 0);
  this->setFrames(RIGHT, 125, 125, 0, 6, 0);
  (*this->_animations)[UP].setSpriteSheet(*this->_texture);

  this->setFrames(UP, 125, 125, 0, 6, 0);

  //this->setFrames(UP, 70, 90, 0, 6, 0);
  this->_x = 0;
  this->_y = 0;
  this->_speed = 900;
  this->_strengh = false;
  this->_jumpHeight = 250;
  this->_current = &((*this->_animations)[RIGHT]);
  this->_animate->setPosition(sf::Vector2f(screenDimensions));
  this->_animate->play(*this->_current);
  this->_animate->setOrigin(48, 39);
}

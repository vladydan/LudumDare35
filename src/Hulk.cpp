#include "Hulk.hpp"
#include "data.hpp"

Hulk::Hulk() : ACharacter()
{
  this->_texture = new sf::Texture();
  this->_texture->loadFromFile("ressources/bear.png");
  this->_texture->setSmooth(true);
  //sf::Vector2i screenDimensions(200, HEIGHT - 100);
  sf::Vector2i screenDimensions(300, HEIGHT - 184);

  this->_animate = new AnimatedSprite(sf::seconds(0.1), true, false);
  (*this->_animations)[RIGHT].setSpriteSheet(*this->_texture);
  this->setFrames(RIGHT, 140, 180, 0, 8, 0);
  this->_x = 0;
  this->_y = 0;
  this->_speed = 700;
  this->_jumpHeight = 300;
  this->_strengh = true;
  this->_current = &((*this->_animations)[RIGHT]);
  this->_animate->setPosition(sf::Vector2f(screenDimensions));
  this->_animate->play(*this->_current);
  this->_animate->setOrigin(48, 39);
}

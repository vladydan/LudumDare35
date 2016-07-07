#include "JumpDuck.hpp"
#include <iostream>
#include "data.hpp"

JumpDuck::JumpDuck(int sizeX, int sizeY, std::string const &texture) : AObstacle()
{
  sf::Vector2i screenDimensions(200, HEIGHT - 110);
  this->_type = JUMP;
  this->_isDestructible = false;
  if (!this->_texture.loadFromFile(texture))
      std::cout << texture <<": texture loading error" << std::endl;
  this->_shape = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
  this->_shape->setPosition(sf::Vector2f(-1, -1));
  _sizeX = sizeX;
  _sizeY = sizeY;
  this->_animate = new AnimatedSprite(sf::seconds(0.1), true, false);
  (*this->_animations)[ACharacter::IDLE].setSpriteSheet(this->_texture);
  this->setFrames(ACharacter::IDLE, 270, 570, 0, 1, 0);

  this->_current = &((*this->_animations)[ACharacter::IDLE]);
  this->_animate->setPosition(sf::Vector2f(screenDimensions));
  this->_animate->play(*this->_current);
  this->_animate->setOrigin(48, 39);
}

void JumpDuck::init()
{
  this->_animate->setPosition(sf::Vector2f(WIDTH, -50));
}

JumpDuck::~JumpDuck()
{

}

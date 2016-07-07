#include "DestructibleObstacle.hpp"
#include <iostream>
#include "data.hpp"

DestructibleObstacle::DestructibleObstacle(int sizeX, int sizeY, std::string const &texture) : AObstacle()
{
  sf::Vector2i screenDimensions(200, HEIGHT - 110);
  this->_type = JUMP;
  this->_isDestructible = true;
  if (!this->_texture.loadFromFile(texture))
      std::cout << texture <<": texture loading error" << std::endl;
  this->_shape = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
  this->_shape->setPosition(sf::Vector2f(-1, -1));
  _sizeX = sizeX;
  _sizeY = sizeY;
  this->_animate = new AnimatedSprite(sf::seconds(0.06), true, false);
  (*this->_animations)[ACharacter::RIGHT].setSpriteSheet(this->_texture);
  this->setFrames(ACharacter::RIGHT,100, 600, 0, 8, 0);
  (*this->_animations)[ACharacter::IDLE].setSpriteSheet(this->_texture);
  this->setFrames(ACharacter::IDLE, 100, 600, 0, 1, 0);

  this->_current = &((*this->_animations)[ACharacter::IDLE]);
  this->_animate->setPosition(sf::Vector2f(screenDimensions));
  this->_animate->play(*this->_current);
  this->_animate->setOrigin(48, 39);
}

void DestructibleObstacle::init()
{
  this->_animate->setPosition(sf::Vector2f(WIDTH, -19));
}

DestructibleObstacle::~DestructibleObstacle()
{

}

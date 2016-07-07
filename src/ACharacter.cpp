#include "ACharacter.hpp"
#include <iostream>

ACharacter::ACharacter()
{
  this->_animations = new std::vector<Animation>(20);
  this->_lastAction = IDLE;
  this->_bird = false;
}

int ACharacter::getX()
{
  return _x;
}
int ACharacter::getY()
{
  return _y;
}

int ACharacter::getSpeed()
{
  return _speed;
}

int ACharacter::getJumpHeight()
{
  return _jumpHeight;
}

bool ACharacter::getStrength()
{
  return _strengh;
}

void ACharacter::setX(int x)
{
  _x = x;
}

void ACharacter::setY(int Y)
{
  _y = Y;
}

void ACharacter::setSpeed(int speed)
{
  _speed = speed;
}

void ACharacter::setJumpHeigt(int jumpHeight)
{
  _jumpHeight = jumpHeight;
}

void ACharacter::setStrengh(bool strengh)
{
  _strengh = strengh;
}

AnimatedSprite& ACharacter::getAnimatedSprite()
{
  return *_animate;
}

std::vector<Animation>& ACharacter::getAnimations()
{
  return *_animations;
}

void ACharacter::setFrames(animations anim, int sizeX, int sizeY, int line, int maxPerLine, int begin)
{
  int i;

  i = begin;
  while (i < begin + (maxPerLine * sizeX))
  {
    (*this->_animations)[anim].addFrame(sf::IntRect(i, line, sizeX, sizeY));
    i += sizeX;
  }
}

bool ACharacter::collide(sf::RectangleShape &back1, sf::RectangleShape &back2)
{
  if (_bird == true)
    return false;
  if (this->_animate->getGlobalBounds().intersects(back1.getGlobalBounds()) == false
    && this->_animate->getGlobalBounds().intersects(back2.getGlobalBounds()) == false)
      {
        return false;
      }
  return true;
}

void ACharacter::move(animations move, sf::Vector2f coord, const sf::Time& time,
  sf::RectangleShape &back1, sf::RectangleShape &back2)
{
  if (_bird == false && move == RIGHT && this->_animate->getGlobalBounds().intersects(back1.getGlobalBounds()) == false && this->_animate->getGlobalBounds().intersects(back2.getGlobalBounds()) == false)
  {
    coord.y = this->_speed / 2;
  }
  this->_animate->play(*this->_current);
  this->_animate->move(coord * time.asSeconds());
  this->_animate->update(time);
}

bool ACharacter::getBird()
{
  return _bird;
}

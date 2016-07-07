#include "AObstacle.hpp"
#include "data.hpp"

AObstacle::AObstacle()
{
  this->_animations = new std::vector<Animation>(20);
}

AObstacle::~AObstacle()
{

}

bool AObstacle::getDestructible() const
{
  return (this->_isDestructible);
}

sf::Vector2f AObstacle::getVector() const
{
  return (this->_vector2f);
}

TYPE_OBSTACLE AObstacle::getType() const
{
  return (this->_type);
}

void AObstacle::setDestructible(bool x)
{
  this->_isDestructible = x;
}

void AObstacle::setType(TYPE_OBSTACLE x)
{
  this->_type = x;
}

sf::Shape &AObstacle::getShape()
{
  return *this->_shape;
}

bool AObstacle::checkPlayerCollision(ACharacter &character)
{
  if (character.getAnimatedSprite().getGlobalBounds().intersects(this->_animate->getGlobalBounds()) == true && _isDestructible == true && character.getStrength() == true)
  {
    this->_current = &(*this->_animations)[ACharacter::RIGHT];
    return false;
  }
  return character.getAnimatedSprite().getGlobalBounds().intersects(this->_animate->getGlobalBounds());
}

void                AObstacle::update(sf::RenderWindow & win, const sf::Time& time)
{
    sf::Vector2f    posTmp;
    sf::Vector2f    coord(0, 0);

    posTmp = this->_animate->getPosition();
    posTmp.x -= SPEED;
    if (posTmp.x <= 0 - WIDTH)
    {

      this->_current = &(*this->_animations)[ACharacter::IDLE];
      return;
      posTmp.x = WIDTH;
    }
    this->_animate->setPosition(posTmp);
    this->_animate->play(*this->_current);
    this->_animate->update(time);
    win.draw(*this->_animate);
}

void AObstacle::setFrames(ACharacter::animations anim, int sizeX, int sizeY, int line, int maxPerLine, int begin)
{
  int i;

  i = begin;
  while (i < begin + (maxPerLine * sizeX))
  {
    (*this->_animations)[anim].addFrame(sf::IntRect(i, line, sizeX, sizeY));
    i += sizeX;
  }
}

AnimatedSprite& AObstacle::getAnimatedSprite()
{
  return *_animate;
}

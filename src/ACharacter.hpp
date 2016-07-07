#ifndef ACHARACTER_HPP
#define ACHARACTER_HPP

#include "AnimatedSprite.hpp"
#include "data.hpp"
#include <vector>

class ACharacter
{
  public:
    ACharacter();
    int getX();
    int getY();
    int getSpeed();
    int getJumpHeight();
    bool getStrength();
    void setX(int x);
    void setY(int x);
    void setSpeed(int x);
    void setJumpHeigt(int x);
    void setStrengh(bool x);
    AnimatedSprite& getAnimatedSprite();
    std::vector<Animation>& getAnimations();
    enum          animations
    {
      UP,
      DOWN,
      LEFT,
      RIGHT,
      RUP,
      LUP,
      RDOWN,
      LDOWN,
      DIE,
      HIT,
      UPIDLE,
      IDLE,
      LEFTIDLE,
      RIGHTIDLE,
      ATTACKL,
      ATTACKR,
      ATTACKF,
      ATTACKB,
    };
  void setFrames(animations move, int sizeX, int sizeY, int line, int maxPerLine, int begin);
  void move(animations move, sf::Vector2f coord, const sf::Time& time, sf::RectangleShape &back1, sf::RectangleShape &back2);
  bool collide(sf::RectangleShape &back1, sf::RectangleShape &back2);
  bool getBird();
  protected:
    int _x;
    int _y;
    int _speed;
    int _jumpHeight;
    bool _strengh;
    bool _bird;
    AnimatedSprite* _animate;
    Animation*      _current;
    std::vector<Animation>* _animations;
    animations    _lastAction;
    sf::Texture*  _texture;
};

#endif

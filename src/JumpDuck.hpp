#pragma once

#include <SFML/System.hpp>
#include "AObstacle.hpp"

class JumpDuck : public AObstacle
{
public:
  JumpDuck(int x ,int y, std::string const &texture);
  virtual void init();
  ~JumpDuck();
};

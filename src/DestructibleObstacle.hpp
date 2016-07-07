#pragma once

#include <SFML/System.hpp>
#include "AObstacle.hpp"

class DestructibleObstacle : public AObstacle
{
public:
  DestructibleObstacle(int x ,int y, std::string const &texture);
  virtual void init();
  ~DestructibleObstacle();
};

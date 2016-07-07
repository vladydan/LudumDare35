#ifndef JUMP_RABBIT_OBSTACLE_HPP
#define JUMP_RABBIT_OBSTACLE_HPP

#include <SFML/System.hpp>
#include "AObstacle.hpp"

class JumpRabbitObstacle : public AObstacle
{
public:
  JumpRabbitObstacle(int x ,int y, std::string const &texture);
  virtual void init();
  ~JumpRabbitObstacle();
};

#endif

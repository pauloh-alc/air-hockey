#ifndef GOAL_H
#define GOAL_H
#include <glm/glm.hpp>
#include "puck.h"

class Goal {
private:
  glm::vec2 position;
  float width;
  float lenght;
  glm::vec3 background_color;

public:
  Goal();
  void draw();

  void set_position_x(float x) { position.x = x; }

  void set_position_y(float y) { position.y = y; }

  bool check_collision(Puck &puck);
};

#endif // GOAL_H

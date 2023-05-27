#ifndef GOAL_H
#define GOAL_H
#include <glm/glm.hpp>

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
};

#endif // GOAL_H

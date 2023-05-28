#ifndef PUCK_H
#define PUCK_H
#include "glm/glm.hpp"

class Puck {
private:
  glm::vec2 position;
  glm::vec2 direction;
  float radius;
  glm::vec3 color;
  float size;

public:
  Puck();
  void draw();

  glm::vec2 get_position() { return position; }

  float get_position_x() { return position.x; }

  float get_position_y() { return position.y; }

  float get_radius() { return radius; }

  float get_size() { return size; }

  void set_position(glm::vec2 value) { position = value; }

  void set_position_x(float x) { position.x = x; }

  void set_position_y(float y) { position.y = y; }

  void set_direction(float x, float y) {
    direction = glm::normalize(glm::vec2(x, y));
  }

  void reset_diretion(float x, float y) {
    direction = glm::vec2(x, y);
  }

  glm::vec2 get_direction() { return direction; }

  void move_puck(float distance);
};

#endif // PUCK_H

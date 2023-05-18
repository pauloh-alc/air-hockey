#ifndef PUCK_H
#define PUCK_H
#include "glm/glm.hpp"

class Puck {
private:
  glm::vec2 position;
  float radius;
  glm::vec3 color;
  float size;
  float speed;

public:
  Puck();
  void draw();
};

#endif // PUCK_H

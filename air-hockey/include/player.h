#ifndef PLAYER_H
#define PLAYER_H
#include "glm/glm.hpp"

class Player {
private:
  glm::vec2 position;
  float radius;
  glm::vec3 color;
  float size;
  float speed;

public:
  Player();
  void draw();
};

#endif // PLAYER_H

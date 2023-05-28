#ifndef AI_H
#define AI_H
#include "glm/glm.hpp"
#include "puck.h"

enum{
  LEFT = 1,
  RIGHT
};

class AI {
  private:
    glm::vec2 position;
    int direction;
    float radius;
    glm::vec3 color;
    float size;

  public:
    AI();
    void draw();
    void move(float distantion);

    float get_position_x() { return position.x; }

    float get_position_y() { return position.y; }

    bool check_collision(Puck &puck);
};

#endif // AI_H

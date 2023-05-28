#include "goal.h"
#include "colors.h"
#include "shapes.h"
#include "sizes.h"
#include "puck.h"

Goal::Goal() {
  position = glm::vec2(WIDTH_AREA / 2.0f, 14.0f);
  width = 100;
  lenght = 10;
  background_color = glm::vec3(YELLOW[0], YELLOW[1], YELLOW[2]);
}

void Goal::draw() {
  glPushMatrix();
    glTranslatef(position.x, position.y, 0);
    glScalef(width, lenght, 1);
    glColor3f(background_color.r, background_color.g, background_color.b);
    Shapes::square();
  glPopMatrix();
}


bool Goal::check_collision(Puck& puck) {
  float limit_min_x = position.x - width - (puck.get_radius() * puck.get_size());
  float limit_max_x = position.x + width + (puck.get_radius() * puck.get_size());
  float limit_min_y = position.y - lenght - (puck.get_radius() * puck.get_size());
  float limit_max_y = position.y + lenght + (puck.get_radius() * puck.get_size());

  bool delta_x = puck.get_position_x() >= limit_min_x && puck.get_position_x() <= limit_max_x;
  bool delta_y = puck.get_position_y() >= limit_min_y && puck.get_position_y() <= limit_max_y;

  return (delta_x && delta_y) ? true : false;
}




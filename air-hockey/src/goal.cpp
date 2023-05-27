#include "goal.h"
#include "colors.h"
#include "shapes.h"
#include "sizes.h"

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

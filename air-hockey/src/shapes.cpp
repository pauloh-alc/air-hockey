#include "shapes.h"
#include <GL/glut.h>
#include <cmath>

Shapes::Shapes() {}

void Shapes::circle(int divisions, float radius) {
  float angle, axis_x, axis_y;

  glBegin(GL_POLYGON);
  for (int i = 0; i < divisions; i++) {
    angle = i * (2.0 * M_PI / divisions);
    axis_x = radius * cos(angle);
    axis_y = radius * sin(angle);
    glVertex2d(axis_x, axis_y);
  }
  glEnd();
}

void Shapes::square() {
  glBegin(GL_QUADS);
      glVertex2f(-1, -1);
      glVertex2f(1, -1);
      glVertex2f(1, 1);
      glVertex2f(-1, 1);
  glEnd();
}

#include "puck.h"
#include "colors.h"
#include "shapes.h"
#include "sizes.h"

Puck::Puck() {
    position = glm::vec2(WIDTH_AREA / 2.0f, HEIGHT_AREA / 2.0f);
    color = glm::vec3(BLUE[0], BLUE[1], BLUE[2]);
    radius = 3;
    size = 5;
    speed = 0;
}

void Puck::draw() {
    glPushMatrix();
        glTranslatef(position.x, position.y, 0);
        glScalef(size, size, 1);
        glColor3f(color.r, color.g, color.b);
        Shapes::circle(36, radius);
    glPopMatrix();
}

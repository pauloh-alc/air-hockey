#include "puck.h"
#include "colors.h"
#include "shapes.h"
#include "sizes.h"

Puck::Puck() {
    position = glm::vec2(WIDTH_AREA / 2.0f - 100, HEIGHT_AREA / 2.0f - 200);
    color = glm::vec3(BLUE[0], BLUE[1], BLUE[2]);
    direction = glm::vec2(0.0f, 0.0f);
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

void Puck::move_puck(float distance) {
    position = position + (direction * distance);
}





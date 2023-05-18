#include "ai.h"
#include "colors.h"
#include "shapes.h"
#include "sizes.h"

AI::AI() {
    position = glm::vec2(WIDTH_AREA / 2.0f, HEIGHT_AREA - 100.0);
    color = glm::vec3(WHITE[0], WHITE[1], WHITE[2]);
    radius = 3;
    size = 15;
    speed = 0;
}

void AI::draw() {
    glPushMatrix();
        glTranslatef(position.x, position.y, 0);
        glScalef(size, size, 1);
        glColor3f(color.r, color.g, color.b);
        Shapes::circle(36, radius);
    glPopMatrix();
}

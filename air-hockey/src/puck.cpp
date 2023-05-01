#include "puck.h"
#include "colors.h"
#include "shapes.h"

Puck::Puck()
{
    position = glm::vec2(2,3);
    color = glm::vec3(BLUE[0],BLUE[1],BLUE[2]);
    size = 0.15;
    speed = 0;
}

void Puck::draw()
{
    glPushMatrix();
        glTranslatef(position.x, position.y, 0);
        glScalef(size, size, 1);
        glColor3f(color.r, color.g, color.b);
        Shapes::circle(36);
    glPopMatrix();
}

#include "shapes.h"
#include <GL/glut.h>
#include <cmath>

Shapes::Shapes()
{

}


void Shapes::circle(int divisions)
{
    float angle, axis_x, axis_y;

    glBegin(GL_POLYGON);
        for (int i = 0; i < divisions; i++) {
            angle = i * (2.0 * M_PI / divisions);
            axis_x = cos(angle);
            axis_y = sin(angle);
            glVertex2d(axis_x, axis_y);
        }
    glEnd();
}

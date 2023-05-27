#include "table.h"
#include "colors.h"
#include "shapes.h"
#include "sizes.h"
#include <GL/gl.h>

Table::Table() {
    width = WINDOW_HEIGHT;
    lenght = WINDOW_WIDTH;
    background_color = glm::vec3(GREEN_FIELD[0], GREEN_FIELD[1], GREEN_FIELD[2]);
    border_color = glm::vec3(WHITE[0], WHITE[1], WHITE[2]);
    border_width = 10.0f;
}

void Table::draw() {
    glColor3f(background_color.r, background_color.g, background_color.b);
    glBegin(GL_QUADS);
        glVertex2d(0.0, 0.0);
        glVertex2d(lenght, 0.0);
        glVertex2d(lenght, width);
        glVertex2d(0.0, width);
    glEnd();

    glPushMatrix();
        glTranslatef(WINDOW_WIDTH / 2.0f, HEIGHT_AREA / 2.0F, 1.0f);
        glScalef(WINDOW_WIDTH, 4.5f, 1);
        glColor3f(WHITE[0], WHITE[1], WHITE[2]);
        Shapes::square();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(WINDOW_WIDTH / 2.0f, HEIGHT_AREA / 2.0F, 1.0f);
        glScalef(6, 6, 1);
        glColor3f(WHITE[0], WHITE[1], WHITE[2]);
        Shapes::circle(25, 3);
    glPopMatrix();

    glColor3f(border_color.r, border_color.g, border_color.b);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(border_width);
    glBegin(GL_LINE_LOOP);
        glVertex2d(0.0, 0.0);
        glVertex2d(lenght, 0.0);
        glVertex2d(lenght, width);
        glVertex2d(0.0, width);
    glEnd();
}

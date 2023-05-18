#include "table.h"
#include "colors.h"
#include "sizes.h"

Table::Table() {
    width = WINDOW_HEIGHT;
    lenght = WINDOW_WIDTH;
    background_color = glm::vec3(BLACK[0], BLACK[1], BLACK[2]);
    border_color = glm::vec3(WHITE[0], WHITE[1], WHITE[2]);
    border_width = 5.0f;
}

void Table::draw() {
    glColor3f(background_color.r, background_color.g, background_color.b);
        glBegin(GL_QUADS);
        glVertex2d(0.0, 0.0);
        glVertex2d(lenght, 0.0);
        glVertex2d(lenght, width);
        glVertex2d(0.0, width);
    glEnd();

    glColor3f(border_color.r, border_color.g, border_color.b);
        glLineWidth(border_width);
        glBegin(GL_LINE_LOOP);
        glVertex2d(0.0, 0.0);
        glVertex2d(lenght, 0.0);
        glVertex2d(lenght, width);
        glVertex2d(0.0, width);
    glEnd();
}

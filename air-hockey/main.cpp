#include <iostream>
#include <GL/glut.h>
#include <shapes.h>
#include <colors.h>
#include <puck.h>
#include <player.h>
#include <ai.h>
#include <sizes.h>
#include <table.h>

using namespace std;

const char *GAME_NAME = "Air Hockey";

Puck puck;
Table table;
Player player1;
AI player2;

void init()
{
    glClearColor(BACKGROUND_COLOR_WINDOW[0], BACKGROUND_COLOR_WINDOW[1], BACKGROUND_COLOR_WINDOW[2], BACKGROUND_COLOR_WINDOW[3]);
}


void initWindow(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow(GAME_NAME);

    int x_axis = (glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2;
    int y_axis = (glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2;

    glutPositionWindow(x_axis, y_axis);
}


void setProjection()
{
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH_AREA, 0, HEIGHT_AREA, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void move_player1(int key, int x, int y)
{
    float move_step = 8.0;

    switch(key) {
        case GLUT_KEY_LEFT:  player1.set_position_x(player1.get_position_x() - move_step); break;
        case GLUT_KEY_RIGHT: player1.set_position_x(player1.get_position_x() + move_step); break;
        case GLUT_KEY_DOWN:  player1.set_position_y(player1.get_position_y() - move_step); break;
        case GLUT_KEY_UP:    player1.set_position_y(player1.get_position_y() + move_step); break;
    }
    glutPostRedisplay();
}


void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    setProjection();
    table.draw();
    puck.draw();
    player1.draw();
    player2.draw();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    initWindow(argc, argv);
    init();
    glutDisplayFunc(draw);
    glutSpecialFunc(move_player1);
    glutMainLoop();
    return 0;
}

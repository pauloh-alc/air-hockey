#include <iostream>
#include <GL/glut.h>

using namespace std;

const char *GAME_NAME = "Air Hockey";
const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;


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


int main(int argc, char** argv)
{
    initWindow(argc, argv);
    glutMainLoop();
    return 0;
}

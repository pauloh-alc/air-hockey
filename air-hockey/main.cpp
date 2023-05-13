#include <GL/glut.h>
#include <ai.h>
#include <colors.h>
#include <iostream>
#include <player.h>
#include <puck.h>
#include <shapes.h>
#include <sizes.h>
#include <table.h>

using namespace std;

const char *GAME_NAME = "Air Hockey";

Puck puck;
Table table;
Player player1;
AI player2;

void init() {
  glClearColor(BACKGROUND_COLOR_WINDOW[0], BACKGROUND_COLOR_WINDOW[1],
               BACKGROUND_COLOR_WINDOW[2], BACKGROUND_COLOR_WINDOW[3]);
}

void init_window(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow(GAME_NAME);

  int x_axis = (glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2;
  int y_axis = (glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2;

  glutPositionWindow(x_axis, y_axis);
}

void set_projection() {
  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, WIDTH_AREA, 0, HEIGHT_AREA, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  set_projection();
  table.draw();
  puck.draw();
  player1.draw();
  player2.draw();
  glutSwapBuffers();
}

int main(int argc, char **argv) {
  init_window(argc, argv);
  init();
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}

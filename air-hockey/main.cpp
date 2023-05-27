#include <GL/glut.h>
#include <ai.h>
#include <colors.h>
#include <goal.h>
#include <iostream>
#include <player.h>
#include <puck.h>
#include <set>
#include <shapes.h>
#include <sizes.h>
#include <table.h>
#define FPS 60

using namespace std;

const char *GAME_NAME = "Air Hockey";

Puck puck;
Table table;
Player player1;
AI player2;
Goal goal1;
Goal goal2;
std::set<int> keys;

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

void release_key(int key, int x, int y) { keys.erase(key); }

void timer(int v){
  glutTimerFunc(1000.0/FPS, timer, 0);
  puck.move_puck(9);
  player2.move(10);
  glutPostRedisplay();
}

void verify_collision() {
  if (player1.check_collision(puck)) {
    float player1_pos_x = player1.get_position_x();
    float player1_pos_y = player1.get_position_y();

    float puck_pos_x = puck.get_position_x();
    float puck_pos_y = puck.get_position_y();

    float direction_x = puck_pos_x - player1_pos_x;
    float direction_y = puck_pos_y - player1_pos_y;

    puck.set_direction(direction_x, direction_y);
  }
}

void move_player1(int key, int x, int y) {
  keys.insert(key);

  int step = 15;
  float player1_x = player1.get_position_x();
  float player1_y = player1.get_position_y();

  float limit_max_x = WIDTH_AREA - (player1.get_size() * player1.get_radius());
  float limit_max_y = (HEIGHT_AREA - (player1.get_size() * player1.get_radius())) / 2.0f - table.get_border_width();
  float limit_min_x = player1.get_size() * player1.get_radius() + table.get_border_width();
  float limit_min_y = player1.get_size() * player1.get_radius() + table.get_border_width();

  if (keys.count(GLUT_KEY_LEFT) && player1_x > limit_min_x)
    player1_x -= step;
  if (keys.count(GLUT_KEY_RIGHT) && player1_x < limit_max_x)
    player1_x += step;
  if (keys.count(GLUT_KEY_DOWN) && player1_y > limit_min_y)
    player1_y -= step;
  if (keys.count(GLUT_KEY_UP) && player1_y < limit_max_y)
    player1_y += step;

  player1.set_position_x(player1_x);
  player1.set_position_y(player1_y);

  if (player1.check_collision(puck)) {
    verify_collision();
  }

  glutPostRedisplay();
}

void draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  set_projection();
  table.draw();
  puck.draw();
  player1.draw();
  player2.draw();
  goal1.set_position_y(14.0f);
  goal1.draw();
  goal2.set_position_y(HEIGHT_AREA - 14.0f);
  goal2.draw();

  glutSwapBuffers();
}

int main(int argc, char **argv) {
  init_window(argc, argv);
  init();
  glutDisplayFunc(draw);
  glutSpecialFunc(move_player1);
  glutSpecialUpFunc(release_key);
  glutTimerFunc(1000.0 / FPS, timer, 0);
  glutMainLoop();

  return 0;
}

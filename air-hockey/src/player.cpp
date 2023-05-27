#include "player.h"
#include "colors.h"
#include "puck.h"
#include "shapes.h"
#include "sizes.h"
#include <iostream>

Player::Player() {
  position = glm::vec2(WIDTH_AREA / 2.0f, HEIGHT_AREA / 7.0f);
  color = glm::vec3(RED[0], RED[1], RED[2]);
  radius = 3;
  size = 15;
  speed = 0;
}

void Player::draw() {
  glPushMatrix();
      glTranslatef(position.x, position.y, 0);
      glScalef(size, size, 1);
      glColor3f(color.r, color.g, color.b);
      Shapes::circle(36, radius);
  glPopMatrix();
}

bool Player::check_collision(Puck &puck) {

  glm::vec2 distance_player1_puck = position - puck.get_position();
  float radius_player1_puck = (radius * size) + (puck.get_radius() * puck.get_size());

  bool result = glm::length(distance_player1_puck) < radius_player1_puck;

  return result;
}

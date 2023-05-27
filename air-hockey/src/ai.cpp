#include "ai.h"
#include "colors.h"
#include "shapes.h"
#include "sizes.h"
#include <iostream>
AI::AI() {
  position = glm::vec2(WIDTH_AREA / 2.0f, HEIGHT_AREA - 100.0);
  direction = LEFT;
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


void AI::move(float distantion){
  if(direction == RIGHT){
    position.x += distantion;
    if(position.x > WIDTH_AREA - (radius * size)) direction = LEFT;
  }
  else{
    position.x -= distantion;
    if(position.x < (radius * size)) direction = RIGHT;
  }
}

bool AI::check_collision(Puck &puck) {
  glm::vec2 distance_player2_puck = position - puck.get_position();
  float radius_player2_puck = (radius * size) + (puck.get_radius() * puck.get_size());

  bool result = glm::length(distance_player2_puck) < radius_player2_puck;
  std::cout << result;
  return result;
}

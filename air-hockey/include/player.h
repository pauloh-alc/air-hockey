#ifndef PLAYER_H
#define PLAYER_H
#include "glm/glm.hpp"

class Player {
    private:
        glm::vec2 position;
        float radius;
        glm::vec3 color;
        float size;
        float speed;

    public:
        Player();

        float get_position_x() {
            return position.x;
        }

        float get_position_y() {
            return position.y;
        }

        float get_radius() {
            return radius;
        }

        float get_size() {
            return size;
        }

        void set_position_x(float x) {
            position.x = x;
        }

        void set_position_y(float y) {
            position.y = y;
        }

        void set_position_x();
        void draw();
};

#endif // PLAYER_H

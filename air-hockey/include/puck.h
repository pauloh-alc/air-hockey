#ifndef PUCK_H
#define PUCK_H
#include "glm/glm.hpp"

class Puck {
    private:
        glm::vec2 position;
        float radius;
        glm::vec3 color;
        float size;
        float speed;

    public:
        Puck();
        void draw();

        glm::vec2 get_position() {
            return position;
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

        void set_position_y(float y) {
            position.y = y;
        }

        void move_puck(float distance);
};

#endif // PUCK_H

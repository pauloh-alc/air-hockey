#ifndef AI_H
#define AI_H
#include "glm/glm.hpp"

enum{
    LEFT = 1,
    RIGHT
};

class AI {
    private:
        glm::vec2 position;
        int direction;
        float radius;
        glm::vec3 color;
        float size;
        float speed;

    public:
        AI();
        void draw();
        void move(float distantion);
};

#endif // AI_H

#ifndef AI_H
#define AI_H
#include "glm/glm.hpp"

class AI {
    private:
        glm::vec2 position;
        float radius;
        glm::vec3 color;
        float size;
        float speed;
    public:
        AI();
        void draw();

};

#endif // AI_H

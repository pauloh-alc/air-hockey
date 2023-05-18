#ifndef TABLE_H
#define TABLE_H
#include <glm/glm.hpp>

class Table {
private:
  float width;
  float lenght;
  glm::vec3 background_color;
  glm::vec3 border_color;
  float border_width;

    public:
        Table();
        float get_border_width()
        {
            return border_width;
        }
        void draw();
};

#endif // TABLE_H

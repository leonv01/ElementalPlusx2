//
// Created by leon on 9/2/23.
//

#ifndef ELEMENTALPLUSX2_RENDER_H
#define ELEMENTALPLUSX2_RENDER_H

#include <vector>
#include "GL/glut.h"

class Render {
private:
    std::vector<std::vector<unsigned int>>* idMap;
public:
    static constexpr int WIN_WIDTH = 1920;
    static constexpr int WIN_HEIGHT = 1080;

    static constexpr int CELL_SIZE = 2;
    static constexpr int CELL_CENTER = CELL_SIZE / 2;

    explicit Render(std::vector<std::vector<unsigned int>>* id);
    ~Render();

    void renderGrid();
    void init();
};


#endif //ELEMENTALPLUSX2_RENDER_H

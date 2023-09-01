//
// Created by leon on 9/2/23.
//

#ifndef ELEMENTALPLUSX2_RENDER_H
#define ELEMENTALPLUSX2_RENDER_H

#include "GL/glut.h"

class Render {

public:
    static constexpr int WIN_WIDTH = 800;
    static constexpr int WIN_HEIGHT = 800;

    Render();

    static void renderGrid();
    void init();
};


#endif //ELEMENTALPLUSX2_RENDER_H

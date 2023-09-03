//
// Created by leon on 9/2/23.
//

#ifndef ELEMENTALPLUSX2_RENDER_H
#define ELEMENTALPLUSX2_RENDER_H

#include <vector>
#include <cstdio>

#include "Particle.h"
#include "GL/glut.h"

class Render {
private:
    std::vector<std::vector<Particle>>* particleMap;
public:
    static constexpr int WIN_WIDTH = 1920;
    static constexpr int WIN_HEIGHT = 1080;

    static constexpr int CELL_SIZE = 2;
    static constexpr int CELL_CENTER = CELL_SIZE / 2;

    int* mouseX,* mouseY;
    bool* leftButton;
    bool* rightButton{};

    Render(std::vector<std::vector<Particle>>* particleVec, int* mouseX, int* mouseY, bool* leftMouse);
    ~Render();

    void mousePosition(int x, int y) const;
    void mouseButtonDown(int button, int state, int x, int y) const;
    static void resize(int x, int y);
    void renderGrid();
    void init();
};


#endif //ELEMENTALPLUSX2_RENDER_H

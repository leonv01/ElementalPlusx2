//
// Created by leon on 9/2/23.
//

#ifndef ELEMENTALPLUSX2_RENDER_H
#define ELEMENTALPLUSX2_RENDER_H

#include <vector>
#include <cstdio>
#include "GL/glut.h"

class Render {
private:
    std::vector<std::vector<unsigned int>>* idMap;
public:
    static constexpr int WIN_WIDTH = 1920;
    static constexpr int WIN_HEIGHT = 1080;

    static constexpr int CELL_SIZE = 10;
    static constexpr int CELL_CENTER = CELL_SIZE / 2;

    int* mouseX,* mouseY;
    bool* userInput;

    Render(std::vector<std::vector<unsigned int>>* id, int* mouseX, int* mouseY, bool* userInput);
    ~Render();

    void mousePosition(int x, int y) const;
    void renderGrid();
    void init();
};


#endif //ELEMENTALPLUSX2_RENDER_H

//
// Created by leon on 9/2/23.
//

#ifndef ELEMENTALPLUSX2_RENDER_H
#define ELEMENTALPLUSX2_RENDER_H

#include <vector>
#include <cstdio>

#include "Particle.h"
#include "GL/glut.h"
#include "GL/freeglut.h"
#include "UserInput.h"

class Render {
private:
    std::vector<std::vector<Particle>>* particleMap;
    UserInput* userInput;

public:
    static constexpr int WIN_WIDTH = 1920;
    static constexpr int WIN_HEIGHT = 1080;

    static constexpr int CELL_SIZE = 5;
    static constexpr int CELL_CENTER = CELL_SIZE / 2;

    Render(std::vector<std::vector<Particle>>* particleVec, UserInput* userInput);
    ~Render();

    void mousePosition(int x, int y) const;
    void mouseButtonDown(int button, int state, int x, int y) const;
    void keyboardPress(unsigned char key, int x, int y);
    void mouseWheel(int wheel, int direction, int x, int y);
    static void resize(int x, int y);
    void renderGrid();
    void init();

    void renderString(float x, float y, void *font, const char *string);
};


#endif //ELEMENTALPLUSX2_RENDER_H

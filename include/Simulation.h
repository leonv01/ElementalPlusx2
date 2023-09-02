//
// Created by leon on 9/1/23.
//

#ifndef ELEMENTALPLUSX2_SIMULATION_H
#define ELEMENTALPLUSX2_SIMULATION_H


#include <cstdint>
#include <vector>

#include "Render.h"
#include "thread"
#include "chrono"
#include "Particle.h"

class Simulation {
private:
    int i = 0;

    static constexpr unsigned int GRID_WIDTH = Render::WIN_WIDTH / Render::CELL_SIZE;
    static constexpr unsigned int GRID_HEIGHT = Render::WIN_HEIGHT / Render::CELL_SIZE;

    std::vector<std::vector<Particle>> particleGrid;
    std::vector<std::vector<unsigned int>> colorIdGrid;

    void updateSandParticle(unsigned int x, unsigned int y);

    int* mouseX,* mouseY;
    bool* userInput;
public:
    Simulation();

    void testGrid();
    void printParticleGrid();

    std::vector<std::vector<unsigned int>>* getIdMap();
    int* getMouseX();
    int* getMouseY();
    bool* getUserInput();

    void setParticle();
    void initGrid();
    void update();

    void printColorIdGrid();
};


#endif //ELEMENTALPLUSX2_SIMULATION_H

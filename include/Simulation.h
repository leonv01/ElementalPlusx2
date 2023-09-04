//
// Created by leon on 9/1/23.
//

#ifndef ELEMENTALPLUSX2_SIMULATION_H
#define ELEMENTALPLUSX2_SIMULATION_H


#include <cstdint>
#include <vector>
#include <random>

#include "Render.h"
#include "thread"
#include "chrono"
#include "Particle.h"

enum ELEMENT : unsigned int{
    _EMPTY = 0,
    _SAND = 1,
    _WATER = 2
};

class Simulation {
private:

    ELEMENT currentElement;

    static constexpr unsigned int GRID_WIDTH = Render::WIN_WIDTH / Render::CELL_SIZE;
    static constexpr unsigned int GRID_HEIGHT = Render::WIN_HEIGHT / Render::CELL_SIZE;
    int BRUSH_SIZE = 2;

    std::vector<std::vector<Particle>> particleGrid;
    std::vector<std::vector<unsigned int>> colorIdGrid;

    void updateSandParticle(unsigned int x, unsigned int y);
    void updateWaterParticle(unsigned int x, unsigned int y);

    UserInput* userInput;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<double> distribution;

    bool frame{};

public:
    Simulation();
    std::vector<std::vector<Particle>>* getParticleVec();

    UserInput* getUserInput();

    void handleUserInput();

    bool checkBounds(int x, int y) const;
    void setParticle(int id);
    void initGrid();
    void update();
};


#endif //ELEMENTALPLUSX2_SIMULATION_H

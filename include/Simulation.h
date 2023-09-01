//
// Created by leon on 9/1/23.
//

#ifndef ELEMENTALPLUSX2_SIMULATION_H
#define ELEMENTALPLUSX2_SIMULATION_H


#include <cstdint>
#include <vector>
#include "thread"
#include "chrono"
#include "Particle.h"

class Simulation {
private:
    static constexpr uint32_t WIDTH = 10;
    static constexpr uint32_t HEIGHT = 10;

    std::vector<std::vector<Particle>> particleGrid;

    void updateSandParticle(uint8_t x, uint8_t y);
public:
    Simulation();

    void testGrid();

    void printGrid();
    void run();
    void initGrid();
    void checkGrid();
};


#endif //ELEMENTALPLUSX2_SIMULATION_H

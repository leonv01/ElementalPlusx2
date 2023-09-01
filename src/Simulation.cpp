//
// Created by leon on 9/1/23.
//

#include <iostream>
#include "../include/Simulation.h"

Simulation::Simulation() {
    initGrid();
}

void Simulation::initGrid() {
    particleGrid = std::vector<std::vector<Particle>>(HEIGHT);
    for (std::vector<Particle> &v: particleGrid) {
        v = std::vector<Particle>(WIDTH);
        for (Particle &p: v) p = Particle{};
    }
}

void Simulation::checkGrid() {
    for (int y = HEIGHT - 1; y >= 0; y--) {
        std::cout << std::endl;
        for (int x = 0; x < WIDTH; x++) {

            // Update Particle location based on id
            switch (particleGrid[y][x].getID()) {
                // Standard Particle aka. no reaction
                case 0:
                    break;
                    // Sand Particle
                case 1:
                    updateSandParticle(x, y);
                    break;

            }
        }
    }
}

/*
 * Example: Particle checks adjacent particles
 * x x x
 * x p x
 * o o o
 */
void Simulation::updateSandParticle(uint8_t x, uint8_t y) {

    /*
     * 1. Check middle
     * 2. Check left
     * 3. Check right
     */
    if ((y + 1) < HEIGHT) {
        if (particleGrid[y + 1][x].getID() == 0) {
            std::swap(particleGrid[y][x], particleGrid[y + 1][x]);
        } else if ((x - 1) >= 0 && particleGrid[y + 1][x - 1].getID() == 0) {
            std::swap(particleGrid[y][x], particleGrid[y + 1][x - 1]);
        } else if ((x + 1) < WIDTH && particleGrid[y + 1][x + 1].getID() == 0) {
            std::swap(particleGrid[y][x], particleGrid[y + 1][x + 1]);
        }
    }
}

void Simulation::run() {
    testGrid();
    int i = 0;
    while(true){

        printGrid();
        checkGrid();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << std::endl;
        i++;

        if(i % 5 == 0) testGrid();
    }
}

void Simulation::testGrid() {
    particleGrid[0][4] = Particle(1);
}

void Simulation::printGrid() {
    for(const std::vector<Particle>& y : particleGrid){
        for(Particle x : y){
            std::cout << static_cast<int>(x.getID()) << " ";
        }
        std::cout << std::endl;
    }
}

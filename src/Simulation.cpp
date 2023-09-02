//
// Created by leon on 9/1/23.
//

#include <iostream>
#include "../include/Simulation.h"

Simulation::Simulation() {
    initGrid();
}

void Simulation::initGrid() {
    particleGrid = std::vector<std::vector<Particle>>(GRID_HEIGHT);
    colorIdGrid = std::vector<std::vector<unsigned int>>(GRID_HEIGHT);

    for (size_t y = 0; y < GRID_HEIGHT; y++) {
        particleGrid[y] = std::vector<Particle>(GRID_WIDTH);
        colorIdGrid[y] = std::vector<unsigned int>(GRID_WIDTH);

        for (size_t x = 0; x < GRID_WIDTH; x++) {
            particleGrid[y][x] = Particle();
            colorIdGrid[y][x] = 0;
        }
    }
}

void Simulation::update() {
    i++;
    for (int y = GRID_HEIGHT - 1; y >= 0; y--) {
        std::cout << std::endl;
        for (int x = 0; x < GRID_WIDTH; x++) {
            unsigned int id = particleGrid[y][x].getID();
            colorIdGrid[y][x] = id;
            switch (id) {
                // Standard Particle aka. no reaction
                case 0:
                    break;
                    // Sand Particle
                case 1:
                    updateSandParticle(x, y);
                    break;
                default:
                    break;

            }

        }
    }
    if (i % 5 == 0)
        testGrid();
    //printColorIdGrid();
}

/*
 * Example: Particle checks adjacent particles
 * x x x
 * x p x
 * o o o
 */
void Simulation::updateSandParticle(unsigned int x, unsigned int y) {

    /*
     * 1. Check middle
     * 2. Check left
     * 3. Check right
     */
    if ((y + 1) < GRID_HEIGHT) {
        if (particleGrid[y + 1][x].getID() == 0) {
            std::swap(particleGrid[y][x], particleGrid[y + 1][x]);
        } else if ((x - 1) > 0 && particleGrid[y + 1][x - 1].getID() == 0) {
            std::swap(particleGrid[y][x], particleGrid[y + 1][x - 1]);
        } else if ((x + 1) < GRID_WIDTH && particleGrid[y + 1][x + 1].getID() == 0) {
            std::swap(particleGrid[y][x], particleGrid[y + 1][x + 1]);
        }
    }
}

void Simulation::testGrid() {
    particleGrid[0][4] = Particle(1);
}

void Simulation::printParticleGrid() {
    for (const std::vector<Particle> &y: particleGrid) {
        for (Particle x: y) {
            std::cout << static_cast<int>(x.getID()) << " ";
        }
        std::cout << std::endl;
    }
}

void Simulation::printColorIdGrid(){
    for(const std::vector<unsigned int>& y: colorIdGrid){
        for(unsigned int x : y){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}
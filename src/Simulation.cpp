#include <iostream>
#include "../include/Simulation.h"

Simulation::Simulation() {
    currentElement = _SAND;
    userInput = new UserInput;
    gen = std::mt19937(rd());
    distribution = std::uniform_real_distribution<double>(0.0, 1.0);

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

    handleUserInput();

    if(frame) {
        for (int y = GRID_HEIGHT - 1; y >= 0; y--) {
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

                    case 2:
                        updateWaterParticle(x, y);
                    default:
                        break;
                }
            }
        }
    }
    else {
        for (int y = GRID_HEIGHT - 1; y >= 0; y--) {
            for (int x = GRID_WIDTH - 1; x >= 0; x--) {
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

                    case 2:
                        updateWaterParticle(x, y);
                    default:
                        break;
                }
            }
        }
    }
    frame = !frame;
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

    Particle *currentParticle = &particleGrid[y][x];

    Particle *leftAdjacent;
    Particle *rightAdjacent;
    Particle *centerAdjacent;

    currentParticle->updateParticle();

    unsigned int gravity = currentParticle->getGravity();

    unsigned int newY = y + 1;
    unsigned int currentY = y;

    if(newY < GRID_HEIGHT && (x - 1) > 0 && (x + 1) < GRID_WIDTH && x != 0) {
        if (
                particleGrid[newY][x + 1].getID() == 1 &&
                particleGrid[newY][x].getID() == 1 &&
                particleGrid[newY][x - 1].getID() == 1
        ) {
             return;
        }
    }
    for(unsigned int offset = 1; offset < gravity; offset++){
        newY = y + offset;

        if(particleGrid[newY][x].getID() == 0 && newY != GRID_HEIGHT - 1){
            currentY = newY;
        }
        else {
            break;
        }
    }

    if (newY != GRID_HEIGHT - 1) {

        leftAdjacent = &particleGrid[newY][x - 1];
        centerAdjacent = &particleGrid[currentY][x];
        rightAdjacent = &particleGrid[newY][x + 1];


        if (particleGrid[currentY][x].getID() == 0) {
           // currentParticle->setColor(1.0,0.5,0.5);
            std::swap(*currentParticle, *centerAdjacent);
        } else {
            //currentParticle->setColor(1.0,0.65,0.0);

            if (x == 0) {
                if (rightAdjacent->getID() == 0)
                    std::swap(particleGrid[y][x], *rightAdjacent);
            } else if (x == GRID_WIDTH - 1) {
                if (leftAdjacent->getID() == 0) {
                    std::swap(particleGrid[y][x], *leftAdjacent);
                }
            } else {
                if (distribution(gen) < 0.5) {
                    std::swap(*currentParticle,*leftAdjacent);
                } else {
                    std::swap(*currentParticle, *rightAdjacent);
                }
            }
        }
    }
}

void Simulation::updateWaterParticle(unsigned int x, unsigned int y) {

    /*
     * 1. Check middle
     * 2. Check left
     * 3. Check right
     */


    Particle *particle = &particleGrid[y][x];

    particle->updateParticle();

    unsigned int gravity = particle->getGravity();

    unsigned int newY = y + 1;
    unsigned int currentY = y;


    for(unsigned int offset = 1; offset < gravity; offset++){
        newY = y + offset;

        if(particleGrid[newY][x].getID() == 0 && newY < GRID_HEIGHT - 1){
            currentY = newY;
        }
        else break;
    }
    if (newY < GRID_HEIGHT - 1) {
        if (particleGrid[currentY][x].getID() == 0) {
            std::swap(particleGrid[y][x], particleGrid[currentY][x]);
        } else {
            if (x == 0) {
                if (particleGrid[currentY][x].getID() == 0)
                    std::swap(particleGrid[y][x], particleGrid[currentY][x + 1]);
            } else if (x == GRID_WIDTH - 1) {
                if (particleGrid[currentY][x - 1].getID() == 0) {
                    std::swap(particleGrid[y][x], particleGrid[currentY][x + 1]);
                }
            } else {
                if (distribution(gen) < 0.5) {
                    std::swap(particleGrid[y][x], particleGrid[currentY][x - 1]);
                } else {
                    std::swap(particleGrid[y][x], particleGrid[currentY][x + 1]);
                }

            }
        }
    }
}


void Simulation::setParticle(int id) {
    unsigned int brushCenter = BRUSH_SIZE / 2;

    for (unsigned int y = userInput->getMouseY() - brushCenter; y < userInput->getMouseY() + brushCenter; y++) {
        for (unsigned int x = userInput->getMouseX() - brushCenter; x < userInput->getMouseX() + brushCenter; x++) {
            if(!checkBounds(x, y)) break;
            particleGrid[y][x] = Particle(id);
        }
    }
}

std::vector<std::vector<Particle>> *Simulation::getParticleVec() {
    return &particleGrid;
}

bool Simulation::checkBounds(unsigned int x, unsigned int y) const {
    return (
            x > 0 && x < GRID_WIDTH - 1 &&
            y > 0 && y < GRID_HEIGHT - 1
    );
}

UserInput *Simulation::getUserInput() {
    return userInput;
}

void Simulation::handleUserInput() {
    if (userInput->getMouseLeft() && !userInput->getMouseRight()) {
        setParticle(currentElement);
    } else if (!userInput->getMouseLeft() && userInput->getMouseRight()) {
        setParticle(0);
    } else if (userInput->getKeyR()) {
        initGrid();
        userInput->setKeyR(false);
    } else if (userInput->getMouseWheelUp()) {
        BRUSH_SIZE += 5;
        userInput->setMouseWheelUp(false);
    } else if (userInput->getMouseWheelDown()) {
        BRUSH_SIZE -= 5;
        userInput->setMouseWheelDown(false);
    } else if(userInput->getKey1()){
        currentElement = _SAND;
    } else if(userInput->getKey2()){
        currentElement = _WATER;
    }

}

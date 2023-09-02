//
// Created by leon on 9/1/23.
//

#ifndef ELEMENTALPLUSX2_PARTICLE_H
#define ELEMENTALPLUSX2_PARTICLE_H


#include <cstdint>
#include "GL/glut.h"

class Particle {
private:
    unsigned int id;
    size_t lifeTime{};
    size_t timeAlive{};
    int color[3]{};

public:
    Particle();
    explicit Particle(unsigned int id);
    Particle(unsigned int id, size_t lifeTime);

    ~Particle() = default;

    unsigned int getID() const;

    size_t getLifeTime();
    size_t getTimeAlive();

    void inline incrementTimeAlive();
};

#endif //ELEMENTALPLUSX2_PARTICLE_H

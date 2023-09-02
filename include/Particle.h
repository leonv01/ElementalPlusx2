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
    double lifeTime{};
    double timeAlive{};
    int color[3];

public:
    Particle();
    explicit Particle(unsigned int id);

    ~Particle() = default;

    unsigned int getID() const;
};

#endif //ELEMENTALPLUSX2_PARTICLE_H

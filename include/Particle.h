//
// Created by leon on 9/1/23.
//

#ifndef ELEMENTALPLUSX2_PARTICLE_H
#define ELEMENTALPLUSX2_PARTICLE_H


#include <cstdint>
#include <GL/glut.h>
#include <GL/gl.h>

class Particle {
private:
    uint8_t id;
    double lifeTime{};
    double timeAlive{};

public:
    Particle();
    explicit Particle(uint8_t id);

    uint8_t getID() const;
};


#endif //ELEMENTALPLUSX2_PARTICLE_H

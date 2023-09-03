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

    int gravity;
    float color[3];
    float horizontalSpreading;


public:
    Particle();
    explicit Particle(unsigned int id);
    Particle(unsigned int id, size_t lifeTime);

    ~Particle() = default;

    unsigned int getID() const;
    void getColor(float* r, float* g, float* b) const;
    size_t getLifeTime();
    size_t getTimeAlive();
    int getGravity();

    void updateParticle();

};

#endif //ELEMENTALPLUSX2_PARTICLE_H

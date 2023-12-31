//
// Created by leon on 9/1/23.
//

#ifndef ELEMENTALPLUSX2_PARTICLE_H
#define ELEMENTALPLUSX2_PARTICLE_H


#include <cstdint>
#include "GL/glut.h"

class Particle {
private:
    bool staticPosition{};

    unsigned int id;
    int lifeTime{};
    unsigned int timeAlive{};

    int gravity;
    float color[3];
    float horizontalSpreading;


public:
    Particle() = default;
    Particle(unsigned int id, int lifeTime);

    ~Particle() = default;


    int getGravity() const;
    unsigned int getID() const;

    void createSand();
    void createWater();
    void createEmpty();
    void createWood();

    void swap(Particle* other);
    void updateParticle();
    void getColor(float* r, float* g, float* b) const;
    void setColor(float r, float g, float b);
};

#endif //ELEMENTALPLUSX2_PARTICLE_H

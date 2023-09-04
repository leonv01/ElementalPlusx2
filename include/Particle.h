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


    int getGravity() const;
    unsigned int getID() const;
    bool getStaticPosition() const;

    void updateParticle();
    void getColor(float* r, float* g, float* b) const;
    void create(unsigned int id);
    void setStaticPosition(bool value);
    void setColor(float r, float g, float b);

    size_t getLifeTime();
    size_t getTimeAlive();
};

#endif //ELEMENTALPLUSX2_PARTICLE_H

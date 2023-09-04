//
// Created by leon on 9/1/23.
//

#include "../include/Particle.h"

Particle::Particle() {
    color[0] = 0.0;
    color[1] = 0.0;
    color[2] = 0.0;

    this->id = 0;
    lifeTime = -1;
    timeAlive = 0;
}
Particle::Particle(unsigned int id) {
    create(id);
    this->id = id;
    lifeTime = -1;
    timeAlive = 0;
}

Particle::Particle(unsigned int id, int lifeTime) {
    create(id);
    this->id = id;
    this->lifeTime = lifeTime;
    timeAlive = 0;
}

void Particle::create(const unsigned int id) {
    switch (id) {
        case 0:
            gravity = 0;
            color[0] = 0.0;
            color[1] = 0.0;
            color[2] = 0.0;
            break;

        case 1:
            gravity = 10;
            color[0] = 1.0;
            color[1] = 0.65;
            color[2] = 0.0;
            break;

        case 2:
            gravity = 4;
            color[0] = 0.0;
            color[1] = 0.92;
            color[2] = 1.0;
            break;
    }
}

unsigned int Particle::getID() const {
    return id;
}

void Particle::updateParticle() {
    timeAlive++;
    /*
     * If Time Alive exceeds Maximum Life Time
     * -> Set ID to 0 for reset
     */
    if(timeAlive >= lifeTime){
        color[0] = 0.0;
        color[1] = 0.0;
        color[2] = 0.0;
        id = 0;
    }
}

int Particle::getLifeTime() {
    return lifeTime;
}

unsigned int Particle::getTimeAlive() {
    return timeAlive;
}

void Particle::getColor(float *r, float *g, float *b) const {
    *r = color[0];
    *g = color[1];
    *b = color[2];
}

int Particle::getGravity() const{
    return gravity;
}

bool Particle::getStaticPosition() const {
    return staticPosition;
}

void Particle::setStaticPosition(bool value) {
    staticPosition = value;
}

void Particle::setColor(float r, float g, float b) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
}





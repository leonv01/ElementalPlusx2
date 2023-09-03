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
    if(id == 1) {
        gravity = 4;
        color[0] = 1.0;
        color[1] = 0.65;
        color[2] = 0.0;
    }
    else{
        gravity = 0;
        color[0] = 0.0;
        color[1] = 0.0;
        color[2] = 0.0;
    }
    this->id = id;
    lifeTime = -1;
    timeAlive = 0;
}

Particle::Particle(unsigned int id, size_t lifeTime) {
    this->id = id;
    this->lifeTime = lifeTime;
    timeAlive = 0;
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
        id = 0;
    }
}

size_t Particle::getLifeTime() {
    return lifeTime;
}

size_t Particle::getTimeAlive() {
    return timeAlive;
}

void Particle::getColor(float *r, float *g, float *b) const {
    *r = color[0];
    *g = color[1];
    *b = color[2];
}

int Particle::getGravity(){
    return gravity;
}




//
// Created by leon on 9/1/23.
//

#include "../include/Particle.h"

Particle::Particle() {
    this->id = 0;
}
Particle::Particle(unsigned int id) {
    this->id = id;
}

Particle::Particle(unsigned int id, size_t lifeTime) {
    this->id;
    this->lifeTime = lifeTime;
}

unsigned int Particle::getID() const {
    return id;
}

void inline Particle::incrementTimeAlive() {
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


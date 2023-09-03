//
// Created by leon on 9/1/23.
//

#include "../include/Particle.h"

Particle::Particle() {
    this->id = 0;
    lifeTime = -1;
    timeAlive = 0;
}
Particle::Particle(unsigned int id) {
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

void Particle::incrementTimeAlive() {
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


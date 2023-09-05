//
// Created by leon on 9/1/23.
//

#include "../include/Particle.h"

Particle::Particle(unsigned int id, int lifeTime) {
    this->id = id;
    this->lifeTime = lifeTime;
    timeAlive = 0;

    switch(id){
        case 0:
            createEmpty();
            break;
        case 1:
            createSand();
            break;
        case 2:
            createWater();
        default:
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
        id = 0;
    }
}

void Particle::getColor(float *r, float *g, float *b) const {
    *r = color[0];
    *g = color[1];
    *b = color[2];
}

int Particle::getGravity() const{
    return gravity;
}

void Particle::setColor(float r, float g, float b) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

void Particle::createSand() {
    gravity = 10;
    setColor(1.0, 0.65, 0.0);
}

void Particle::createEmpty() {
    setColor(0.0,0.0,0.0);
}

void Particle::createWater() {
    gravity = 10;
    setColor(0.0,0.3, 0.85);

}

void Particle::swap(Particle *other) {
    unsigned int tempX, tempY;
}

void Particle::createWood() {
    gravity = 0;
    setColor(0.3, 0.0,0.0);
}





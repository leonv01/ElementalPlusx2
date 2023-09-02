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

unsigned int Particle::getID() const {
    return id;
}

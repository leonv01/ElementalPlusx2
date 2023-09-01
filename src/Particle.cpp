//
// Created by leon on 9/1/23.
//

#include "../include/Particle.h"

Particle::Particle() {
    this->id = 0;
}
Particle::Particle(uint8_t id) {
    this->id = id;
}

uint8_t Particle::getID() const {
    return id;
}

/* Implementation file of Pellet */
#include "Pellet.hpp"
#include "../aquarium/Aquarium.hpp"

#define PELLET_SPEED 1.0

Pellet::Pellet(Aquarium* a) : Aquatic(0.5, 0.0, a->getCurrTime(), PELLET_SPEED, a) {}

void Pellet::updateState() {
    this->move();
}

void Pellet::move() {
    if (this->isInside()) {
        this->setY(this->getY() - PELLET_SPEED);
    }
}
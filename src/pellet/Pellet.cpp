/* Implementation file of Pellet */
#include "Pellet.hpp"
#include "../aquarium/Aquarium.hpp"

const double PELLET_SPEED 1.0;

Pellet::Pellet(double x, Aquarium* a) : Aquatic(x, 0.0, a->getCurrTime(), PELLET_SPEED, a) {}

void Pellet::updateState() {
    this->move();
}

void Pellet::move() {
    if (this->isInside()) {
        this->setY(this->getY() - PELLET_SPEED);
    }
}
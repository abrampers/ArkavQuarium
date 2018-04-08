/* Implementation file of Pellet */
#include "Pellet.hpp"
#include "../aquarium/Aquarium.hpp"

const double PELLET_SPEED 1.0; //TBD

Pellet::Pellet(double x, Aquarium* a) : Aquatic(x, 0.0, a->getCurrTime(), PELLET_SPEED, a) {}

void Pellet::updateState() {
	double current_time = this->getAquarium()->getCurrTime();
    this->move();
    if (this->getY() == this->getAquarium()->getYMax()) {
    	this->getAquarium()->deletePellet(this);
    }
}

void Pellet::move() {
	double current_time = this->getAquarium()->getCurrTime();
	double dy = this->getMoveSpeed() * ((current_time - this->getLastCurrTime()) / 1000);
    if (this->isInside()) {
		if (this->getY() + dy > this->getAquarium()->getYMax()) {
			this->setY(this->getAquarium()->getYMax());
		}
		else {
			this->setY(this->getY() + dy);
		}
	}
}
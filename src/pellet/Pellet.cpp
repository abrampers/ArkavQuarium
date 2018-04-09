/* Implementation file of Pellet */
#include "pellet/Pellet.hpp"
#include "aquarium/Aquarium.hpp"

Pellet::Pellet(double x, Aquarium* a) : Aquatic(x, 0.0, PELLET_SPEED, a) {}

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
/* Implementation file of Pellet */
#include "pellet/Pellet.hpp"
#include "aquarium/Aquarium.hpp"

Pellet::Pellet(double x, double y, Aquarium* a) : Aquatic(x, y, pelletSpeed, a) {}

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

void Pellet::updateProgress() {}

void Pellet::dead() {}
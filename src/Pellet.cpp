/* Implementation file of Pellet */
#include "Pellet.hpp"
#include "Aquarium.hpp"

Pellet::Pellet(double x, double y, Aquarium* a) : Aquatic(x, y, pelletSpeed, a) {}

void Pellet::updateState() {
	this->updateProgress();
    this->move();
    if (this->getY() >= this->getAquarium()->getYMax()) {
    	this->dead();
    }
}

void Pellet::move() {
	double current_time = this->getAquarium()->getCurrTime();
	double dy = this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));
    if (this->isInside()) {
		if (this->getY() + dy > this->getAquarium()->getYMax()) {
			this->setY(this->getAquarium()->getYMax());
		}
		else {
			this->setY(this->getY() + dy);
		}
	}
}

void Pellet::updateProgress() {
	double current_time = this->getAquarium()->getCurrTime();
	if(current_time - this->getLastProgressTime() > pelletProgressIncrementTime) {
		if(this->getProgress() < progressPeriod - 1) {
			this->setProgress(this->getProgress() + 1);
		} else {
			this->setProgress(0);
		}
		this->setLastProgressTime(current_time);
	}
}

void Pellet::dead() {
	this->getAquarium()->deletePellet(this);
}
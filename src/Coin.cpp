/* Implementation file of Coin */
#include "Coin.hpp"
#include "Aquarium.hpp"

Coin::Coin(double x, double y, int value, Aquarium *aquarium) : Aquatic(x, y, coinMoveSpeed, aquarium), value(value) {
	last_bottom_time = 0;
	this->setState(movingRight);
}

int Coin::getValue() const {
	return value;
}

void Coin::updateState() {
	double current_time = this->getAquarium()->getCurrTime();
	this->updateProgress();
	this->move();
	if (this->getY() == this->getAquarium()->getYMax()) {
		if (current_time - last_bottom_time > coinDeletionInterval) {
			this->dead();
		}
	}
	this->setLastCurrTime(current_time);
}

/* For coin, X is constant, Y always move downwards */
void Coin::move() {
	double current_time = this->getAquarium()->getCurrTime();
	double dy = this->getMoveSpeed() * ((current_time - this->getLastCurrTime())); //Asumsi waktu dalam ms
	if (this->isInside()) {
		if (this->getY() + dy > this->getAquarium()->getYMax()) {
			this->setY(this->getAquarium()->getYMax());
			last_bottom_time = current_time;
		}
		else {
			this->setY(this->getY() + dy);
		}
	}
}

void Coin::updateProgress() {
	double current_time = this->getAquarium()->getCurrTime();
	if(this->getY() == this->getAquarium()->getYMax()) {
		this->setState(State::fading);
		this->setProgress(0);
	}
	if(current_time - this->getLastProgressTime() > pelletProgressIncrementTime) {
		if(this->getProgress() < progressPeriod - 1) {
			this->setProgress(this->getProgress() + 1);
		} else {
			this->setProgress(0);
		}
		this->setLastProgressTime(current_time);
	}
}

void Coin::dead() {
	this->getAquarium()->deleteCoin(this);
}
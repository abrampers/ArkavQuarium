/* Implementation file of Coin */

#include "../coin/Coin.hpp"

const double COIN_MOVE_SPEED = 10; //TBD
const double COIN_DELETION_INTERVAL = 10; //TBD

Coin::Coin(double x, double y, Aquarium *aquarium) : Aquatic(x, y, 0, COIN_MOVE_SPEED, aquarium) {
	last_bottom_time = 0;
	value = 0;
}

Coin::Coin(double x, double y, int value, double created_time, Aquarium* aquarium) : Aquatic(x, y, created_time, COIN_MOVE_SPEED, aquarium) {
	last_bottom_time = 0;
	this->value = value;
}

void Coin::updateState(double current_time) {
	move(current_time);
	this->setLastCurrTime(current_time);
	if (this->getY() == this->getAquarium()->getYMax()) {
		if (current_time - last_bottom_time > COIN_DELETION_INTERVAL) {
			this->getAquarium()->deleteCoin(this);
		}
	}
}

/* For coin, X is constant, Y always move downwards */
void Coin::move(double current_time) {
	double dy = this->getMoveSpeed() * ((current_time - this->getLastCurrTime()) / 1000); //Asumsi waktu dalam ms
	if (this->getY() < this->getAquarium()->getYMax()) {
		if (this->getY() + dy > this->getAquarium()->getYMax()) {
			this->setY(this->getAquarium()->getYMax());
			last_bottom_time = current_time;
		}
		else {
			this->setY(this->getY() + dy);
		}
	}
}
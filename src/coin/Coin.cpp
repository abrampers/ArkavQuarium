/* Implementation file of Coin */

#include "../coin/Coin.hpp"

const double COIN_MOVE_SPEED = 0; //TBD

Coin::Coin(double x, double y, Aquarium *aquarium) : Aquatic(x, y, 0, COIN_MOVE_SPEED, aquarium) {
	value = 0;
}

Coin::Coin(double x, double y, int value, double created_time, Aquarium* aquarium) : Aquatic(x, y, created_time, COIN_MOVE_SPEED, aquarium) {
	this->value = value;
}

void Coin::updateState(double current_time) {
	move(current_time);
	this->setLastCurrTime(current_time);
}

/* For coin, X is constant, Y always move downwards */
void Coin::move(double current_time) {
	double dy = this->getMoveSpeed() * ((current_time - this->getLastCurrTime()) / 1000); //Asumsi waktu dalam ms
	this->setY(this->getY() + dy);
}
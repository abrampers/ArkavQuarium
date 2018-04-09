/* Implementation file of Snail */
#include "snail/Snail.hpp"
#include "aquarium/Aquarium.hpp"

Snail::Snail(Aquarium* a) : Aquatic(fRand(0.0, a->getXMax()), a->getYMax(), SNAIL_SPEED, a), coin_radius(SNAIL_RADIUS) {
	nearest_coin = NULL;
	hold_coin_value = 0;
	x_dir = 0;
}

double Snail::getDistance(Aquatic* a, Aquatic* b) {
	return sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b->getY(), 2));
}

bool Snail::isCoinOnTop() {
	return (this->getX() - nearest_coin->getX() < SNAIL_RADIUS * 0.5);
}

void Snail::pickCoin(Coin* c) {
	hold_coin_value = c->getValue();
	this->getAquarium()->getCoinList().remove(c);
}

void Snail::findNearestCoin() {
	// Find nearest coin to pursue
	LinkedList<Coin*>& coin_list = this->getAquarium()->getCoinList();
	Coin* current_nearest_coin = NULL;
	for (int i = 0; i < coin_list.getLength(); i++) {
		Coin *current_coin = coin_list.get(i);
		if(current_nearest_coin == NULL) {
			current_nearest_coin = current_coin;
		} else if ((getDistance(current_coin, this)) > getDistance(current_nearest_coin, this)) {
			current_nearest_coin = current_coin;
		}
	}
	this->nearest_coin = current_nearest_coin;
}

bool Snail::nearestCoinInRange() {
	if (nearest_coin != NULL) {
		if (getDistance(this, nearest_coin) < SNAIL_RADIUS) {
			return true;
		}
	}
	return false;
}

Direction Snail::getDirection() { 
	return x_dir >= 0 ? Direction::right : Direction::left;
}

void Snail::updateState() {
	double current_time = this->getAquarium()->getCurrTime();
	findNearestCoin();
	if (nearestCoinInRange()) {
		pickCoin(nearest_coin); 
	} else {
		move();
	}
	this->setLastCurrTime(current_time);
}

void Snail::move() {
	double current_time = this->getAquarium()->getCurrTime();
	if (nearest_coin != NULL) {
		if(!isCoinOnTop()) {
			double dx = this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));
			if (nearest_coin->getX() > this->getX()) {
				x_dir = 1;
				this->setX(this->getX() + dx);
			} else {
				x_dir = -1;
				this->setX(this->getX() - dx);
			}
		}
	}
}


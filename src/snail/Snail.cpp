/* Implementation file of Snail */
#include "Snail.hpp"
#include "../linkedlist/LinkedList.hpp"
#include "../aquarium/Aquarium.hpp"
#include <math.h>

const double SNAIL_SPEED = 80;
const double SNAIL_RADIUS = 1.0;

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

	cout << coin_list. getLength() << endl;
	// coin_list.print();

	for (int i = 0; i < coin_list.getLength(); i++) {
		cout << "masuk" << endl;
		Coin *current_coin = coin_list.get(i);
		cout << "masuk sadfasdf" << endl;
		if(current_nearest_coin == NULL) {
			current_nearest_coin = current_coin;
		} else if ((getDistance(current_coin, this)) > getDistance(current_nearest_coin, this)) {
			current_nearest_coin = current_coin;
		}
		cout << "masuk sadfasdf kakama" << endl;
	}

	cout << "hhh" << endl;

	this->nearest_coin = current_nearest_coin;

	cout << "iii" << endl;
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


/* Implementation file of Snail */
#include "Snail.hpp"
#include "../linkedlist/LinkedList.hpp"
#include "../aquarium/Aquarium.hpp"
#include <math.h>

const double SNAIL_SPEED = 1.0;
const double SNAIL_RADIUS = 1.0;

double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

Snail::Snail(Aquarium* a) : Aquatic(fRand(0.0, a->getXMax()), a->getYMax(), SNAIL_SPEED, a), coin_radius(SNAIL_RADIUS) {
	nearest_coin = NULL;
	hold_coin_value = 0;
	x_dir = 0;
}

double Snail::getDistance(Aquatic* a, Aquatic* b) {
	return sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b->getY(), 2));
}

void Snail::pickCoin(Coin* c) {
	hold_coin_value = c->getValue();
	this->getAquarium()->getCoinList().remove(c);
}

void Snail::findNearestCoin() {
	// Find nearest coin to pursue
	LinkedList<Coin*> ll = this->getAquarium()->getCoinList();
	Coin* current_nearest_coin = NULL;
	Node<Coin*>* curr_node = ll.getHead();
	while(curr_node != NULL) {
	  curr_node = curr_node->getNext();
	  Coin* current_coin = curr_node->getValue();
	  if(current_nearest_coin == NULL) {
	  	current_nearest_coin = current_coin;
	  } 
	  else if ((getDistance(current_coin, this)) > getDistance(current_nearest_coin, this)) {
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

void Snail::updateState() {
	double current_time = this->getAquarium()->getCurrTime();
	findNearestCoin();
	if (nearestCoinInRange()) {
		pickCoin(nearest_coin); 
	}
	else {
		move();
	}
	this->setLastCurrTime(current_time);
}

void Snail::move() {
	double current_time = this->getAquarium()->getCurrTime();
	if (nearest_coin != NULL) {
		double dx = this->getMoveSpeed() * ((current_time - this->getLastCurrTime()) / 1000);
		if (nearest_coin->getX() > this->getX()) {
			x_dir = 1;
			this->setX(this->getX() + dx);
		} 
		else {
			this->setX(this->getX() - dx);
		}
	}
}


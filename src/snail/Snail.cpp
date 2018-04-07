/* Implementation file of Snail */
#include "Snail.hpp"
#include "../linkedlist/LinkedList.hpp"
#include "../aquarium/Aquarium.hpp"
#include <math.h>

#define SNAIL_SPEED 1.0
#define SNAIL_RADIUS 1.0

Snail::Snail(Aquarium* a) : Aquatic(0.5, a->getYMax(), a->getCurrTime(), SNAIL_SPEED, a), coin_radius(SNAIL_RADIUS) {}

double Snail::getDistance(Aquatic* a, Aquatic* b) {
	return sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b->getY(), 2));
}


void Snail::updateState() {
	// Find nearest coin to pursue
	LinkedList<Coin*> ll = this->getAquarium()->getCoinList();
	Coin* current_nearest_coin = NULL;
	Node<Coin*>* curr_node = ll.getHead();
	while(curr_node->getNext() != NULL) {
	  curr_node = curr_node->getNext();
	  Coin* current_coin = curr_node->getValue();
	  if(current_nearest_coin == NULL) {
	  	current_nearest_coin = current_coin;
	  } else if((getDistance(current_coin, this)) > getDistance(current_nearest_coin, this)) {
	  	current_nearest_coin = current_coin;
	  }
	}
	// If the coin is in range, pick the coin
	if (getDistance(this, current_nearest_coin) < SNAIL_RADIUS) pickCoin(current_nearest_coin); else {
		// Else, move to that coin
		if (current_nearest_coin->getX() > this->getX()){
			this->move(this->getMoveSpeed());
		} else {
			this->move(-1 * this->getMoveSpeed());
		}
	}
}

void Snail::move(double dx) {
	this->setX(this->getX() + dx);
}

void Snail::pickCoin(Coin* c) {
	this->getAquarium()->getCoinList().remove(c);
}


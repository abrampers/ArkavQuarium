/* Implementation file of Aquarium */

#include "../aquarium/Aquarium.hpp"

const double XMAX = 0; //TBD
const double YMAX = 0; //TBD

Aquarium::Aquarium() : xMax(XMAX), yMax(YMAX), content_piranha(), content_guppy(), content_snail(), content_pellet(), content_coin() {
	curr_time = 0;
}

double Aquarium::getXMax() const {
	return xMax;
}

double Aquarium::getYMax() const {
	return yMax;
}

LinkedList<Piranha*>& Aquarium::getPiranhaList() {
	return content_piranha;
}

LinkedList<Guppy*>& Aquarium::getGuppyList() {
	return content_guppy;
}

LinkedList<Snail*>& Aquarium::getSnailList() {
	return content_snail;
}

LinkedList<Pellet*>& Aquarium::getPelletList() {
	return content_pellet;
}

LinkedList<Coin*>& Aquarium::getCoinList() {
	return content_coin;
}

void Aquarium::setCurrTime(double t) {
	this->curr_time = t;
}

void Aquarium::updateState() {
	Aquatic* pointer;
	/* Piranha */
	pointer = content_piranha.getHead()->getNext();
	while (pointer != NULL) {
		pointer->updateState(curr_time);
		pointer = pointer->getNext();
	}
	/*Guppy*/
	pointer = content_guppy.getHead()->getNext();
	while (pointer != NULL) {
		pointer->updateState(curr_time);
		pointer = pointer->getNext();
	}
	/*Snail*/
	pointer = content_snail.getHead()->getNext();
	while (pointer != NULL) {
		pointer->updateState(curr_time);
		pointer = pointer->getNext();
	}
	/*Pellet*/
	pointer = content_pellet.getHead()->getNext();
	while (pointer != NULL) {
		pointer->updateState(curr_time);
		pointer = pointer->getNext();
	}
	/*Coin*/
	pointer = content_coin.getHead()->getNext();
	while (pointer != NULL) {
		pointer->updateState(curr_time);
		pointer = pointer->getNext();
	}
}

void Aquarium::createPiranha() {
	content_piranha.add(new Piranha( /* TBD */ ));
}

void Aquarium::createGuppy() {
	content_guppy.add(new Guppy(curr_time, this));
}

void Aquarium::createSnail() {
	content_snail.add(new Snail( /* TBD */ ));
}

void Aquarium::createPellet() {
	content_pellet.add(new Pellet( /* TBD */ ));
}

void Aquarium::createCoin(double x, double y, int value) {
	content_coin.add(new Coin(x, y, value, curr_time, this));
}

void Aquarium::deletePiranha(Piranha* p) {
	content_piranha.remove(*p);
}

void Aquarium::deleteGuppy(Guppy* g) {
	content_guppy.remove(*g);
}

void Aquarium::deleteSnail(Snail* s) {
	content_snail.remove(*s);
}

void Aquarium::deletePellet(Pellet* p) {
	content_pellet.remove(*p);
}

void Aquarium::deleteCoin(Coin* c) {
	content_coin.remove(*c);
}
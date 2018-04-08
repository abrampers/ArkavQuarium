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

double Aquarium::getCurrTime() {return this->curr_time;}

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

void Aquarium::updateState(double current_time) {
	this->curr_time = current_time;
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
	Piranha* new_elmt = new Piranha (/* TBD */);
	content_piranha.add(new_elmt);
}

void Aquarium::createGuppy() {
	Guppy* new_elmt = new Guppy(curr_time, this)
	content_guppy.add(new_elmt);
}

void Aquarium::createSnail() {
	Snail* new_elmt = new Snail(this);
	content_snail.add(new_elmt);
}

void Aquarium::createPellet(double x) {
	Pellet* new_elmt = new Pellet(x, this);
	content_pellet.add(new_elmt);
}

void Aquarium::createCoin(double x, double y, int value) {
	content_coin.add(new Coin(x, y, value, curr_time, this));
}

void Aquarium::deletePiranha(Piranha* p) {
	content_piranha.remove(p);
}

void Aquarium::deleteGuppy(Guppy* g) {
	content_guppy.remove(g);
}

void Aquarium::deleteSnail(Snail* s) {
	content_snail.remove(s);
}

void Aquarium::deletePellet(Pellet* p) {
	content_pellet.remove(p);
}

void Aquarium::deleteCoin(Coin* c) {
	content_coin.remove(c);
}
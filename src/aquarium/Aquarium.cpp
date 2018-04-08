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
	Node<Piranha*>* pointer_piranha;
	/* Piranha */
	pointer_piranha = content_piranha.getHead();
	while (pointer_piranha != NULL) {
		pointer_piranha->getValue()->updateState(curr_time);
		pointer_piranha = pointer_piranha->getNext();
	}
	/* Guppy */
	Node<Guppy*>* pointer_guppy;
	pointer_guppy = content_guppy.getHead();
	while (pointer_guppy != NULL) {
		pointer_guppy->getValue()->updateState(curr_time);
		pointer_guppy = pointer_guppy->getNext();
	}
	/* Snail */
	Node<Snail*>* pointer_snail;
	pointer_snail = content_snail.getHead();
	while (pointer_snail != NULL) {
		pointer_snail->getValue()->updateState(curr_time);
		pointer_snail = pointer_snail->getNext();
	}
	/* Pellet */
	Node<Pellet*>* pointer_pellet;
	pointer_pellet = content_pellet.getHead();
	while (pointer_pellet != NULL) {
		pointer_pellet->getValue()->updateState(curr_time);
		pointer_pellet = pointer_pellet->getNext();
	}
	/*Coin*/
	Node<Coin*>* pointer_coin;
	pointer_coin = content_coin.getHead();
	while (pointer_coin != NULL) {
		pointer_coin->getValue()->updateState(curr_time);
		pointer_coin = pointer_coin->getNext();
	}
}

void Aquarium::createPiranha() {
	Piranha* new_elmt = new Piranha (/* TBD */);
	content_piranha.add(new_elmt);
}

void Aquarium::createGuppy() {
	Guppy* new_elmt = new Guppy(curr_time, this);
	content_guppy.add(new_elmt);
}

void Aquarium::createSnail() {
	Snail* new_elmt = new Snail( /* TBD */ );
	content_snail.add(new_elmt);
}

void Aquarium::createPellet() {
	Pellet* new_elmt = new Pellet( /* TBD */ );
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
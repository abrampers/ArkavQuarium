/* Implementation file of Aquarium */

#include "Aquarium.hpp"

Aquarium::Aquarium(double xMin, double yMin, double xMax, double yMax)
    : xMin(xMin), yMin(yMin), xMax(xMax), yMax(yMax) {
  curr_time = 0;
  // this->createPiranha();
  this->createGuppy();
  this->createSnail();
}

Aquarium::~Aquarium(){};

double Aquarium::getXMax() const { return xMax; }

double Aquarium::getYMax() const { return yMax; }

double Aquarium::getXMin() const { return xMin; }

double Aquarium::getYMin() const { return yMin; }

double Aquarium::getCurrTime() { return this->curr_time; }

LinkedList<Piranha*>& Aquarium::getPiranhaList() { return content_piranha; }

LinkedList<Guppy*>& Aquarium::getGuppyList() { return content_guppy; }

LinkedList<Snail*>& Aquarium::getSnailList() { return content_snail; }

LinkedList<Pellet*>& Aquarium::getPelletList() { return content_pellet; }

LinkedList<Coin*>& Aquarium::getCoinList() { return content_coin; }

void Aquarium::setCurrTime(double t) { this->curr_time = t; }

void Aquarium::updateState(double current_time) {
  this->curr_time = current_time;
  Node<Piranha*>* pointer_piranha;
  /* Piranha */
  pointer_piranha = content_piranha.getHead();
  while (pointer_piranha != nullptr) {
    pointer_piranha->getValue()->updateState();
    pointer_piranha = pointer_piranha->getNext();
  }
  /* Guppy */
  Node<Guppy*>* pointer_guppy;
  pointer_guppy = content_guppy.getHead();
  while (pointer_guppy != nullptr) {
    pointer_guppy->getValue()->updateState();
    pointer_guppy = pointer_guppy->getNext();
  }
  /* Snail */
  Node<Snail*>* pointer_snail;
  pointer_snail = content_snail.getHead();
  while (pointer_snail != nullptr) {
    pointer_snail->getValue()->updateState();
    pointer_snail = pointer_snail->getNext();
  }
  /* Pellet */
  Node<Pellet*>* pointer_pellet;
  pointer_pellet = content_pellet.getHead();
  while (pointer_pellet != nullptr) {
    pointer_pellet->getValue()->updateState();
    pointer_pellet = pointer_pellet->getNext();
  }
  /*Coin*/
  Node<Coin*>* pointer_coin;
  pointer_coin = content_coin.getHead();
  while (pointer_coin != nullptr) {
    pointer_coin->getValue()->updateState();
    pointer_coin = pointer_coin->getNext();
  }
}

void Aquarium::createPiranha() {
  Piranha* new_elmt = new Piranha(this);
  content_piranha.add(new_elmt);
}

void Aquarium::createGuppy() {
  Guppy* new_elmt = new Guppy(this);
  content_guppy.add(new_elmt);
}

void Aquarium::createSnail() {
  Snail* new_elmt = new Snail(this);
  content_snail.add(new_elmt);
}

void Aquarium::createPellet(double x, double y) {
  Pellet* new_elmt = new Pellet(x, y, this);
  content_pellet.add(new_elmt);
}

void Aquarium::createCoin(double x, double y, int value) {
  Coin* new_elmt = new Coin(x, y, value, this);
  content_coin.add(new_elmt);
}

void Aquarium::deletePiranha(Piranha* p) { content_piranha.remove(p); }

void Aquarium::deleteGuppy(Guppy* g) { content_guppy.remove(g); }

void Aquarium::deleteSnail(Snail* s) { content_snail.remove(s); }

void Aquarium::deletePellet(Pellet* p) { content_pellet.remove(p); }

void Aquarium::deleteCoin(Coin* c) { content_coin.remove(c); }
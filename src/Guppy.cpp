/* Implementation file of Guppy */
#include "include/Guppy.hpp"
#include "include/Aquarium.hpp"

const int GUPPY_FOOD_THRES = 20;
const double GUPPY_EAT_RADIUS = 1.25;
const double GUPPY_FULL_INTERVAL = 5; /* Ini detik ye bos */
const double GUPPY_HUNGER_TIMEOUT = 10;

static const Guppy::coin_creation_interval = 8; /* Ini juga detik ye bos */

Guppy::Guppy() : Fish(GUPPY_FOOD_THRES, GUPPY_EAT_RADIUS, GUPPY_FULL_INTERVAL, GUPPY_HUNGER_TIMEOUT) {
	last_eat_time = 0;
	last_random_time = 0;
	nearest_pellet = NULL;
}

Guppy::Guppy(double last_eat_time, double last_random_time) : Fish(GUPPY_FOOD_THRES, GUPPY_EAT_RADIUS, GUPPY_FULL_INTERVAL, GUPPY_HUNGER_TIMEOUT) {
	this->last_eat_time = last_eat_time;
	this->last_random_time = last_random_time;
	nearest_pellet = NULL;
}

double Guppy::distanceToPellet(Pellet *p) {
	double guppy_x_position = this->getX();
	double guppy_y_position = this->getY();
	double pellet_x_position = p->getX();
	double pellet_y_position = p->getX();

	return sqrt((guppy_x_position - pellet_x_position) * (guppy_x_position - pellet_x_position) + (guppy_y_position - pellet_y_position) * (guppy_y_position - pellet_y_position));
}

void Guppy::findNearestPellet() {
	LinkedList<Pellet*> ll = this->getAquarium()->getPelletList();
	Pellet* current_nearest_pellet = NULL;
	Node<T>* curr_node = ll.head;
	while(curr_node->getNext() != NULL) {
	    curr_node = curr_node->getNext();
	    Pellet* current_pellet = curr_node->getValue();
	    if(current_nearest_pellet == NULL) {
	    	current_nearest_pellet = current_pellet;
	    } else if(distanceToPellet(current_pellet) > distanceToPellet(current_nearest_pellet)) {
	    	current_nearest_pellet = current_pellet;
	    }
	}
	this->nearest_pellet =  current_nearest_pellet;
}

bool Guppy::nearestPelletInRange() {
	if(nearest_pellet == NULL) {
		return false;
	} else if(distanceToPellet(nearest_pellet) < this->eat_radius) {
		return true;
	} else {
		return false;
	}
}

void Guppy::updateState(double current_time) {
	this->findNearestPellet();
	eat();
	this->findNearestPellet();
	move(current_time);
}

void Guppy::move(double current_time) {
	double x_direction = nearest_pellet->getX() - this->getX();
	double y_direction = nearest_pellet->getY() - this->getY();
	double distance = distanceToPellet(nearest_pellet);

	double dx = (x_direction / distance) * this->move_speed * ((current_time - this->curr_time) / 1000); /* Gue masih asumsikan kalo current time dalem ms */
	double dy = (y_direction / distance) * this->move_speed * ((current_time - this->curr_time) / 1000); /* Kabari kalo misalkan dalam fps atau satuan lain */

	this->setX(this->getX() + dx);
	this->setY(this->getY() + dy);
}

void Guppy::eat() {
	if(nearestPelletInRange()) {
		LinkedList<Pellet*> ll = this->getAquarium()->getPelletList();
		ll.remove(nearest_pellet);
		nearest_pellet = NULL;
	}
}

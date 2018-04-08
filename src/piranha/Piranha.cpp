/* Implementation file of Piranha */
#include "../piranha/Piranha.hpp"
#include "../aquarium/Aquarium.hpp"

const int piranhaFoodThres = 10;
const double piranhaEatRadius = 1.5;
const double piranhaFullInterval = 10; /* Ini detik ye bos */
const double piranhaHungerInterval = 15;
const double piranhaMoveSpeed = 250000;
const double randomMoveInterval = 4; /* Ini juga detik ya brok */
const double pi = 3.14159265;
const double piranhaCoinInterval = 8;
const int guppyPrice = 100;

Piranha::Piranha(Aquarium *aquarium): 
Aquatic(floor(fRand(0, aquarium->getXMax())), 
	floor(fRand(0, aquarium->getYMax())), 
	piranhaMoveSpeed, 
	aquarium),
Fish(piranhaFoodThres, 
	piranhaEatRadius, 
	piranhaFullInterval, 
	piranhaHungerInterval, 
	aquarium->getCurrTime()) {
	
	nearest_pellet = NULL;
	double rad = fRand(0, 360) * pi / 180;
	this->x_dir = cos(rad);
	this->y_dir = sin(rad);
}

double Piranha::distanceToGuppy(Guppy *g) {
	double piranha_x_position = this->getX();
	double piranha_y_position = this->getY();
	double guppy_x_position = g->getX();
	double guppy_y_position = g->getX();

	return sqrt((piranha_x_position - guppy_x_position) * (piranha_x_position - guppy_x_position) + (guppy_y_position - pellet_y_position) * (guppy_y_position - pellet_y_position));
}

void Piranha::findNearestGuppy() {
	LinkedList<Guppy*> ll = this->getAquarium()->getGuppyList();
	Guppy* current_nearest_guppy = NULL;
	Node<Guppy*>* curr_node = ll.getHead();
	while(curr_node != NULL) {
	    curr_node = curr_node->getNext();
	    Guppy* current_pellet = curr_node->getValue();
	    if(current_nearest_guppy == NULL) {
	    	current_nearest_guppy = current_guppy;
	    } else if(distanceToGuppy(current_guppy) > distanceToGuppy(current_nearest_guppy)) {
	    	current_nearest_guppy = current_guppy;
	    }
	}
	this->nearest_guppy =  current_nearest_guppy;
}

bool Piranha::nearestGuppyInRange() {
	if(nearest_guppy == NULL) {
		return false;
	} else if(distanceToGuppy(nearest_guppy) < this->eatRadius) {
		return true;
	} else {
		return false;
	}
}

/* Change hunger status */
void Piranha::updateState() {
	double current_time = this->getAquarium()->getCurrTime();
	if(current_time - this->getLastCurrTime() > this->hungerTimeout) {
		/* Dead guppy */
		this->getAquarium()->getPiranhaList().remove(this);
	} else {
		this->findNearestGuppy();
		eat();
		this->findNearestGuppy();
		move();
		this->setLastCurrTime(current_time);
	}
}

void Piranha::move() {
	/* Tunggu move guppy */
}

/* TODO: Implement naik level */
void Piranha::eat() {
	double current_time = this->getAquarium()->getCurrTime();
	if(!this->getHungry() && (current_time - this->getLastEatTime() > this->fullInterval)) {
		/* Change guppy hunger state */
		this->setHungry(true);
	}

	if(this->getHungry() && nearestGuppyInRange()) {
		this->dropCoin();
		this->getAquarium()->deleteGuppy(nearest_guppy);
		nearest_guppy = NULL;
		this->setHungry(false);
		this->setLastEatTime(current_time);
	} 
}

void Piranha::dropCoin() {
	this->getAquarium()->createCoin(this->getX(), this->getY(), 100 * (nearest_guppy->getLevel() + 1));
}
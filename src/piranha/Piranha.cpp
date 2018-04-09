/* Implementation file of Piranha */
#include "piranha/Piranha.hpp"
#include "aquarium/Aquarium.hpp"

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
	
	nearest_guppy = NULL;
	double rad = fRand(0, 360) * pi / 180;
	this->x_dir = cos(rad);
	this->y_dir = sin(rad);
}

double Piranha::distanceToGuppy(Guppy *g) {
	double piranha_x_position = this->getX();
	double piranha_y_position = this->getY();
	double guppy_x_position = g->getX();
	double guppy_y_position = g->getX();

	return sqrt((piranha_x_position - guppy_x_position) * (piranha_x_position - guppy_x_position) + (piranha_y_position - guppy_y_position) * (piranha_y_position - guppy_y_position));
}

void Piranha::findNearestGuppy() {
	LinkedList<Guppy*> ll = this->getAquarium()->getGuppyList();
	Guppy* current_nearest_guppy = NULL;
	Node<Guppy*>* curr_node = ll.getHead();
	while(curr_node != NULL) {
	    curr_node = curr_node->getNext();
	    Guppy* current_guppy = curr_node->getValue();
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
	if(this->getHungry() && current_time - this->getLastHungerTime() > this->hungerTimeout) {
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
	double current_time = this->getAquarium()->getCurrTime();
	if(nearest_guppy != NULL && this->getHungry()) {
		double x_direction = nearest_guppy->getX() - this->getX();
		double y_direction = nearest_guppy->getY() - this->getY();
		double distance = distanceToGuppy(nearest_guppy);

		/* Check if this need to change */
		double dx = (x_direction / distance) * this->getMoveSpeed() * ((current_time - this->getLastCurrTime()) / 1000); /* Gue masih asumsikan kalo current time dalem ms */
		double dy = (y_direction / distance) * this->getMoveSpeed() * ((current_time - this->getLastCurrTime()) / 1000); /* Kabari kalo misalkan dalam fps atau satuan lain */

		this->setX(this->getX() + dx);
		this->setY(this->getY() + dy);
		this->x_dir = x_direction;
	} else {
		/* Randomize move direction after some interval */
		if(current_time - this->getLastRandomTime() > randomMoveInterval) {
			this->setLastRandomTime(current_time);
			double rad = fRand(0.0, 2.0 * pi);

			this->x_dir = cos(rad);
			this->y_dir = sin(rad);
		}


		/* Continue movement */
		double dx = this->x_dir * this->getMoveSpeed() * (current_time - this->getLastCurrTime());
		double dy = this->y_dir * this->getMoveSpeed() * (current_time - this->getLastCurrTime());


		if (getX() + dx >= getAquarium()->getXMax() && x_dir > 0.0) {
			this->x_dir *= -1.0;
		} else if (getX() + dx <= 0.0 && x_dir < 0.0) {
			this->x_dir *= -1.0;
		} else {
			this->setX(this->getX() + dx);
		}


		if (getY() + dx >= getAquarium()->getYMax() && y_dir > 0.0) {
			this->y_dir *= -1.0;
		} else if (getY() + dy <= 0.0 && y_dir < 0.0) {
			this->y_dir *= -1.0;
		} else {
			this->setY(this->getY() + dy);
		}

		/* DEBUG */
		// cout << "x_dir: " << x_dir << endl;
		// cout << "y_dir: " << y_dir << endl;
		// cout << "mag: " << x_dir * x_dir + y_dir * y_dir << endl << endl;

	}
}

/* TODO: Implement naik level */
void Piranha::eat() {
	double current_time = this->getAquarium()->getCurrTime();
	if(!this->getHungry() && (current_time - this->getLastEatTime() > this->fullInterval)) {
		/* Change guppy hunger state */
		this->setHungry(true);
		this->setLastHungerTime(current_time);
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
/* Implementation file of Guppy */
#include "guppy/Guppy.hpp"
#include "aquarium/Aquarium.hpp"

Guppy::Guppy(Aquarium *aquarium): 
Aquatic(floor(fRand(0, aquarium->getXMax())), 
	floor(fRand(0, aquarium->getYMax())), 
	guppyMoveSpeed, 
	aquarium),
Fish(guppyFoodThres, 
	guppyEatRadius, 
	guppyFullInterval, 
	guppyHungerInterval, 
	aquarium->getCurrTime()) {
	
	nearest_pellet = NULL;
	last_drop_coin = aquarium->getCurrTime();
	/* Initialize random movement */
	double rad = fRand(0.0, 2.0 * pi);
	this->x_dir = cos(rad);
	this->y_dir = sin(rad);
}

double Guppy::distanceToPellet(Pellet *p) {
	double guppy_x_position = this->getX();
	double guppy_y_position = this->getY();
	double pellet_x_position = p->getX();
	double pellet_y_position = p->getX();

	return sqrt((guppy_x_position - pellet_x_position) * (guppy_x_position - pellet_x_position) + (guppy_y_position - pellet_y_position) * (guppy_y_position - pellet_y_position));
}

void Guppy::findNearestPellet() {
	LinkedList<Pellet*>& ll = this->getAquarium()->getPelletList();
	Pellet* current_nearest_pellet = NULL;
	Node<Pellet*>* curr_node = ll.getHead();
	while(curr_node != NULL) {
	    Pellet* current_pellet = curr_node->getValue();
	    if(current_nearest_pellet == NULL) {
	    	current_nearest_pellet = current_pellet;
	    } else if(distanceToPellet(current_pellet) > distanceToPellet(current_nearest_pellet)) {
	    	current_nearest_pellet = current_pellet;
	    }
	    curr_node = curr_node->getNext();
	}
	this->nearest_pellet =  current_nearest_pellet;
}

bool Guppy::nearestPelletInRange() {
	if(nearest_pellet == NULL) {
		return false;
	} else if(distanceToPellet(nearest_pellet) < this->eatRadius) {
		return true;
	} else {
		return false;
	}
}

/* Change hunger status */
void Guppy::updateState() {
	double current_time = this->getAquarium()->getCurrTime();
	if(this->getHungry() && current_time - this->getLastHungerTime() > this->hungerTimeout) {
		/* Dead guppy */
		this->getAquarium()->getGuppyList().remove(this);
	} else {
		this->dropCoin();
		this->findNearestPellet();
		this->eat();
		this->findNearestPellet();
		this->move();
		this->setLastCurrTime(current_time);
	}
}

void Guppy::move() {
	double current_time = this->getAquarium()->getCurrTime();
	if(nearest_pellet != NULL && this->getHungry()) {
		double x_direction = nearest_pellet->getX() - this->getX();
		double y_direction = nearest_pellet->getY() - this->getY();
		double distance = distanceToPellet(nearest_pellet);

		/* Check if this need to change */
		double dx = (x_direction / distance) * this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));
		double dy = (y_direction / distance) * this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));

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
	}
}

void Guppy::eat() {
	double current_time = this->getAquarium()->getCurrTime();
	if(!this->getHungry() && (current_time - this->getLastEatTime() > this->fullInterval)) {
		/* Change guppy hunger state */
		this->setHungry(true);
		this->setLastHungerTime(current_time);
	}

	if(this->getHungry() && nearestPelletInRange()) {
		this->getAquarium()->deletePellet(nearest_pellet);
		nearest_pellet = NULL;
		this->setHungry(false);
		this->setLastEatTime(current_time);
		this->setFoodEaten(this->getFoodEaten() + 1);

		if(this->getLevel() < maxLevel && this->getFoodEaten() > this->foodThres) {
			this->setLevel(this->getLevel() + 1);
			this->setFoodEaten(0);
		}
	} 
}

void Guppy::dropCoin() {
	double current_time = this->getAquarium()->getCurrTime();
	if(current_time - this->last_drop_coin > guppyCoinInterval) {
		this->getAquarium()->createCoin(this->getX(), this->getY(), this->getLevel() * guppyCoinMultiplier);
		this->last_drop_coin = current_time;
	}
}

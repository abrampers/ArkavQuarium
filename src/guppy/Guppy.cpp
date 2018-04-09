/* Implementation file of Guppy */
#include "guppy/Guppy.hpp"
#include "aquarium/Aquarium.hpp"

Guppy::Guppy(Aquarium *aquarium): 
Aquatic(floor(fRand(aquarium->getXMin(), aquarium->getXMax())), 
	floor(fRand(aquarium->getYMin(), aquarium->getYMax())), 
	guppyMoveSpeed, 
	aquarium),
Fish(guppyFoodThres, 
	guppyEatRadius, 
	guppyFullInterval, 
	guppyHungerInterval, 
	aquarium->getCurrTime()) {
	
	this->nearest_pellet = NULL;
	this->last_drop_coin = aquarium->getCurrTime();
	/* Initialize random movement */
	double rad = fRand(0.0, 2.0 * pi);
	this->x_dir = cos(rad);
	this->y_dir = sin(rad);
	/* Initialize Aquatic state */
	State state = this->x_dir >= 0 ? movingRight : movingLeft;
	this->setState(state);
}

double Guppy::distanceToPellet(Pellet *p) {
	double guppy_x_position = this->getX();
	double guppy_y_position = this->getY();
	double pellet_x_position = p->getX();
	double pellet_y_position = p->getY();

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
	    } else if(distanceToPellet(current_pellet) < distanceToPellet(current_nearest_pellet)) {
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
	if(this->getState() == State::deadLeft || this->getState() == State::deadRight || (this->getHungry() && current_time - this->getLastHungerTime() > this->hungerTimeout)) {
		/* Dead guppy */
		this->dead();
	} else {
		this->updateProgress();
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
	if(this->getState() != turningRight && this->getState() != turningLeft) {
		if(nearest_pellet != NULL && this->getHungry()) {
			double x_direction = nearest_pellet->getX() - this->getX();
			double y_direction = nearest_pellet->getY() - this->getY();
			double distance = distanceToPellet(nearest_pellet);

			/* Check if this need to change */
			double dx = (x_direction / distance) * this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));
			double dy = (y_direction / distance) * this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));

			this->setX(this->getX() + dx);
			this->setY(this->getY() + dy);
			this->x_dir = x_direction / distance;
			this->y_dir = y_direction / distance;
		} else {
			/* Randomize move direction after some interval */
			if(current_time - this->getLastRandomTime() > randomMoveInterval) {
				this->setLastRandomTime(current_time);
				double rad = fRand(0.1, 1.9 * pi);

				double x_direction = cos(rad);
				if(x_direction >= 0 && this->x_dir < getAquarium()->getXMin()) {
					this->setState(turningRight);
					this->setLastProgressTime(current_time);
					this->setProgress(0);
				}

				if(x_direction < 0 && this->x_dir >= getAquarium()->getXMin()) {
					this->setState(turningLeft);
					this->setLastProgressTime(current_time);
					this->setProgress(0);
				}

				this->x_dir = x_direction;
				this->y_dir = sin(rad);
			}


			/* Continue movement */
			double dx = this->x_dir * this->getMoveSpeed() * (current_time - this->getLastCurrTime());
			double dy = this->y_dir * this->getMoveSpeed() * (current_time - this->getLastCurrTime());


			if (getX() + dx >= getAquarium()->getXMax() && this->x_dir > 0.0) {
				this->x_dir *= -1.0;
				this->setState(turningLeft);
				this->setLastProgressTime(current_time);
				this->setProgress(0);
			} else if (getX() + dx <= getAquarium()->getXMin() && this->x_dir < 0.0) {
				this->x_dir *= -1.0;
				this->setState(turningRight);
				this->setLastProgressTime(current_time);
				this->setProgress(0);
			} else {
				this->setX(this->getX() + dx);
			}


			if (getY() + dx >= getAquarium()->getYMax() && this->y_dir > 0.0) {
				this->y_dir *= -1.0;
			} else if (getY() + dy <= getAquarium()->getYMin() && this->y_dir < 0.0) {
				this->y_dir *= -1.0;
			} else {
				this->setY(this->getY() + dy);
			}
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

/* TODO: Last changed progress time perlu ga? */
void Guppy::updateProgress() {
	double current_time = this->getAquarium()->getCurrTime();
	double progress_increment_time = (this->getState() == State::movingRight || this->getState() == State::movingLeft)
									? guppyMoveProgressIncrementTime 
									: guppyTurnProgressIncrementTime;
	if(current_time - this->getLastProgressTime() > progress_increment_time) {
		if(this->getProgress() < progressPeriod - 1) {
			this->setProgress(this->getProgress() + 1);
		} else if(this->getState() == turningRight) {
			this->setProgress(0);
			this->setState(movingRight);
		} else if(this->getState() == turningLeft) {
			this->setProgress(0);
			this->setState(movingLeft);
		} else {
			this->setProgress(0);
		}
		this->setLastProgressTime(current_time);
	}
}

/* Implementasi dead masih salah bung */
void Guppy::dead() {
	if(this->getState() == movingRight || (this->getState() == turningRight && this->getProgress() >= 5) || (this->getState() == turningLeft && this->getProgress() < 5)) {
		this->setState(State::deadRight);
	} else if(this->getState() == movingLeft || (this->getState() == turningLeft && this->getProgress() >= 5) || (this->getState() == turningRight && this->getProgress() < 5)) {
		this->setState(State::deadLeft);
	}
	double current_time = this->getAquarium()->getCurrTime();
	if(current_time - this->getLastProgressTime() > guppyDeadProgressIncrementTime) {
		this->setProgress(this->getProgress() + 1);
		this->setLastProgressTime(current_time);
		if(this->getProgress() >= progressPeriod) {
			this->getAquarium()->deleteGuppy(this);
		}
	}
}

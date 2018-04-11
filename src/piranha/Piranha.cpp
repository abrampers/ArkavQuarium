/* Implementation file of Piranha */
#include "piranha/Piranha.hpp"
#include "aquarium/Aquarium.hpp"

Piranha::Piranha(Aquarium *aquarium): 
Aquatic(floor(fRand(aquarium->getXMin(), aquarium->getXMax())), 
	floor(fRand(aquarium->getYMin(), aquarium->getYMax())), 
	piranhaMoveSpeed, 
	aquarium),
Fish(piranhaFoodThres, 
	piranhaEatRadius, 
	piranhaFullInterval, 
	piranhaHungerInterval, 
	aquarium->getCurrTime()) {
	nearest_guppy = NULL;
	/* Initialize random movement */
	double rad = fRand(0, 360) * pi / 180;
	this->x_dir = cos(rad);
	this->y_dir = sin(rad);
	/* Initialize aquatic state */
	State state = this->x_dir >= 0 ? movingRight : movingLeft;
	this->setState(state);
}

double Piranha::distanceToGuppy(Guppy *g) {
	double piranha_x_position = this->getX();
	double piranha_y_position = this->getY();
	double guppy_x_position = g->getX();
	double guppy_y_position = g->getY();

	return sqrt((piranha_x_position - guppy_x_position) * (piranha_x_position - guppy_x_position) + (piranha_y_position - guppy_y_position) * (piranha_y_position - guppy_y_position));
}

void Piranha::findNearestGuppy() {
	LinkedList<Guppy*>& ll = this->getAquarium()->getGuppyList();
	Guppy* current_nearest_guppy = NULL;
	Node<Guppy*>* curr_node = ll.getHead();
	while(curr_node != NULL) {
	    Guppy* current_guppy = curr_node->getValue();
	    if(current_nearest_guppy == NULL) {
	    	current_nearest_guppy = current_guppy;
	    } else if(distanceToGuppy(current_guppy) < distanceToGuppy(current_nearest_guppy)) {
	    	current_nearest_guppy = current_guppy;
	    }
	    curr_node = curr_node->getNext();
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
	if(this->getState() == State::deadLeft || this->getState() == State::deadRight || (this->getHungry() && current_time - this->getLastHungerTime() > this->hungerTimeout)) {
		/* Dead guppy */
		this->dead();
	} else {
		this->updateProgress();
		this->findNearestGuppy();
		this->eat();
		this->findNearestGuppy();
		this->move();
		this->setLastCurrTime(current_time);
	}
}

void Piranha::move() {
	double current_time = this->getAquarium()->getCurrTime();
	if(this->getState() != turningRight && this->getState() != turningLeft) {
		if(nearest_guppy != NULL && this->getHungry()) {
			double x_direction = nearest_guppy->getX() - this->getX();
			double y_direction = nearest_guppy->getY() - this->getY();
			double distance = distanceToGuppy(nearest_guppy);

			/* Check if this need to change */
			double dx = (x_direction / distance) * this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));
			double dy = (y_direction / distance) * this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));

			if(x_direction >= 0 && this->x_dir < 0) {
				this->setState(turningRight);
				this->setLastProgressTime(current_time);
				this->setProgress(0);
			}

			if(x_direction < 0 && this->x_dir >= 0) {
				this->setState(turningLeft);
				this->setLastProgressTime(current_time);
				this->setProgress(0);
			}

			this->setX(this->getX() + dx);
			this->setY(this->getY() + dy);
			this->x_dir = x_direction / distance;
			this->y_dir = y_direction / distance;
		} else {
			/* Randomize move direction after some interval */
			if(current_time - this->getLastRandomTime() > randomMoveInterval) {
				this->setLastRandomTime(current_time);
				double rad = fRand(0.0, 2.0 * pi);

				double x_direction = cos(rad);
				if(x_direction >= 0 && this->x_dir < 0) {
					this->setState(turningRight);
					this->setLastProgressTime(current_time);
					this->setProgress(0);
				}

				if(x_direction < 0 && this->x_dir >= 0) {
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


			if (getX() + dx >= getAquarium()->getXMax() && x_dir > 0.0) {
				this->x_dir *= -1.0;
				this->setState(turningLeft);
				this->setLastProgressTime(current_time);
				this->setProgress(0);
			} else if (getX() + dx <= getAquarium()->getXMin() && x_dir < 0.0) {
				this->x_dir *= -1.0;
				this->setState(turningRight);
				this->setLastProgressTime(current_time);
				this->setProgress(0);

			} else {
				this->setX(this->getX() + dx);
			}


			if (getY() + dx >= getAquarium()->getYMax() && y_dir > 0.0) {
				this->y_dir *= -1.0;
			} else if (getY() + dy <= getAquarium()->getYMin() && y_dir < 0.0) {
				this->y_dir *= -1.0;
			} else {
				this->setY(this->getY() + dy);
			}
		}
	}
}

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
		this->setFoodEaten(this->getFoodEaten() + 1);

		if(this->getLevel() < maxLevel && this->getFoodEaten() > this->foodThres) {
			this->setLevel(this->getLevel() + 1);
			this->setFoodEaten(0);
		}
	} 
}

void Piranha::dropCoin() {
	this->getAquarium()->createCoin(this->getX(), this->getY(), 100 * (nearest_guppy->getLevel() + 1));
}

void Piranha::updateProgress() {
	double current_time = this->getAquarium()->getCurrTime();
	double progress_increment_time; 
	switch(this->getState()) {
		case State::movingRight :
			progress_increment_time = piranhaMoveProgressIncrementTime;
			break;
		case State::movingLeft :
			progress_increment_time = piranhaMoveProgressIncrementTime;
			break;
		case State::turningRight :
			progress_increment_time = piranhaTurnProgressIncrementTime;
			break;
		case State::turningLeft :
			progress_increment_time = piranhaTurnProgressIncrementTime;
			break;
		case State::eatingRight :
			progress_increment_time = piranhaEatProgressIncrementTime;
			break;
		case State::eatingLeft :
			progress_increment_time = piranhaEatProgressIncrementTime;
			break;
		default:
			progress_increment_time = piranhaMoveProgressIncrementTime;
	}

	if((this->getState() != State::eatingRight && this->getState() != State::eatingLeft) && (this->nearest_guppy != NULL) && distanceToGuppy(this->nearest_guppy) < (2 * piranhaEatRadius)) {
		if(this->getState() == State::movingRight) {
			this->setState(State::eatingRight);
		} else {
			this->setState(State::eatingLeft);
		}
		this->setProgress(0);
		this->setLastProgressTime(current_time);
		return;
	}

	if(current_time - this->getLastProgressTime() > progress_increment_time) {
		if(this->getProgress() < progressPeriod - 1) {
			this->setProgress(this->getProgress() + 1);
		} else if(this->getState() == turningRight) {
			this->setProgress(0);
			this->setState(movingRight);
		} else if(this->getState() == turningLeft) {
			this->setProgress(0);
			this->setState(movingLeft);
		} else if(this->x_dir >= 0) {
			this->setState(movingRight);
			this->setProgress(0);
		} else if(this->x_dir < 0) {
			this->setState(movingLeft);
			this->setProgress(0);
		}
		this->setLastProgressTime(current_time);
	}
}

void Piranha::dead() {
	if(this->getState() == movingRight || (this->getState() == turningRight && this->getProgress() >= 5) || (this->getState() == turningLeft && this->getProgress() < 5)) {
		this->setState(State::deadRight);
	} else if(this->getState() == movingLeft || (this->getState() == turningLeft && this->getProgress() >= 5) || (this->getState() == turningRight && this->getProgress() < 5)) {
		this->setState(State::deadLeft);
	}
	double current_time = this->getAquarium()->getCurrTime();
	if(current_time - this->getLastProgressTime() > piranhaDeadProgressIncrementTime) {
		this->setProgress(this->getProgress() + 1);
		this->setLastProgressTime(current_time);
		if(this->getProgress() >= progressPeriod) {
			this->getAquarium()->deletePiranha(this);
		}
	}
}
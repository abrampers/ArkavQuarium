/* Implementation file of Snail */
#include "snail/Snail.hpp"
#include "aquarium/Aquarium.hpp"

Snail::Snail(Aquarium* a) : Aquatic(fRand(0.0, a->getXMax()), a->getYMax(), snailSpeed, a), snailRadius(snailEatRadius) {
	nearest_coin = NULL;
	hold_coin_value = 0;
	x_dir = 0;
	this->setLastProgressTime(a->getCurrTime());
}

double Snail::getDistance(Aquatic* a, Aquatic* b) {
	return sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b->getY(), 2));
}

bool Snail::isCoinOnTop() {
	return (abs(this->getX() - nearest_coin->getX()) < this->snailRadius * 0.5);
}

void Snail::pickCoin(Coin* c) {
	hold_coin_value = c->getValue();
	this->getAquarium()->deleteCoin(c);
	nearest_coin = NULL;
}

void Snail::findNearestCoin() {
	/* Find nearest coin to pursue */
	LinkedList<Coin*>& coin_list = this->getAquarium()->getCoinList();
	Coin* current_nearest_coin = NULL;
	for (int i = 0; i < coin_list.getLength(); i++) {
		Coin *current_coin = coin_list.get(i);
		if(current_nearest_coin == NULL) {
			current_nearest_coin = current_coin;
		} else if ((getDistance(current_coin, this)) < getDistance(current_nearest_coin, this)) {
			current_nearest_coin = current_coin;
		}
	}
	this->nearest_coin = current_nearest_coin;
}

bool Snail::nearestCoinInRange() {
	if (nearest_coin != NULL) {
		if (getDistance(this, nearest_coin) < this->snailRadius) {
			return true;
		}
	}
	return false;
}

Direction Snail::getDirection() { 
	return x_dir >= 0 ? Direction::right : Direction::left;
}

void Snail::updateState() {
	cout << this->getState() << endl;
	double current_time = this->getAquarium()->getCurrTime();
	this->updateProgress();
	this->findNearestCoin();
	if (nearestCoinInRange()) {
		pickCoin(nearest_coin); 
	} else {
		move();
	}
	this->setLastCurrTime(current_time);
}

void Snail::move() {
	double current_time = this->getAquarium()->getCurrTime();
	if(this->getState() != turningRight && this->getState() != turningLeft) {
		if (nearest_coin != NULL) {
			if(!isCoinOnTop()) {
				double dx = this->getMoveSpeed() * ((current_time - this->getLastCurrTime()));
				double x_direction = this->x_dir;
				if (nearest_coin->getX() > this->getX()) {
					x_dir = 1;
					this->setX(this->getX() + dx);
				} else {
					x_dir = -1;
					this->setX(this->getX() - dx);
				}

				if(x_direction >= 0 && this->x_dir < 0) {
					this->setState(turningLeft);
					this->setLastProgressTime(current_time);
					this->setProgress(0);
				}

				if(x_direction < 0 && this->x_dir >= 0) {
					this->setState(turningRight);
					this->setLastProgressTime(current_time);
					this->setProgress(0);
				}
			}
		}
	}
}

void Snail::updateProgress() {
	double current_time = this->getAquarium()->getCurrTime();
	double progress_increment_time = (this->getState() == State::movingRight || this->getState() == State::movingLeft)
									? snailMoveProgressIncrementTime 
									: snailTurnProgressIncrementTime;
	if(current_time - this->getLastProgressTime() > progress_increment_time) {
		this->setProgress(this->getProgress() + 1);
		if(this->getProgress() >= progressPeriod) {
			if(this->getState() == turningRight) {
				this->setProgress(0);
				this->setState(movingRight);
			} else if(this->getState() == turningLeft) {
				this->setProgress(0);
				this->setState(movingLeft);
			} else {
				this->setProgress(0);
			}
		}
		this->setLastProgressTime(current_time);
	}

}

void Snail::dead() {}


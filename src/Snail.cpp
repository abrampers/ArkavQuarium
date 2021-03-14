/* Implementation file of Snail */
#include "Snail.hpp"
#include "Aquarium.hpp"

Snail::Snail(Aquarium* a) : Aquatic(fRand(a->getXMin(), a->getXMax()), a->getYMax(), snailSpeed, a), snailRadius(snailEatRadius) {
	nearest_coin = nullptr;
	hold_coin_value = 0;
	x_dir = 0;
	this->setLastProgressTime(a->getCurrTime());
}

double Snail::getDistance(Aquatic* a, Aquatic* b) {
	return sqrt(pow(a->getX() - b->getX(), 2) + pow(a->getY() - b->getY(), 2));
}

int Snail::getCoin() {
	return hold_coin_value;
}

void Snail::resetCoin() {
	this->hold_coin_value = 0;
}

bool Snail::isCoinOnTop() {
	return (abs(this->getX() - nearest_coin->getX()) < this->snailRadius * 0.5);
}

void Snail::pickCoin(Coin* c) {
	hold_coin_value += c->getValue();
	this->getAquarium()->deleteCoin(c);
	nearest_coin = nullptr;
}

void Snail::findNearestCoin() {
	/* Find nearest coin to pursue */
	LinkedList<Coin*>& coin_list = this->getAquarium()->getCoinList();
	Coin* current_nearest_coin = nullptr;
	for (int i = 0; i < coin_list.getLength(); i++) {
		Coin *current_coin = coin_list.get(i);
		if(current_nearest_coin == nullptr) {
			current_nearest_coin = current_coin;
		} else if ((getDistance(current_coin, this)) < getDistance(current_nearest_coin, this)) {
			current_nearest_coin = current_coin;
		}
	}
	this->nearest_coin = current_nearest_coin;
}

bool Snail::nearestCoinInRange() {
	if (nearest_coin != nullptr) {
		if (getDistance(this, nearest_coin) < this->snailRadius) {
			return true;
		}
	}
	return false;
}

void Snail::updateState() {
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
		if (nearest_coin != nullptr) {
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

				if(x_direction == 0) {
					if(this->getState() == State::stillLeft && x_dir == 1) {
						this->setState(turningRight);
						this->setLastProgressTime(current_time);
						this->setProgress(0);
					} else if(this->getState() == State::stillRight && x_dir == -1) {
						this->setState(turningLeft);
						this->setLastProgressTime(current_time);
						this->setProgress(0);
					} else if(this->getState() == State::stillLeft && x_dir == -1) {
						this->setState(movingLeft);
						this->setLastProgressTime(current_time);
						this->setProgress(0);
					} else if(this->getState() == State::stillRight && x_dir == 1) {
						this->setState(movingRight);
						this->setLastProgressTime(current_time);
						this->setProgress(0);
					}
				}

				if(x_direction == 1 && this->x_dir == -1) {
					this->setState(turningLeft);
					this->setLastProgressTime(current_time);
					this->setProgress(0);
				}

				if(x_direction == -1 && this->x_dir == 1) {
					this->setState(turningRight);
					this->setLastProgressTime(current_time);
					this->setProgress(0);
				}
			} else {
				if(this->x_dir == 1) {
					this->setState(State::stillRight);
				} else {
					this->setState(State::stillLeft);
				}
				this->x_dir = 0;
			}
		} else {
			if(this->x_dir == 1) {
				this->setState(State::stillRight);
			} else {
				this->setState(State::stillLeft);
			}
			this->x_dir = 0;
		}
	}
}

void Snail::updateProgress() {
	if(this->getState() == State::stillRight || this->getState() == State::stillLeft) {
		this->setProgress(0);
	} else {
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
}

void Snail::dead() {}


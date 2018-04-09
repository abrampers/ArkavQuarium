/* Implementation file of Aquatic */
#include "aquatic/Aquatic.hpp"
#include "aquarium/Aquarium.hpp"

Aquatic::Aquatic(Aquarium *aquarium) : moveSpeed(0) {
	x = 0;
	y = 0;
	last_curr_time = this->getAquarium()->getCurrTime();
	this->aquarium = aquarium;
	this->curr_state = movingRight;
	this->last_progress_time = 0;
	this->progress = 0;
}

Aquatic::Aquatic(double x, double y, double move_speed, Aquarium *aquarium) : moveSpeed(move_speed) {
	this->x = x;
	this->y = y;
	this->last_curr_time = aquarium->getCurrTime();
	this->aquarium = aquarium;
	this->curr_state = movingRight;
	this->last_progress_time = 0;
	this->progress = 0;
}

Aquarium *Aquatic::getAquarium() {
	return this->aquarium;
}

double Aquatic::getMoveSpeed() const {
	return this->moveSpeed;
}

double Aquatic::getX() {
	return this->x;
}

double Aquatic::getY() {
	return this->y;
}

double Aquatic::getLastCurrTime() const {
	return this->last_curr_time;
}

State Aquatic::getState() {
	return this->curr_state;
}

int Aquatic::getProgress() {
	return this->progress;
}

double Aquatic::getLastChangedProgressTime() {
	return this->last_changed_progress_time;
}

double Aquatic::getLastProgressTime() {
	return this->last_progress_time;
}

void Aquatic::setX(double x) {
	this->x = x;
}

void Aquatic::setY(double y) {
	this->y = y;
}

void Aquatic::setLastCurrTime(double t) {
	this->last_curr_time = t;
}

void Aquatic::setState(State state) {
	this->curr_state = state;
}

void Aquatic::setProgress(int progress) {
	this->progress = progress;
}

void Aquatic::setLastChangedProgressTime(double t) {
	this->last_changed_progress_time = t;
}

void Aquatic::setLastProgressTime(double t) {
	this->last_progress_time = t;
}

bool Aquatic::isInside() {
	return x >= 0 && y >= 0 && y < this->aquarium->getYMax() && x < this->aquarium->getXMax();
}
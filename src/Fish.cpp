/* Implementation file of Fish */
#include "include/Fish.hpp"

Fish::Fish(int food_thres, double eat_radius, double full_interval, double hunger_timeout) {
	this->food_thres = food_thres;
	this->eat_radius = eat_radius;
	this->hunger_timeout = hunger_timeout;
	this->level = 1;
	hungry = false;
	level = 1;
}
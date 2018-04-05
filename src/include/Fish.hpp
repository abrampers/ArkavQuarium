#ifndef FISH_HPP
#define FISH_HPP

class Fish {
    protected:
        const int food_thres; // Pellets needed for growth
        const double eat_radius; // Pellet fetch radius
        const double full_interval; // Duration until next hunger
        const double hunger_timeout; // Duration until starvation
        int level;
        double last_eat_time;
        double last_random_time;

    public:
    	//ctor
    	Fish(); //Initialize fish variables

        void dropCoin(); //Create new coin, value depends on type of fish and its phase, or what it eats
    	virtual void eat() = 0; // Method for eat action
};

#endif
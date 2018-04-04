#ifndef FISH_HPP
#define FISH_HPP

class Fish {
    protected:
        const int food_thres; // Pellets needed for growth
        const int eat_radius; // Pellet fetch radius
        const int full_interval; // Duration until next hunger
        const int hunger_timeout; // Duration until starvation
        int level;
        int last_eat_time;

    public:
    	//ctor
    	Fish(); //Initialize fish variables

        void dropCoin(); //Create new coin, value depends on type of fish and its phase, or what it eats
    	virtual void eat() = 0; // Method for eat action
};

#endif
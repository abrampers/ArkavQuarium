#ifndef FISH_HPP
#define FISH_HPP

class Fish {
    protected:
        /* Food needed for growth */
        const int food_thres; 
        /* Pellet fetch radius */
        const double eat_radius; 
        /* Duration until next hunger */
        const double full_interval; 
        /* Duration until starvation */
        const double hunger_timeout; 
        bool hungry;
        int level;

    public:
    	/* constructor */
        /* TODO: Cek apakah butuh default constructor */
    	//Fish(); 
        Fish(int food_thres, double eat_radius, double full_interval, double hunger_timeout);

        /***********/
        /* Methods */
        /***********/
    	/* Method for eat action */
        virtual void eat() = 0; 
};

#endif
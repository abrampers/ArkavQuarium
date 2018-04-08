#ifndef FISH_HPP
#define FISH_HPP

class Fish {
    private:
        /* Last eat time of the fish */
        double last_eat_time;
        /* Last random time of the fish */
        double last_random_time;
        /* Number of food eaten */
        int food_eaten;
        /* State of the fish */
        bool hungry;
        /* Level of the fish */
        int level;
    protected:
        /* Food needed for growth */
        const int food_thres; 
        /* Pellet fetch radius */
        const double eat_radius; 
        /* Duration until next hunger */
        const double full_interval; 
        /* Duration until starvation */
        const double hunger_timeout; 
        

    public:
    	/* constructor */
        /* TODO: Cek apakah butuh default constructor */
    	// Fish(); 
        Fish(int food_thres, double eat_radius, double full_interval, double hunger_timeout, double created_time);

        /* Getter and Setter */
        double getLastEatTime();
        double getLastRandomTime();
        int getFoodEaten();
        bool getHungry();
        int getLevel();
        void setLastEatTime(double last_eat_time);
        void setLastRandomTime(double last_random_time);
        void setFoodEaten(int food_eaten);
        void setHungry(bool hungry);
        void setLevel(int level);

        /***********/
        /* Methods */
        /***********/
    	/* Method for eat action */
        virtual void eat(double current_time) = 0; 
};

#endif
#ifndef FISH_HPP
#define FISH_HPP

#include "../common/Constants.hpp"

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
        const int foodThres; 
        /* Pellet fetch radius */
        const double eatRadius; 
        /* Duration until next hunger */
        const double fullInterval; 
        /* Duration until starvation */
        const double hungerTimeout;

        double x_dir;
        double y_dir;
        

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
        /* TODO: Ganti enum */
        Direction getDirection();

        /***********/
        /* Methods */
        /***********/
    	/* Method for eat action */
        virtual void eat() = 0; 
        virtual void dropCoin() = 0; 
};

#endif
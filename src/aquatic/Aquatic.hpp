/* A parent class for aquatic entities sans fish */
#ifndef AQUATIC_HPP
#define AQUATIC_HPP

class Aquarium;

class Aquatic {
    private:
        Aquarium* aquarium;
        double x, y;
        double last_curr_time;
        const double moveSpeed; /* Movement Speed per second */

    public:
        /* Constructor */
    	Aquatic(Aquarium *aquarium);
    	Aquatic(double x, double y, double move_speed, Aquarium* aquarium);

        /*Getter - Setter */
        Aquarium *getAquarium();
        double getMoveSpeed() const;
        double getX();
        double getY();
        double getLastCurrTime() const;
        void setX(double x);
        void setY(double y);
        void setLastCurrTime(double t);

        /***********/
    	/* Methods */
        /***********/
        /* Whether the position is inside the aquarium or not. */
        bool isInside();                        

        /* All aquatic entities can move. Returns pair of <vx, vy> where vx is velocity in X direction and vy is velocity in y direction.*/
        virtual void move() = 0; // Check if move should be private member function          

        /* What action will it take if the time increments*/
        virtual void updateState() = 0;
};

#endif
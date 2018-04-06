/* A parent class for aquatic entities sans fish */
#ifndef AQUATIC_HPP
#define AQUATIC_HPP

class Aquarium;

class Aquatic {
    private:
        Aquarium* aquarium;
        double x, y;
        double curr_time;
        const double move_speed; /* Movement Speed per second */

    public:
        /* Constructor */
    	Aquatic();
    	Aquatic(int, int);

        /* Destructor */
    	~Aquatic();

        /*Getter - Setter */
        Aquarium *getAquarium();
        double getMoveSpeed() const;
        double getX();
        double getY();
        double getCurrTime() const;
        void setX(double x);
        void setY(double y);
        void setCurrTime(double t);

        /***********/
    	/* Methods */
        /***********/
        /* Whether the position is inside the aquarium or not. */
        bool isInside();                        

        /* All aquatic entities can move. Returns pair of <vx, vy> where vx is velocity in X direction and vy is velocity in y direction.*/
        virtual void move(double current_time) = 0; // Check if move should be private member function          

        /* What action will it take if the time increments*/
        virtual void updateState(double current_time) = 0;
};

#endif
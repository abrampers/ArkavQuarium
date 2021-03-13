/* A parent class for aquatic entities sans fish */
#ifndef AQUATIC_HPP
#define AQUATIC_HPP

#include "Constants.hpp"

class Aquarium;

//! Abstract Class Aquatic. Represents all object in Aquarium such as Piranha, Guppy, Snail, Pellet, and Coin.
class Aquatic {
    private:
        Aquarium* aquarium;
        double x, y;
        double last_curr_time;
        double last_progress_time;
        const double moveSpeed; /* Movement Speed per second */
        State curr_state;
        int progress;

    public:
        /* Constructor */
        //! A constructor.
        /*! Constructs a new Aquatic object. 
            \param Aquarium *aquarium The Aquarium that contains the object.
        */
    	Aquatic(Aquarium *aquarium);

        //! A constructor.
        /*! Constructs a new Aquarium object. 
            \param double x Initial x-position of the object in the aquarium.
            \param double y Initial y-position of the object in the aquarium.
            \param double move_speed Object move speed.
            \param Aquarium *aquarium The Aquarium that contains the object.
        */
    	Aquatic(double x, double y, double move_speed, Aquarium* aquarium);

        /*Getter - Setter */
        //! Getter for aquarium.
        /*!  
            \return Aquarium *aquarium Pointer to the Aquarium that contains the object.
        */
        Aquarium *getAquarium();

        //! Getter for move_speed.
        /*!  
            \return double move_speed
        */
        double getMoveSpeed() const;

        //! Getter for x.
        /*!  
            \return double x x-axis position of the object.
        */
        double getX();

        //! Getter for y.
        /*!  
            \return double y y-axis position of the object.
        */
        double getY();

        //! Getter for last_curr_time.
        /*!  
            \return double last_curr_time The last time the object was updated.
        */
        double getLastCurrTime() const;

        //! Getter for state.
        /*!  
            \return State state The current state of the Aquatic : movingRight, movingLeft, turningRight, turningLeft, stillLeft, stillRight, deadLeft, deadRight
        */
        State getState();

        //! Getter for progress.
        /*!  
            \return int progress The progress of the state.
        */
        int getProgress();

        //! Getter for last_progress_times.
        /*!  
            \return double last_progress_time The last time the object progress time was updated.
        */
        double getLastProgressTime();

        //! Setter for x.
        /*! 
            \param double x
         */
        void setX(double x);

        //! Setter for y.
        /*! 
            \param double y
         */
        void setY(double y);

        //! Setter for curr_time.
        /*! 
            \param double current time
         */
        void setLastCurrTime(double t);

        //! Setter for state.
        /*! 
            \param State state
         */
        void setState(State state);

        //! Setter for progress.
        /*! 
            \param int progress
         */
        void setProgress(int progress);

        //! Setter for last_progress_time.
        /*! 
            \param double last progress time
         */
        void setLastProgressTime(double t);

        /***********/
    	/* Methods */
        /***********/
        //! Check whether the object is inside the aquarium or not.
        /*! \return bool true if inside */
        bool isInside();                        

        /* All aquatic entities can move. Returns pair of <vx, vy> where vx is velocity in X direction and vy is velocity in y direction.*/
        //! Moves the object independently.
        virtual void move() = 0;

        /* What action will it take if the time increments*/
        //! Updates the object state independently.
        virtual void updateState() = 0;

        /* Update progress of moving, turning, or dead */
        //! Updates the object progress independently.
        virtual void updateProgress() = 0;

        /* Doing all dead animation */
        //! Executing dead progress.
        virtual void dead() = 0;
};

#endif
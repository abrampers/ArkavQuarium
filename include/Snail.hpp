#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "Constants.hpp"
#include "Helper.hpp"
#include "Aquatic.hpp"
#include "Coin.hpp"
#include <cmath>

//! Class Snail. Represents all Snail object in Aquarium.
class Snail : public Aquatic {
	private:
		const double snailRadius;
		Coin* nearest_coin;
		int hold_coin_value;
		int x_dir;

		/****************************/
        /* Private member functions */
        /****************************/
		double getDistance(Aquatic*, Aquatic*);
		bool isCoinOnTop();
		void pickCoin(Coin*);
		void findNearestCoin();
        bool nearestCoinInRange();
	public:
		/* Constructor */
		//! A constructor.
        /*! Constructs a new Snail object. 
        	Initialize y-axis location to be always at the bottom of the aquarium.
            \param Aquarium *aquarium The Aquarium that contains the Snail.
        */
		Snail(Aquarium*); //

		/* Getter & Setter */
		//! Getter for hold_coin_value.
        /*!  
            \return int hold_coin_value
        */
        int getCoin();

        //! Setter for hold_coin_value.
        /*! Reset the hold_coin_value to 0 */
        void resetCoin();

		/***********/
        /* Methods */
        /***********/
        //! Implements pure virtual method from Aquatic
        void updateState(); 

        //! Implements pure virtual method from Aquatic
        void move();

        //! Implements pure virtual method from Aquatic
        void updateProgress();

        //! Implements pure virtual method from Aquatic
        void dead();
};

#endif
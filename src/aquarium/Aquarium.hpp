#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "aquatic/Aquatic.hpp"
#include "coin/Coin.hpp"
#include "fish/Fish.hpp"
#include "guppy/Guppy.hpp"
#include "linkedlist/LinkedList.hpp"
#include "pellet/Pellet.hpp"
#include "piranha/Piranha.hpp"
#include "snail/Snail.hpp"

class Aquarium {
    private:
        const double xMax, yMax;
        double curr_time;
        LinkedList<Piranha*> content_piranha;
        LinkedList<Guppy*> content_guppy;
        LinkedList<Snail*> content_snail;
        LinkedList<Pellet*> content_pellet;
        LinkedList<Coin*> content_coin;

    public:
        /* Constructor */
        Aquarium(double xMax, double yMax);

        /* Destructor */
        ~Aquarium();
        
        /* Operator Overloading */

        /* Setter & Getter */
        double getXMax() const;
        double getYMax() const;
        double getCurrTime();
        LinkedList<Piranha*>& getPiranhaList();
        LinkedList<Guppy*>& getGuppyList();
        LinkedList<Snail*>& getSnailList();
        LinkedList<Pellet*>& getPelletList();
        LinkedList<Coin*>& getCoinList();
        
        void setCurrTime(double t);

        /***********/
        /* Methods */
        /***********/
        /* A function that will increment time and processes all content (coin moves down, etc.) */
        void updateState(double current_time);

        /* Create and Delete Operations for Aquatic */
        void createPiranha();
        void createGuppy();
        void createSnail();
        void createPellet(double x, double y);
        void createCoin(double x, double y, int value);
        void deletePiranha(Piranha* p);
        void deleteGuppy(Guppy* g);
        void deleteSnail(Snail* s);
        void deletePellet(Pellet* p);
        void deleteCoin(Coin* c);
};

#endif
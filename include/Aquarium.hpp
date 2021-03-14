#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "Aquatic.hpp"
#include "Coin.hpp"
#include "Fish.hpp"
#include "Guppy.hpp"
#include "LinkedList.hpp"
#include "Pellet.hpp"
#include "Piranha.hpp"
#include "Snail.hpp"

//! Class Aquarium. Contains all game object such as Piranha, Guppy, Snail,
//! Pellet, and Coin.
class Aquarium {
 private:
  const double xMin, yMin, xMax, yMax;
  double curr_time;
  LinkedList<Piranha*> content_piranha;
  LinkedList<Guppy*> content_guppy;
  LinkedList<Snail*> content_snail;
  LinkedList<Pellet*> content_pellet;
  LinkedList<Coin*> content_coin;

 public:
  /* Constructor */
  //! A constructor.
  /*! Constructs a new Aquarium object.
      \param double xMin Minium x value in the aquarium.
      \param double yMin Minium y value in the aquarium.
      \param double xMax Maximum x value in the aquarium.
      \param double yMax Maximum y value in the aquarium.
  */
  Aquarium(double xMin, double yMin, double xMax, double yMax);

  /* Destructor */
  //! A destructor.
  /*! Destructs the Aquarium object. */
  ~Aquarium();

  /* Operator Overloading */

  /* Setter & Getter */
  //! Getter for xMax.
  /*!
      \return double xMax
  */
  double getXMax() const;

  //! Getter for yMax.
  /*!
      \return double yMax
  */
  double getYMax() const;

  //! Getter for xMin.
  /*!
      \return double xMin
  */
  double getXMin() const;

  //! Getter for yMin.
  /*!
      \return double yMin
  */
  double getYMin() const;

  //! Getter for curr_time.
  /*!
      \return double curr_time
   */
  double getCurrTime();

  //! Getter for content_piranha list.
  /*! \return LinkedList<Piranha *>& list of all Piranha*/
  LinkedList<Piranha*>& getPiranhaList();

  //! Getter for content_guppy list.
  /*! \return LinkedList<Guppy *>& list of all Guppy */
  LinkedList<Guppy*>& getGuppyList();

  //! Getter for content_snail list.
  /*! \return LinkedList<Snail *>& list of all Snail */
  LinkedList<Snail*>& getSnailList();

  //! Getter for content_pellet list.
  /*! \return LinkedList<Pellet *>& list of all Pellet */
  LinkedList<Pellet*>& getPelletList();

  //! Getter for content_coin list.
  /*! \return LinkedList<Coin *>& list of all Coin */
  LinkedList<Coin*>& getCoinList();

  //! Setter for curr_time.
  /*!
      \param double current time
   */
  void setCurrTime(double t);

  /***********/
  /* Methods */
  /***********/
  /* A function that will increment time and processes all content (coin moves
   * down, etc.) */
  //! Updates all the aquarium object state.
  /*! \param double current time */
  void updateState(double current_time);

  /* Create and Delete Operations for Aquatic */
  //! Create Piranha.
  /*! Creates a new Piranha and adds it to content_piranha list. */
  void createPiranha();

  //! Create Guppy.
  /*! Creates a new Guppy and adds it to content_guppy list. */
  void createGuppy();

  //! Create Snail.
  /*! Creates a new Snail and adds it to content_snail list. */
  void createSnail();

  //! Create Pellet.
  /*! Creates a new Pellet and adds it to content_pellet list.
      \param double x x-axis position of the newly created Pellet.
      \param double y y-axis position of the newly created Pellet.
  */
  void createPellet(double x, double y);

  //! Create Coin.
  /*! Creates a new Coin and adds it to content_coin list.
      \param double x x-axis position of the newly created Coin.
      \param double y y-axis position of the newly created Coin.
      \param int value the value of the Coin
  */
  void createCoin(double x, double y, int value);

  //! Delete Piranha.
  /*! Deletes a Piranha and removes it from content_piranha list.
      \param Piranha *p Pointer to the Piranha.
  */
  void deletePiranha(Piranha* p);

  //! Delete Guppy.
  /*! Deletes a Guppy and removes it from content_guppy list.
      \param Guppy *g Pointer to the Guppy.
  */
  void deleteGuppy(Guppy* g);

  //! Delete Snail.
  /*! Deletes a Snail and removes it from content_snail list.
      \param Snail *s Pointer to the Snail.
  */
  void deleteSnail(Snail* s);

  //! Delete Pellet.
  /*! Deletes a Pellet and removes it from content_pellet list.
      \param Pellet *p Pointer to the Pellet.
  */
  void deletePellet(Pellet* p);

  //! Delete Coin.
  /*! Deletes a Coin and removes it from content_coin list.
      \param Coin *c Pointer to the Coin.
  */
  void deleteCoin(Coin* c);
};

#endif

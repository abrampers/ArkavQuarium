#ifndef FISH_HPP
#define FISH_HPP

#include "Constants.hpp"
#include "Helper.hpp"

//! Abstract Class Fish. Represents all Fish object in Aquarium such as Piranha
//! and Guppy.
class Fish {
 private:
  /* Last eat time of the fish */
  double last_eat_time;
  /* Last random time of the fish */
  double last_random_time;
  /* Last hunger time */
  double last_hunger_time;
  /* Number of food eaten */
  int food_eaten;
  /* State of the fish */
  bool hungry;
  /* Level of the fish */
  int level;

 protected:
  //! Food needed for growth
  const int foodThres;
  //! Pellet fetch radius
  const double eatRadius;
  //! Duration until next hunger
  const double fullInterval;
  //! Duration until starvation
  const double hungerTimeout;
  //! X-axis direction of the Fish
  double x_dir;
  //! Y-axis direction of the Fish
  double y_dir;

 public:
  /* Constructor */
  //! A constructor.
  /*! Constructs a new Fish object.
      \param int food_thres Number of food to level up.
      \param double eat_radius
      \param double full_interval Full to hungry interval.
      \param double hunger_timeout Hungry to dead interval if there's no food.
      \param double created_time
  */
  Fish(int food_thres, double eat_radius, double full_interval,
       double hunger_timeout, double created_time);

  /* Getter and Setter */
  //! Getter for last_eat_time.
  /*!
      \return double last_eat_time
  */
  double getLastEatTime();

  //! Getter for last_random_time.
  /*!
      \return double last_random_time
  */
  double getLastRandomTime();

  //! Getter for last_hunger_time.
  /*!
      \return double last_hunger_time
  */
  double getLastHungerTime();

  //! Getter for food_eaten.
  /*!
      \return int food_eaten Number of food eaten.
  */
  int getFoodEaten();

  //! Getter for hungry.
  /*!
      \return bool hungry status of the Fish.
  */
  bool getHungry();

  //! Getter for level.
  /*!
      \return int level of the Fish.
  */
  int getLevel();

  //! Setter for last_eat_time.
  /*!
      \param double last_eat_time
   */
  void setLastEatTime(double last_eat_time);

  //! Setter for last_random_time.
  /*!
      \param double last_random_time
   */
  void setLastRandomTime(double last_random_time);

  //! Setter for last_hunger_time.
  /*!
      \param double last_hunger_time
   */
  void setLastHungerTime(double last_hunger_time);

  //! Setter for food_eaten.
  /*!
      \param int food_eaten
   */
  void setFoodEaten(int food_eaten);

  //! Setter for hungry.
  /*!
      \param bool hungry
   */
  void setHungry(bool hungry);

  //! Setter for level.
  /*!
      \param int level
   */
  void setLevel(int level);

  /***********/
  /* Methods */
  /***********/
  /* Method for eat action */
  //! Eat object.
  /*! Eat food if the food is in range */
  virtual void eat() = 0;

  //! Drop coin.
  /*! Drop coin following each subclasses rule */
  virtual void dropCoin() = 0;
};

#endif
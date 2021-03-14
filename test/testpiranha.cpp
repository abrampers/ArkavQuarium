/* Driver file for Piranha */
#include <gtest/gtest.h>

#include "Aquarium.hpp"
#include "Piranha.hpp"

class PiranhaTest : public ::testing::Test {
 protected:
  void SetUp() override {
    aq = new Aquarium(0, 0, 480, 640);
    aq->createPiranha();
    pir = aq->getPiranhaList().get(0);
    gup = aq->getGuppyList().get(0);

    gup->setX(pir->getX());
    gup->setY(pir->getY());
    pir->setHungry(true);
    aq->setCurrTime(5);
  }

  void TearDown() override { delete aq; }

  Aquarium *aq;
  Piranha *pir;
  Guppy *gup;
};

TEST_F(PiranhaTest, EatGupppyWhenHungry) {
  pir->updateState();
  EXPECT_EQ(0, aq->getGuppyList().getLength());
}

TEST_F(PiranhaTest, CoinCreated) {
  pir->updateState();
  EXPECT_EQ(1, aq->getCoinList().getLength());
}

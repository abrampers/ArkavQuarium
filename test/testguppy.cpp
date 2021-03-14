/* Driver file for Guppy */
#include <gtest/gtest.h>

#include "Aquarium.hpp"
#include "Guppy.hpp"

class GuppyTest : public ::testing::Test {
 protected:
  void SetUp() override {
    aq = new Aquarium(0, 0, 480, 640);
    gup = aq->getGuppyList().get(0);
    aq->createPellet(gup->getX(), gup->getY());
    gup->setHungry(true);
  }

  void TearDown() override { delete aq; }

  Aquarium *aq;
  Guppy *gup;
};

TEST_F(GuppyTest, ForwardTime5ms_Should_EatPellet) {
  aq->setCurrTime(5);
  gup->updateState();
  EXPECT_EQ(0, aq->getPelletList().getLength());
}

TEST_F(GuppyTest, ForwardTime200ms_Should_DropCoin) {
  aq->setCurrTime(15);
  gup->updateState();
  aq->setCurrTime(15);
  gup->updateState();
  EXPECT_EQ(1, aq->getCoinList().getLength());
}

TEST_F(GuppyTest, ForwardTime200ms_Should_Dead) {
  aq->setCurrTime(200);
  gup->updateState();
  EXPECT_EQ(State::deadRight, gup->getState());
}

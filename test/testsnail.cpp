/* Driver file for Snail */
#include <gtest/gtest.h>
#include "Aquarium.hpp"
#include "Snail.hpp"

class SnailTest: public ::testing::Test {
protected:
  void SetUp() override {
    aq = new Aquarium(0, 0, 480, 640);
    s = aq->getSnailList().get(0);
  }

  Aquarium *aq;
  Snail *s;
};

TEST_F(SnailTest, GetCoinOnTheSameCoordinate) {
  aq->createCoin(s->getX(), s->getY(), 100);
  s->updateState();
  EXPECT_EQ(0, aq->getCoinList().getLength());
}

TEST_F(SnailTest, NoCoin_SnailShouldNotMove) {
  aq->setCurrTime(200);
  double x = s->getX();
  double y = s->getY();
  s->updateState();
  EXPECT_DOUBLE_EQ(x, s->getX());
  EXPECT_DOUBLE_EQ(y, s->getY());
}

TEST_F(SnailTest, CoinPresent_SnailShouldMoveToCoin) {
  aq->createCoin(s->getX() + 100, s->getY() + 100, 10);
  double x = s->getX();
  double y = s->getY();
  aq->setCurrTime(10);
  s->updateState();
  EXPECT_LT(x, s->getX());
  EXPECT_DOUBLE_EQ(y, s->getY());
}

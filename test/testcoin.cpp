/* Driver file for Aquarium */
#include <gtest/gtest.h>
#include "Aquarium.hpp"
#include "Coin.hpp"

class CoinTest: public ::testing::Test {
protected:
  void SetUp() override {
    aq = new Aquarium(0, 0, 480, 640);
    aq->createCoin(5, 5, 100);
    c = aq->getCoinList().get(0);
    x = c->getX();
    y = c->getY();
  }

  void TearDown() override {
    delete aq;
  }

  Aquarium *aq;
  Coin *c;
  double x, y;
};

TEST_F(CoinTest, Forward100ms_Should_MoveDownOnYAxis_And_StayOnXAxis) {
  aq->setCurrTime(100);
  c->updateState();
  EXPECT_LT(y, c->getY());
  EXPECT_DOUBLE_EQ(x, c->getX());
}

TEST_F(CoinTest, Forward200ms_Should_MoveDownOnYAxis_And_StayOnXAxis) {
  aq->setCurrTime(200);
  c->updateState();
  EXPECT_LT(y, c->getY());
  EXPECT_DOUBLE_EQ(x, c->getX());
}

TEST_F(CoinTest, Forward300ms_Should_MoveDownOnYAxis_And_StayOnXAxis) {
  aq->setCurrTime(300);
  c->updateState();
  EXPECT_LT(y, c->getY());
  EXPECT_DOUBLE_EQ(x, c->getX());
}

TEST_F(CoinTest, Forward400ms_Should_MoveDownOnYAxis_And_StayOnXAxis) {
  aq->setCurrTime(400);
  c->updateState();
  EXPECT_LT(y, c->getY());
  EXPECT_DOUBLE_EQ(x, c->getX());
}

TEST_F(CoinTest, Forward500ms_Should_MoveDownOnYAxis_And_StayOnXAxis) {
  aq->setCurrTime(500);
  c->updateState();
  EXPECT_LT(y, c->getY());
  EXPECT_DOUBLE_EQ(x, c->getX());
}

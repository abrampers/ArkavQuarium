/* Driver file for Pellet */
#include <gtest/gtest.h>

#include "Aquarium.hpp"
#include "Pellet.hpp"

class PelletTest : public ::testing::Test {
 protected:
  void SetUp() override {
    aq = new Aquarium(0, 0, 480, 640);
    aq->createPellet(5, 5);
    p = aq->getPelletList().get(0);
    x = p->getX();
    y = p->getY();
  }

  void TearDown() override { delete aq; }

  Aquarium *aq;
  Pellet *p;
  double x, y;
};

TEST_F(PelletTest, ForwardTime100ms_Should_GoDownYAxis_And_StayOnXAxis) {
  aq->setCurrTime(100);
  p->updateState();
  EXPECT_LT(y, p->getY());
  EXPECT_DOUBLE_EQ(x, p->getX());
}

TEST_F(PelletTest, ForwardTime200ms_Should_GoDownYAxis_And_StayOnXAxis) {
  aq->setCurrTime(200);
  p->updateState();
  EXPECT_LT(y, p->getY());
  EXPECT_DOUBLE_EQ(x, p->getX());
}

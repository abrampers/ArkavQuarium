#include "gtest/gtest.h"
#include "Aquarium.hpp"

class CreateAquariumTest : public ::testing::Test {
protected:
  void SetUp() override {
    aq = new Aquarium(0, 0, 480, 640);
  }
  Aquarium *aq;
};

TEST_F(CreateAquariumTest, CreatePiranha) {
  aq->createPiranha();
  EXPECT_EQ(1, aq->getPiranhaList().getLength());
}

TEST_F(CreateAquariumTest, CreateGuppy) {
  aq->createGuppy();
  EXPECT_EQ(2, aq->getGuppyList().getLength());
}

TEST_F(CreateAquariumTest, CreateSnail) {
  aq->createSnail();
  EXPECT_EQ(2, aq->getSnailList().getLength());
}

TEST_F(CreateAquariumTest, CreatePellet_At5x5) {
  aq->createPellet(5, 5);
  EXPECT_EQ(1, aq->getPelletList().getLength());
}

TEST_F(CreateAquariumTest, CreateCoin_At5x5_WithValue_1) {
  aq->createCoin(5, 5, 1);
  EXPECT_EQ(1, aq->getCoinList().getLength());
}

class DeleteAquariumTest : public ::testing::Test {
protected:
  void SetUp() override {
    aq = new Aquarium(0, 0, 480, 640);
    aq->createPiranha();
    aq->createPellet(5, 5);
    aq->createCoin(5, 5, 1);

    pir = aq->getPiranhaList().get(0);
    gup = aq->getGuppyList().get(0);
    snail = aq->getSnailList().get(0);
    coin = aq->getCoinList().get(0);
    pellet = aq->getPelletList().get(0);
  }

  Aquarium *aq;
  Piranha *pir;
  Guppy *gup;
  Snail *snail;
  Coin *coin;
  Pellet *pellet;
};

TEST_F(DeleteAquariumTest, DeletePiranha) {
  aq->deletePiranha(pir);
  EXPECT_EQ(0, aq->getPiranhaList().getLength());
}

TEST_F(DeleteAquariumTest, DeleteGuppy) {
  aq->deleteGuppy(gup);
  EXPECT_EQ(0, aq->getGuppyList().getLength());
}

TEST_F(DeleteAquariumTest, DeleteSnail) {
  aq->deleteSnail(snail);
  EXPECT_EQ(0, aq->getSnailList().getLength());
}

TEST_F(DeleteAquariumTest, DeletePellet) {
  aq->deletePellet(pellet);
  EXPECT_EQ(0, aq->getPelletList().getLength());
}

TEST_F(DeleteAquariumTest, DeleteCoin) {
  aq->deleteCoin(coin);
  EXPECT_EQ(0, aq->getCoinList().getLength());
}

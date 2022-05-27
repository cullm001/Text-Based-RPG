#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "gtest/gtest.h"

#include "../header/archetypes.hpp"
#include "../header/item.hpp"
#include "../header/player.hpp"
#include "../header/entity.hpp"
#include "../header/bag.hpp"
#include "../header/combat.hpp"
#include "../header/Enemies/Boss.hpp"
#include "../header/Enemies/Enemy.hpp"
#include "../header/Enemies/Minion.hpp"


TEST(PlayerArchertypes, PaladinLevel) {
    Player* test = new Paladin();
    EXPECT_EQ(test->getLevel(), 5);
}

#endif
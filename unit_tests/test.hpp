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

// entity class tests
TEST(EntityClass, DefaultConstructor) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_DOUBLE_EQ(test->getLevel(), 5);
    delete test;
}
TEST(EntityClass, LevelFiveConstructor) {
    Entity* test = new Entity(5);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_DOUBLE_EQ(test->getLevel(), 5);
    delete test;
}
TEST(EntityClass, LevelTenConstructor) {
    Entity* test = new Entity(10);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_DOUBLE_EQ(test->getLevel(), 10);
    delete test;
}
TEST(EntityClass, AllStatsConstructor) {
    Entity* test = new Entity(1, 2, 3, 4);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 3);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 3);
    EXPECT_DOUBLE_EQ(test->getAttack(), 1);
    EXPECT_DOUBLE_EQ(test->getDefense(), 2);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_DOUBLE_EQ(test->getLevel(), 4);
    delete test;
}
TEST(EntityClass, LevelUp) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_DOUBLE_EQ(test->getLevel(), 5);
    test->takedmg(100);
    test->levelUp(1);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 22);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 22);
    EXPECT_DOUBLE_EQ(test->getAttack(), 15.2);
    EXPECT_DOUBLE_EQ(test->getDefense(), 11);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_DOUBLE_EQ(test->getLevel(), 6);
    delete test;
}
TEST(EntityClass, AddTempStats) {
    Entity* test = new Entity();
    test->addTempAttack(5);
    test->addTempDefense(6);
    test->addTempCritRate(0.5);
    EXPECT_DOUBLE_EQ(test->getAttack(), 18.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 16);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.65);
    delete test;
}
TEST(EntityClass, RemoveTempStats) {
    Entity* test = new Entity();
    test->addTempAttack(5);
    test->addTempDefense(6);
    test->addTempCritRate(0.5);
    EXPECT_DOUBLE_EQ(test->getAttack(), 18.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 16);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.65);
    test->resetTempStats();
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    delete test;
}
TEST(EntityClass, AddTempHealth) {
    Entity* test = new Entity();
    test->addTempHealth(10);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    delete test;
}
TEST(EntityClass, RemoveTempHealth) {
    Entity* test = new Entity();
    test->addTempHealth(10);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    test->removeTempHealth();
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    delete test;
}
TEST(EntityClass, RemoveTempHealthDamaged) {
    Entity* test = new Entity();
    test->addTempHealth(10);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    test->takedmg(120); // causes the player to take 12 damage (2 more than the temp health)
    test->removeTempHealth();
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 18);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    delete test;
}
TEST(EntityClass, GetAttackDamage) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->getAttackDamage(), 54);
    // dmg = ((2*level)/5 + 2) * attack
    delete test;
}
TEST(EntityClass, TakeDamage) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->takedmg(100), 10);
    // damage taken = damage the enemy deals / defense
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 10);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    delete test;
}
TEST(EntityClass, HealPartial) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->takedmg(100), 10);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 10);
    test->heal(5);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 15);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    delete test;
}
TEST(EntityClass, FullHeal) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->takedmg(100), 10);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 10);
    test->fullheal();
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    delete test;
}
TEST(EntityClass, HealOver) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->takedmg(100), 10);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 10);
    test->heal(12);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    delete test;
}
TEST(EntityClass, IsBoostedCheckTempStats) {
    Entity* test = new Entity();
    EXPECT_FALSE(test->isBoosted());
    test->addTempHealth(1);
    EXPECT_TRUE(test->isBoosted());
    test->resetTempStats();
    EXPECT_FALSE(test->isBoosted());
    test->addTempAttack(1);
    EXPECT_TRUE(test->isBoosted());
    test->resetTempStats();
    EXPECT_FALSE(test->isBoosted());
    test->addTempDefense(1);
    EXPECT_TRUE(test->isBoosted());
    test->resetTempStats();
    EXPECT_FALSE(test->isBoosted());
    test->addTempCritRate(1);
    EXPECT_TRUE(test->isBoosted());
    test->resetTempStats();
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(EntityClass, IsBoostedCheckBoosts) {
    Entity* test = new Entity();
    EXPECT_FALSE(test->isBoosted());
    test->addAttackBoost(1);
    EXPECT_TRUE(test->isBoosted());
    test->resetBoosts();
    EXPECT_FALSE(test->isBoosted());
    test->addDefenseBoost(1);
    EXPECT_TRUE(test->isBoosted());
    test->resetBoosts();
    EXPECT_FALSE(test->isBoosted());
    test->addCritBoost(1);
    EXPECT_TRUE(test->isBoosted());
    test->resetBoosts();
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(EntityClass, AddStatsHealth) {
    Entity* test = new Entity();
    test->addMaxHealthAndCurrHealth(3);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 23);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 23);
    test->addMaxHealth(4);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 27);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 23);
    test->addCurrHealth(5);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 27);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 28);
    delete test;
}
TEST(EntityClass, AddStatsAtkDefCrit) {
    Entity* test = new Entity();
    test->addAttack(1);
    EXPECT_DOUBLE_EQ(test->getAttack(), 14.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    test->addDefense(2);
    EXPECT_DOUBLE_EQ(test->getAttack(), 14.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 12);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    test->addCritRate(0.6);
    EXPECT_DOUBLE_EQ(test->getAttack(), 14.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 12);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.75);
    delete test;
}
TEST(EntityClass, AttackBoost) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    test->addAttackBoost(1);
    EXPECT_DOUBLE_EQ(test->getAttack(), 16.875);
    test->resetBoosts();
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    test->addAttackBoost(3);
    EXPECT_DOUBLE_EQ(test->getAttack(), 23.625);
    EXPECT_DOUBLE_EQ(test->getAttackDamage(), 94.5);
    delete test;
}
TEST(EntityClass, DefenseBoost) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    test->addDefenseBoost(1);
    EXPECT_DOUBLE_EQ(test->getDefense(), 12.5);
    test->resetBoosts();
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    test->addDefenseBoost(3);
    EXPECT_DOUBLE_EQ(test->getDefense(), 17.5);
    EXPECT_NEAR(test->takedmg(100), 5.71428, 0.0002);
    delete test;
}
TEST(EntityClass, CritBoost) {
    Entity* test = new Entity();
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    test->addCritBoost(1);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.3);
    test->resetBoosts();
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    test->addCritBoost(3);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.6);
    delete test;
}

// player class tests
TEST(PlayerClass, EquipWeapon) {
    Player* test = new TestArchetype();
    EXPECT_DOUBLE_EQ(test->getAttack(), 14);
    Weapon* testWeapon = new Weapon("gtest", 10, 5, "Searches", "Google");
    test->equip(testWeapon);
    EXPECT_DOUBLE_EQ(test->getAttack(), 23.5);
    EXPECT_EQ(test->getWeapon(), testWeapon);
    delete test;
}
TEST(PlayerClass, SetArchetype) {
    Player* test = new TestArchetype();
    EXPECT_EQ(test->getArchetype(), "Testing");
    test->setArchetype("google test");
    EXPECT_EQ(test->getArchetype(), "google test");
    delete test;
}

// unit tests for each player archetype
TEST(PlayerArchetypes, PaladinStatsDefault) {
    Player* test = new Paladin();
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 14);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted()); 
    delete test;
}
TEST(PlayerArchetypes, PaladinStatsLevelTen) {
    Player* test = new Paladin(10);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(PlayerArchetypes, PaladinClassAbility) {
    Player* test = new Paladin();
    EXPECT_EQ(test->get_class_ability_line(), "You call upon the heavens to protect you. A divine shield bolsters your defense.");
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getDefense(), 12.5);
    delete test;
}
TEST(PlayerArchetypes, PaladinFirstWeapon) {
    Player* test = new Paladin();
    EXPECT_EQ(test->getWeapon()->getType(), "Sword");
    EXPECT_EQ(test->getWeapon()->getLevel(), 5);
    EXPECT_EQ(test->getWeapon()->getAttackDescription(), "slash");
    EXPECT_EQ(test->getWeapon()->getRarity(), "Common");
    EXPECT_DOUBLE_EQ(test->getWeapon()->getBoost(), 0.5);
    delete test;
}
TEST(PlayerArchetypes, WizardStatsDefault) {
    Player* test = new Wizard();
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 14);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted()); 
    delete test;
}
TEST(PlayerArchetypes, WizardStatsLevelTen) {
    Player* test = new Wizard(10);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(PlayerArchetypes, WizardClassAbility) {
    Player* test = new Wizard();
    EXPECT_EQ(test->get_class_ability_line(), "You channel your magic into the air, and feel a tingling sensation. You feel more powerful but you're not sure how.");
    EXPECT_DOUBLE_EQ(test->getAttack(), 14);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    test->class_ability();
    EXPECT_TRUE(test->isBoosted());
    delete test;
}
TEST(PlayerArchetypes, WizardFirstWeapon) {
    Player* test = new Wizard();
    EXPECT_EQ(test->getWeapon()->getType(), "Staff");
    EXPECT_EQ(test->getWeapon()->getLevel(), 5);
    EXPECT_EQ(test->getWeapon()->getAttackDescription(), "zap");
    EXPECT_EQ(test->getWeapon()->getRarity(), "Common");
    EXPECT_DOUBLE_EQ(test->getWeapon()->getBoost(), 0.5);
    delete test;
}
TEST(PlayerArchetypes, ArcherStatsDefault) {
    Player* test = new Archer();
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 14);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted()); 
    delete test;
}
TEST(PlayerArchetypes, ArcherStatsLevelTen) {
    Player* test = new Archer(10);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(PlayerArchetypes, ArcherClassAbility) {
    Player* test = new Archer();
    EXPECT_EQ(test->get_class_ability_line(), "You meditate for a moment and your focus sharpens greatly. Your crit rate has increased.");
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.30);
    delete test;
}
TEST(PlayerArchetypes, ArcherFirstWeapon) {
    Player* test = new Archer();
    EXPECT_EQ(test->getWeapon()->getType(), "Bow");
    EXPECT_EQ(test->getWeapon()->getLevel(), 5);
    EXPECT_EQ(test->getWeapon()->getAttackDescription(), "shoot");
    EXPECT_EQ(test->getWeapon()->getRarity(), "Common");
    EXPECT_DOUBLE_EQ(test->getWeapon()->getBoost(), 0.5);
    delete test;
}
TEST(PlayerArchetypes, ClericStatsDefault) {
    Player* test = new Cleric();
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 14);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted()); 
    delete test;
}
TEST(PlayerArchetypes, ClericStatsLevelTen) {
    Player* test = new Cleric(10);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(PlayerArchetypes, ClericClassAbility) {
    Player* test = new Cleric();
    test->takedmg(100);
    EXPECT_EQ(test->get_class_ability_line(), "You clasps your hands together and pray. You receive a heal of 5 health.");
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 10);
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 15);
    delete test;
}
TEST(PlayerArchetypes, ClericFirstWeapon) {
    Player* test = new Cleric();
    EXPECT_EQ(test->getWeapon()->getType(), "Mace");
    EXPECT_EQ(test->getWeapon()->getLevel(), 5);
    EXPECT_EQ(test->getWeapon()->getAttackDescription(), "smite");
    EXPECT_EQ(test->getWeapon()->getRarity(), "Common");
    EXPECT_DOUBLE_EQ(test->getWeapon()->getBoost(), 0.5);
    delete test;
}
TEST(PlayerArchetypes, BarbarianStatsDefault) {
    Player* test = new Barbarian();
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 14);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted()); 
    delete test;
}
TEST(PlayerArchetypes, BarbarianStatsLevelTen) {
    Player* test = new Barbarian(10);
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(PlayerArchetypes, BarbarianClassAbility) {
    Player* test = new Barbarian();
    EXPECT_EQ(test->get_class_ability_line(), "You shout towards the sky and enter a rage. You feel stronger.");
    EXPECT_DOUBLE_EQ(test->getAttack(), 14);
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getAttack(), 17.5);
    delete test;
}
TEST(PlayerArchetypes, BarbarianFirstWeapon) {
    Player* test = new Barbarian();
    EXPECT_EQ(test->getWeapon()->getType(), "Hammer");
    EXPECT_EQ(test->getWeapon()->getLevel(), 5);
    EXPECT_EQ(test->getWeapon()->getAttackDescription(), "smash");
    EXPECT_EQ(test->getWeapon()->getRarity(), "Common");
    EXPECT_DOUBLE_EQ(test->getWeapon()->getBoost(), 0.5);
    delete test;
}

// Enemy Class Unit Tests
TEST(GoblinMinionClass, DefaultConstructor) {
    GoblinMinion* test = new GoblinMinion();
    EXPECT_EQ(test->getName(), "Goblin");
    EXPECT_EQ(test->getAttackNoise(), "shanks");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(GoblinMinionClass, LevelFiveConstructor) {
    GoblinMinion* test = new GoblinMinion(5);
    EXPECT_EQ(test->getName(), "Goblin");
    EXPECT_EQ(test->getAttackNoise(), "shanks");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(GoblinMinionClass, LevelTenConstructor) {
    GoblinMinion* test = new GoblinMinion(10);
    EXPECT_EQ(test->getName(), "Goblin");
    EXPECT_EQ(test->getAttackNoise(), "shanks");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(GoblinMinionClass, AllStatConstructor) {
    GoblinMinion* test = new GoblinMinion(10, 20, 30, 40);
    EXPECT_EQ(test->getName(), "Goblin");
    EXPECT_EQ(test->getAttackNoise(), "shanks");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 10);
    EXPECT_DOUBLE_EQ(test->getDefense(), 20);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 40);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(GoblinMinionClass, ClassAbility) {
    GoblinMinion* test = new GoblinMinion();
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_FALSE(test->isBoosted());
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.30);
    EXPECT_TRUE(test->isBoosted());
    delete test;
}
TEST(GoblinMinionClass, GetClassAbility) {
    GoblinMinion* test = new GoblinMinion();
    test->get_class_ability_line();
    EXPECT_EQ(test->get_class_ability_line(), "The Goblin hones its focus, its more likely to crit.");
    delete test;
}
TEST(SlimeMinionClass, DefaultConstructor) {
    SlimeMinion* test = new SlimeMinion();
    EXPECT_EQ(test->getName(), "Slime");
    EXPECT_EQ(test->getAttackNoise(), "tackles");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(SlimeMinionClass, LevelFiveConstructor) {
    SlimeMinion* test = new SlimeMinion(5);
    EXPECT_EQ(test->getName(), "Slime");
    EXPECT_EQ(test->getAttackNoise(), "tackles");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(SlimeMinionClass, LevelTenConstructor) {
    SlimeMinion* test = new SlimeMinion(10);
    EXPECT_EQ(test->getName(), "Slime");
    EXPECT_EQ(test->getAttackNoise(), "tackles");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(SlimeMinionClass, AllStatConstructor) {
    SlimeMinion* test = new SlimeMinion(10, 20, 30, 40);
    EXPECT_EQ(test->getName(), "Slime");
    EXPECT_EQ(test->getAttackNoise(), "tackles");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 10);
    EXPECT_DOUBLE_EQ(test->getDefense(), 20);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 40);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(SlimeMinionClass, ClassAbilityDamaged) {
    SlimeMinion* test = new SlimeMinion();
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    test->takedmg(100);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 10);
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 14);
    delete test;
}
TEST(SlimeMinionClass, ClassAbilityFull) {
    SlimeMinion* test = new SlimeMinion();
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    test->takedmg(20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 18);
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    delete test;
}
TEST(SlimeMinionClass, GetClassAbility) {
    SlimeMinion* test = new SlimeMinion();
    test->get_class_ability_line();
    EXPECT_EQ(test->get_class_ability_line(), "The Slime eats a strange substance, it looks lively.");
    delete test;
}

TEST(ChickenMinionClass, DefaultConstructor) {
    ChickenMinion* test = new ChickenMinion();
    EXPECT_EQ(test->getName(), "Angry Chicken");
    EXPECT_EQ(test->getAttackNoise(), "pecks");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(ChickenMinionClass, LevelFiveConstructor) {
    ChickenMinion* test = new ChickenMinion(5);
    EXPECT_EQ(test->getName(), "Angry Chicken");
    EXPECT_EQ(test->getAttackNoise(), "pecks");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(ChickenMinionClass, LevelTenConstructor) {
    ChickenMinion* test = new ChickenMinion(10);
    EXPECT_EQ(test->getName(), "Angry Chicken");
    EXPECT_EQ(test->getAttackNoise(), "pecks");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(ChickenMinionClass, AllStatConstructor) {
    ChickenMinion* test = new ChickenMinion(10, 20, 30, 40);
    EXPECT_EQ(test->getName(), "Angry Chicken");
    EXPECT_EQ(test->getAttackNoise(), "pecks");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 10);
    EXPECT_DOUBLE_EQ(test->getDefense(), 20);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 40);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(ChickenMinionClass, ClassAbility) {
    ChickenMinion* test = new ChickenMinion();
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_FALSE(test->isBoosted());
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getAttack(), 16.875);
    EXPECT_TRUE(test->isBoosted());
    delete test;
}
TEST(ChickenMinionClass, GetClassAbility) {
    ChickenMinion* test = new ChickenMinion();
    test->get_class_ability_line();
    EXPECT_EQ(test->get_class_ability_line(), "The Angry Chicken sharpens its beak and claws, it looks more dangerous.");
    delete test;
}
TEST(HobgoblinBossClass, DefaultConstructor) {
    HobgoblinBoss* test = new HobgoblinBoss();
    EXPECT_EQ(test->getName(), "Hobgoblin");
    EXPECT_EQ(test->getAttackNoise(), "crushes");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(HobgoblinBossClass, LevelFiveConstructor) {
    HobgoblinBoss* test = new HobgoblinBoss(5);
    EXPECT_EQ(test->getName(), "Hobgoblin");
    EXPECT_EQ(test->getAttackNoise(), "crushes");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 20);
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_DOUBLE_EQ(test->getDefense(), 10);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 5);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(HobgoblinBossClass, LevelTenConstructor) {
    HobgoblinBoss* test = new HobgoblinBoss(10);
    EXPECT_EQ(test->getName(), "Hobgoblin");
    EXPECT_EQ(test->getAttackNoise(), "crushes");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 22);
    EXPECT_DOUBLE_EQ(test->getDefense(), 15);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 10);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(HobgoblinBossClass, AllStatConstructor) {
    HobgoblinBoss* test = new HobgoblinBoss(10, 20, 30, 40);
    EXPECT_EQ(test->getName(), "Hobgoblin");
    EXPECT_EQ(test->getAttackNoise(), "crushes");
    EXPECT_DOUBLE_EQ(test->getMaxHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getCurrHealth(), 30);
    EXPECT_DOUBLE_EQ(test->getAttack(), 10);
    EXPECT_DOUBLE_EQ(test->getDefense(), 20);
    EXPECT_DOUBLE_EQ(test->getCritRate(), 0.15);
    EXPECT_EQ(test->getLevel(), 40);
    EXPECT_FALSE(test->isBoosted());
    delete test;
}
TEST(HobgoblinBossClass, ClassAbility) {
    HobgoblinBoss* test = new HobgoblinBoss();
    EXPECT_DOUBLE_EQ(test->getAttack(), 13.5);
    EXPECT_FALSE(test->isBoosted());
    test->class_ability();
    EXPECT_DOUBLE_EQ(test->getAttack(), 20.25);
    EXPECT_TRUE(test->isBoosted());
    delete test;
}
TEST(HobgoblinBossClass, GetClassAbility) {
    HobgoblinBoss* test = new HobgoblinBoss();
    test->get_class_ability_line();
    EXPECT_EQ(test->get_class_ability_line(), "The Hobgoblin roars, its veins popping out. It looks extremely enraged.");
    delete test;
}

// weapon class unit tests
TEST(WeaponClass, AllStatConstructor) {
    Weapon* test = new Weapon("Test Type", 5, 10, "searches", "Google");
    EXPECT_EQ(test->getType(), "Test Type");
    EXPECT_DOUBLE_EQ(test->getBoost(), 5);
    EXPECT_DOUBLE_EQ(test->getLevel(), 10);
    EXPECT_EQ(test->getAttackDescription(), "searches");
    EXPECT_EQ(test->getRarity(), "Google");
    delete test;
}
TEST(WeaponClass, LevelConstructor) {
    Weapon* test = new Weapon("Test Type", 5, "searches");
    EXPECT_EQ(test->getType(), "Test Type");
    EXPECT_DOUBLE_EQ(test->getLevel(), 5);
    EXPECT_EQ(test->getAttackDescription(), "searches");
    delete test;
}
TEST(WeaponClass, LevelRarityConstructor) {
    Weapon* test = new Weapon("Test Type", 5, "searches", "Common");
    EXPECT_EQ(test->getType(), "Test Type");
    EXPECT_DOUBLE_EQ(test->getBoost(), 0.5);
    EXPECT_DOUBLE_EQ(test->getLevel(), 5);
    EXPECT_EQ(test->getAttackDescription(), "searches");
    EXPECT_EQ(test->getRarity(), "Common");
    delete test;
}
TEST(WeaponClass, BasedOnConstructor) {
    Weapon* test = new Weapon("Test Type", 12, "searches");
    Weapon* test2 = new Weapon(test, 15);
    EXPECT_EQ(test2->getType(), "Test Type");
    EXPECT_EQ(test2->getAttackDescription(), "searches");
    EXPECT_DOUBLE_EQ(test2->getLevel(), 15);
    delete test;
    delete test2;
}
TEST(WeaponClass, PrintStatsFunction) {
    Weapon* test = new Weapon("Test Type", 10, 20, "searches", "Google");
    EXPECT_EQ(test->printStats(), "--- Weapon Stats ---\nType: Test Type\nRarity: Google\nBuff: 10.000000");
    delete test;
}
TEST(WeaponClass, PrintFoundFunction) {
    Weapon* test = new Weapon("Test Type", 10, 20, "searches", "Google");
    EXPECT_EQ(test->printFound(), "You discovered a Lvl. 20 Google Test Type (+10)!");
    delete test;
}
TEST(WeaponClass, PrintAllStatsFunction) {
    Weapon* test = new Weapon("Test Type", 10, 20, "searches", "Google");
    EXPECT_EQ(test->printAllStats(), "--- Weapon Stats ---\nType: Test Type\nRarity: Google\nBuff: 10.000000\nAttack Description: searches");
    delete test;
}
TEST(Bag, Add_Remove){
    Bag* test = new Bag();
    testing::internal::CaptureStdout();
    test->print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "There is nothing in your bag.\n");
    delete test;
}
TEST(Bag, Add_Remove2){
    Player* testPlayer = new Wizard();
    Bag* testBag = new Bag(testPlayer);
    Item* heal = new healthpot();
    Item* str = new strengthpot();
    testBag->add(heal);
    testBag->add(str);
    testBag->use(1);
    EXPECT_EQ(testBag->use(1), "You used an strength potion. You temporarily boosted your attack.");
    delete heal;
    delete testBag;
    delete testPlayer;
    delete str;
}

TEST(Bag, Add_Remove3){
    Player* testPlayer = new Wizard();
    Bag* testBag = new Bag(testPlayer);
    Item* heal = new healthpot();
    Item* str = new strengthpot();
    testBag->add(heal);
    testBag->add(str);
    EXPECT_EQ(testBag->use(1), "You used a healing potion. You restored 5 health.");
    delete heal;
    delete testBag;
    delete testPlayer;
    delete str;
}
TEST(Bag, Add_Remove4){
    Player* testPlayer = new Wizard();
    Bag* testBag = new Bag(testPlayer);
    Item* heal = new healthpot();
    Item* str = new strengthpot();
    testBag->add(heal);
    testBag->add(heal);
    EXPECT_EQ(testBag->use(1), "You used a healing potion. You restored 5 health.");
    delete heal;
    delete testBag;
    delete testPlayer;
    delete str;
}
TEST(Bag, Add_Remove5){
    Player* testPlayer = new Wizard();
    Bag* testBag = new Bag(testPlayer);
    Item* heal = new healthpot();
    Item* str = new strengthpot();
    testBag->add(heal);
    testBag->add(str);
    EXPECT_EQ(testBag->use(2), "You used an strength potion. You temporarily boosted your attack.");
    delete heal;
    delete testBag;
    delete testPlayer;
    delete str;
}

TEST(Combat, print){
    Player* testPlayer = new Wizard();
    Bag* testBag = new Bag(testPlayer);
    testPlayer->levelUp(10);
    Item* heal = new healthpot();
    Enemy* testEnemy = new ChickenMinion(10);
    combat testFight(testBag, testEnemy, heal);
    testing::internal::CaptureStdout();
    testFight.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Health:  40/40 HP\nEnemy:   30/30 HP\n------------------------------------\n  1. Attack\t2. Bag\n  3. Ability\t4. Run\n-------------------------------------\n");
    delete testPlayer;
    delete testBag;
    delete heal;
    delete testEnemy;
}
TEST(Combat, monster){
    Player* testPlayer = new Wizard();
    Bag* testBag = new Bag(testPlayer);
    testPlayer->levelUp(5);
    Item* heal = new healthpot();
    Enemy* testEnemy = new ChickenMinion(10);
    combat testFight(testBag, testEnemy, heal);
    testing::internal::CaptureStdout();
    testFight.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Health:  30/30 HP\nEnemy:   30/30 HP\n------------------------------------\n  1. Attack\t2. Bag\n  3. Ability\t4. Run\n-------------------------------------\n");
    delete testPlayer;
    delete testBag;
    delete heal;
    delete testEnemy;
}
TEST(Combat, player){
    Player* testPlayer = new Wizard();
    Bag* testBag = new Bag(testPlayer);
    testPlayer->levelUp(1);
    Item* heal = new healthpot();
    Enemy* testEnemy = new ChickenMinion(10);
    combat testFight(testBag, testEnemy, heal);
    testing::internal::CaptureStdout();
    testFight.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Health:  22/22 HP\nEnemy:   30/30 HP\n------------------------------------\n  1. Attack\t2. Bag\n  3. Ability\t4. Run\n-------------------------------------\n");
    delete testPlayer;
    delete testBag;
    delete heal;
    delete testEnemy;
}

#endif

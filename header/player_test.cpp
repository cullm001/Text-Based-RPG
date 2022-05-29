#include "combat.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "bag.hpp"
#include "./Enemies/Boss.hpp"
#include "./Enemies/Enemy.hpp"
#include "./Enemies/Minion.hpp"
#include "item.hpp"
#include "archetypes.hpp"
#include "Weapon/weapon.hpp"
#include <iostream>
using namespace std;


int main() {
  Player* testPlayer = new Wizard();
  Bag* testBag = new Bag(testPlayer);
  testPlayer->levelUp(10);

  Item* heal = new healthpot();
  Item* str = new strengthpot();
  testBag->add(heal);
  testBag->add(str);

  Enemy* testEnemy = new ChickenMinion(10);
  combat testFight(testBag, testEnemy, heal);

  testFight.printStats();
  testFight.start("Test Enemy Combat");

  return 0;
}
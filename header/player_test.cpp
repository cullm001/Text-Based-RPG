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
  Player* ptest = new Archer();
  Bag fiction(ptest);
  ptest->levelUp(10);

  healthpot heal("healing potion", "When taken, a small angel pops out and sings a song", 1);
  dmgpot dmg("strength potion", "When taken the user feels a slight boost to their muscles", 1);
  fiction.add(&heal);
  fiction.add(&dmg);

  Enemy* bobby = new SlimeMinion(10);
  combat testFight(&fiction, bobby, &heal);

  cout << "Health " << fiction.getplayer()->getCurrHealth() <<"/"<< fiction.getplayer()->getMaxHealth() << endl;
  cout << "Attack " << fiction.getplayer()->getAttack() << endl;
  cout << "Defense " << fiction.getplayer()->getDefense() << "\n" << endl;
  testFight.start("Slime Combat");

  return 0;
}
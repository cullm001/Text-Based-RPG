#include "combat.hpp"
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


int main(){
    Player* Paul = new Barbarian();
    Bag fiction(Paul);
    healthpot heal("healing potion", "When taken, a small angel pops out and sings a song", 1);
    dmgpot dmg("strength potion", "When taken the user feels a slight boost to their muscles", 1);
    fiction.add(&heal);
    fiction.add(&dmg);
    Minion bob(7, 6, 6, "goblin");
    combat epic(&fiction, &bob, &heal);
    // for(int i = 0; i < 20; i++){
    //     fiction.getplayer()->levelUp();
    // }
    fiction.getplayer()->heal();
    //epic.start("bob");
    //fiction.getplayer();
    cout << "health " << fiction.getplayer()->getCurrHealth() <<"/"<< fiction.getplayer()->getMaxHealth() << endl;
    cout << "attack " << fiction.getplayer()->getAttack() << endl;
    cout << "defense " << fiction.getplayer()->getDefense() << "\n" << endl;
    epic.start("Goblin Combat Test");

  //fiction.print();
  //fiction.use(1);
  //cout << "health " << fiction.getplayer()->getCurrHealth() <<"/"<< fiction.getplayer()->getMaxHealth() << endl;
  //cout << "attack " << fiction.getplayer()->getAttack() << endl;
  //cout << "defense " << fiction.getplayer()->getDefense() << endl;
  //fiction.use(2);
  //cout << "health " << fiction.getplayer()->getCurrHealth() <<"/"<< fiction.getplayer()->getMaxHealth() << endl;
  //cout << "attack " << fiction.getplayer()->getAttack() << endl;
  //cout << "defense " << fiction.getplayer()->getDefense() << endl;

	return 0;
}

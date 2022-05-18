#include "combat.hpp"
#include "player.hpp"
#include "bag.hpp"
#include "item.hpp"
#include <iostream>
using namespace std;


int main(){
  
    Bag fiction;
    healthpot heal("healpotion", "When taken, a small angel pops out and sings a song", 1);
    dmgpot dmg("Attackpotion", "When taken the user feels a slight boost to their muscles", 1);
  fiction.add(&heal);
  fiction.add(&dmg);
  fiction.getplayer();
  cout << "health " << fiction.getplayer()->getCurrHealth() <<"/"<< fiction.getplayer()->getMaxHealth() << endl;
  cout << "attack " << fiction.getplayer()->getAttack() << endl;
  cout << "defense " << fiction.getplayer()->getDefense() << endl;
  fiction.print();
  fiction.use(1);
  cout << "health " << fiction.getplayer()->getCurrHealth() <<"/"<< fiction.getplayer()->getMaxHealth() << endl;
  cout << "attack " << fiction.getplayer()->getAttack() << endl;
  cout << "defense " << fiction.getplayer()->getDefense() << endl;
  fiction.use(2);
  cout << "health " << fiction.getplayer()->getCurrHealth() <<"/"<< fiction.getplayer()->getMaxHealth() << endl;
  cout << "attack " << fiction.getplayer()->getAttack() << endl;
  cout << "defense " << fiction.getplayer()->getDefense() << endl;

	return 0;
}

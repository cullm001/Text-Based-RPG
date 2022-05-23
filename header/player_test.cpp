#include "combat.hpp"
#include "player.hpp"
#include "bag.hpp"
#include "./Enemies/Boss.hpp"
#include "./Enemies/Enemy.hpp"
#include "./Enemies/Minion.hpp"
#include "item.hpp"
#include <iostream>
using namespace std;


int main(){
  
    Bag fiction;
    healthpot heal("healpotion", "When taken, a small angel pops out and sings a song", 1);
    dmgpot dmg("Attackpotion", "When taken the user feels a slight boost to their muscles", 1);
    fiction.add(&heal);
    fiction.add(&dmg);
    Minion bob(5, 5, 5, "hello");
    combat epic(&fiction, &bob, &heal);
    for(int i = 0; i < 20; i++){
        fiction.getplayer()->levelUp();
    }
    fiction.getplayer()->heal();
    //epic.start("bob");
    //fiction.getplayer();
    cout << "health " << fiction.getplayer()->getCurrHealth() <<"/"<< fiction.getplayer()->getMaxHealth() << endl;
    cout << "attack " << fiction.getplayer()->getAttack() << endl;
    cout << "defense " << fiction.getplayer()->getDefense() << "/n" << endl;
    epic.start("bob");

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

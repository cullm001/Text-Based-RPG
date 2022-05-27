#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <string>
using namespace std;

class Weapon {
	private:
		string type;
		string attackDescription;
		string rarity; // common 5% > uncommon 10% > rare 15% > epic 20% > legendary 25% 
		int buff;
		int level;
    public:
		Weapon(string t, int b, int lvl, string atk, string rar); //set every stat
		string getType() { return type; }
		int getBoost()  { return buff; }
		int getLevel() { return level; }
		string getRarity() { return rarity; }
		string getAttackDescription() { return attackDescription; }
		string printStats();
		string printFound();
};

#endif

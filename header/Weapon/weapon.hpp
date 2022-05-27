#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <string>
using namespace std;

class Weapon {
	private:
		string type;
		string attackDescription;
		string rarity; // common 5% > uncommon 10% > rare 15% > epic 20% > legendary 25% 
		double buff;
		int level;
		double calcBoost(string r);
		string randRarity();
    public:
		Weapon(string t, int lvl, string atk); //randomly determines rarity and buff based on lvl*rarity
		Weapon(string t, int lvl, string atk, string rar); //only determines buff
		Weapon(string t, int b, int lvl, string atk, string rar); //set every stat
		string getType() { return type; }
		double getBoost()  { return buff; }
		int getLevel() { return level; }
		string getRarity() { return rarity; }
		string getAttackDescription() { return attackDescription; }
		string printStats();
		string printFound();
};

#endif

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <string>
using namespace std;

class Weapon {
	private:
		string type;
		string attackDescription;
		string rarity;
		int buff;
    public:
		Weapon(string t, int b, string atk, string rar);
		string getType() { return type; }
		int getBoost()  { return buff; }
		string getRarity() { return rarity; }
		string getAttackDescription() { return attackDescription; }
		string printStats();
		string printFound();
};

#endif

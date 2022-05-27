#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <string>
using namespace std;

class Weapon {
	private:
		string name;
		string attackDescription;
		string rarity;
		int buff;
    public:
		Weapon(string n, int b, string atk, string rar);
		string getName() { return name; }
		int getBoost()  { return buff; }
		string getRarity() { return rarity; }
		string getAttackDescription() { return attackDescription; }
		void print();
};

#endif

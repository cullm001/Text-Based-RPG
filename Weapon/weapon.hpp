#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <string>
using namespace std;

class Weapon {
    public:
	Weapon(string n, int b);
	int getBoost();
	int print();
    private:
	string name;
	int buff;

};

#endif

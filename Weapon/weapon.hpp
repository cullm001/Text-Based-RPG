#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <string>
using namespace std;

class Weapon {
    public:
	Weapon(string n, int b);
	int getBoost();
    private:
	string name;
	int buff;

};

#endif

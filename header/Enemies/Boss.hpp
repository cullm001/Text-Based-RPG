#ifndef BOSS_HPP
#define BOSS_HPP
#include "Enemy.hpp"
#include <iostream>
using namespace std;

class Boss: public Enemy{
	private:
		virtual void class_ability() = 0;
	public:
		// a = attack, d = defense, h = health, l = level, nm = name, an = attackNoise
		Boss(string nm) : Enemy(nm) {}
		Boss(int l, string nm) : Enemy(l, nm) {}
		Boss(double a, double d, double h, int l, string nm): Enemy(a, d, h, l, nm) {}

		Boss(string nm, string an) : Enemy(nm, an) {}
		Boss(int l, string nm, string an) : Enemy(l, nm, an) {}
		Boss(double a, double d, double h, int l, string nm, string an): Enemy(a, d, h, l, nm, an) {}

		double move();
};

class Hobgoblin : public Boss {
	void class_ability() {
		cout << "The hobgoblin roars, its veins popping out. It looks like its enraged." << endl;
		this->addAttackBoost(2);
	}
};
#endif

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
		virtual string get_class_ability_line() = 0;
};

class HobgoblinBoss : public Boss {
	public: 
		HobgoblinBoss() : Boss("hobgoblin", "crushes") {}
		HobgoblinBoss(int l) : Boss(l, "hobgoblin", "crushes") {}
		HobgoblinBoss(double a, double d, double h, int l) : Boss(a, d, h, l, "hobgoblin", "crushes") {}

		void class_ability() {
			this->addAttackBoost(2);
		}
		string get_class_ability_line() {
			return "The hobgoblin roars, its veins popping out. It looks extremely enraged.";
		}
};
#endif

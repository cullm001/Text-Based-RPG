#ifndef MINION_HPP
#define MINION_HPP
#include "Enemy.hpp"
#include <iostream>

using namespace std;

class Minion : public Enemy {
	private:
		virtual void class_ability() = 0;
	public:
		// a = attack, d = defense, h = health, l = level, nm = name, an = attackNoise
		Minion(string nm, string an) : Enemy(nm, an) {}
		Minion(int lvl, string nm, string an) : Enemy(lvl, nm, an) {}
		Minion(double a, double d, double h, int l, string nm, string an) : Enemy(a, d, h, l, nm, an) {}

		Minion(string nm) : Enemy(nm) {}
		Minion(int lvl, string nm) : Enemy(lvl, nm) {}
		Minion(double a, double d, double h, int l, string nm) : Enemy(a, d, h, l, nm) {}

		double move();
		virtual string get_class_ability_line() = 0;
};

class GoblinMinion : public Minion {
	public:
		GoblinMinion() : Minion("goblin", "shanks") {}
		GoblinMinion(int l) : Minion(l, "goblin", "shanks") {}
		GoblinMinion(double a, double d, double h, int l) : Minion (a, d, h, l, "goblin", "shanks") {}

		void class_ability() {
			this->addCritBoost(1);
		}
		string get_class_ability_line() {
			return "The goblin honed its focus, its more likely to crit.";
		}
};

class SlimeMinion : public Minion {
	public:
		SlimeMinion() : Minion("slime", "tackles") {}
		SlimeMinion(int l) : Minion(l, "slime", "tackles") {}
		SlimeMinion(double a, double d, double h, int l) : Minion (a, d, h, l, "slime", "tackles") {}
		void class_ability() {
			this->addCurrHealth(this->getMaxHealth()*0.2);
		}
		string get_class_ability_line() {
			return "The slime eats a strange substance, it looks lively.";
		}
};

class ChickenMinion : public Minion {
	void class_ability() {
		this->addAttackBoost(1);
	}
	string get_class_ability_line() {
		return "The chicken sharpened its beak with its claws, it looks more dangerous.";
	}
};

#endif

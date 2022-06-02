#ifndef MINION_HPP
#define MINION_HPP
#include "Enemy.hpp"
#include <iostream>

using namespace std;

class Minion : public Enemy {
	public:
		// a = attack, d = defense, h = health, l = level, nm = name, an = attackNoise
		Minion(string nm, string an) : Enemy(nm, an) {}
		Minion(int lvl, string nm, string an) : Enemy(lvl, nm, an) {}
		Minion(double a, double d, double h, int l, string nm, string an) : Enemy(a, d, h, l, nm, an) {}

		Minion(string nm) : Enemy(nm) {}
		Minion(int lvl, string nm) : Enemy(lvl, nm) {}
		Minion(double a, double d, double h, int l, string nm) : Enemy(a, d, h, l, nm) {}

		double move();
		virtual void class_ability() = 0;
		virtual string get_class_ability_line() = 0;
};

class GoblinMinion : public Minion {
	public:
		GoblinMinion() : Minion("Goblin", "shanks") {}
		GoblinMinion(int l) : Minion(l, "Goblin", "shanks") {}
		GoblinMinion(double a, double d, double h, int l) : Minion(a, d, h, l, "Goblin", "shanks") {}

		void class_ability() {
			this->addCritBoost(1);
		}
		string get_class_ability_line() {
			return "The Goblin hones its focus, its more likely to crit.";
		}
};

class SlimeMinion : public Minion {
	public:
		SlimeMinion() : Minion("Slime", "tackles") {}
		SlimeMinion(int l) : Minion(l, "Slime", "tackles") {}
		SlimeMinion(double a, double d, double h, int l) : Minion(a, d, h, l, "Slime", "tackles") {}
		
		void class_ability() {
			this->addTempHealth((int)(this->getMaxHealth()*0.3));
		}
		string get_class_ability_line() {
			return "The Slime eats a strange substance, it grows in size.";
		}
};

class ChickenMinion : public Minion {
	public: 
		ChickenMinion() : Minion("Angry Chicken", "pecks") {}
		ChickenMinion(int l) : Minion(l, "Angry Chicken", "pecks") {}
		ChickenMinion(double a, double d, double h, int l) : Minion(a, d, h, l, "Angry Chicken", "pecks") {}

		void class_ability() {
			this->addAttackBoost(1);
		}
		string get_class_ability_line() {
			return "The Angry Chicken sharpens its beak and claws, it looks more dangerous.";
		}
};

#endif

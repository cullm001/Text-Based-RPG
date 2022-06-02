#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../entity.hpp"
#include <string>
using namespace std;

class Enemy: public Entity {
	protected:
		string name;
		string attackNoise = "punches";
		
	public:
		virtual double move() = 0;
		virtual string get_class_ability_line() {return ""; }
		virtual void class_ability() = 0;

		// a = attack, d = defense, h = health, l = level, nm = name, an = attackNoise
		Enemy(int l, string nm) : Entity(l) {}
		Enemy(string nm) : Entity() {}
		Enemy(double a, double d, double h, int l, string nm) : Entity(a, d, h, l) {}

		Enemy(int l, string nm, string an) : Entity(l) { name = nm; attackNoise = an; }
		Enemy(string nm, string an) : Entity() { name = nm; attackNoise = an; }
		Enemy(double a, double d, double h, int l, string nm, string an) : Entity(a, d, h, l) { name = nm; attackNoise = an; }

		string getName() { return name; }
		string getAttackNoise() { return attackNoise; }
}; 
#endif

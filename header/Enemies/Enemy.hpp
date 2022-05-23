#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../entity.hpp"
#include <string>
using namespace std;

class Enemy: public Entity{
	protected:
		string name;
		
	public:
		virtual int move() = 0;;
		Enemy(int attac, int defens, int health, string nm){
	           attack = attac;
        	   maxHealth = health;
           	   currHealth = health;
           	   defense = defens;
           	   critRate = 0.5;
		   name = nm;
		}
		void takedmg(int i){
			currHealth = currHealth - i;
		}
		string getName() {
			return name;
		}

}; 
#endif

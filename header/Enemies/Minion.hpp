#ifndef MINION_HPP
#define MINION_HPP
#include "Enemy.hpp"
using namespace std;

class Minion: public Enemy{
	public:
		int Attack();
	Minion(){
                maxHealth = 0;
                currHealth = 0;
                defense = 0;
                critRate = 0;
}
       Minion(int attac, int defens, int health){
            attack = attac;
            maxHealth = health;
            currHealth = health;
            defense = defens;
            critRate = 0.5;
}

};
#endif

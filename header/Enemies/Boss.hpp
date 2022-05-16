#ifndef BOSS_HPP
#define BOSS_HPP
#include "Enemy.hpp"
using namespace std;

class Boss: public Enemy{
	public:
		int Attack();
		void ClassAbility();
	Boss(){
                maxHealth = 0;
                currHealth = 0;
                defense = 0;
                critRate = 0;
}
        Boss(int attac, int defens, int health){
	    attack = attac;
            maxHealth = health;
            currHealth = health;
            defense = defens;
            critRate = 0.5;
}
          //  resetTempStats();
          //
          //          }
          //
};
#endif

#ifndef BOSS_HPP
#define BOSS_HPP
#include "Enemy.hpp"
using namespace std;

class Boss: public Enemy{
	private:
		int Attack();
		void ClassAbility();
	public:
		int move();
		Boss(int i, int j, int b,string n): Enemy(i, j, b,n){
			int nothing = 0;
		}	




          //  resetTempStats();
          //
          //          }
          //
};
#endif

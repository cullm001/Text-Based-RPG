#ifndef BOSS_HPP
#define BOSS_HPP
#include "Enemy.hpp"
using namespace std;

class Boss: public Enemy{
	public:
		int Attack();
		void ClassAbility();
};
#endif

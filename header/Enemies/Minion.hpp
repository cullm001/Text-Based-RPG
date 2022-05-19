#ifndef MINION_HPP
#define MINION_HPP
#include "Enemy.hpp"
using namespace std;

class Minion: public Enemy{
	private:
		int Attack();
	public:
		 Minion(int i, int j, int b, string n): Enemy(i, j, b, n){
                        int nothing = 0;
                }
		int move();
};

#endif

#include "Boss.hpp"
#include "Minion.hpp"
#include "Enemy.hpp"
#include <iostream>

using namespace std;

int main(){
	Boss test = Boss(30,30,30, "Bowser");
	test.move();

	Minion test2 = Minion(20,20,20, "Goomba");
	test2.move();
	
	return 0;
}

#include "Enemy.h"
#include "Boss.h"
#include "Minion.h"
#include <iostream>
using namespace std;

int main(){
	Boss test1 = Boss();
	Minion test2 = Minion();
	
	test1.Attack();
	test1.ClassAbility();
	
	test2.Attack();

	return 0;
}

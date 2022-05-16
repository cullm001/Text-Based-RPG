#include "Boss.hpp"
#include "Minion.hpp"
#include "Enemy.hpp"
#include <iostream>

using namespace std;

int main(){
	Boss test = Boss(30,30,30);
	cout << "Boss attack: " << test.Attack() << endl;
	
	Minion test2 = Minion(20,20,20);
	cout << "Minion attack: " << test2.Attack() << endl;
	
	return 0;
}

#include "Boss.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int Boss::Attack(){
	int damage =  this->getAttack() + rand() % 11;
	reset();
	return damage;
}

void Boss::ClassAbility(){

}


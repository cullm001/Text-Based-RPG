#include "Boss.hpp"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

int Boss::Attack(){
	srand(time(0));
	int damage =  this->getAttack() + rand() % 11;
	return damage;
}

void Boss::ClassAbility(){

}


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
	cout << "Boss swang its fist dealing " << damage << " damage!" << endl;
	return damage;
}

void Boss::ClassAbility(){
	cout << "Boss used class ability" << endl;	
	this->addTempHealth(5);
}

int Boss::move(){
	srand(time(0));
	double abilityChance = rand() % 5;
	if (abilityChance < 1){
		ClassAbility();
		return 0;
	}
	
	return Attack();
}


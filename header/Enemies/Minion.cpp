#include "Minion.hpp"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

int Minion::Attack(){
	srand(time(0));
	int damage =  this->getAttack() + rand() % 11;
	cout << name << " attacked dealing " << damage << " damage!" << endl;
        return damage;
}

int Minion::move(){
	return Attack();
}

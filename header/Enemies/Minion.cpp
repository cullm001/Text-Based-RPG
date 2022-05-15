#include "Minion.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int Minion::Attack(){
	int damage =  this->getAttack() + rand() % 11;
	reset();
        return damage;
}

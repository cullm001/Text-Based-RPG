#include "Minion.hpp"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

double Minion::move() {
	srand(time(0));
	double abilityChance = rand() % 3;
	if (abilityChance < 1) {
		class_ability();
		return 0;
	}
	return getAttackDamage();
}
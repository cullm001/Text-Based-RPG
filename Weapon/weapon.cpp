#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(string n, int b) {
    name = n;
    buff = b;
}

int Weapon::getBoost() {
    cout << "Weapon received a boost" << endl;
    return 1;
}

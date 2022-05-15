#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(string n, int b) {
    name = n;
    buff = b;
}

int Weapon::getBoost() {
    return buff;
}
void Weapon::print() {
    cout << "The legendary " << n << "glows in your hand";
    return;
}

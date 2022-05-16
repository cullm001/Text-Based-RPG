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
    cout << "The legendary " << name << "glows in your hand";
    return;
}
string Weapon::getAttackDescription() {
    return attackDescription;
}

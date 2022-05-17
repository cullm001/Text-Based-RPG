#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(string n, int b, string atk) {
    name = n;
    buff = b;
    attackDescription = atk;
}

int Weapon::getBoost() {
    return buff;
}
void Weapon::print() {
    cout << "The " << name << " glows in your hand";
    return;
}
string Weapon::getAttackDescription() {
    return attackDescription;
}

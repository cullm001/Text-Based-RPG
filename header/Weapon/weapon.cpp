#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(string n, int b, string atk, string rar) {
    name = n;
    buff = b;
    attackDescription = atk;
    rarity = rar;
}

void Weapon::print() {
    cout << "The " << name << " glows in your hand";
    return;
}

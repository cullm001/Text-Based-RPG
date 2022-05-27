#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(string n, int b, string atk, string rar) {
    name = n;
    buff = b;
    attackDescription = atk;
    rarity = rar;
}

string Weapon::printFound() {
    string output;
    output += "You discovered a " + getRarity() + " " + getName() + " (+" + to_string(getBoost()) + ")!";
    return output;
}

string Weapon::printStats() {
    string output;
    output += "--- Weapon Stats ---\nName: " + getName() + "\nRarity: " + getRarity() + "\nBuff: " 
    + to_string(getBoost()) + "\nAttack Description: " + getAttackDescription();
    return output;
}

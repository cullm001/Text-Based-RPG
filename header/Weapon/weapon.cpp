#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(string t, int b, string atk, string rar) {
    type = t;
    buff = b;
    attackDescription = atk;
    rarity = rar;
}

string Weapon::printFound() {
    string output;
    output += "You discovered a " + getRarity() + " " + getType() + " (+" + to_string(getBoost()) + ")!";
    return output;
}

string Weapon::printStats() {
    string output;
    output += "--- Weapon Stats ---\nType: " + getType() + "\nRarity: " + getRarity() + "\nBuff: " 
    + to_string(getBoost()) + "\nAttack Description: " + getAttackDescription();
    return output;
}

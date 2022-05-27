#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(string t, int b, int lvl, string atk, string rar) {
    type = t;
    buff = b;
    level = lvl;
    attackDescription = atk;
    rarity = rar;
}

string Weapon::printFound() {
    string output;
    output += "You discovered a Lvl. " + to_string(getLevel()) + " " + getRarity() + " " + getType() + " (+" + to_string(getBoost()) + ")!";
    return output;
}

string Weapon::printStats() {
    string output;
    output += "--- Weapon Stats ---\nType: " + getType() + "\nRarity: " + getRarity() + "\nBuff: " 
    + to_string(getBoost()) + "\nAttack Description: " + getAttackDescription();
    return output;
}

#include "weapon.hpp"
#include <iostream>

Weapon::Weapon(Weapon* base, int lvl) {
    type = base->getType();
    level = lvl;
    attackDescription = base->getAttackDescription();
    rarity = randRarity();
    buff = calcBoost(rarity);
}

Weapon::Weapon(string t, int lvl, string atk) {
    type = t;
    level = lvl;
    attackDescription = atk;
    rarity = randRarity();
    buff = calcBoost(rarity);
}

Weapon::Weapon(string t, int lvl, string atk, string rar) {
    type = t;
    level = lvl;
    attackDescription = atk;
    rarity = rar;
    buff = calcBoost(rarity); // determines buff based on rarity and level
}

Weapon::Weapon(string t, int b, int lvl, string atk, string rar) {
    type = t;
    buff = b;
    level = lvl;
    attackDescription = atk;
    rarity = rar;
}

string Weapon::randRarity() {
    srand(time(0));
    int roll = rand() % 100;
    if (roll < 40) { return "Common"; }
    if (roll < 70) { return "Uncommon"; }
    if (roll < 85) { return "Rare"; }
    if (roll < 95) { return "Epic"; }
    else { return "Legendary"; }
}

double Weapon::calcBoost(string r) {
    if (rarity == "Common") { return level * 0.05 * 2; } 
    else if (r == "Uncommon") { return level * 0.1 * 2; } 
    else if (r == "Rare") { return level * 0.15 * 2; }
    else if (r == "Epic") { return level * 0.20 * 2; } 
    else if (r == "Legendary") { return level * 0.25 * 2; } 
    else { return 0; }
}

string Weapon::printFound() {
    string output;
    output += "You discovered a Lvl. " + to_string(getLevel()) + " " + getRarity() + " " + getType() + " (+" + to_string((int) getBoost()) + ")!";
    return output;
}

string Weapon::printStats() {
    string output;
    output += "--- Weapon Stats ---\nType: " + getType() + "\nRarity: " + getRarity() + "\nBuff: " 
    + to_string(getBoost()) + "\nAttack Description: " + getAttackDescription();
    return output;
}

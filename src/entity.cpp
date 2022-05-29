#include "../header/entity.hpp"

using namespace std;

// constructors
Entity::Entity(){
    maxHealth = 20;
    currHealth = 20;
    attack = 13.5;
    defense = 10;
    critRate = 0.15;
    level = 5;
}

Entity::Entity(int lvl) {
    maxHealth = 10 + (lvl*2);
    currHealth = maxHealth;
    attack = 5 + (lvl*1.7);
    defense = 5 + (lvl);
    critRate = 0.15;
    level = lvl;
}

Entity::Entity(double atk, double def, double hth, int lvl){
    maxHealth = hth;
    currHealth = hth;
    attack = atk;
    defense = def;
    critRate = 0.15;
    level = lvl;
}

// dmg = ((2*level)/5 + 2) * attack
double Entity::getAttackDamage() {
    double dmg = (((2*level)/5) + 2) * getAttack();
    return dmg;
}

// damage taken = damage the enemy deals / defense
double Entity::takedmg(double dmg) {
    double damageTaken = (dmg / getDefense());
    currHealth -= damageTaken;
    return damageTaken;
}

void Entity::heal(double val) {
    currHealth += val;
    if (currHealth > getMaxHealth()) {
        currHealth == getMaxHealth();
    }
}

void Entity::levelUp(int lvl) {
    maxHealth += (lvl*2);
    currHealth = maxHealth;
    attack += (lvl*1.7);
    defense += lvl;
    level += lvl;
}

// *Note that this does not remove currHealth unless it exceeds maxHealth
void Entity::removeTempHealth() {
    maxHealth -= tempHealth;
    if (currHealth > maxHealth) {
        currHealth = maxHealth;
    }
    tempHealth = 0;
}

void Entity::resetTempStats() {
    removeTempHealth();
    removeTempDefense();
    removeTempAttack();
    removeTempCritRate();
}

bool Entity::isBoosted() {
    if (attackBoost + defenseBoost + critBoost != 0 || tempHealth + tempAttack + tempDefense + tempCritRate != 0) {
        return true;
    }
    return false;
}

void Entity::resetBoosts() {
    attackBoost = 0;
    defenseBoost = 0;
    critBoost = 0;
}

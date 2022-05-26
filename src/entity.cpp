#include "../header/entity.hpp"

using namespace std;

// dmg = ((2*level)/5 + 2) * attack

double Entity::getAttackDamage() {
    double dmg = (((2*level)/5) + 2) * getAttack();
    return dmg;
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

void Entity::resetBoosts() {
    attackBoost = 0;
    defenseBoost = 0;
    critBoost = 0;
}

// dmg = ((2*level)/5 + 2) * attack
// full damage taken = ((2*level)/5 + 2) * attack / defense
double Entity::takedmg(double dmg) {
    double damageTaken = (dmg / getDefense());
    currHealth -= damageTaken;
    return damageTaken;
}

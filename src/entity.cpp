#include "../header/entity.hpp"

using namespace std;



Entity::~Entity() {}
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

void Entity::takedmg(int dmg){
    int temp = dmg - getDefense();
    if(temp > 0){
        currHealth = currHealth - temp;
    }
}
void Entity::fullheal(){
    resetTempStats();
    currHealth = maxHealth;
}

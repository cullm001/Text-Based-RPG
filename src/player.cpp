#include "../header/player.hpp"
#include "../header/entity.hpp"
#include "../header/Weapon/weapon.hpp"

using namespace std;

Player::Player(){
    maxHealth = 1;
    currHealth = 1;
    defense = 1;
    critRate = 0.5;
    attack = 1;
    tempHealth = 0;

//`            resetTempStats();
} 

void Player::levelUp() {
    this->addMaxHealth(1);
    this->addDefense(1);
    this->addAttack(1);
}
void Player::class_ability(){
    return;
}
int Player::Attack() {
    int temp = this->getAttack();
    return temp;
}


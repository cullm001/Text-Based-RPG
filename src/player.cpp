#include "../header/player.hpp"
#include "../header/entity.hpp"
#include "../header/Weapon/weapon.hpp"

using namespace std;

Player::Player(){
    maxHealth = 10;
    currHealth = 10;
    defense = 5;
    critRate = 0.5;
    attack = 10;
    tempHealth = 0;
} 

void Player::levelUp() {
    this->addMaxHealthAndCurrHealth(5);
    this->addDefense(1);
    this->addAttack(5);
}
void Player::class_ability(){
    return;
}
int Player::Attack() {
    int temp = this->getAttack();
    return temp;
}


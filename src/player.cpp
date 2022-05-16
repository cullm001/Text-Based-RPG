#include "../header/player.hpp"
#include "../header/entity.hpp"

using namespace std;

Player::~Player(){}

Player::Player(): Entity(){
   random = 0;
} 

void Player::levelUp() {
    this->addMaxHealth(1);
    this->addDefense(1);
    this->addAttack(1);
}
void Player::ability(){
    return;
}
int Player::Attack() {
    return Entity::getAttack();
}


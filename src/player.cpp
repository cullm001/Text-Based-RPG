#include "src/player.hpp"
#include "entity.hpp"

using namespace std;

Player::Player(): Entitiy(1,1,1){
    
} 

void Player::levelUp(int levels) {
    this->addMaxHealth(1);
    this->addDefense(1);
    this->addAttack(1);
}
void Player::Class_ability(){
    return;
}
void Player::Attack(){
    int temp = this->getAttack();
    return temp;
}

